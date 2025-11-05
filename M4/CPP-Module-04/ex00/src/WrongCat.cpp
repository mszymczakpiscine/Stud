/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 20:43:54 by mszymcza          #+#    #+#             */
/*   Updated: 2025/11/05 20:43:54 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->type = "WrongCat";
	std::cout << GREEN << "⚠️  WrongCat default constructor called" << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	std::cout << GREEN << "⚠️  WrongCat copy constructor called" << RESET << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	std::cout << GREEN	 << "⚠️  WrongCat assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		WrongAnimal::operator=(other);
	}
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << GREEN << "⚠️  WrongCat destructor called" << RESET << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << GREEN << "⚠️  Wrong Meow! Wrong Meow!" << RESET << std::endl;
}
