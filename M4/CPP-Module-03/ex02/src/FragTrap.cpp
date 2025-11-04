/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 19:22:46 by mszymcza          #+#    #+#             */
/*   Updated: 2025/11/04 19:22:46 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    HitPoints = 100;
    EnergyPoints = 100;
    AttackDamage = 30;
    std::cout << GREEN << "FragTrap Default Constructor called" << RESET << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    HitPoints = 100;
    EnergyPoints = 100;
    AttackDamage = 30;
    std::cout << GREEN << "FragTrap Constructor called for " << name << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << BLUE << "FragTrap Copy Constructor called" << RESET << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    std::cout << PURPLE << "FragTrap Copy assignment operator called" << RESET << std::endl;
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << RED << "FragTrap Destructor called "<< RESET << std::endl;
}

void FragTrap::attack(const std::string& target)
{
    if (EnergyPoints > 0 && HitPoints > 0)
    {
        std::cout << YELLOW << "FragTrap " << name;
        std::cout << " attacks " << target << ", causing ";
        std::cout << AttackDamage << " points of damage!" << RESET << std::endl;
        EnergyPoints--;
    }
    else if (EnergyPoints <= 0)
        std::cout << RED << name << " has not enough Energy Points!" << RESET << std::endl;
    else if (HitPoints <= 0)
        std::cout << RED << name << " is dead, he can't attack!" << RESET << std::endl;
}

void FragTrap::highFivesGuys()
{
    if (HitPoints > 0)
        std::cout << PURPLE << "FragTrap " << name << " is requesting a high five! ✋" << RESET << std::endl;
    else
        std::cout << NRED << "FragTrap " << name << " is dead, he can't request a high five!" << RESET << std::endl;
}

