#include <iostream>
#include "Intern.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

/**
 * @brief Entry point - demonstrates Intern form creation
 * @return 0 on success
 */
int main()
{
	Intern intern;
	AForm * form;

	form = intern.makeForm("robotomy request", "Bender");
	if (form)
	{
		std::cout << *form << std::endl;
		delete form;
	}

	form = intern.makeForm("shrubbery creation", "home");
	if (form)
	{
		std::cout << *form << std::endl;
		delete form;
	}

	form = intern.makeForm("some random form", "target");
	if (form)
		delete form;

	return (0);
}
