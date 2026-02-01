#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <exception>
# include <iostream>
# include <string>

class Bureaucrat
{
  private:
	Bureaucrat(); // forbidden: use Bureaucrat(name, grade)

	const std::string name;
	int grade;

	static bool isGradeTooHigh(int value);
	static bool isGradeTooLow(int value);

  public:
	Bureaucrat(const std::string &nameValue, int gradeValue);
	Bureaucrat(const Bureaucrat &other);
	~Bureaucrat();

	Bureaucrat &operator=(const Bureaucrat &other);

	const std::string &getName() const;
	int getGrade() const;

	void incrementGrade();
	void decrementGrade();

	class GradeTooHighException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif
