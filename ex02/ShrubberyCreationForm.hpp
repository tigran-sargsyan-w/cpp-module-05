#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <string>

class ShrubberyCreationForm : public AForm
{
  private:
	ShrubberyCreationForm();

	std::string target;

  protected:
	virtual void executeAction() const;

  public:
	ShrubberyCreationForm(const std::string &targetValue);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	~ShrubberyCreationForm();

	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

	const std::string &getTarget() const;
};

#endif
