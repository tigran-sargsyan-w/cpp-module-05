#include "Bureaucrat.hpp"
#include "Form.hpp"

/**
 * @brief Tests valid form creation + operator<<
 */
static void	testFormValidCreation(void)
{
	std::cout << "\n=== Form: valid creation + operator<< ===\n";
	try
	{
		Form a("FormA", 1, 1);
		Form b("FormB", 150, 150);
		Form c("FormC", 42, 100);

		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << c << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}
}

/**
 * @brief Tests invalid form creation (grade out of bounds)
 */
static void	testFormInvalidCreation(void)
{
	std::cout << "\n=== Form: invalid creation ===\n";
	try
	{
		Form bad1("BadHigh", 0, 42);
		std::cout << bad1 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}
	try
	{
		Form bad2("BadLow", 42, 151);
		std::cout << bad2 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}
	try
	{
		Form bad3("BadBoth", 0, 151);
		std::cout << bad3 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}
}

/**
 * @brief Tests beSigned success and failure
 */
static void	testFormBeSigned(void)
{
	std::cout << "\n=== Form: beSigned (direct call) ===\n";
	try
	{
		Bureaucrat ok("SignerOK", 10);
		Bureaucrat bad("SignerBad", 100);
		Form f("Permit", 50, 50);

		std::cout << ok << std::endl;
		std::cout << bad << std::endl;
		std::cout << f << std::endl;

		std::cout << "\n-- bad tries beSigned (should throw) --\n";
		try
		{
			f.beSigned(bad);
			std::cout << "This line should not print\n";
		}
		catch (std::exception &e)
		{
			std::cout << "Caught: " << e.what() << std::endl;
		}

		std::cout << "\n-- ok tries beSigned (should sign) --\n";
		f.beSigned(ok);
		std::cout << "After beSigned: " << f << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}
}

/**
 * @brief Tests Bureaucrat::signForm output
 */
static void	testBureaucratSignForm(void)
{
	std::cout << "\n=== Bureaucrat: signForm ===\n";
	try
	{
		Bureaucrat boss("Boss", 1);
		Bureaucrat worker("Worker", 100);

		Form easy("Easy", 150, 150);
		Form medium("Medium", 80, 80);

		std::cout << boss << std::endl;
		std::cout << worker << std::endl;

		std::cout << easy << std::endl;
		std::cout << medium << std::endl;

		std::cout << "\n-- worker signs Easy (should succeed) --\n";
		worker.signForm(easy);

		std::cout << "\n-- worker signs Medium (should fail) --\n";
		worker.signForm(medium);

		std::cout << "\n-- boss signs Medium (should succeed) --\n";
		boss.signForm(medium);

		std::cout << "\nAfter signing:\n";
		std::cout << easy << std::endl;
		std::cout << medium << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}
}

/**
 * @brief Tests Form copy constructor and assignment operator
 */
static void	testFormCopyAndAssignment(void)
{
	std::cout << "\n=== Form: copy + assignment (assignment copies signed state only) ===\n";
	try
	{
		Form a("A", 10, 20);
		Form b("B", 100, 120);

		std::cout << "before sign a: " << a << std::endl;
		std::cout << "before assign b: " << b << std::endl;

		Bureaucrat signer("Signer", 1);
		signer.signForm(a);
		std::cout << "after sign a:  " << a << std::endl;

		Form copy(a);
		std::cout << "copy:          " << copy << std::endl;

		b = a;
		std::cout << "after assign b:" << b << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}
}

/**
 * @brief Entry point - runs all ex01 tests
 * @return 0 on success
 */
int	main(void)
{
	testFormValidCreation();
	testFormInvalidCreation();
	testFormBeSigned();
	testBureaucratSignForm();
	testFormCopyAndAssignment();
	return (0);
}
