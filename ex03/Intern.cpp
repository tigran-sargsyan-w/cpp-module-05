#include "Intern.hpp"

#include <iostream>

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(Intern const & other)
{
	(void)other;
}

Intern & Intern::operator=(Intern const & other)
{
	(void)other;
	return (*this);
}

Intern::~Intern() {}

AForm * Intern::createShrubbery(std::string const & target) const
{
	return (new ShrubberyCreationForm(target));
}

AForm * Intern::createRobotomy(std::string const & target) const
{
	return (new RobotomyRequestForm(target));
}

AForm * Intern::createPresidential(std::string const & target) const
{
	return (new PresidentialPardonForm(target));
}

AForm * Intern::makeForm(std::string const & formName, std::string const & target) const
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
