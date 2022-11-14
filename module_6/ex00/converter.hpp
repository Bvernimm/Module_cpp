#ifndef CONVERTER_HPP
# define CONVERTER_HPP

#include <iostream>
#include <string>
#include <stdexcept>

class	Converter
{
private:
	std::string	_baseValue;
	std::string	_type;
	std::string	_error;

	bool		_intMax;
	
public:
	Converter(void);
	Converter(std::string baseValue);
	Converter(Converter const &other);
	Converter &operator=(Converter const &other);
	~Converter(void);

	int 		maxValueFloat(void);
	int 		maxValueInt(void);
	long int	intStrToInt(int i) const;
	long int	floatStrToInt(void) const;

	void	displayCharValue(std::ostream &os) const;
	void	displayIntValue(std::ostream &os) const;
	void	displayFloatValue(std::ostream &os) const;
	void	displayDoubleValue(std::ostream &os) const;
	void 	print(std::ostream &os) const;
};

std::ostream &operator<<(std::ostream &os, Converter const &Converter);

#endif