/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:06:32 by mszymcza          #+#    #+#             */
/*   Updated: 2025/11/05 12:11:51 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal()
{
	_type = "Don't know this WrongCat\n";
	std::cout << BLUE << "WrongCat Default Constructor called" << RESET << std::endl;
}

WrongCat::WrongCat(std::string type): WrongAnimal(type) 
{
	_type = type;
	std::cout << BLUE << "WrongCat Constructor called with attribute type : " << type << RESET << std::endl;	
}

WrongCat::WrongCat(const WrongCat &src): WrongAnimal(src)
{
	std::cout << YELLOW << "WrongCat Copy Constructor called" << RESET << std::endl;
	*this = src;
}

WrongCat::WrongCat()
{
	std::cout << RED << "WrongCat Destructor called" << RESET << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &other)
{
	std::cout << PURPLE << "WrongCat Copy assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return *this;
}

void	WrongCat::set_type(std::string type)
{
	_type = type;
}

std::string WrongCat::getType() const
{
	return _type;
}

void	WrongCat::makeSound() const 
{
	std::cout << GREEN << _type << "Curious sound form a WrongCat\n" << RESET << std::endl;
}