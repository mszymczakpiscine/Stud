/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 18:29:12 by mszymcza          #+#    #+#             */
/*   Updated: 2025/11/04 18:29:12 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap() : name(""), HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
    std::cout << GREEN << "Default Constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : name(name), HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
    std::cout << GREEN << "Constructor called for " << name << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    std::cout << BLUE << "Copy Constructor called" << RESET << std::endl;
    *this = other;
}

ClapTrap::~ClapTrap()
{
    std::cout << RED << "Destructor called"<< RESET << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << PURPLE << "Copy assignment operator called" << RESET << std::endl;
    if (this != &other)
    {
        name = other.name;
        HitPoints = other.HitPoints;
        EnergyPoints = other.EnergyPoints;
        AttackDamage = other.AttackDamage;
    }
    return *this;
}

void ClapTrap::attack(const std::string& target)
{
    if (EnergyPoints > 0 && HitPoints > 0)
    {
        std::cout << YELLOW << "ClapTrap " << name;
        std::cout << " attacks " << target << ", causing ";
        std::cout << AttackDamage << " points of damage!" << RESET << std::endl;
        EnergyPoints--;
    }
    else if (EnergyPoints <= 0)
        std::cout << RED << name << " has not enough Energy Points!" << RESET << std::endl;
    else if (HitPoints <= 0)
        std::cout << RED << name << " is dead, he can't attack!" << RESET << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (amount == 0)
    {
        std::cout << PURPLE << "Attack Missed!" << RESET << std::endl;
        return;
    }
    if (HitPoints > 0)
    {
        std::cout << RED << name << " took " << amount << " damage";
        if (amount >= HitPoints)
        {
            HitPoints = 0;
            std::cout << " and died!" << RESET << std::endl;
        }
        else
        {
            HitPoints -= amount;
            std::cout << ", remaining hit points: " << HitPoints << RESET << std::endl;
        }
        if (HitPoints == 0)
            std::cout << NRED << name << " is destroyed!" << RESET << std::endl;
    }
    else
        std::cout << NRED << name << " is already dead!" << RESET << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (amount == 0)
    {
        std::cout << RED << "Nothing to repair!" << RESET << std::endl;
        return;
    }
    if (EnergyPoints > 0 && HitPoints > 0)
    {
        EnergyPoints--;
        HitPoints += amount;
        std::cout << GREEN << name << " repaired itself for " << amount << " points, new hit points: " << HitPoints << RESET << std::endl;
    }
    else if (HitPoints <= 0)
        std::cout << RED << name << " is dead, he can't repair!" << RESET << std::endl;
    else if (EnergyPoints <= 0)
        std::cout << RED << name << " has not enough Energy Points!" << RESET << std::endl;
}

void ClapTrap::set_damages(unsigned int amount)
{
    AttackDamage = amount;
}

int ClapTrap::get_damages() const
{
    return AttackDamage;
}

void ClapTrap::print_infos() const
{
    std::cout << NBLUE << "=== " << name << " Stats ===" << RESET << std::endl;
    std::cout << NBLUE << "Hit Points remaining: " << HitPoints << RESET << std::endl;
    std::cout << NBLUE << "Energy Points remaining: " << EnergyPoints << RESET << std::endl;
    std::cout << NBLUE << "Attack Damage: " << AttackDamage << RESET << std::endl;
}
