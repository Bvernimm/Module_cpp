#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

#include "AForm.hpp"

class	AForm;

class	Bureaucrat
{
private:
	std::string const			_name;
	unsigned int				_grade;
	static const unsigned int	_minGrade = 150;
	static const unsigned int	_maxGrade = 1;
public:
	Bureaucrat(void);
	Bureaucrat(Bureaucrat const &other);
	Bureaucrat(std::string const name, unsigned int grade);
	Bureaucrat &operator=(Bureaucrat const &other);
	~Bureaucrat(void);

	std::string const	getName(void);
	unsigned int		getGrade(void) const;

	void	checkGrade(void);
	void	increaseGrade(void);
	void	lowerGrade(void);
	void	print(std::ostream &os) const;
	void	signAForm(AForm &AForm);

	class GradeTooHighException : public std::exception
	{
		const char * what () const throw ();
	};
	class GradeTooLowException : public std::exception
	{
		const char * what () const throw ();
	};

	void	executeForm(AForm const & form);
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &Bureaucrat);

#endif