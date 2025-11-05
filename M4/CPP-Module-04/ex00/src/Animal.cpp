/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:17:37 by mszymcza          #+#    #+#             */
/*   Updated: 2025/11/05 13:31:54 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	_type = "I don't know this animal\n";
	std::cout << BLUE << "Animal Default Constructor called" << RESET << std::endl;
}

Animal::Animal(std::string name)
{
	_type = name;
	std::cout << BLUE << "Animal Constructor called with attribute type : " << name << RESET << std::endl;	
}

Animal::Animal(const Animal &src)
{
	std::cout << YELLOW << "Animal Copy Constructor called" << RESET << std::endl;
	*this = src;
}

Animal::~Animal()
{
	std::cout << RED << "Animal Destructor called" << RESET << std::endl;
}

Animal &Animal::operator=(Animal const &other)
{
	std::cout << PURPLE << "Animal Copy assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return *this;
}

void	Animal::set_type(std::string type)
{
	_type = type;
}

std::string Animal::getType() const
{
	return _type;
}

void	Animal::makeSound() const 
{
	std::cout << GREEN << _type << "Make some noisy sound\n" << RESET << std::endl;
}