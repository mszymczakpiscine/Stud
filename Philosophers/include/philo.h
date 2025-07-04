//
// Created by maia on 04/07/25.
//

#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct s_data t_data;

typedef struct s_philo {
    int            id;
    int            left_fork;
    int            right_fork;
    long long      last_meal;
    int            meals_eaten;
    pthread_t      thread;
    t_data         *data;
}                t_philo;

typedef struct s_data {
    int             philo_count;
    int             time_to_die;
    int             time_to_eat;
    int             time_to_sleep;
    int             must_eat;
    int             someone_died;
	int 			finished_philos;
	int     full_count;
	pthread_mutex_t full_mutex;

    long long       start_time;

    pthread_mutex_t *forks;
    pthread_mutex_t print_mutex;
    pthread_mutex_t death_mutex;

    t_philo         *philos;
}               t_data;

void 		*monitor_meals(void *arg);
void 		init_philosophers(t_data *data);
int         init_all(t_data *data, int argc, char **argv);
void        *philo_routine(void *arg);
void        *check_death(void *arg);
long long   current_time(void);
void        precise_usleep(long long time);
void        print_status(t_philo *philo, const char *status);

#endif
