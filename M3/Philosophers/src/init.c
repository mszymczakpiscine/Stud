//
// Created by maia on 04/07/25.
//
#include "philo.h"

static int	ft_atoi(const char *str)
{
    int res = 0;
    while (*str >= '0' && *str <= '9')
        res = res * 10 + (*str++ - '0');
    return (res);
}

static int init_mutexes(t_data *data)
{
    int i;

    data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_count);
    if (!data->forks)
        return (1);

    for (i = 0; i < data->philo_count; i++)
    {
        if (pthread_mutex_init(&data->forks[i], NULL) != 0)
            return (1);
    }

    if (pthread_mutex_init(&data->print_mutex, NULL) != 0)
        return (1);
    if (pthread_mutex_init(&data->death_mutex, NULL) != 0)
        return (1);
    if (pthread_mutex_init(&data->full_mutex, NULL) != 0)  // <-- ajout ici
        return (1);

    return (0);
}

void init_philosophers(t_data *data)
{
    int i;

    i = 0;
    while (i < data->philo_count)
    {
        data->philos[i].id = i + 1;
        data->philos[i].left_fork = i;
        data->philos[i].right_fork = (i + 1) % data->philo_count;
        data->philos[i].last_meal = current_time();
        data->philos[i].meals_eaten = 0;
        data->philos[i].data = data;
        i++;
    }
}

int init_all(t_data *data, int argc, char **argv)
{
    data->philo_count = ft_atoi(argv[1]);
    data->time_to_die = ft_atoi(argv[2]);
    data->time_to_eat = ft_atoi(argv[3]);
    data->time_to_sleep = ft_atoi(argv[4]);
    data->must_eat = -1;
    data->someone_died = 0;
    data->full_count = 0;
    data->start_time = current_time();

    if (argc == 6)
        data->must_eat = ft_atoi(argv[5]);

    data->philos = malloc(sizeof(t_philo) * data->philo_count);
    if (!data->philos)
        return (1);

    if (init_mutexes(data))
        return (1);

    for (int i = 0; i < data->philo_count; i++)
    {
        data->philos[i].id = i + 1;
        data->philos[i].left_fork = i;
        data->philos[i].right_fork = (i + 1) % data->philo_count;
        data->philos[i].meals_eaten = 0;
        data->philos[i].data = data;
        data->philos[i].last_meal = data->start_time;  // initialisation ici
    }
    return (0);
}
