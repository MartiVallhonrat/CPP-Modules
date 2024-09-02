/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:14:59 by mvallhon          #+#    #+#             */
/*   Updated: 2024/05/29 13:15:01 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../PhoneBook.hpp"
#include "../Contact.hpp"

static std::string  get_phrase()
{
    std::string input = "";

    std::cout << "\t- ";
    std::getline(std::cin, input);
    return (input);
}

static void set_contact(int *i, PhoneBook *phoneBook)
{
    std::string input = "";
    Contact newContact;
	std::string	phrase;

    if (*i == 8)
        *i = 0;
    std::cout << "First name:" << std::endl;
	phrase = get_phrase();
	if (std::cin.eof() || phrase.empty())
	{
		std::cout << "Invalid Input!" << std::endl;
		return ;
    }
	newContact.set_firstName(phrase);
    std::cout << "Last name:" << std::endl;
	phrase = get_phrase();
	if (std::cin.eof() || phrase.empty())
	{
		std::cout << "Invalid Input!" << std::endl;
		return ;
    }
	newContact.set_lastName(phrase);
    std::cout << "Nickname:" << std::endl;
	phrase = get_phrase();
	if (std::cin.eof() || phrase.empty())
	{
		std::cout << "Invalid Input!" << std::endl;
		return ;
    }
	newContact.set_nickname(phrase);
    std::cout << "Phone number:" << std::endl;
	phrase = get_phrase();
	if (std::cin.eof() || phrase.empty())
	{
		std::cout << "Invalid Input!" << std::endl;
		return ;
    }
	newContact.set_phoneNumber(phrase);
    std::cout << "Dark secret:" << std::endl;
	phrase = get_phrase();
	if (std::cin.eof() || phrase.empty())
	{
		std::cout << "Invalid Input!" << std::endl;
		return ;
    }
    newContact.set_darkSecret(phrase);
    phoneBook->add_contact(newContact, *i);
    (*i)++;
}

int main(void)
{
    PhoneBook   phoneBook;
    std::string input = "";
    int i = 0;
    
    while (1)
    {
        std::cout << "> " << std::flush;
        std::getline(std::cin, input);
        if (std::cin.eof() || input == "EXIT")
            break ;
        else if (input == "ADD")
            set_contact(&i, &phoneBook);
        else if (input == "SEARCH")
            phoneBook.search();
    }
    return (0);
}