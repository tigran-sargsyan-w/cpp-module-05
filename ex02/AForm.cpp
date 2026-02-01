#include "AForm.hpp"
#include "Bureaucrat.hpp"

static const int	highestGrade = 1;
static const int	lowestGrade = 150;

bool AForm::isGradeTooHigh(int value)
{
	return (value < highestGrade);
}

bool AForm::isGradeTooLow(int value)
{
	return (value > lowestGrade);
}

AForm::AForm(const std::string &nameValue, int signValue, int execValue)
	: name(nameValue), signedFlag(false), gradeToSign(signValue), gradeToExecute(execValue)
{
	if (isGradeTooHigh(gradeToSign) || isGradeTooHigh(gradeToExecute))
		throw AForm::GradeTooHighException();
	if (isGradeTooLow(gradeToSign) || isGradeTooLow(gradeToExecute))
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other)
	: name(other.name),
	  signedFlag(other.signedFlag),
	  gradeToSign(other.gradeToSign),
	  gradeToExecute(other.gradeToExecute) {}

AForm::~AForm() {}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
		signedFlag = other.signedFlag;
	return (*this);
}

const std::string &AForm::getName() const
{
	return (name);
}

bool AForm::isSigned() const
{
	return (signedFlag);
}

int AForm::getGradeToSign() const
{
	return (gradeToSign);
}

int AForm::getGradeToExecute() const
{
	return (gradeToExecute);
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > gradeToSign)
		throw AForm::GradeTooLowException();
	signedFlag = true;
}

void AForm::execute(const Bureaucrat &executor) const
{
	if (!signedFlag)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > gradeToExecute)
		throw AForm::GradeTooLowException();
	executeAction();
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("AForm: grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("AForm: grade is too low");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("AForm: form is not signed");
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
	os << "AForm " << form.getName()
		<< ", signed: " << (form.isSigned() ? "yes" : "no")
		<< ", gradeToSign: " << form.getGradeToSign()
		<< ", gradeToExecute: " << form.getGradeToExecute();
	return (os);
}
