/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:55:09 by mszymcza          #+#    #+#             */
/*   Updated: 2025/07/09 18:55:09 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

typedef struct  s_point
  {
    int           x;
    int           y;
} t_point;

void  flood_fill(char **tab, t_point size, t_point begin)
{
	char	c;
	t_point p;

	if (begin.x < 0 || begin.x >= size.x || begin.y < 0 || begin.y >= size.y)
		return ;
	c = tab[begin.y][begin.x];
	tab[begin.y][begin.x] = 'F';
	p = (t_point){.x = begin.x, .y = begin.y - 1};
	if (p.x >= 0 && p.x < size.x && p.y >= 0 && p.y < size.y && tab[p.y][p.x] == c)
		flood_fill(tab, size, p);
	p = (t_point){.x = begin.x, .y = begin.y + 1};
	if (p.x >= 0 && p.x < size.x && p.y >= 0 && p.y < size.y && tab[p.y][p.x] == c)
		flood_fill(tab, size, p);
	p = (t_point){.x = begin.x - 1, .y = begin.y};
	if (p.x >= 0 && p.x < size.x && p.y >= 0 && p.y < size.y && tab[p.y][p.x] == c)
		flood_fill(tab, size, p);
	p = (t_point){.x = begin.x + 1, .y = begin.y};
	if (p.x >= 0 && p.x < size.x && p.y >= 0 && p.y < size.y && tab[p.y][p.x] == c)
		flood_fill(tab, size, p);
}
/*
char** make_area(char** zone, t_point size)
{
        char** new;

        new = malloc(sizeof(char*) * size.y);
        for (int i = 0; i < size.y; ++i)
        {
                new[i] = malloc(size.x + 1);
                for (int j = 0; j < size.x; ++j)
                        new[i][j] = zone[i][j];
                new[i][size.x] = '\0';
        }

        return new;
}

int main(void)
{
        t_point size = {8, 5};
        char *zone[] = {
                "11111111",
                "10001001",
                "10010001",
                "10110001",
                "11100001",
        };

        char**  area = make_area(zone, size);
        for (int i = 0; i < size.y; ++i)
                printf("%s\n", area[i]);
        printf("\n");

        t_point begin = {0, 1};
        flood_fill(area, size, begin);
        for (int i = 0; i < size.y; ++i)
                printf("%s\n", area[i]);
        return (0);
}*/

