/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 18:35:01 by mszymcza          #+#    #+#             */
/*   Updated: 2025/11/04 18:35:01 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

int main()
{
	ClapTrap a("Roger");
	ClapTrap b = a;
	a.set_damages(4);
	a.beRepaired(10);
	a.print_infos();
	a.takeDamage(15);
	a.attack("George");
	a.print_infos();
	a.attack("George");
	a.beRepaired(500);
	a.print_infos();
	a.beRepaired(500);
	a.beRepaired(500);
	a.print_infos();
	a.attack("George");
	a.attack("George");
	return 0;
}
