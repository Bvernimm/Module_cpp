#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	try {
		Form	PresidentialTurkeyPardon("PresidentialTurkeyPardon", 5, 0);
		std::cout << PresidentialTurkeyPardon << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

	try {
		Bureaucrat	John("John", 37);
		Form		RandomForm("RandomForm", 50, 25);
		std::cout << RandomForm << std::endl;
		John.signForm(RandomForm);
		std::cout << RandomForm << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

	return (0);
}