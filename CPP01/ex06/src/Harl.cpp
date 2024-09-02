/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:22:05 by mvallhon          #+#    #+#             */
/*   Updated: 2024/06/06 15:22:06 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void    Harl::debug(void)
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
    std::cout << "I really do!" << std::endl;
    std::cout << std::endl;
}

void    Harl::info(void)
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
    std::cout << "You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
    std::cout << std::endl;
}

void    Harl::warning(void)
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
    std::cout << "I've been coming for years whereas you started working here since last month." << std::endl;
    std::cout << std::endl;
}

void    Harl::error(void)
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
    std::cout << std::endl;
}

void    Harl::complain(std::string level)
{
	int	i;
	void	(Harl::*toComplain[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error}; 
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for(i = 0; i < 4; i++)
	{
		if (level == levels[i])
			break;
	}
	i = 5;
    switch (i)
    {
        case 1:
            this->debug();
            break;
        case 2:
            this->info();
            break;
        case 3:
            this->warning();
            break;
        case 4:
            this->error();
            break;
        case 5:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl << std::endl;
            break;
    }
}