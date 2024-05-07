/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 21:08:12 by isromero          #+#    #+#             */
/*   Updated: 2024/05/07 20:29:00 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern was created" << std::endl;
}

Intern::Intern(const Intern &other)
{
	(void)other;
	std::cout << "Intern copy was created" << std::endl;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	std::cout << "Intern = Intern" << std::endl;
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern was destroyed" << std::endl;
}

AForm *Intern::makeForm(std::string const &formName, std::string const &target)
{
	struct Form
	{
		std::string name;
		AForm *(*create)(std::string const &target);
	};

	Form forms[] = {
		{"presidential pardon", &PresidentialPardonForm::create},
		{"robotomy request", &RobotomyRequestForm::create},
		{"shrubbery creation", &ShrubberyCreationForm::create}};

	for (size_t i = 0; i < (sizeof(forms) / sizeof(forms[0])); i++)
	{
		if (forms[i].name == formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return forms[i].create(target);
		}
	}

	std::cerr << "Error: form not found" << std::endl;
	return (nullptr);
}
