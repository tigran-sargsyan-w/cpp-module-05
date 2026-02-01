#include "ShrubberyCreationForm.hpp"
#include <fstream>

/**
 * @brief Default constructor with "default" target
 */
ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), target("default") {}

/**
 * @brief Parameterized constructor
 * @param targetValue - target filename prefix
 */
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &targetValue)
	: AForm("ShrubberyCreationForm", 145, 137), target(targetValue) {}

/**
 * @brief Copy constructor
 * @param other - form to copy from
 */
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other), target(other.target) {}

/**
 * @brief Destructor
 */
ShrubberyCreationForm::~ShrubberyCreationForm() {}

/**
 * @brief Copy assignment operator
 * @param other - form to assign from
 * @return reference to this form
 */
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
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
const std::string &ShrubberyCreationForm::getTarget() const
{
	return (target);
}

/**
 * @brief Creates a file with ASCII tree art
 * File is named <target>_shrubbery
 */
void ShrubberyCreationForm::executeAction() const
{
	std::string fileName = target + "_shrubbery";
	std::ofstream out(fileName.c_str());
	if (!out)
		return ;

	out <<
		"       _-_\n"
		"    /~~   ~~\\\n"
		" /~~         ~~\\\n"
		"{               }\n"
		" \\  _-     -_  /\n"
		"   ~  \\\\ //  ~\n"
		"_- -   | | _- _\n"
		"  _ -  | |   -_\n"
		"      // \\\\\n";
}
