//
// Created by maia on 04/07/25.
//

#include "philo.h"

long long current_time() // mesure le temps
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return ((tv.tv_sec * 1000LL) + (tv.tv_usec / 1000LL)); //convert second in millisec (LL for long long) & micro in milli
}

void    precise_usleep(long long time) // verif
{
    long long start = current_time();
    while (current_time() - start < time)
        usleep(100);
}

void    print_status(t_philo *philo, const char *status) // affiche le status en cours d'execution
{
    pthread_mutex_lock(&philo->data->print_mutex);
    if (!philo->data->someone_died) // si aucun philo n'est mort
        printf("%lld %d %s\n", current_time() - philo->data->start_time, philo->id, status); // calcul le tps ecoule depuis le debut
    pthread_mutex_unlock(&philo->data->print_mutex);
}