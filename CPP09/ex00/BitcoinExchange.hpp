#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <iostream>
# include <map>
# include <fstream>
# include <string>
# include <algorithm>
# include <cstdlib>
# include <sstream>

typedef struct s_vars
{
    std::string                     infile;
    std::string                     line;
    std::string                     date;
    std::string                     newDate;
    int                             year;
    int                             month;
    int                             day;
    double                          value;
    std::ifstream                   inputFile;
    std::map<std::string, double>   data; 
}                               t_vars;


#endif