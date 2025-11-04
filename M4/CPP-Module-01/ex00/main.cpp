/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:59:31 by mszymcza          #+#    #+#             */
/*   Updated: 2025/11/04 13:59:31 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/zombie.hpp"

int main()
{
    Zombie *zombie1 = newZombie("Heap_Zombie");
    randomChump("Stack_Zombie");
    zombie1->annonce();
    delete zombie1;
    return (0);
}
