/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 16:42:01 by mszymcza          #+#    #+#             */
/*   Updated: 2025/08/14 17:12:39 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
    t_data      data;
    pthread_t   monitor_thread;
    int         i;

    if (argc < 5)
    {
        write(1, "needs more arguments\n", 21);
        return (0);
    }
    if (init_all(&data, argc, argv) != 0)
        return (1);

    data.start_time = current_time();
    data.full_count = 0;
    i = 0;
    while (i < data.philo_count)
    {
        if (pthread_create(&data.philos[i].thread, NULL, philo_routine,
                           &data.philos[i]) != 0)
        {
            perror("pthread_create philo");
            return (1);
        }
        i++;
    }
    if (pthread_create(&monitor_thread, NULL, check_death, &data) != 0)
    {
        perror("pthread_create monitor");
        return (1);
    }
    i = 0;
    while (i < data.philo_count)
    {
        if (pthread_join(data.philos[i].thread, NULL) != 0)
            perror("pthread_join philo");
        i++;
    }
    if (pthread_join(monitor_thread, NULL) != 0)
        perror("pthread_join monitor");
    i = 0;
    while (i < data.philo_count)
    {
        pthread_mutex_destroy(&data.forks[i]);
        i++;
    }
    pthread_mutex_destroy(&data.print_mutex);
    pthread_mutex_destroy(&data.death_mutex);
    pthread_mutex_destroy(&data.full_mutex);
    free(data.forks);
    free(data.philos);

    return (0);
}
