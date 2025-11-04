/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:14:35 by mszymcza          #+#    #+#             */
/*   Updated: 2025/11/04 14:14:35 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie::Zombie()
{
    std::cout << "Zombie created!" << std::endl;
}

Zombie::Zombie(std::string name) : name(name)
{
    std::cout << "Zombie Horde " << this->name << " created !" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "Zombie Horde " << "destroyed !" << std::endl;
}

void Zombie::annonce(void) const
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::set_zombie_horde(std::string name)
{
    this->name = name;
}
