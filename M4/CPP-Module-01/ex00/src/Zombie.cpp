/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:49:49 by mszymcza          #+#    #+#             */
/*   Updated: 2025/11/04 13:49:49 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/zombie.hpp"

Zombie::Zombie(std::string name)
{
        this->name = name;
}

void    Zombie::setName(std::string name)
{
        this->name = name;
}

void    Zombie::annonce(void) const
{
        std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
        std::cout << this->name << " is destroyed" << std::endl;
}
