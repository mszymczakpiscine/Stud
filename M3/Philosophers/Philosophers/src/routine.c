/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 16:42:12 by mszymcza          #+#    #+#             */
/*   Updated: 2025/08/14 17:12:49 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_someone_dead(t_data *data)
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

static void	update_meal(t_philo *philo)
{
    pthread_mutex_lock(&philo->data->death_mutex);
    philo->last_meal = current_time();
    pthread_mutex_unlock(&philo->data->death_mutex);
}

static int	check_full(t_philo *philo)
{
    if (philo->data->must_eat != -1 && ++philo->meals_eaten == philo->data->must_eat)
    {
        pthread_mutex_lock(&philo->data->full_mutex);
        philo->data->full_count++;
        pthread_mutex_unlock(&philo->data->full_mutex);
        return (1);
    }
    return (0);
}

void	*philo_routine(void *arg)
{
    t_philo	*philo = (t_philo *)arg;
    t_data	*data = philo->data;

    if (philo->id % 2 == 0)
        usleep(1000);
    while (1)
    {
        if (is_someone_dead(data))
            break;
        print_status(philo, "is thinking");
        pthread_mutex_lock(&data->forks[philo->left_fork]);
        print_status(philo, "has taken a fork");
        pthread_mutex_lock(&data->forks[philo->right_fork]);
        print_status(philo, "has taken a fork");
        update_meal(philo);
        print_status(philo, "is eating");
        precise_usleep(data->time_to_eat);
        pthread_mutex_unlock(&data->forks[philo->left_fork]);
        pthread_mutex_unlock(&data->forks[philo->right_fork]);
        if (check_full(philo))
            break;
        print_status(philo, "is sleeping");
        precise_usleep(data->time_to_sleep);
    }
    return (NULL);
}
