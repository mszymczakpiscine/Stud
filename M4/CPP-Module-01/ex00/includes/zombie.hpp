/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:50:00 by mszymcza          #+#    #+#             */
/*   Updated: 2025/11/04 13:50:00 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
    public:
        Zombie(std::string name);
        ~Zombie();
        void annonce(void) const;
        void setName(std::string name);
    private:
    std::string name;
};

Zombie  *newZombie(std::string name);
void    randomChump(std::string name);

#endif
