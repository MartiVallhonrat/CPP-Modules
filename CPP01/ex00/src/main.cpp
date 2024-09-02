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
    std::cout << "Creating the first Zombie..." << std::endl;   
    
    Zombie  zombie1("Zombie 1");

    zombie1.announce();
    randomChump("Zombie 2");

    return (0);
}
