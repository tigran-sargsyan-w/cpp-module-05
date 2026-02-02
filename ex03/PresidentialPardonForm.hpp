#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include <string>

class PresidentialPardonForm : public AForm
{
  private:
	PresidentialPardonForm();

	std::string target;

  protected:
	virtual void executeAction() const;

  public:
	PresidentialPardonForm(const std::string &targetValue);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	~PresidentialPardonForm();

	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

	const std::string &getTarget() const;
};

#endif
