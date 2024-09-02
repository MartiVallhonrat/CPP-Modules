/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:12:24 by mvallhon          #+#    #+#             */
/*   Updated: 2024/05/29 13:12:27 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <cstdlib>
# include <cctype>

class Contact
{
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkSecret;

    public:
        void            set_firstName(std::string firstName);
        void            set_lastName(std::string lastName);
        void            set_nickname(std::string nickname);
        void            set_phoneNumber(std::string phoneNumber);
        void            set_darkSecret(std::string darkSecret);

        std::string    get_firstName();
        std::string    get_lastName();
        std::string    get_nickname();
};

#endif