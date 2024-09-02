/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:33:52 by mvallhon          #+#    #+#             */
/*   Updated: 2024/06/05 17:33:53 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP

# define ZOMBIE_HPP
# include <iostream>

class Zombie
{
private:
    std::string name;

public:
    Zombie();
    ~Zombie();

    void    setName(std::string name);
    void    announce(void);
};

Zombie *zombieHorde(int N, std::string name);

#endif