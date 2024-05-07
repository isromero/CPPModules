/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 09:43:05 by isromero          #+#    #+#             */
/*   Updated: 2024/05/07 20:30:42 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	try
	{
		Intern someRandomIntern;

		someRandomIntern.makeForm("robotomy request", "Bender");
		someRandomIntern.makeForm("shrubbery creation", "Bender");
		someRandomIntern.makeForm("presidential pardon", "Bender");

		someRandomIntern.makeForm("robotomy requestfefefe", "Bender");

		AForm *form = someRandomIntern.makeForm("robotomy request", "Bender");
		Bureaucrat bureaucrat(1, "bureaucrat");

		bureaucrat.signForm(*form);
		bureaucrat.executeForm(*form);
		delete form;
	}
	catch (std::exception &error)
	{
		std::cerr << error.what() << std::endl;
	}
	return (0);
}
