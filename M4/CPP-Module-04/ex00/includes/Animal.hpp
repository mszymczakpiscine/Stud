/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:09:54 by mszymcza          #+#    #+#             */
/*   Updated: 2025/11/05 11:22:49 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

// Color codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define PURPLE  "\033[35m"
#define NRED    "\033[1;31m"
#define NBLUE   "\033[1;34m"


class Animal
{
	public:
		Animal();
		Animal(std::string name);
		Animal(const Animal &src);
		
		virtual ~Animal();
		
		Animal &operator=(Animal const &other);
		
		virtual void makeSound() const ;
		void		 set_type(std::string type);
		std::string  getType() const ;

	protected:
		std::string _type;
};

#endif