#ifndef AFORM_HPP
# define AFORM_HPP

# include <exception>
# include <iostream>
# include <string>

class	Bureaucrat;

class AForm
{
  private:
	AForm(); // forbidden: use AForm(name, gradeToSign, gradeToExecute)

	const std::string name;
	bool signedFlag;
	const int gradeToSign;
	const int gradeToExecute;

	static bool isGradeTooHigh(int value);
	static bool isGradeTooLow(int value);

  protected:
	virtual void executeAction() const = 0;

  public:
	AForm(const std::string &nameValue, int signValue, int execValue);
	AForm(const AForm &other);
	virtual ~AForm();

	AForm &operator=(const AForm &other);

	const std::string &getName() const;
	bool isSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	void beSigned(const Bureaucrat &bureaucrat);
	void execute(const Bureaucrat &executor) const;

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

	class FormNotSignedException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif
