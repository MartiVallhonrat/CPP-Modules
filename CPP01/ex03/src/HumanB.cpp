/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:46:53 by mvallhon          #+#    #+#             */
/*   Updated: 2024/06/06 15:46:54 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HumanB.hpp"

HumanB::HumanB(std::string name): name(name)
{
    this->weapon = NULL;
}

HumanB::~HumanB()
{
    std::cout << this->name << ": Human destroyed!" << std::endl;
}

void    HumanB::attack(void)
{
    if (this->weapon)
        std::cout << this->name << " attack with their weapon " << (*this->weapon).getType() << std::endl;
    else
        std::cout << this->name << " has no weapon so he can't attack" << std::endl;
}

void    HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}
