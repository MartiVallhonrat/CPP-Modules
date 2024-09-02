/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:38:19 by mvallhon          #+#    #+#             */
/*   Updated: 2024/06/06 18:38:21 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

static std::string replaceInput(std::string &input, std::string str1, std::string str2)
{
    size_t  from = 0;
    size_t  to = 0;
    std::string new_input;
    std::string tmp_input;

    to = input.find(str1, from);
    if (to == std::string::npos)
        return (input);
    while (to != std::string::npos)
    {
		tmp_input = "";
		while (from != to)
			tmp_input = tmp_input.append(input.substr(from++, 1));
        new_input.append(tmp_input);
        new_input.append(str2);
        from = to + str1.length();
        to = input.find(str1, from);
    }
    new_input.append(input.substr(from, input.length()));
    return (new_input);
}

int main(int argc, char *argv[])
{
    std::string input;

    if (argc != 4)
    {
        std::cerr << "Too few or too many arguments!" << std::endl;
        return (1);
    }
    std::ifstream   inputFile(argv[1]);
    std::ofstream   outputFile("outfile.replace");

    if (!inputFile.is_open() || !outputFile.is_open())
    {
        std::cerr << "Invalid files!" << std::endl;
        return (1);
    }
    while (std::getline(inputFile, input))
       outputFile << replaceInput(input, argv[2], argv[3]) << std::endl;

    inputFile.close();
    outputFile.close();

    return (0);
}