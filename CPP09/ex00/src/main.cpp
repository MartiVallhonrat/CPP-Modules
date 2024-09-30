# include "../BitcoinExchange.hpp"

static bool openFile(t_vars &vars)
{
    vars.inputFile.open(vars.infile.c_str());
    if (!vars.inputFile.is_open())
    {
        std::cerr << "Error: can't open the file " << vars.infile << '\n';
        return (true);
    }
    return (false);
}

static bool readData(t_vars &vars)
{
    std::ifstream   data;
    std::string     line;
    size_t          limiter = 0;

    data.open("data.csv");
    if (!data.is_open())
    {
        std::cerr << "Error: can't read data.csv file" << '\n';
        return (true);
    }
    while (std::getline(data, line))
    {
        limiter = line.find(',');
        if (limiter == std::string::npos)
            return (true);
        vars.data[line.substr(0, limiter)] = std::strtod(line.substr(limiter + 1).c_str(), NULL);
    }
    return (false);
}

static bool strIsDate(std::string &str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!((str[i] >= '0' && str[i] <= '9')
            || str[i] == '-' || std::isspace(str[i]) ))
        {
            return (false);
        }
    }
    return (true);
}

static bool parseLineTime(t_vars &vars, std::string &date)
{
    if (!strIsDate(date) || date.size() > 10)
    {
        std::cerr << "Error: Some values in date are non valid" << '\n';
        return (true);
    }
    size_t  pos;
    double  n;
    size_t  pre_pos = 0;
    std::string input;
    for (int i = 0; i < 3; i++)
    {
        if (i < 2)
        {
            pos = date.find('-', pre_pos);
            if (pos == std::string::npos)
                return (true);
            input = date.substr(pre_pos, pos - pre_pos);
        }
        else
            input = date.substr(pre_pos);

        n = strtod(input.c_str(), NULL);
        if (date == "2009-01-01")
            return (true);
        if (n < 1)
            return (true);
        if (i == 0 && (n > 2022 || n < 2009))
            return (true);
        if (i == 1 && n > 12)
            return (true);
        if (i == 2 && n > 31)
            return (true);

        pre_pos = pos + 1;
        switch (i)
        {
            case 0:
                vars.year = n;
                break;
            case 1:
                vars.month = n;
                break;
            case 2:
                vars.day = n;
                break; 
            default:
                break;
        }
    }
    vars.date = date;
    return (false);
}

static bool parseLineValue(t_vars &vars, std::string &value)
{
    if (value.empty())
    {
        std::cerr << "Error: no value" << '\n';
        return (true);
    }
    double n = strtod(value.c_str(), NULL);
    
    if (n < 0)
    {
        std::cerr << "Error: not a positive number" << '\n';
        return (true);
    }
    else if (n > 1000)
    {
        std::cerr << "Error: too large a number" << '\n';
        return (true);
    }
    vars.value = n;
    return (false);
}

static bool parseLine(t_vars &vars)
{
    std::string::iterator end_pos =  std::remove(vars.line.begin(), vars.line.end(), ' ');
    vars.line.erase(end_pos, vars.line.end());
    size_t limit = vars.line.find("|");
    if (limit == std::string::npos)
    {
        std::cerr << "Error: bad input => " << vars.line << '\n';
        return (true);
    }
    std::string date = vars.line.substr(0, limit);
    if (parseLineTime(vars, date))
    {
        std::cerr << "Error: bad input => " << date << '\n';
        return (true);
    }
    std::string value = vars.line.substr(limit + 1);
    if (parseLineValue(vars, value))
        return (true);
    return (false);
}

static void findValue(t_vars &vars)
{
    vars.newDate = vars.date;
    while (vars.data.count(vars.newDate) < 1)
    {
        if (vars.day == 1)
        {
            vars.month--;
            if (vars.month == 0)
            {
                vars.year--;
                vars.month = 12;
                vars.day = 31;
            }    
            else if (vars.month == 2)
                vars.day = 28;
            else if (vars.month == 4 || vars.month == 6 || vars.month == 9
                || vars.month == 11)
                vars.day = 30;
            else if (vars.month == 3 || vars.month == 5 || vars.month == 7
                || vars.month == 8 || vars.month == 10 || vars.month == 12)
                vars.day = 31;
        }
        else
            vars.day--;
    
        std::ostringstream  str;
        int                 digit = vars.year;
        for (size_t i = 0; i < 3; i++)
        {
            if (i == 1)
                digit = vars.month;
            else if (i == 2)
                digit = vars.day;
            
            if (digit < 10)
                str << 0;
            str << digit;
            if (i < 2)
                str << '-';
        }
        vars.newDate = str.str();
    }
}

static void printValue(t_vars &vars)
{
    std::cout << vars.date << " => " << vars.value << " = " \
    << vars.data[vars.newDate] * vars.value << '\n';
}

int main(int argc, char const *argv[])
{
    t_vars  vars;

    if (argc != 2)
    {
        std::cerr << "Error: Too many or too few arguments!" << '\n';
        return (1);
    }
    vars.infile = argv[1];
    if (openFile(vars))
        return (1);
    if (readData(vars))
        return (1);
    //skip the first one because input | value line
    std::getline(vars.inputFile, vars.line);
    while (std::getline(vars.inputFile, vars.line))
    {
        if (parseLine(vars))
            continue;
        findValue(vars);
        printValue(vars);
    }
    vars.inputFile.close();
    return (0);
}