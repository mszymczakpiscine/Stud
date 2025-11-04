/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:12:18 by mszymcza          #+#    #+#             */
/*   Updated: 2025/11/04 14:12:18 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie *zombieHorde(int n, std::string name)
{
    if (n < 1)
        return NULL;
    Zombie *zombieHorde = new Zombie[n];
    for (int i = 0; i < n; i++)
    {
        zombieHorde[i].set_zombie_horde(name);
    }
    return zombieHorde;
}
