#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <time.h>

class	RobotomyRequestForm : public AForm
{
private:
	const std::string			_target;
	static const unsigned int	_signGrade = 72;
	static const unsigned int	_excecuteGrade = 45;
public:
	RobotomyRequestForm(void);
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm const &other);
	RobotomyRequestForm &operator=(RobotomyRequestForm const &other);
	~RobotomyRequestForm(void);

	void	execute(Bureaucrat const & executor) const;
};

#endif