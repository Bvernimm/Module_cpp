#include "Intern.hpp"

Intern::Intern(void) {
	_FormNames[0] = "ShrubberyCreationForm";
	_FormNames[1] = "RobotomyRequestForm";
	_FormNames[2] = "PresidentialPardonForm";
}

Intern::Intern(Intern const &other) {
	*this = other;
}

Intern &Intern::operator=(Intern const &other) {
	(void) other;
	return *this;
}

Intern::~Intern(void) {
}

/*---------------------------------------------*/

AForm	*Intern::makeForm(std::string form, std::string target)
{
	AForm	*newform;
	int	i;

	for (i = 0; i < 3; i++)
		if (form == _FormNames[i])
			break ;
	switch (i) {
		case 0:
			newform = new ShrubberyCreationForm(target);
			break;
		case 1:
			newform = new RobotomyRequestForm(target);
			break;
		case 2:
			newform = new PresidentialPardonForm(target);
			break;
		default:
			throw UnknownForm();
	}
	std::cout << "Intern creates " << newform->getName() << std::endl;
	return (newform);
}

/*---------------------------------------------*/

const char *Intern::UnknownForm::what () const throw ()
{
	return "UnknownForm";
}