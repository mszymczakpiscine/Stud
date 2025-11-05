/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 20:43:47 by mszymcza          #+#    #+#             */
/*   Updated: 2025/11/05 20:43:47 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << RED << "❌ WrongAnimal default constructor called" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type)
{
	std::cout << RED << "❌ WrongAnimal copy constructor called" << RESET << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << RED << "❌ WrongAnimal assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		this->type = other.type;
	}
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << RED << "❌ WrongAnimal destructor called" << RESET << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << RED << "❌ * Generic wrong animal sound *" << RESET << std::endl;
}

std::string WrongAnimal::getType() const
{
	return this->type;
}
