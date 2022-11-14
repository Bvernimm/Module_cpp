#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class	PresidentialPardonForm : public AForm
{
private:
	const std::string			_target;
	static const unsigned int	_signGrade = 25;
	static const unsigned int	_excecuteGrade = 5;
public:
	PresidentialPardonForm(void);
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm const &other);
	PresidentialPardonForm &operator=(PresidentialPardonForm const &other);
	~PresidentialPardonForm(void);

	void	execute(Bureaucrat const & executor) const;
};

#endif