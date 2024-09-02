/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:46:34 by mvallhon          #+#    #+#             */
/*   Updated: 2024/06/06 15:46:35 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Weapon.hpp"

Weapon::Weapon(std::string type): type(type) 
{
}

Weapon::~Weapon()
{
    std::cout << this->type << ": Weapon destroyed!" << std::endl;
}

const std::string   &Weapon::getType()
{
    return (this->type);
}

void    Weapon::setType(std::string type)
{
    this->type = type;
}