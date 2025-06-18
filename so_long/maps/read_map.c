/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:06:49 by mszymcza          #+#    #+#             */
/*   Updated: 2025/06/17 14:46:56 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_tile	*read_map(char *file_in)
{
	int i = 0;
	t_tile	*tab[] = {0};
	open(file_in, O_RDONLY);
	//bouleen (tab[][])
	//parsing
	//lire tab[] allocation dyamique pour avoir la size officielle
	//fichier pour size
	// verif si 0 ou 1 (good ou pas good chaque critere)
	// si good open la bonne size de map else ERROR 
	// une fois read, close
	//free touuuuuut <3
	
	
}

