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

void *philo_routine(void *arg)
{
    t_philo *philo = (t_philo *)arg;
    t_data *data = philo->data;

    if (philo->id % 2 == 0)
        usleep(1000);
    while (1)
    {
        pthread_mutex_lock(&data->death_mutex);
        if (data->someone_died)
        {
            pthread_mutex_unlock(&data->death_mutex);
            break;
        }
        pthread_mutex_unlock(&data->death_mutex);
        print_status(philo, "is thinking");
        pthread_mutex_lock(&data->forks[philo->left_fork]);
        print_status(philo, "has taken a fork");
        pthread_mutex_lock(&data->forks[philo->right_fork]);
        print_status(philo, "has taken a fork");
        pthread_mutex_lock(&data->death_mutex);
        philo->last_meal = current_time();
        pthread_mutex_unlock(&data->death_mutex);
        print_status(philo, "is eating");
        precise_usleep(data->time_to_eat);
        pthread_mutex_unlock(&data->forks[philo->left_fork]);
        pthread_mutex_unlock(&data->forks[philo->right_fork]);
        philo->meals_eaten++;
        if (data->must_eat != -1 && philo->meals_eaten == data->must_eat)
        {
            pthread_mutex_lock(&data->full_mutex);
            data->full_count++;
            pthread_mutex_unlock(&data->full_mutex);
            break;
        }
        print_status(philo, "is sleeping");
        precise_usleep(data->time_to_sleep);
    }
    return (NULL);
}
