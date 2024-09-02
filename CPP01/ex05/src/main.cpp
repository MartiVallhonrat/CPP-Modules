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

int main(void)
{
    Harl        Harl;
    std::string input = "";

    while (1)
    {
        std::cout << "> " << std::flush;
        std::getline(std::cin, input);
        if (std::cin.eof() || input == "EXIT")
            break;
        Harl.complain(input);
    }
    return (0);
}
