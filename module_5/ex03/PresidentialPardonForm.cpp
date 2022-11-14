#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : 
	AForm ("PresidentialPardonForm", _signGrade, _excecuteGrade) {
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : 
	AForm ("PresidentialPardonForm", _signGrade, _excecuteGrade),
	_target (target) {
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other) : 
	AForm(other),
	_target (other._target){
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other) {
	AForm::operator=(other);
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
}

/*---------------------------------------------*/

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	checkExecute(executor);
	std::cout << _target << " was forgiven by Zaphod Beeblebrox." << std::endl;
}