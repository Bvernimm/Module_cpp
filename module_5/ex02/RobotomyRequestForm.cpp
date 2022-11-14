#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : 
	AForm ("RobotomyRequestForm", _signGrade, _excecuteGrade) {
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : 
	AForm ("RobotomyRequestForm", _signGrade, _excecuteGrade),
	_target (target) {
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) : 
	AForm(other),
	_target (other._target){
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other) {
	AForm::operator=(other);
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
}

/*---------------------------------------------*/

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	int	random;

	checkExecute(executor);
	srand (time(NULL));
	random = std::rand() % 2;
	std::cout << "Brrrrrrrrrrrrrrr" << std::endl;
	if (random == 1) {
        std::cout << _target << " has been robotomized" << std::endl;
    } else {
        std::cout << _target << " hasn't been robotomized" << std::endl;
    }
}