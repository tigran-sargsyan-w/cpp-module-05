#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>

class	AForm;

class Intern
{
  private:
	typedef AForm *(Intern::*CreateFunc)(std::string const &target) const;

	AForm *createShrubbery(std::string const &target) const;
	AForm *createRobotomy(std::string const &target) const;
	AForm *createPresidential(std::string const &target) const;

  public:
	Intern();
	Intern(Intern const &other);
	Intern &operator=(Intern const &other);
	~Intern();

	AForm *makeForm(std::string const &formName, std::string const &target) const;
};

#endif
