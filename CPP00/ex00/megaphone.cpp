/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:44:28 by mvallhon          #+#    #+#             */
/*   Updated: 2024/05/28 11:44:30 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        for (int i = 1; argv[i]; i++)
        {
            for (int j = 0; argv[i][j]; j++)
            {
                if (argv[i][j] >= 'a' && argv[i][j] <= 'z')
                    std::cout << (char)toupper(argv[i][j]);
                else
                    std::cout << argv[i][j];
            }
        }
		std::cout << std::endl;
		return (0);
    }
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return (0);
}