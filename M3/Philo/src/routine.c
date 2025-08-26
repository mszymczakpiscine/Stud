/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 16:42:12 by mszymcza          #+#    #+#             */
/*   Updated: 2025/08/26 14:22:42 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lock_forks(t_philo *philo, t_data *data)
{
	int	first;
	int	second;

	first = philo->left_fork;
	second = philo->right_fork;
	if (first > second)
	{
		first = philo->right_fork;
		second = philo->left_fork;
	}
	pthread_mutex_lock(&data->forks[first]);
	philo->left_taken = (first == philo->left_fork);
	philo->right_taken = (first == philo->right_fork);
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(&data->forks[second]);
	philo->left_taken = (philo->left_taken || second == philo->left_fork);
	philo->right_taken = (philo->right_taken || second == philo->right_fork);
	print_status(philo, "has taken a fork");
}

void	unlock_forks(t_philo *philo, t_data *data)
{
	if (philo->left_taken)
	{
		pthread_mutex_unlock(&data->forks[philo->left_fork]);
		philo->left_taken = 0;
	}
	if (philo->right_taken)
	{
		pthread_mutex_unlock(&data->forks[philo->right_fork]);
		philo->right_taken = 0;
	}
}

static int	f(t_philo *philo, t_data *data)
{
	if (is_someone_dead(data) || check_full(philo))
		return (1);
	print_status(philo, "is thinking");
	lock_forks(philo, data);
	if (is_someone_dead(data))
	{
		unlock_forks(philo, data);
		return (1);
	}
	print_status(philo, "is eating");
	precise_usleep(data->time_to_eat);
	update_meal(philo);
	unlock_forks(philo, data);
	if (is_someone_dead(data) || check_full(philo))
		return (1);
	print_status(philo, "is sleeping");
	precise_usleep(data->time_to_sleep);
	return (0);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	if (data->time_to_die <= 0)
	{
		print_status(philo, "died");
		return (NULL);
	}
	if (philo->id % 2 == 0)
		usleep(1000);
	while (!f(philo, data))
		;
	unlock_forks(philo, data);
	return (NULL);
}
