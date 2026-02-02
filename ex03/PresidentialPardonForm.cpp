#include "PresidentialPardonForm.hpp"
#include <iostream>

/**
 * @brief Default constructor with "default" target
 */
PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", 25, 5), target("default") {}

/**
 * @brief Parameterized constructor
 * @param targetValue - target to be pardoned
 */
PresidentialPardonForm::PresidentialPardonForm(const std::string &targetValue)
	: AForm("PresidentialPardonForm", 25, 5), target(targetValue) {}

/**
 * @brief Copy constructor
 * @param other - form to copy from
 */
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
	: AForm(other), target(other.target) {}

/**
 * @brief Destructor
 */
PresidentialPardonForm::~PresidentialPardonForm() {}

/**
 * @brief Copy assignment operator
 * @param other - form to assign from
 * @return reference to this form
 */
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
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
const std::string &PresidentialPardonForm::getTarget() const
{
	return (target);
}

/**
 * @brief Announces that target has been pardoned by Zaphod Beeblebrox
 */
void PresidentialPardonForm::executeAction() const
{
	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
