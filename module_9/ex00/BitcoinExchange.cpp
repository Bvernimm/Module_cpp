#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
	std::fstream	file;
	std::string		text;
	std::string		nb;
	char			c;

	file.open("data.csv", std::ios::in);
	if(!file)
		std::cout << "Missing data file\n";
	else
	{
		file.get(c);
		while (c != '\n')
			file.get(c);
		while (file.get(c))
		{
			if (c != ',')
				text = text + c;
			else
			{
				file.get(c);
				while (c != '\n')
				{
					nb = nb + c;
					file.get(c);
				}
				_data[text] = atof(nb.c_str());
				text.clear();
				nb.clear();
			}
		}
	}
	file.close();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other)
{
	_data = other._data;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &other)
{
	_data = other._data;
	return *this;
}

BitcoinExchange::~BitcoinExchange(void) {
}

void	BitcoinExchange::printMultipleValue(std::string filename)
{
	std::fstream	file;
	std::string		text;
	std::string		date;
	float			value;
	char			c;
	int				i;

	file.open(filename, std::ios::in);
	if(!file)
		std::cout << "Error: could not open file.\n";
	else
	{
		while (file.get(c) && c != '\n')
			text = text + c;
		if (isalpha(text[0]))
		{
			text.clear();
			while (file.get(c) && c != '\n')
				text = text + c;
		}
		while (text.size() > 0)
		{
			i = _checkLine(text, &value);
			if (i == 1)
				std::cout << "Error: invalid date." << std::endl;
			else if (i == 2)
				std::cout << "Error: invalid separator." << std::endl;
			else if (i == 3)
				std::cout << "Error: invalid number." << std::endl;
			else if (i == 4)
				std::cout << "Error: too large a number." << std::endl;
			else if (i == 5)
				std::cout << "Error: bad imput." << std::endl;
			else if (i == 6)
				std::cout << "Error: not a positive number." << std::endl;
			else
			{
				date = text.substr(0, 10);
				std::cout << date << " => " << value << " = " << _getResult(date, value) << std::endl;
			}
			text.clear();
			while (file.get(c))
			{
				if (c == '\n')
					continue ;
				else
				{
					text = text + c;
					break ;
				}
			}
			while (file.get(c) && c != '\n')
				text = text + c;
		}
	}
	file.close();
}

int	BitcoinExchange::_checkLine(std::string line, float *value)
{
	std::string	nb;
	int			i;
	int			count;
	int			floot;

	if (line.size() < 13)
		return (5);
	if (!isdigit(line[0]) || !isdigit(line[1]) || !isdigit(line[2]) || !isdigit(line[3]) || line[4] != '-' || !isdigit(line[5])
		|| !isdigit(line[6]) || line[7] != '-' || !isdigit(line[8]) || !isdigit(line[9]))
		return (1);
	if (line[10] != ' ' || line[11] != '|' || line[12] != ' ')
		return (2);
	nb = line.substr(13, line.size() - 13);
	i = 0;
	floot = 0;
	count = 0;
	if (nb[0] == '-')
		return (6);
	else if (nb[0] == '+')
		i++;
	while(nb[i] == '0')
		i++;
	while (nb[i])
	{
		if (nb[i] == '.' && floot == 0)
			floot = 1;
		else if (nb[i] == '.' && floot == 1)
			return (3);
		if (!isdigit(nb[i]) && nb[i] != '.')
			return (3);
		i++;
		count++;
	}
	if (floot == 0 && count > 4)
		return (4);
	*value = atof(nb.c_str());
	if (*value > 1000)
		return (4);
	return (0);
}

float	BitcoinExchange::_getResult(std::string date, float value)
{
	std::map<std::string, float>::iterator it;

	it = _data.find(date);
	if (it == _data.end())
	{
		it = _data.lower_bound(date);
		if (it != _data.begin())
			it--;
	}
	return (value * it->second);
}
