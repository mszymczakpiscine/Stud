/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 11:57:36 by mszymcza          #+#    #+#             */
/*   Updated: 2025/08/26 14:21:14 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000LL) + (tv.tv_usec / 1000LL));
}

void	precise_usleep(long long time)
{
	long long	start;

	start = current_time();
	while (current_time() - start < time)
		usleep(100);
}

void	print_status(t_philo *philo, const char *status)
{
	int	someone_died;

	pthread_mutex_lock(&philo->data->death_mutex);
	someone_died = philo->data->someone_died;
	pthread_mutex_unlock(&philo->data->death_mutex);
	if (!someone_died)
	{
		pthread_mutex_lock(&philo->data->print_mutex);
		printf("%lld %d %s\n", current_time() - philo->data->start_time,
			philo->id, status);
		pthread_mutex_unlock(&philo->data->print_mutex);
	}
}

int	is_dead(t_data *data)
{
	int	result;

	pthread_mutex_lock(&data->death_mutex);
	result = data->someone_died;
	pthread_mutex_unlock(&data->death_mutex);
	return (result);
}
