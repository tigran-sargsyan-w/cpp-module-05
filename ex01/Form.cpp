#include "Bureaucrat.hpp"
#include "Form.hpp"

static const int	highestGrade = 1;
static const int	lowestGrade = 150;

/**
 * @brief Checks if the grade value is too high (less than 1)
 * @param value - grade value to check
 * @return true if grade is too high, false otherwise
 */
bool Form::isGradeTooHigh(int value)
{
	return (value < highestGrade);
}

/**
 * @brief Checks if the grade value is too low (greater than 150)
 * @param value - grade value to check
 * @return true if grade is too low, false otherwise
 */
bool Form::isGradeTooLow(int value)
{
	return (value > lowestGrade);
}

/**
 * @brief Parameterized constructor
 * @param nameValue - form name
 * @param signValue - grade required to sign
 * @param execValue - grade required to execute
 * @throws GradeTooHighException if any grade < 1
 * @throws GradeTooLowException if any grade > 150
 */
Form::Form(const std::string &nameValue, int signValue, int execValue)
	: name(nameValue), signedFlag(false), gradeToSign(signValue), gradeToExecute(execValue)
{
	if (isGradeTooHigh(gradeToSign) || isGradeTooHigh(gradeToExecute))
		throw Form::GradeTooHighException();
	if (isGradeTooLow(gradeToSign) || isGradeTooLow(gradeToExecute))
		throw Form::GradeTooLowException();
}

/**
 * @brief Copy constructor
 * @param other - form to copy from
 */
Form::Form(const Form &other)
	: name(other.name),
	  signedFlag(other.signedFlag),
	  gradeToSign(other.gradeToSign),
	  gradeToExecute(other.gradeToExecute) {}

/**
 * @brief Destructor
 */
Form::~Form() {}

/**
 * @brief Copy assignment operator (copies signed state only)
 * @param other - form to assign from
 * @return reference to this form
 */
Form &Form::operator=(const Form &other)
{
	if (this != &other)
		signedFlag = other.signedFlag;
	return (*this);
}

/**
 * @brief Gets the form name
 * @return const reference to the name
 */
const std::string &Form::getName() const
{
	return (name);
}

/**
 * @brief Returns whether the form is signed
 * @return true if signed, false otherwise
 */
bool Form::isSigned() const
{
	return (signedFlag);
}

/**
 * @brief Gets the grade required to sign
 * @return grade value
 */
int Form::getGradeToSign() const
{
	return (gradeToSign);
}

/**
 * @brief Gets the grade required to execute
 * @return grade value
 */
int Form::getGradeToExecute() const
{
	return (gradeToExecute);
}

/**
 * @brief Signs the form if bureaucrat grade is sufficient
 * @param bureaucrat - bureaucrat who tries to sign
 * @throws GradeTooLowException if bureaucrat grade is too low
 */
void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > gradeToSign)
		throw Form::GradeTooLowException();
	signedFlag = true;
}

/**
 * @brief Returns exception description for GradeTooHighException
 * @return error message string
 */
const char *Form::GradeTooHighException::what() const throw()
{
	return ("Form: grade is too high");
}

/**
 * @brief Returns exception description for GradeTooLowException
 * @return error message string
 */
const char *Form::GradeTooLowException::what() const throw()
{
	return ("Form: grade is too low");
}

/**
 * @brief Output stream operator for Form
 * @param os - output stream
 * @param form - form to output
 * @return reference to the output stream
 */
std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << "Form " << form.getName()
		<< ", signed: " << (form.isSigned() ? "yes" : "no")
		<< ", gradeToSign: " << form.getGradeToSign()
		<< ", gradeToExecute: " << form.getGradeToExecute();
	return (os);
}
