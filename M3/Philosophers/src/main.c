/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 16:42:01 by mszymcza          #+#    #+#             */
/*   Updated: 2025/08/26 11:56:20 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	join_threads(t_data *data, pthread_t monitor_thread)
{
	int	i;

	i = 0;
	while (i < data->philo_count)
	{
		if (pthread_join(data->philos[i].thread, NULL) != 0)
			perror("pthread_join philo");
		i++;
	}
	if (pthread_join(monitor_thread, NULL) != 0)
		perror("pthread_join monitor");
}

static void	destroy_and_free(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_count)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->death_mutex);
	pthread_mutex_destroy(&data->full_mutex);
	free(data->forks);
	free(data->philos);
}

static int	handle_one_philo(t_data *data)
{
	print_status(&data->philos[0], "has taken a fork");
	usleep(data->time_to_die * 1000);
	print_status(&data->philos[0], "died");
	return (1);
}

int	main(int argc, char **argv)
{
	t_data		data;
	pthread_t	monitor_thread;
	int			i;

	if (argc < 5)
	{
		write(1, "needs more arguments\n", 21);
		return (0);
	}
	if (init_all(&data, argc, argv) != 0)
		return (1);
	if (data.philo_count == 1)
		return (handle_one_philo(&data));
	i = 0;
	while (i < data.philo_count)
	{
		if (pthread_create(&data.philos[i].thread, NULL, philo_routine,
				&data.philos[i]) != 0)
			return (perror("pthread_create philo"), 1);
		i++;
	}
	if (pthread_create(&monitor_thread, NULL, check_death, &data) != 0)
		return (perror("pthread_create monitor"), 1);
	join_threads(&data, monitor_thread);
	destroy_and_free(&data);
	return (0);
}


