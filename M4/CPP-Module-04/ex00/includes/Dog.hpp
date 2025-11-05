/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:48:03 by mszymcza          #+#    #+#             */
/*   Updated: 2025/11/05 11:48:52 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Dog_HPP
#define Dog_HPP

//#include <iostream>
#include "Animal.hpp"

// Color codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define PURPLE  "\033[35m"
#define NRED    "\033[1;31m"
#define NBLUE   "\033[1;34m"

class Dog
{
	public:
		Dog();
		Dog(std::string name);
		Dog(const Dog &src);
		
		virtual ~Dog();
		Dog &operator=(Dog const &other);
		virtual void	makeSound() const;
		void			set_type(std::string type);
		std::string		getType() const;
};

#endif
