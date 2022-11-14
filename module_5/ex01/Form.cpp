#include "Form.hpp"

Form::Form(void) : _name (""), _signed (false), _signGrade (_minGrade), _executeGrade (_minGrade){
}

Form::Form(Form const &other) : _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _executeGrade(other._executeGrade) {
	checkGrade();
}

Form::Form(std::string const name, unsigned int signGrade, unsigned int executeGrade) : _name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade) {
	checkGrade();
}

Form &Form::operator=(Form const &other) {
	_signed = other._signed;
	checkGrade();
	return *this;
}

Form::~Form(void) {
}

/*---------------------------------------------*/

std::string const Form::getName(void)
{
	return (_name);
}

unsigned int Form::getSignGrade(void)
{
	return (_signGrade);
}

unsigned int Form::getExecuteGrade(void)
{
	return (_executeGrade);
}

/*---------------------------------------------*/

void Form::checkGrade(void)
{
	if (_signGrade < _maxGrade || _executeGrade < _maxGrade)
		throw GradeTooHighException();
	if (_signGrade > _minGrade || _executeGrade > _minGrade)
		throw GradeTooLowException();
}

void Form::beSigned(Bureaucrat &Bureaucrat)
{
	if (Bureaucrat.getGrade() > _signGrade)
		throw GradeTooLowException();
	else
		_signed = true;
}

void Form::print(std::ostream &os) const
{
	os << "Form called " << _name;
	if (_signed)
		os << " is signed, ";
	else
		os << " is unsigned, ";
	os << "grade needed to sign is " << _signGrade;
	os << " and grade needed to execute is " << _executeGrade;
}

/*---------------------------------------------*/

const char *Form::GradeTooHighException::what () const throw ()
{
	return "GradeTooHighException";
}

const char *Form::GradeTooLowException::what () const throw ()
{
	return "GradeTooLowException";
}

/*---------------------------------------------*/

std::ostream &operator<<(std::ostream &os, Form const &Form) {
	Form.print (os);
	return (os);
}