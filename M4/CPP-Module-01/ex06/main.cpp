/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:59:39 by mszymcza          #+#    #+#             */
/*   Updated: 2025/11/04 16:59:39 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./harlFilter <level>" << std::endl;
        return 1;
    }
    
    HarlFilter harlFilter;
    std::string level = argv[1];
    int filterLevel = harlFilter.filterLevel(level);

    switch (filterLevel)
    {
        case DEBUG:
            harlFilter.complain("DEBUG");
        case INFO:
            harlFilter.complain("INFO");
        case WARNING:
            harlFilter.complain("WARNING");
        case ERROR:
            harlFilter.complain("ERROR");
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]\n" << std::endl;
    }
    return 0;
}