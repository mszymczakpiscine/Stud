/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 20:43:51 by mszymcza          #+#    #+#             */
/*   Updated: 2025/11/05 20:43:51 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	std::cout << BLUE << "🐕 Dog default constructor called" << RESET << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << BLUE << "🐕 Dog copy constructor called" << RESET << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << BLUE << "🐕 Dog assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << BLUE << "🐕 Dog destructor called" << RESET << std::endl;
}

void Dog::makeSound() const
{
	std::cout << BLUE << "🐕 Woof! Woof!" << RESET << std::endl;
}
