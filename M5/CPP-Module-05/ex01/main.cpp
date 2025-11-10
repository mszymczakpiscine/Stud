/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:41:12 by mszymcza          #+#    #+#             */
/*   Updated: 2025/11/10 11:41:12 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	int grade;

	std::cout << NPURPLE << "--------------------------------------------------------------"
			  << RESET << std::endl;
	std::cout << NGREEN << "trying correct input" << RESET << std::endl;
	std::cout << NPURPLE << "--------------------------------------------------------------"
			  << RESET << std::endl;

	std::cout << NPURPLE << "creating Alice" << RESET << std::endl;
	std::cout << NGREEN << "Form 'contract' requires grade 1 to sign" << RESET << std::endl;
	std::cout << "Enter grade for Alice (1-150): ";
	std::cin >> grade;
	try {
		Bureaucrat Alice("Alice Johnson", grade);
		Form contract("contract", 1, 1);
		std::cout << Alice;
		Alice.signForm(contract);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << NPURPLE << "--------------------------------------------------------------"
			  << RESET << std::endl;
	std::cout << NRED << "trying incorrect input" << RESET << std::endl;
	std::cout << NPURPLE << "--------------------------------------------------------------"
			  << RESET << std::endl;

	std::cout << NPURPLE << "creating Bob" << RESET << std::endl;
	std::cout << NRED << "Form 'permit' requires grade 1 to sign" << RESET << std::endl;
	std::cout << "Enter grade for Bob (1-150): ";
	std::cin >> grade;
	try {
		Bureaucrat Bob("Bob Smith", grade);
		std::cout << Bob;
		std::cout << NPURPLE << "creating Form" << RESET << std::endl;
		Form permit("permit", 1, 1);
		Bob.signForm(permit);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << NPURPLE << "creating Charlie" << RESET << std::endl;
	std::cout << NRED << "Form 'invoice' requires grade 150 to sign" << RESET << std::endl;
	std::cout << "Enter grade for Charlie (1-150): ";
	std::cin >> grade;
	try {
		Bureaucrat Charlie("Charlie Brown", grade);
		std::cout << Charlie;
		std::cout << NPURPLE << "creating Form" << RESET << std::endl;
		Form invoice("invoice", 150, 1);
		Charlie.signForm(invoice);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << NPURPLE << "creating Diana" << RESET << std::endl;
	std::cout << NRED << "Form 'badForm' has invalid grade 151" << RESET << std::endl;
	std::cout << "Enter grade for Diana (1-150): ";
	std::cin >> grade;
	try {
		Bureaucrat Diana("Diana Prince", grade);
		std::cout << NPURPLE << "creating Form with invalid grade" << RESET << std::endl;
		Form badForm("badForm", 151, 1);
		std::cout << Diana;
		Diana.decrementGrade();
		Diana.decrementGrade();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
