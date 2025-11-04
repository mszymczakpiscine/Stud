/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:26:02 by mszymcza          #+#    #+#             */
/*   Updated: 2025/11/04 15:26:02 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"

Weapon::Weapon(std::string type)
{
    this->type = type;
    std::cout << "Weapon of type " << this->type << " created!" << std::endl;
}
Weapon::~Weapon()
{
    std::cout << "Weapon of type " << this->type << " destroyed!" << std::endl;
}
void Weapon::setType(std::string type)
{
    this->type = type;
}
const std::string &Weapon::getType() const
{
    return this->type;
}

