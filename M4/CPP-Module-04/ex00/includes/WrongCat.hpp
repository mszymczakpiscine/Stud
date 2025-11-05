/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:02:08 by mszymcza          #+#    #+#             */
/*   Updated: 2025/11/05 12:05:57 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

// Color codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define PURPLE  "\033[35m"
#define NRED    "\033[1;31m"
#define NBLUE   "\033[1;34m"

class WrongCat
{
	public:
		WrongCat();
		WrongCat(std::string type);
		WrongCat(WrongCat const &src);

		virtual ~WrongCat;

		WrongCat &operator=(const WrongCat &src);

		std::string		getType() const ;
		void			set_type(std::string type);
		void			makeSound() const ;
};

#endif
