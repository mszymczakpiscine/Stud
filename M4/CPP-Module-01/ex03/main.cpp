/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:26:50 by mszymcza          #+#    #+#             */
/*   Updated: 2025/11/04 15:26:50 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanA.hpp"
#include "../includes/HumanB.hpp"

int main(){

	{
		Weapon club = Weapon("Katana");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("Axe");
		bob.attack();
	}
	{
		Weapon club = Weapon("Katana");
		HumanB jim("Jim");
		jim.attack();
		jim.setWeapon(club);
		club.setType("Axe");
		jim.attack();
	}
	return 0;
}