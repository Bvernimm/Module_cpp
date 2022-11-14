#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{

	try {
		Bureaucrat	John("John", 5);
		PresidentialPardonForm		PresidentialForm("test");
		std::cout << PresidentialForm << std::endl;
		John.signAForm(PresidentialForm);
		std::cout << PresidentialForm << std::endl;
		//PresidentialForm.execute(John);
		John.executeForm(PresidentialForm);
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

	return (0);
}