/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:49:34 by mszymcza          #+#    #+#             */
/*   Updated: 2025/11/05 12:00:47 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog(): Animal()
{
	_type = "Dog\n";
	std::cout << BLUE << "Dog Default Constructor called" << RESET << std::endl;
}

Dog::Dog(std::string type): Animal(type)
{
	_type = type;
	std::cout << BLUE << "Dog Constructor called with attribute type : " << type << RESET << std::endl;	
}

Dog::Dog(const Dog &src): Animal(src)
{
	std::cout << YELLOW << "Dog Copy Constructor called" << RESET << std::endl;
	*this = src;
}

Dog::Dog()
{
	std::cout << RED << "Dog Destructor called" << RESET << std::endl;
}

Dog &Dog::operator=(Dog const &other)
{
	std::cout << PURPLE << "Dog Copy assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return *this;
}

void	Dog::set_type(std::string type)
{
	_type = type;
}

std::string Dog::getType() const
{
	return _type;
}

void	Dog::makeSound() const 
{
	std::cout << GREEN << _type << "WAAAFFFFF\n" << RESET << std::endl;
}