/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 15:27:03 by mszymcza          #+#    #+#             */
/*   Updated: 2025/08/03 15:48:44 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct  s_point
{
	int		x;
    int		y;
}			t_point;


void flood_fill(char **tab, t_point size, t_point begin)
{
    char c;
    t_point p;

    // Vérifie qu'on est dans la zone
    if (begin.x < 0 || begin.x >= size.x || begin.y < 0 || begin.y >= size.y)
        return;

    c = tab[begin.y][begin.x];   // y = ligne, x = colonne
    tab[begin.y][begin.x] = 'F';

    // gauche
    p = (t_point){begin.x - 1, begin.y};
    if (p.x >= 0 && tab[p.y][p.x] == c)
        flood_fill(tab, size, p);

    // droite
    p = (t_point){begin.x + 1, begin.y};
    if (p.x < size.x && tab[p.y][p.x] == c)
        flood_fill(tab, size, p);

    // haut
    p = (t_point){begin.x, begin.y - 1};
    if (p.y >= 0 && tab[p.y][p.x] == c)
        flood_fill(tab, size, p);

    // bas
    p = (t_point){begin.x, begin.y + 1};
    if (p.y < size.y && tab[p.y][p.x] == c)
        flood_fill(tab, size, p);
}
