//
// Created by maia on 04/07/25.
//
#include "philo.h"

int main(int argc, char **argv)
{
    t_data data;
    pthread_t monitor_thread;
    int i;

    if (init_all(&data, argc, argv) != 0)
        return (1);
    data.start_time = current_time();  // initialisation du temps de départ
    data.full_count = 0;
    i = 0;
    while (i < data.philo_count)
    {
        pthread_create(&data.philos[i].thread, NULL, philo_routine, &data.philos[i]);
        i++;
    }
    pthread_create(&monitor_thread, NULL, check_death, &data);
    i = 0;
    while (i < data.philo_count)
    {
        pthread_join(data.philos[i].thread, NULL);
        i++;
    }
    pthread_join(monitor_thread, NULL);
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
