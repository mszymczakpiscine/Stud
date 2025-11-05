/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 20:43:57 by mszymcza          #+#    #+#             */
/*   Updated: 2025/11/05 20:43:57 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	std::cout << YELLOW << "🐱 Cat default constructor called" << RESET << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << YELLOW << "🐱 Cat copy constructor called" << RESET << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << YELLOW << "🐱 Cat assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << YELLOW << "🐱 Cat destructor called" << RESET << std::endl;
}

void Cat::makeSound() const
{
	std::cout << YELLOW << "🐱 Meow! Meow!" << RESET << std::endl;
}
