/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:32:03 by mvallhon          #+#    #+#             */
/*   Updated: 2024/06/05 17:32:05 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Zombie.hpp"

int main(void)
{
    std::cout << "Starting..." << std::endl;
    int length = 4;
    Zombie *zombies = zombieHorde(4, "Test");

    for(int i = 0; i < length; i++)
    {
        zombies[i].announce();
    }
    delete[] zombies;

    return (0);
}
