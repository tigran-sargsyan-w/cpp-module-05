#include "Bureaucrat.hpp"

static const int	highestGrade = 1;
static const int	lowestGrade = 150;

bool Bureaucrat::isGradeTooHigh(int value)
{
	return (value < highestGrade);
}

bool Bureaucrat::isGradeTooLow(int value)
{
	return (value > lowestGrade);
}

Bureaucrat::Bureaucrat(const std::string &nameValue, int gradeValue)
	: name(nameValue), grade(gradeValue)
{
	if (isGradeTooHigh(grade))
		throw Bureaucrat::GradeTooHighException();
	if (isGradeTooLow(grade))
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
	: name(other.name), grade(other.grade) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		grade = other.grade;
	return (*this);
}

const std::string &Bureaucrat::getName() const
{
	return (name);
}

int Bureaucrat::getGrade() const
{
	return (grade);
}

void Bureaucrat::incrementGrade()
{
	if (isGradeTooHigh(grade - 1))
		throw Bureaucrat::GradeTooHighException();
	grade -= 1;
}

void Bureaucrat::decrementGrade()
{
	if (isGradeTooLow(grade + 1))
		throw Bureaucrat::GradeTooLowException();
	grade += 1;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat: grade is too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat: grade is too low");
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return (os);
}
