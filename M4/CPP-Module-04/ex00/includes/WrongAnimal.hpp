/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:52:32 by mszymcza          #+#    #+#             */
/*   Updated: 2025/11/05 11:56:27 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

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


class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(WrongAnimal const *src);
		
		virtual ~WrongAnimal();
		WrongAnimal &operator=(const WrongAnimal &src);
		
		std::string		getType() const ;
		void			set_type(std::string type);
		void			makeSound() const ;

	protected:
		std::string _type;
};

#endif