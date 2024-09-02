/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:46:45 by mvallhon          #+#    #+#             */
/*   Updated: 2024/06/06 15:46:46 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): name(name), weapon(weapon)
{
}

HumanA::~HumanA()
{
    std::cout << this->name << ": Human destroyed!" << std::endl;
}

void    HumanA::attack(void)
{
    std::cout << this->name << " attack with their weapon " << this->weapon.getType() << std::endl;
}
