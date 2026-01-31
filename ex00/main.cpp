#include "Bureaucrat.hpp"

static void	printTitle(const std::string &title)
{
	std::cout << "\n=== " << title << " ===\n";
}

int	main(void)
{
	printTitle("Valid creation + operator<<");
	try
	{
		Bureaucrat a("Alice", 1);
		Bureaucrat b("Bob", 150);
		std::cout << a << std::endl;
		std::cout << b << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}
	printTitle("Invalid creation");
	try
	{
		Bureaucrat bad1("BadHigh", 0);
		std::cout << bad1 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat bad2("BadLow", 151);
		std::cout << bad2 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}
	printTitle("Increment/decrement inside bounds");
	try
	{
		Bureaucrat c("Charlie", 42);
		std::cout << c << std::endl;
		c.incrementGrade();
		std::cout << "After increment: " << c << std::endl;
		c.decrementGrade();
		std::cout << "After decrement: " << c << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}
	printTitle("Increment at highest (should throw)");
	try
	{
		Bureaucrat top("Top", 1);
		std::cout << top << std::endl;
		top.incrementGrade();
		std::cout << "This line should not print\n";
	}
	catch (std::exception &e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}
	printTitle("Decrement at lowest (should throw)");
	try
	{
		Bureaucrat low("Low", 150);
		std::cout << low << std::endl;
		low.decrementGrade();
		std::cout << "This line should not print\n";
	}
	catch (std::exception &e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}
	printTitle("Copy + assignment (assignment copies grade only)");
	try
	{
		Bureaucrat a("A", 10);
		Bureaucrat b("B", 100);
		Bureaucrat copy(a);
		std::cout << "copy: " << copy << std::endl;
		std::cout << "before assign b: " << b << std::endl;
		b = a;
		std::cout << "after assign b:  " << b << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}
	return (0);
}
