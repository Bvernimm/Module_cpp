#include "AForm.hpp"

AForm::AForm(void) : _name (""), _signed (false), _signGrade (_minGrade), _executeGrade (_minGrade){
}

AForm::AForm(AForm const &other) : _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _executeGrade(other._executeGrade) {
	checkGrade();
}

AForm::AForm(std::string const name, unsigned int signGrade, unsigned int executeGrade) : _name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade) {
	checkGrade();
}

AForm &AForm::operator=(AForm const &other) {
	_signed = other._signed;
	checkGrade();
	return *this;
}

AForm::~AForm(void) {
}

/*---------------------------------------------*/

std::string const AForm::getName(void)
{
	return (_name);
}

unsigned int AForm::getSignGrade(void)
{
	return (_signGrade);
}

unsigned int AForm::getExecuteGrade(void)
{
	return (_executeGrade);
}

/*---------------------------------------------*/

void AForm::checkGrade(void)
{
	if (_signGrade < _maxGrade || _executeGrade < _maxGrade)
		throw GradeTooHighException();
	if (_signGrade > _minGrade || _executeGrade > _minGrade)
		throw GradeTooLowException();
}

void AForm::beSigned(Bureaucrat &Bureaucrat)
{
	if (Bureaucrat.getGrade() > _signGrade)
		throw GradeTooLowException();
	else
		_signed = true;
}

void AForm::print(std::ostream &os) const
{
	os << "AForm called " << _name;
	if (_signed)
		os << " is signed, ";
	else
		os << " is unsigned, ";
	os << "grade needed to sign is " << _signGrade;
	os << " and grade needed to execute is " << _executeGrade;
}

/*---------------------------------------------*/

const char *AForm::GradeTooHighException::what () const throw ()
{
	return "GradeTooHighException";
}

const char *AForm::GradeTooLowException::what () const throw ()
{
	return "GradeTooLowException";
}

const char *AForm::UnsignedException::what () const throw ()
{
	return "UnsignedException";
}

/*---------------------------------------------*/

std::ostream &operator<<(std::ostream &os, AForm const &AForm) {
	AForm.print (os);
	return (os);
}

/*---------------------------------------------*/

void AForm::checkExecute(Bureaucrat const & executor) const
{
	if (!_signed)
		throw UnsignedException();
	if (executor.getGrade() > _executeGrade)
		throw GradeTooLowException();
}