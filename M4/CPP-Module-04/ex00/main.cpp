/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:11:41 by mszymcza          #+#    #+#             */
/*   Updated: 2025/11/05 13:58:19 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	delete i;
	delete j;
	delete meta;

	const Animal* meta = new Animal("Animal");
	const Animal* j = new Dog("Snoopy");
	const Animal* i = new Cat("Garfield");
	
	const Animal unknown("Unknown");
	const Dog chien("Bill");
	const Cat chat("Felix");
	
	chien.makeSound();
	chat.makeSound();
	unknown.makeSound();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	delete i;
	delete j;
	delete meta;
	
	const WrongAnimal* meta = new WrongAnimal();
	const WrongAnimal* i = new WrongCat("Wrong")
}