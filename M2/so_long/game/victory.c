/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   victory.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 14:50:30 by mszymcza          #+#    #+#             */
/*   Updated: 2025/06/21 15:19:45 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void render_victory_screen(t_game *game)
{
    mlx_clear_window(game->mlx, game->win);

    // Affiche du texte au milieu de la fenêtre
    // Position à ajuster selon la taille de ta fenêtre
    int x = game->width * 32 / 4; // exemple pour centrer horizontalement
    int y = game->height * 32 / 2;

    mlx_string_put(game->mlx, game->win, x, y - 20, 0x00FF00, "VICTOIRY !");
    mlx_string_put(game->mlx, game->win, x - 80, y + 20, 0xFFFFFF, "Well done you win!");
    mlx_string_put(game->mlx, game->win, x - 130, y + 60, 0xFFFFFF, "Appuyez sur une touche pour quitter.");

    // Attente d'un événement clavier pour quitter
    // (Dans ta boucle d'événements, tu peux gérer ça)
}

int victory_key_handler(int keycode, t_game *game)
{
    (void)keycode;
    (void)game;
    exit(0);
    return (0);
}

