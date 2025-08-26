/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 14:10:54 by mszymcza          #+#    #+#             */
/*   Updated: 2025/08/26 14:13:16 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_someone_dead(t_data *data)
{
	pthread_mutex_lock(&data->death_mutex);
	if (data->someone_died)
	{
		pthread_mutex_unlock(&data->death_mutex);
		return (1);
	}
	pthread_mutex_unlock(&data->death_mutex);
	return (0);
}

void	update_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->death_mutex);
	philo->last_meal = current_time();
	pthread_mutex_unlock(&philo->data->death_mutex);
}

int	check_full(t_philo *philo)
{
	if (philo->data->must_eat != -1
		&& ++philo->meals_eaten == philo->data->must_eat)
	{
		pthread_mutex_lock(&philo->data->full_mutex);
		philo->data->full_count++;
		pthread_mutex_unlock(&philo->data->full_mutex);
		return (1);
	}
	return (0);
}
