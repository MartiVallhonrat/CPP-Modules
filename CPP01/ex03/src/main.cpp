/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:46:23 by mvallhon          #+#    #+#             */
/*   Updated: 2024/06/06 15:46:25 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HumanA.hpp"
#include "../HumanB.hpp"

int main(void)
{
    Weapon  club1 = Weapon("default club");
    HumanA bob("Bob", club1);
    bob.attack();
    club1.setType("super special club");
    bob.attack();
    
    Weapon club2 = Weapon("crude spiked club");
    HumanB jim("Jim");
    //jim.setWeapon(club2);
    jim.attack();
    club2.setType("some other type of club");
    jim.attack();

    return (0);
}
