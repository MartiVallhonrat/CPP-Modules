/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:33:19 by mvallhon          #+#    #+#             */
/*   Updated: 2024/06/05 17:33:21 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Zombie.hpp"

void    randomChump(std::string name)
{
    Zombie  *zombie2;

    zombie2 = newZombie(name);
    zombie2->announce();
    delete zombie2;
}