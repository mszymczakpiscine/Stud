/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:35:03 by mszymcza          #+#    #+#             */
/*   Updated: 2025/11/05 12:00:44 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat(): Animal()
{
	_type = "Cat\n";
	std::cout << BLUE << "Cat Default Constructor called" << RESET << std::endl;
}

Cat::Cat(std::string type): Animal(type)
{
	_type = type;
	std::cout << BLUE << "Cat Constructor called with attribute type : " << type << RESET << std::endl;	
}

Cat::Cat(const Cat &src): Animal(src)
{
	std::cout << YELLOW << "Cat Copy Constructor called" << RESET << std::endl;
	*this = src;
}

Cat::Cat()
{
	std::cout << RED << "Cat Destructor called" << RESET << std::endl;
}

Cat &Cat::operator=(Cat const &other)
{
	std::cout << PURPLE << "Cat Copy assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return *this;
}

void	Cat::set_type(std::string type)
{
	_type = type;
}

std::string Cat::getType() const
{
	return _type;
}

void	Cat::makeSound() const 
{
	std::cout << GREEN << _type << "Mieowwwwww\n" << RESET << std::endl;
}