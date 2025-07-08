/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:09:44 by mszymcza          #+#    #+#             */
/*   Updated: 2025/04/29 10:09:46 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

void test_file(const char filename)
{
    int fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        perror("Erreur d'ouverture de fichier");
        return;
    }

    printf("=== Test du fichier : %s ===\n", filename);

    charline;
    int i = 1;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Ligne %d : %s", i++, line);
        if (line[0] && line[ft_strlen(line) - 1] != '\n')
            printf("\n");  // Ajouter un saut de ligne si manquant
        free(line);
    }
    close(fd);
    printf("=== Fin du fichier ===\n\n");
}
 
int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Usage : %s <fichier1> [fichier2 ...]\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++)
    {
        test_file(argv[i]);
    }

    return 0;
}