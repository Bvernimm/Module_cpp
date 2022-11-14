#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{

	try {
		Intern someRandomIntern;
		Bureaucrat	John("John", 20);
		AForm* rrf;

		rrf = someRandomIntern.makeForm("PresidentialPardonForm", "Bender");
		John.signAForm(*rrf);
		//PresidentialForm.execute(John);
		John.executeForm(*rrf);
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

	return (0);
}