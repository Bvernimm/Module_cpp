#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <stdexcept>

#include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form
{
private:
	std::string const			_name;
	bool						_signed;
	const unsigned int			_signGrade;
	const unsigned int			_executeGrade;
	static const unsigned int	_minGrade = 150;
	static const unsigned int	_maxGrade = 1;
public:
	Form(void);
	Form(Form const &other);
	Form(std::string const name, unsigned int signGrade, unsigned int executeGrade);
	Form &operator=(Form const &other);
	~Form(void);

	std::string const	getName(void);
	unsigned int		getSignGrade(void);
	unsigned int		getExecuteGrade(void);

	void	checkGrade(void);
	void	beSigned(Bureaucrat &Bureaucrat);
	void	print(std::ostream &os) const;

	class GradeTooHighException : public std::exception
	{
		const char * what () const throw ();
	};
	class GradeTooLowException : public std::exception
	{
		const char * what () const throw ();
	};
};

std::ostream &operator<<(std::ostream &os, Form const &Form);

#endif