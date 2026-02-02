#include "AForm.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

/**
 * @brief Default constructor
 */
Intern::Intern() {}

/**
 * @brief Copy constructor
 * @param other - intern to copy from
 */
Intern::Intern(Intern const &other)
{
	(void)other;
}

/**
 * @brief Copy assignment operator
 * @param other - intern to assign from
 * @return reference to this intern
 */
Intern &Intern::operator=(Intern const &other)
{
	(void)other;
	return (*this);
}

/**
 * @brief Destructor
 */
Intern::~Intern() {}

/**
 * @brief Creates a ShrubberyCreationForm
 * @param target - target for the form
 * @return pointer to new ShrubberyCreationForm
 */
AForm *Intern::createShrubbery(std::string const &target) const
{
	return (new ShrubberyCreationForm(target));
}

/**
 * @brief Creates a RobotomyRequestForm
 * @param target - target for the form
 * @return pointer to new RobotomyRequestForm
 */
AForm *Intern::createRobotomy(std::string const &target) const
{
	return (new RobotomyRequestForm(target));
}

/**
 * @brief Creates a PresidentialPardonForm
 * @param target - target for the form
 * @return pointer to new PresidentialPardonForm
 */
AForm *Intern::createPresidential(std::string const &target) const
{
	return (new PresidentialPardonForm(target));
}

/**
 * @brief Creates a form by name
 * @param formName - name of form to create
 * @param target - target for the form
 * @return pointer to created form, or NULL if unknown
 */
AForm *Intern::makeForm(std::string const &formName, std::string const &target) const
{
	std::string const formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	CreateFunc const creators[3] = {
		&Intern::createShrubbery,
		&Intern::createRobotomy,
		&Intern::createPresidential
	};

	for (int index = 0; index < 3; index++)
	{
		if (formName == formNames[index])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return ((this->*creators[index])(target));
		}
	}
	std::cout << "Intern cannot create form: \"" << formName << "\" (unknown form name)" << std::endl;
	return (NULL);
}
