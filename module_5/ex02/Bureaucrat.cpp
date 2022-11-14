#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name (""), _grade (_minGrade) {
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : _name (other._name), _grade(other._grade) {
	checkGrade();
}

Bureaucrat::Bureaucrat(std::string const name, unsigned int grade) : _name (name), _grade (grade) {
	checkGrade();
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other) {
	_grade = other._grade;
	checkGrade();
	return *this;
}

Bureaucrat::~Bureaucrat(void) {
}

/*---------------------------------------------*/

std::string const Bureaucrat::getName(void)
{
	return (_name);
}

unsigned int Bureaucrat::getGrade(void) const
{
	return (_grade);
}

/*---------------------------------------------*/

void Bureaucrat::checkGrade(void)
{
	if (_grade < _maxGrade)
		throw GradeTooHighException();
	if (_grade > _minGrade)
		throw GradeTooLowException();
}

void Bureaucrat::increaseGrade(void)
{
	if (_grade - 1 < _maxGrade)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::lowerGrade(void)
{
	if (_grade + 1 > _minGrade)
		throw GradeTooLowException();
	_grade++;
}

void Bureaucrat::print(std::ostream &os) const
{
	os << _name << ", bureaucrat grade " << _grade;
}

void Bureaucrat::signAForm(AForm &AForm)
{
	try 
	{
		AForm.beSigned(*this);
	}
	catch (AForm::GradeTooLowException)
	{
		std::cout << _name << " couldn’t sign AForm " << AForm.getName() << " because his grade was too low\n";
		return ;
	}
	std::cout << _name << " signed AForm " << AForm.getName() << std::endl;
}

/*---------------------------------------------*/

const char *Bureaucrat::GradeTooHighException::what () const throw ()
{
	return "GradeTooHighException";
}

const char *Bureaucrat::GradeTooLowException::what () const throw ()
{
	return "GradeTooLowException";
}

/*---------------------------------------------*/

std::ostream &operator<<(std::ostream &os, Bureaucrat const &Bureaucrat) {
	Bureaucrat.print (os);
	return (os);
}

/*---------------------------------------------*/

void	Bureaucrat::executeForm(AForm const & form)
{
	form.execute(*this);
}