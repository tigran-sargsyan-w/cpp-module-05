#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <string>

class RobotomyRequestForm : public AForm
{
  private:
	RobotomyRequestForm();

	std::string target;

  protected:
	virtual void executeAction() const;

  public:
	RobotomyRequestForm(const std::string &targetValue);
	RobotomyRequestForm(const RobotomyRequestForm &other);
	~RobotomyRequestForm();

	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

	const std::string &getTarget() const;
};

#endif
