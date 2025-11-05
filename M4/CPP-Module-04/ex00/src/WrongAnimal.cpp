/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:56:32 by mszymcza          #+#    #+#             */
/*   Updated: 2025/11/05 12:12:06 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	_type = "Don't know this WrongAnimal\n";
	std::cout << BLUE << "WrongAnimal Default Constructor called" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
{
	_type = type;
	std::cout << BLUE << "WrongAnimal Constructor called with attribute type : " << type << RESET << std::endl;	
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	std::cout << YELLOW << "WrongAnimal Copy Constructor called" << RESET << std::endl;
	*this = src;
}

WrongAnimal::WrongAnimal()
{
	std::cout << RED << "WrongAnimal Destructor called" << RESET << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &other)
{
	std::cout << PURPLE << "WrongAnimal Copy assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return *this;
}

void	WrongAnimal::set_type(std::string type)
{
	_type = type;
}

std::string WrongAnimal::getType() const
{
	return _type;
}

void	WrongAnimal::makeSound() const 
{
	std::cout << GREEN << _type << "Curious sound form a WrongAnimal\n" << RESET << std::endl;
}