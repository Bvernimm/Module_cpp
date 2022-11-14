#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : 
	AForm ("ShrubberyCreationForm", _signGrade, _excecuteGrade) {
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : 
	AForm ("ShrubberyCreationForm", _signGrade, _excecuteGrade),
	_target (target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) : 
	AForm(other),
	_target (other._target){
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other) {
	AForm::operator=(other);
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
}

/*---------------------------------------------*/

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	checkExecute(executor);
	std::ofstream outfile (_target + "_shrubbery");
	outfile << "            '.,\n              'b      *\n               '$    #.\n                $:   #:\n                *#  @):\n                :@,@):   ,.**:'\n      ,         :@@*: ..**'\n       '#o.    .:(@'.@*''\n          'bq,..:,@@*'   ,*\n          ,p$q8,:@)'  .p*'\n         '    '@@Pp@@*'\n               Y7'.'\n              :@):.\n             .:@:'.\n           .::(@:.\n" << std::endl;
	outfile.close();
}
