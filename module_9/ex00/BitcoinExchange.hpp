#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <cstdlib>

class BitcoinExchange
{
private:
	std::map<std::string, float>	_data;
public:
	BitcoinExchange(void);
	BitcoinExchange(BitcoinExchange const &other);
	BitcoinExchange &operator=(BitcoinExchange const &other);
	~BitcoinExchange(void );

	void	printMultipleValue(std::string filename);
private:
	int		_checkLine(std::string line, float *value);
	float	_getResult(std::string date, float value);
};

#endif