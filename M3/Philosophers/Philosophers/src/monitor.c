/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 16:42:06 by mszymcza          #+#    #+#             */
/*   Updated: 2025/08/14 17:13:27 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *check_death(void *arg)
{
    t_data *data = (t_data *)arg;
    
    while (1)
    {
        for (int i = 0; i < data->philo_count; i++)
        {
            pthread_mutex_lock(&data->death_mutex);
            long long time_since_meal = current_time() 
            - data->philos[i].last_meal;
            if (time_since_meal > data->time_to_die)
            {
                data->someone_died = 1;
                pthread_mutex_unlock(&data->death_mutex);
                pthread_mutex_lock(&data->print_mutex);
                printf("%lld %d died\n", current_time() - data->start_time, 
                data->philos[i].id);
                pthread_mutex_unlock(&data->print_mutex);
                return (NULL);
            }
            pthread_mutex_unlock(&data->death_mutex);
        }
        pthread_mutex_lock(&data->full_mutex);
        if (data->must_eat != -1 && data->full_count == data->philo_count)
        {
            pthread_mutex_unlock(&data->full_mutex);
            pthread_mutex_lock(&data->print_mutex);
            printf("Each philosopher ate %d time(s)\n", data->must_eat);
            pthread_mutex_unlock(&data->print_mutex);
            return (NULL);
        }
        pthread_mutex_unlock(&data->full_mutex);

        usleep(1000);
    }
    return (NULL);
}

void *monitor_meals(void *arg)
{
    t_data *data = (t_data *)arg;
    int i, done;

    while (1)
    {
        done = 0;
        i = 0;
        while (i < data->philo_count)
        {
            pthread_mutex_lock(&data->death_mutex);
            if (data->philos[i].meals_eaten >= data->must_eat)
                done++;
            pthread_mutex_unlock(&data->death_mutex);
            i++;
        }
        if (done == data->philo_count)
        {
            pthread_mutex_lock(&data->print_mutex);
            printf("Each philosopher ate %d time(s)\n", data->must_eat);
            pthread_mutex_unlock(&data->print_mutex);

            pthread_mutex_lock(&data->death_mutex);
            data->someone_died = 1;
            pthread_mutex_unlock(&data->death_mutex);
            return (NULL);
        }
        usleep(1000);
    }
    return (NULL);
}
