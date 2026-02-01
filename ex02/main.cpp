#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
	Bureaucrat boss("Boss", 1);
	Bureaucrat mid("Mid", 50);
	Bureaucrat low("Low", 150);

	ShrubberyCreationForm shrub("home");
	RobotomyRequestForm robo("Bender");
	PresidentialPardonForm pardon("Arthur Dent");

	std::cout << "\n=== Execute unsigned forms (must fail) ===" << std::endl;
	boss.executeForm(shrub);
	boss.executeForm(robo);
	boss.executeForm(pardon);

	std::cout << "\n=== Sign forms ===" << std::endl;
	low.signForm(shrub);
	mid.signForm(shrub);
	mid.signForm(robo);
	boss.signForm(robo);
	boss.signForm(pardon);

	std::cout << "\n=== Execute forms ===" << std::endl;
	mid.executeForm(shrub);
	boss.executeForm(shrub);

	mid.executeForm(robo);
	boss.executeForm(robo);

	mid.executeForm(pardon);
	boss.executeForm(pardon);

	return 0;
}
