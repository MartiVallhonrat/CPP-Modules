/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:32:55 by mvallhon          #+#    #+#             */
/*   Updated: 2024/05/31 14:32:57 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Contact.hpp"

void    Contact::set_firstName(std::string new_firstName)
{
    firstName = new_firstName;
}

void    Contact::set_lastName(std::string new_lastName)
{
    lastName = new_lastName;
}

void    Contact::set_nickname(std::string new_nickname)
{
    nickname = new_nickname;
}

void    Contact::set_phoneNumber(std::string new_phoneNumber)
{
    phoneNumber = new_phoneNumber;
}

void    Contact::set_darkSecret(std::string new_darkSecret)
{
    darkSecret = new_darkSecret;
}

std::string    Contact::get_firstName()
{
    return (firstName);
}

std::string    Contact::get_lastName()
{
    return (lastName);
}

std::string    Contact::get_nickname()
{
    return (nickname);
}