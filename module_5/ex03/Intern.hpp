#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <stdexcept>

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class	Intern
{
private:
	std::string	_FormNames[3];
public:
	Intern(void);
	Intern(Intern const &other);
	Intern &operator=(Intern const &other);
	~Intern(void);

	AForm	*makeForm(std::string form, std::string target);

	class UnknownForm : public std::exception
	{
		const char * what () const throw ();
	};
};

#endif