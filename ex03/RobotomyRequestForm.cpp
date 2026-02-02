#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

/**
 * @brief Default constructor with "default" target
 */
RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45), target("default") {}

/**
 * @brief Parameterized constructor
 * @param targetValue - target to be robotomized
 */
RobotomyRequestForm::RobotomyRequestForm(const std::string &targetValue)
	: AForm("RobotomyRequestForm", 72, 45), target(targetValue) {}

/**
 * @brief Copy constructor
 * @param other - form to copy from
 */
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm(other), target(other.target) {}

/**
 * @brief Destructor
 */
RobotomyRequestForm::~RobotomyRequestForm() {}

/**
 * @brief Copy assignment operator
 * @param other - form to assign from
 * @return reference to this form
 */
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		target = other.target;
	}
	return (*this);
}

/**
 * @brief Gets the target name
 * @return const reference to target
 */
const std::string &RobotomyRequestForm::getTarget() const
{
	return (target);
}

/**
 * @brief Makes drilling noises and robotomizes target with 50% success rate
 */
void RobotomyRequestForm::executeAction() const
{
	static bool seeded = false;

	if (!seeded)
	{
		std::srand(static_cast<unsigned int>(std::time(NULL)));
		seeded = true;
	}

	std::cout << "* drilling noises *" << std::endl;

	if ((std::rand() % 2) == 0)
		std::cout << target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "Robotomy failed on " << target << "." << std::endl;
}
