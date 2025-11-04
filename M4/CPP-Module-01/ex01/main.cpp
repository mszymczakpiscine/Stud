/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:20:34 by mszymcza          #+#    #+#             */
/*   Updated: 2025/11/04 14:20:34 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int main()
{
    int n = 5;
    Zombie *horde = zombieHorde(n, "HordeZombie");
    for (int i = 0; i < n; i++)
    {
        std::cout << i << ": ";
        horde[i].annonce();
    }
    delete[] horde;
    return 0;
}