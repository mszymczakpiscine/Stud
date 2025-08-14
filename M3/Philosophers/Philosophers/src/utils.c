/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 16:42:19 by mszymcza          #+#    #+#             */
/*   Updated: 2025/08/14 17:13:08 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long current_time()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return ((tv.tv_sec * 1000LL) + (tv.tv_usec / 1000LL));

void    precise_usleep(long long time)
{
    long long start = current_time();
    while (current_time() - start < time)
        usleep(100);
}

void    print_status(t_philo *philo, const char *status)
{
    pthread_mutex_lock(&philo->data->print_mutex);
    if (!philo->data->someone_died)
        printf("%lld %d %s\n", current_time() - philo->data->start_time, 
        philo->id, status);
    pthread_mutex_unlock(&philo->data->print_mutex);
}
