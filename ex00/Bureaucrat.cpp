#include "Bureaucrat.hpp"

static const int	highestGrade = 1;
static const int	lowestGrade = 150;

/**
 * @brief Checks if the grade value is too high (less than 1)
 * @param value - grade value to check
 * @return true if grade is too high, false otherwise
 */
bool Bureaucrat::isGradeTooHigh(int value)
{
	return (value < highestGrade);
}

/**
 * @brief Checks if the grade value is too low (greater than 150)
 * @param value - grade value to check
 * @return true if grade is too low, false otherwise
 */
bool Bureaucrat::isGradeTooLow(int value)
{
	return (value > lowestGrade);
}

/**
 * @brief Parameterized constructor
 * @param nameValue - bureaucrat's name
 * @param gradeValue - bureaucrat's grade (1-150)
 * @throws GradeTooHighException if grade < 1
 * @throws GradeTooLowException if grade > 150
 */
Bureaucrat::Bureaucrat(const std::string &nameValue, int gradeValue)
	: name(nameValue), grade(gradeValue)
{
	if (isGradeTooHigh(grade))
		throw Bureaucrat::GradeTooHighException();
	if (isGradeTooLow(grade))
		throw Bureaucrat::GradeTooLowException();
}

/**
 * @brief Copy constructor
 * @param other - bureaucrat to copy from
 */
Bureaucrat::Bureaucrat(const Bureaucrat &other)
	: name(other.name), grade(other.grade) {}

/**
 * @brief Destructor
 */
Bureaucrat::~Bureaucrat() {}

/**
 * @brief Copy assignment operator (copies grade only)
 * @param other - bureaucrat to assign from
 * @return reference to this bureaucrat
 */
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		grade = other.grade;
	return (*this);
}

/**
 * @brief Gets the bureaucrat's name
 * @return const reference to the name
 */
const std::string &Bureaucrat::getName() const
{
	return (name);
}

/**
 * @brief Gets the bureaucrat's grade
 * @return the grade value
 */
int Bureaucrat::getGrade() const
{
	return (grade);
}

/**
 * @brief Increments grade (decreases value by 1)
 * @throws GradeTooHighException if result would be < 1
 */
void Bureaucrat::incrementGrade()
{
	if (isGradeTooHigh(grade - 1))
		throw Bureaucrat::GradeTooHighException();
	grade -= 1;
}

/**
 * @brief Decrements grade (increases value by 1)
 * @throws GradeTooLowException if result would be > 150
 */
void Bureaucrat::decrementGrade()
{
	if (isGradeTooLow(grade + 1))
		throw Bureaucrat::GradeTooLowException();
	grade += 1;
}

/**
 * @brief Returns exception description for GradeTooHighException
 * @return error message string
 */
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat: grade is too high");
}

/**
 * @brief Returns exception description for GradeTooLowException
 * @return error message string
 */
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat: grade is too low");
}

/**
 * @brief Output stream operator for Bureaucrat
 * @param os - output stream
 * @param b - bureaucrat to output
 * @return reference to the output stream
 */
std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return (os);
}
