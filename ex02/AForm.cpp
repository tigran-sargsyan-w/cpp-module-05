#include "AForm.hpp"
#include "Bureaucrat.hpp"

static const int	highestGrade = 1;
static const int	lowestGrade = 150;

/**
 * @brief Checks if grade value is too high (less than 1)
 * @param value - grade value to check
 * @return true if grade is too high
 */
bool AForm::isGradeTooHigh(int value)
{
	return (value < highestGrade);
}

/**
 * @brief Checks if grade value is too low (greater than 150)
 * @param value - grade value to check
 * @return true if grade is too low
 */
bool AForm::isGradeTooLow(int value)
{
	return (value > lowestGrade);
}

/**
 * @brief Parameterized constructor
 * @param nameValue - form name
 * @param signValue - grade required to sign
 * @param execValue - grade required to execute
 * @throws GradeTooHighException if grade < 1
 * @throws GradeTooLowException if grade > 150
 */
AForm::AForm(const std::string &nameValue, int signValue, int execValue)
	: name(nameValue), signedFlag(false), gradeToSign(signValue), gradeToExecute(execValue)
{
	if (isGradeTooHigh(gradeToSign) || isGradeTooHigh(gradeToExecute))
		throw AForm::GradeTooHighException();
	if (isGradeTooLow(gradeToSign) || isGradeTooLow(gradeToExecute))
		throw AForm::GradeTooLowException();
}

/**
 * @brief Copy constructor
 * @param other - form to copy from
 */
AForm::AForm(const AForm &other)
	: name(other.name),
	  signedFlag(other.signedFlag),
	  gradeToSign(other.gradeToSign),
	  gradeToExecute(other.gradeToExecute) {}

/**
 * @brief Destructor
 */
AForm::~AForm() {}

/**
 * @brief Copy assignment operator (copies signedFlag only)
 * @param other - form to assign from
 * @return reference to this form
 */
AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
		signedFlag = other.signedFlag;
	return (*this);
}

/**
 * @brief Gets the form's name
 * @return const reference to the name
 */
const std::string &AForm::getName() const
{
	return (name);
}

/**
 * @brief Checks if form is signed
 * @return true if signed, false otherwise
 */
bool AForm::isSigned() const
{
	return (signedFlag);
}

/**
 * @brief Gets grade required to sign
 * @return grade to sign value
 */
int AForm::getGradeToSign() const
{
	return (gradeToSign);
}

/**
 * @brief Gets grade required to execute
 * @return grade to execute value
 */
int AForm::getGradeToExecute() const
{
	return (gradeToExecute);
}

/**
 * @brief Signs the form if bureaucrat has sufficient grade
 * @param bureaucrat - bureaucrat attempting to sign
 * @throws GradeTooLowException if bureaucrat's grade is insufficient
 */
void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > gradeToSign)
		throw AForm::GradeTooLowException();
	signedFlag = true;
}

/**
 * @brief Executes the form if conditions are met
 * @param executor - bureaucrat attempting to execute
 * @throws FormNotSignedException if form is not signed
 * @throws GradeTooLowException if executor's grade is insufficient
 */
void AForm::execute(const Bureaucrat &executor) const
{
	if (!signedFlag)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > gradeToExecute)
		throw AForm::GradeTooLowException();
	executeAction();
}

/**
 * @brief Returns exception description
 * @return error message string
 */
const char *AForm::GradeTooHighException::what() const throw()
{
	return ("AForm: grade is too high");
}

/**
 * @brief Returns exception description
 * @return error message string
 */
const char *AForm::GradeTooLowException::what() const throw()
{
	return ("AForm: grade is too low");
}

/**
 * @brief Returns exception description
 * @return error message string
 */
const char *AForm::FormNotSignedException::what() const throw()
{
	return ("AForm: form is not signed");
}

/**
 * @brief Output stream operator for AForm
 * @param os - output stream
 * @param form - form to output
 * @return reference to the output stream
 */
std::ostream &operator<<(std::ostream &os, const AForm &form)
{
	os << "AForm " << form.getName()
		<< ", signed: " << (form.isSigned() ? "yes" : "no")
		<< ", gradeToSign: " << form.getGradeToSign()
		<< ", gradeToExecute: " << form.getGradeToExecute();
	return (os);
}
