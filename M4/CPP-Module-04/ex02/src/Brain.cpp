/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 20:54:48 by mszymcza          #+#    #+#             */
/*   Updated: 2025/11/05 20:54:48 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << PURPLE << "🧠 Brain default constructor called" << RESET << std::endl;
	for (int i = 0; i < 100; i++)
	{
		ideas[i] = "";
	}
}

Brain::Brain(const Brain& other)
{
	std::cout << PURPLE << "🧠 Brain copy constructor called" << RESET << std::endl;
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = other.ideas[i];
	}
}

Brain& Brain::operator=(const Brain& other)
{
	std::cout << PURPLE << "🧠 Brain assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
		{
			this->ideas[i] = other.ideas[i];
		}
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << PURPLE << "🧠 Brain destructor called" << RESET << std::endl;
}

void Brain::setIdea(int index, const std::string& idea)
{
	if (index >= 0 && index < 100)
	{
		this->ideas[index] = idea;
	}
}

std::string Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
	{
		return this->ideas[index];
	}
	return "";
}
