/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 18:58:33 by mszymcza          #+#    #+#             */
/*   Updated: 2025/11/04 18:58:33 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    HitPoints = 100;
    EnergyPoints = 50;
    AttackDamage = 20;
    _isGuardingGate = false;
    std::cout << GREEN << "ScavTrap Default Constructor called" << RESET << std::endl;
}
ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    HitPoints = 100;
    EnergyPoints = 50;
    AttackDamage = 20;
    _isGuardingGate = false;
    std::cout << GREEN << "ScavTrap Constructor called for " << name << RESET << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    _isGuardingGate = other._isGuardingGate;
    std::cout << BLUE << "ScavTrap Copy Constructor called" << RESET << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    std::cout << PURPLE << "ScavTrap Copy assignment operator called" << RESET << std::endl;
    if (this != &other)
    {
        ClapTrap::operator=(other);
        _isGuardingGate = other._isGuardingGate;
    }
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << RED << "ScavTrap Destructor called "<< RESET << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (EnergyPoints > 0 && HitPoints > 0)
    {
        std::cout << YELLOW << "ScavTrap " << name;
        std::cout << " attacks " << target << ", causing ";
        std::cout << AttackDamage << " points of damage!" << RESET << std::endl;
        EnergyPoints--;
    }
    else if (EnergyPoints <= 0)
        std::cout << RED << name << " has not enough Energy Points!" << RESET << std::endl;
    else if (HitPoints <= 0)
        std::cout << RED << name << " is dead, he can't attack!" << RESET << std::endl;
}

void ScavTrap::guardGate()
{
    if (!_isGuardingGate)
    {
        _isGuardingGate = true;
        std::cout << BLUE << name << " is now in Gate Keeper mode." << RESET << std::endl;
    }
    else
    {
        _isGuardingGate = false;
        std::cout << BLUE << name << " has exited Gate Keeper mode." << RESET << std::endl;
    }
}
