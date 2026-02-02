# C++ Module 05 – Repetition & Exceptions 🧾⚡️

✅ **Status**: Completed – all exercises  
🏫 **School**: 42 – C++ Modules (Module 05)  
🏅 **Score**: (score)/100

> *Bureaucrats, forms, abstract interfaces, and a lot of exceptions. Repetition, validation, and clean error handling.*

---

## 📚 Table of Contents

* [Description](#-description)
* [Goals of the Module](#-goals-of-the-module)
* [Exercises Overview](#-exercises-overview)

  * [ex00 – Bureaucrat](#ex00--bureaucrat)
  * [ex01 – Forms](#ex01--forms)
  * [ex02 – AForm + Concrete Forms](#ex02--aform--concrete-forms)
  * [ex03 – Intern](#ex03--intern)
* [Requirements](#-requirements)
* [Build & Run](#-build--run)
* [Repository Layout](#-repository-layout)
* [Testing Tips](#-testing-tips)
* [42 Notes](#-42-notes)

---

## 📝 Description

This repository contains my solutions to **42’s C++ Module 05 (C++98)**.
The main focus is **exceptions + repetition of OOP fundamentals** through a small bureaucratic system:

* A `Bureaucrat` with a strict **grade range** (`1` is highest, `150` is lowest)
* Forms that require specific grades to **sign** and **execute**
* An abstract base class (`AForm`) with concrete derived forms
* An `Intern` that creates forms by name (factory-like behavior)

All exercises are written in **C++98** and compiled with strict flags.

---

## 🎯 Goals of the Module

Concepts practiced in this module include:

* Designing classes in **Orthodox Canonical Form** (constructors, copy, assignment, destructor)
* Writing and using **custom exceptions** (`GradeTooHighException`, `GradeTooLowException`, etc.)
* Defensive checks + clear failure behavior via `throw` / `try` / `catch`
* **Encapsulation** (private attributes, getters)
* **Abstract classes** and polymorphism (`AForm`)
* Separating “validation” logic from “action” logic in execution flows
* Avoiding messy if/else chains by using cleaner patterns in `Intern::makeForm()`

---

## 📦 Exercises Overview

### ex00 – Bureaucrat

**Goal:** Implement a `Bureaucrat` class with:

* `const std::string name`
* `int grade` in range **[1..150]**
* Grade changes:

  * `incrementGrade()` (e.g., 3 → 2)
  * `decrementGrade()` (e.g., 3 → 4)
* Exceptions on invalid grade:

  * `GradeTooHighException`
  * `GradeTooLowException`
* `operator<<` output format:

  * `<name>, bureaucrat grade <grade>.`

---

### ex01 – Forms

**Goal:** Add a `Form` class containing:

* `const std::string name`
* `bool isSigned` (initially `false`)
* `const int gradeToSign`
* `const int gradeToExecute`

Key behavior:

* `Form::beSigned(Bureaucrat const&)` signs if grade is high enough
* `Bureaucrat::signForm(Form&)` prints success/failure message with reason
* Exceptions:

  * `Form::GradeTooHighException`
  * `Form::GradeTooLowException`

---

### ex02 – AForm + Concrete Forms

**Goal:** Turn `Form` into an abstract base class `AForm` and implement 3 concrete forms.

Concrete forms:

* **`ShrubberyCreationForm`**
  Required grades: sign **145**, exec **137**
  Creates `<target>_shrubbery` and writes ASCII trees inside.

* **`RobotomyRequestForm`**
  Required grades: sign **72**, exec **45**
  “Drilling noises” + **50% success** robotomy.

* **`PresidentialPardonForm`**
  Required grades: sign **25**, exec **5**
  Announces pardon “by Zaphod Beeblebrox”.

Also required:

* `AForm::execute(Bureaucrat const& executor) const`
  Must check:

  * form is signed
  * executor grade is high enough
    Otherwise throw appropriate exceptions.
* `Bureaucrat::executeForm(AForm const&)` prints success or explicit error.

---

### ex03 – Intern

**Goal:** Implement an `Intern` with:

* `AForm* makeForm(std::string formName, std::string target)`
* Creates and returns the correct form based on `formName`
* Prints:

  * `Intern creates <form>`
* If unknown form name:

  * print explicit error message
* **No ugly giant if/else/else-if chain** (clean mapping approach expected)

---

## 🛠 Requirements

* **Compiler**: `c++`
* **Flags**: `-Wall -Wextra -Werror` (+ must still compile with `-std=c++98`)
* **OS**: Unix-like (Linux/macOS)
* **No external libraries** (no C++11, no Boost)
* Forbidden functions:

  * `printf()`, `malloc()`, `free()` (and similar)
* STL containers/algorithms are not allowed until later modules (08/09)

---

## ▶️ Build & Run

Clone the repository and build each exercise separately:

```bash
git clone <this-repo-url>
cd cpp-module-05
```

### ex00

```bash
cd ex00
make
./bureaucrat
```

### ex01

```bash
cd ex01
make
./bureaucracy
```

### ex02

```bash
cd ex02
make
./forms
```

### ex03

```bash
cd ex03
make
./intern
```

> Executable names may differ depending on implementation — check each `Makefile`.

---

## 📂 Repository Layout

```text
cpp-module-05/
├── ex00/
│   ├── Makefile
│   ├── main.cpp
│   ├── Bureaucrat.hpp
│   └── Bureaucrat.cpp
│
├── ex01/
│   ├── Makefile
│   ├── main.cpp
│   ├── Bureaucrat.hpp / Bureaucrat.cpp
│   ├── Form.hpp
│   └── Form.cpp
│
├── ex02/
│   ├── Makefile
│   ├── main.cpp
│   ├── Bureaucrat.hpp / Bureaucrat.cpp
│   ├── AForm.hpp / AForm.cpp
│   ├── ShrubberyCreationForm.hpp / .cpp
│   ├── RobotomyRequestForm.hpp / .cpp
│   └── PresidentialPardonForm.hpp / .cpp
│
└── ex03/
    ├── Makefile
    ├── main.cpp
    ├── Intern.hpp
    ├── Intern.cpp
    └── (all previous classes reused)
```

---

## 🔍 Testing Tips

* **Grades**

  * Try constructing bureaucrats/forms with grades `0`, `151`, etc. → must throw.
  * Test boundary values: `1` and `150`.

* **Signing**

  * A bureaucrat with insufficient grade must fail to sign and report why.
  * A sufficiently ranked bureaucrat must sign successfully.

* **Execution**

  * Executing an **unsigned** form must throw.
  * Executing with a too-low grade must throw.
  * Successful executions should print the expected messages and side effects.

* **Robotomy**

  * Run multiple times to confirm ~50% success behavior.

* **Intern**

  * Try valid names (e.g. `"robotomy request"`) and invalid names → must show explicit error.

---

## 🧾 42 Notes

* C++ modules don’t enforce **Norminette** style, but readability still matters.
* **Makefile rules are still checked** during evaluation (`all/clean/fclean/re`, no unnecessary relinking, explicit file listing, etc.).
* Don’t just “make it work”: during defense you may be asked to tweak behavior quickly, so keep your design clean and explainable.

---

If you’re a 42 student working on the same module, feel free to explore the code, get inspired, but **write your own implementation** — that’s where the real learning happens. 🚀
