/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 20:43:41 by mszymcza          #+#    #+#             */
/*   Updated: 2025/11/05 21:30:00 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << GREEN << "🦁 Animal default constructor called" << RESET << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type)
{
	std::cout << GREEN << "🦁 Animal copy constructor called" << RESET << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
	std::cout << GREEN << "🦁 Animal assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		this->type = other.type;
	}
	return *this;
}

Animal::~Animal()
{
	std::cout << GREEN << "🦁 Animal destructor called" << RESET << std::endl;
}

// makeSound() is pure virtual, no implementation here

std::string Animal::getType() const
{
	return this->type;
}
