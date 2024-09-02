/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:33:10 by mvallhon          #+#    #+#             */
/*   Updated: 2024/05/31 14:33:12 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../PhoneBook.hpp"

void    PhoneBook::add_contact(Contact new_contact, int pos)
{
    contacts[pos] = new_contact;
}

std::string PhoneBook::limit_str(std::string str)
{
    if (str.length() > 10)
        return (str.substr(0, 9) + ".");
    return (str);
}

static bool	isNumber(const char *str)
{
	for(int	i = 0; str[i]; i++)
	{
		if (!std::isdigit(str[i]))
			return (false);
	}
	return (true);
}

void    PhoneBook::search(void)
{
	int			input_n;
	std::string	input = "";
    int len = sizeof(contacts) / sizeof(Contact);

    for (int i = 0; i < len; i++)
    {
        if (contacts[i].get_firstName().empty() || contacts[i].get_lastName().empty() || contacts[i].get_nickname().empty())
            continue;
        std::cout << std::setw(10) << i << std::flush;
        std::cout << "|" << std::setw(10) << limit_str(contacts[i].get_firstName()) << std::flush;
        std::cout << "|" << std::setw(10) << limit_str(contacts[i].get_lastName()) << std::flush;
        std::cout << "|" << std::setw(10) << limit_str(contacts[i].get_nickname()) << std::flush;
        std::cout << std::endl;
    }
    std::cout << "\t- ";
	std::getline(std::cin, input);
    if (std::cin.eof() || input.empty())
	{
		std::cout << "Invalid input!" << std::endl;
    	return ;
	}
	else
	{
		input_n = atoi(input.c_str());
		if (input_n > 7 || input_n < 0 || contacts[input_n].get_firstName().empty()
			|| contacts[input_n].get_lastName().empty()
			|| contacts[input_n].get_nickname().empty()
			|| !isNumber(input.c_str()))
		{
			std::cout << "Invalid input!" << std::endl;
			return ;
		}
		std::cout << std::setw(10) << input_n << std::flush;
        std::cout << "|" << std::setw(10) << limit_str(contacts[input_n].get_firstName()) << std::flush;
        std::cout << "|" << std::setw(10) << limit_str(contacts[input_n].get_lastName()) << std::flush;
        std::cout << "|" << std::setw(10) << limit_str(contacts[input_n].get_nickname()) << std::flush;
        std::cout << std::endl;
	}
}