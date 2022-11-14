#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <stdexcept>
#include <fstream>

#include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm
{
private:
	std::string const			_name;
	bool						_signed;
	const unsigned int			_signGrade;
	const unsigned int			_executeGrade;
	static const unsigned int	_minGrade = 150;
	static const unsigned int	_maxGrade = 1;
public:
	AForm(void);
	AForm(AForm const &other);
	AForm(std::string const name, unsigned int signGrade, unsigned int executeGrade);
	AForm &operator=(AForm const &other);
	virtual ~AForm(void);

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
	class UnsignedException : public std::exception
	{
		const char * what () const throw ();
	};

	virtual void	execute(Bureaucrat const & executor) const = 0;
	void			checkExecute(Bureaucrat const & executor) const;
};

std::ostream &operator<<(std::ostream &os, AForm const &AForm);

#endif