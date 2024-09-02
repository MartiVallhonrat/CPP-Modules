/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:21:47 by mvallhon          #+#    #+#             */
/*   Updated: 2024/06/06 15:21:48 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Harl.hpp"

int main(int argc, char *argv[])
{
    Harl        Harl;
    std::string input;

    if (argc != 2)
    {
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl << std::endl;
        return (0);
    }
    input = argv[1];

    Harl.complain(input);
    
    return (0);
}
