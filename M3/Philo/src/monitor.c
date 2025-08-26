/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 16:42:06 by mszymcza          #+#    #+#             */
/*   Updated: 2025/08/26 14:09:12 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_death(t_data *data, int id)
{
	pthread_mutex_lock(&data->print_mutex);
	printf("%lld %d died\n", current_time() - data->start_time, id);
	pthread_mutex_unlock(&data->print_mutex);
}

static void	print_all_full(t_data *data)
{
	pthread_mutex_lock(&data->print_mutex);
	printf("Each philosopher ate %d time(s)\n", data->must_eat);
	pthread_mutex_unlock(&data->print_mutex);
}

static int	check_one_philo(t_data *data, int i)
{
	long long	t;

	pthread_mutex_lock(&data->death_mutex);
	t = current_time() - data->philos[i].last_meal;
	if (t > data->time_to_die)
	{
		data->someone_died = 1;
		pthread_mutex_unlock(&data->death_mutex);
		print_death(data, data->philos[i].id);
		return (1);
	}
	pthread_mutex_unlock(&data->death_mutex);
	return (0);
}

void	*check_death(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	while (1)
	{
		i = 0;
		while (i < data->philo_count)
			if (check_one_philo(data, i++))
				return (NULL);
		pthread_mutex_lock(&data->full_mutex);
		if (data->must_eat != -1 && data->full_count == data->philo_count)
		{
			pthread_mutex_unlock(&data->full_mutex);
			print_all_full(data);
			return (NULL);
		}
		pthread_mutex_unlock(&data->full_mutex);
		usleep(1000);
	}
	return (NULL);
}

void	*monitor_meals(void *arg)
{
	t_data	*data;
	int		i;
	int		done;

	data = (t_data *)arg;
	while (1)
	{
		done = 0;
		i = 0;
		while (i < data->philo_count)
		{
			pthread_mutex_lock(&data->death_mutex);
			if (data->philos[i++].meals_eaten >= data->must_eat)
				done++;
			pthread_mutex_unlock(&data->death_mutex);
		}
		if (done == data->philo_count)
		{
			return (print_all_full(data),
				pthread_mutex_lock(&data->death_mutex), data->someone_died = 1,
				pthread_mutex_unlock(&data->death_mutex), NULL);
		}
		usleep(1000);
	}
	return (NULL);
}
