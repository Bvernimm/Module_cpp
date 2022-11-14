#include "converter.hpp"

Converter::Converter(void) : _baseValue(""), _error("Bad constructor") {
}

Converter::Converter(std::string baseValue) : _baseValue(baseValue), _error("no error")
{
	int	i = 0;

	_type = "unknown";
	_intMax = false;
	if (_baseValue.size() == 1 && !std::isdigit(_baseValue[0]))
		_type = "char";
	else if (_baseValue == "+inff" || _baseValue == "-inff" || _baseValue == "nanf")
		_type = "float";
	else if (_baseValue == "+inf" || _baseValue == "-inf" || _baseValue == "nan")
		_type = "double";
	if (_baseValue[0] == '+' || _baseValue[0] == '-')
		i++;
	if (_type == "unknown")
	{
		_type = "int";
		for ( ; _baseValue[i] ; i++)
		{
			if (_baseValue[i] == '.' && _type == "int")
				_type = "double";
			else if ((_baseValue[i] == 'e' || _baseValue[i] == 'E') && (_baseValue[i+1] == '+' || _baseValue[i+1] == '-' || std::isdigit(_baseValue[i+1])))
			{
				_type = "double";
				i++;
			}
			else if (_baseValue[i] == 'f' && !_baseValue[i + 1] && _type == "double")
				_type = "float";
			else if (!std::isdigit(_baseValue[i]))
			{
				_type = "unknown type";
				_error = "unknown type";
				return ;
			}
		}
	}
	if (maxValueFloat() != 0)
		_intMax = true;
	if (maxValueInt() != 0)
		_error = "conversion impossible";
}

Converter::Converter(Converter const &other) : _baseValue(other._baseValue), _type(other._type), _error(other._error) {
}

Converter &Converter::operator=(Converter const &other) {
	_baseValue = other._baseValue;
	_error = other._error;
	_type = other._type;
	return *this;
}

Converter::~Converter(void) {
}

/*---------------------------------------------*/

int Converter::maxValueFloat(void)
{
	int i = 0;
	int nb = 0;
	int exposant = 0;

	if (_type == "float" || _type == "double")
	{
		if (_baseValue.find('e', 0) == std::string::npos)
		{
			while (_baseValue[nb] != '.')
				nb++;
			if (nb > 10)
				return (1);
			return (0);
		}
		while (_baseValue[i] != 'e' && _baseValue[i] != 'E')
			i++;
		i++;
		if (_baseValue[i] == '+')
			i++;
		if ( _baseValue[i] == '-')
			return (0);
		while (_baseValue[i] == '0')
			i++;
		if (_type == "float" && _baseValue[i + 1] != 'f')
			return (1);
		if (_type == "double" && i + 1 != static_cast<int>(_baseValue.size()))
			return (1);
		exposant = _baseValue[i] - '0';
		while (_baseValue[nb] != '.')
			nb++;
		if (nb + exposant > 10)
			return (1);
	}
	return (0);
}

int Converter::maxValueInt(void)
{
	long int	nb = 0;

	if (_type == "int" && _baseValue.size() > 11)
		return (1);
	if (_type == "int")
		nb = intStrToInt(0);
	if (nb < -2147483648 || nb > 2147483647)
		return (1);
	return (0);
}

long int Converter::intStrToInt(int i) const
{
	long int	nb = 0;
	int			sign = 1;

	if (_baseValue[i] == '-')
	{
		sign = -1;
		i++;
	}
	for ( ; _baseValue[i] && _baseValue[i] != 'f'; i++)
	{
		nb = nb * 10;
		nb = nb + _baseValue[i] - '0';
	}
	return (nb * sign);
}

void Converter::displayCharValue(std::ostream &os) const
{
	int	intValue;

	os << "char: ";
	if (_type == "char")
		os << _baseValue[0];
	else if (_type == "int")
	{
		intValue = intStrToInt(0);
		if (intValue < 0 || intValue > 128)
			os << "impossible";
		else if (intValue >= 32 && intValue <= 126)
			os << static_cast<char>(intValue);
		else
			os << "non displayable";
	}
	else if (_type == "float")
	{
		intValue = std::atof(_baseValue.c_str());
		if (_baseValue == "+inff" || _baseValue == "-inff" || _baseValue == "nanf")
			os << "impossible";
		else if (intValue < 0 || intValue > 128)
			os << "impossible";
		else if (intValue >= 32 && intValue <= 126)
			os << static_cast<char>(intValue);
		else
			os << "non displayable";
	}
	else if (_type == "double")
	{
		intValue = std::atof(_baseValue.c_str());
		if (_baseValue == "+inf" || _baseValue == "-inf" || _baseValue == "nan")
			os << "impossible";
		else if (intValue < 0 || intValue > 128)
			os << "impossible";
		else if (intValue >= 32 && intValue <= 126)
			os << static_cast<char>(intValue);
		else
			os << "non displayable";
	}
}

void Converter::displayIntValue(std::ostream &os) const
{
	long int	intValue;

	os << "int: ";
	if (_type == "char")
		os << static_cast<int>(_baseValue[0]);
	else if (_type == "int")
	{
		intValue = intStrToInt(0);
		os << intValue;
	}
	else if (_type == "float")
	{
		intValue = std::atof(_baseValue.c_str());
		if (_baseValue == "+inff" || _baseValue == "-inff" || _baseValue == "nanf" || _intMax == true)
			os << "impossible";
		else if (intValue > 2147483647 || intValue < -2147483648)
			os << "impossible";
		else
			os << intValue;
	}
	else if (_type == "double")
	{
		intValue = std::atof(_baseValue.c_str());
		if (_baseValue == "+inf" || _baseValue == "-inf" || _baseValue == "nan" || _intMax == true)
			os << "impossible";
		else if (intValue > 2147483647 || intValue < -2147483648)
			os << "impossible";
		else
			os << intValue;
	}
}

void Converter::displayFloatValue(std::ostream &os) const
{
	int	intValue;

	os << "float: ";
	if (_type == "char")
		os << static_cast<int>(_baseValue[0]) << ".0f";
	else if (_type == "int")
	{
		intValue = intStrToInt(0);
		os << static_cast<float>(intValue) << ".0f";
	}
	else if (_type == "float")
		os << _baseValue;
	else if (_type == "double")
		os << _baseValue << "f";
}

void Converter::displayDoubleValue(std::ostream &os) const
{
	int			intValue;

	os << "double: ";
	if (_type == "char")
		os << static_cast<int>(_baseValue[0]) << ".0";
	else if (_type == "int")
	{
		intValue = intStrToInt(0);
		os << static_cast<double>(intValue) << ".0";
	}
	else if (_type == "float")
	{
		for (int i = 0 ; i + 1 < static_cast<int>(_baseValue.size()) ; i++)
			os << _baseValue[i];
	}
	else if (_type == "double")
		os << _baseValue;
}

void Converter::print(std::ostream &os) const
{
	if (_error != "no error")
		os << _error << std::endl;
	else
	{
		displayCharValue(os);
		os << std::endl;
		displayIntValue(os);
		os << std::endl;
		displayFloatValue(os);
		os << std::endl;
		displayDoubleValue(os);
		os << std::endl;
	}
}

/*---------------------------------------------*/

std::ostream &operator<<(std::ostream &os, Converter const &Converter) 
{
	Converter.print(os);
	return (os);
}
