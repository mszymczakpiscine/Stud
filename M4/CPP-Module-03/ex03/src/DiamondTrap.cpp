/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 19:49:59 by mszymcza          #+#    #+#             */
/*   Updated: 2025/11/04 19:49:59 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap(), _name("Default")
{
    ClapTrap::name = _name + "_clap_name";
    HitPoints = FragTrap::HitPoints;
    EnergyPoints = ScavTrap::EnergyPoints;
    AttackDamage = FragTrap::AttackDamage;
    std::cout << GREEN << "DiamondTrap Default Constructor called" << RESET << std::endl;
}
DiamondTrap::DiamondTrap(const std::string& name) : ScavTrap(name), FragTrap(name), _name(name)
{
    ClapTrap::name = _name + "_clap_name";
    HitPoints = FragTrap::HitPoints;
    EnergyPoints = ScavTrap::EnergyPoints;
    AttackDamage = FragTrap::AttackDamage;
    std::cout << GREEN << "DiamondTrap Constructor called for " << _name << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other), _name(other._name)
{
    std::cout << BLUE << "DiamondTrap Copy Constructor called" << RESET << std::endl;
}
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    std::cout << PURPLE << "DiamondTrap Copy assignment operator called" << RESET << std::endl;
    if (this != &other)
    {
        ScavTrap::operator=(other);
        FragTrap::operator=(other);
        _name = other._name;
    }
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << RED << "DiamondTrap Destructor called "<< RESET << std::endl;
}
void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}
void DiamondTrap::whoAmI()
{
	if(HitPoints > 0){
		std::cout << YELLOW << "Hi, my name is, euuu.. My name is.. I don't remember? Ho yes ! My name is, ....., " << _name << " and my ClapTrap name is " << ClapTrap::name << RESET << std::endl;
	}
	else 
		std::cout << RED << _name << " can't say his name, he is dead" << RESET << std::endl;
}