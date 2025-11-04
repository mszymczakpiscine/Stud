/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 19:03:45 by mszymcza          #+#    #+#             */
/*   Updated: 2025/11/04 19:03:45 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"
#include "../includes/ClapTrap.hpp"
#include "../includes/FragTrap.hpp"

int main()
{
	std::cout << "CLAPTRAP\n" << std::endl;
	{
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		ClapTrap a;
		ClapTrap b("CAP6Y");

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		a.attack("Some robot");
		a.takeDamage(10);
		a.takeDamage(10);
		a.beRepaired(5);
		a.attack("Some different robot");
		b.beRepaired(3);
		for (int i = 0; i < 12; i++)
			b.attack("Marc the robot");
		b.beRepaired(3);
		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	}
	std::cout << "\n\nSCAVTRAP\n" << std::endl;
	{
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		ScavTrap c;
		ScavTrap d("SC4V-TP");

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		c.attack("unknown target");
		c.beRepaired(22);
		c.takeDamage(21);
		c.beRepaired(22);
		c.guardGate();
		c.guardGate();
		d.attack("SC4V-TP rival");
		d.takeDamage(101);
		d.takeDamage(15);
		d.attack("A man in the street");
		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	}
	std::cout << "\n\nFRAGTRAP\n" << std::endl;
	{
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		FragTrap e;
		FragTrap f("FR4G-TP");

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		e.attack("Hostile enemy");
		e.takeDamage(50);
		e.beRepaired(30);
		e.highFivesGuys();
		f.attack("Swag enemy");
		f.takeDamage(0);
		f.beRepaired(20);
		f.highFivesGuys();
		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	}
	return (0);
}