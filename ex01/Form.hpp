#ifndef FORM_HPP
# define FORM_HPP

# include <exception>
# include <iostream>
# include <string>

class	Bureaucrat;

class Form
{
  private:
	Form(); // forbidden: use Form(name, gradeToSign, gradeToExecute)

	const std::string name;
	bool signedFlag;
	const int gradeToSign;
	const int gradeToExecute;

	static bool isGradeTooHigh(int value);
	static bool isGradeTooLow(int value);

  public:
	Form(const std::string &nameValue, int signValue, int execValue);
	Form(const Form &other);
	~Form();

	Form &operator=(const Form &other);

	const std::string &getName() const;
	bool isSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	void beSigned(const Bureaucrat &bureaucrat);

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

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif
