/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 09:43:05 by isromero          #+#    #+#             */
/*   Updated: 2024/05/06 20:57:46 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat bureaucrat(1, "bureaucrat");

		AForm *robotomy = new RobotomyRequestForm("targetttt");
		AForm *shrubbery = new ShrubberyCreationForm("targetttt");
		AForm *presidential = new PresidentialPardonForm("targetttt");

		std::cout << *robotomy << std::endl;
		std::cout << *shrubbery << std::endl;
		std::cout << *presidential << std::endl;

		bureaucrat.signForm(*robotomy);
		bureaucrat.signForm(*shrubbery);
		bureaucrat.signForm(*presidential);

		bureaucrat.executeForm(*robotomy);
		bureaucrat.executeForm(*shrubbery);
		bureaucrat.executeForm(*presidential);

		delete robotomy;
		delete shrubbery;
		delete presidential;

		AForm *robotomy2 = new RobotomyRequestForm("targetttt2");

		bureaucrat.signForm(*robotomy2);
		bureaucrat.signForm(*robotomy2);

		bureaucrat.incrementGrade();

		// No llegaría hasta aquí por el incrementGrade la exception que lanza
		bureaucrat.executeForm(*robotomy2);

		delete robotomy2;
	}
	catch (std::exception &error)
	{
		std::cerr << error.what() << std::endl;
	}
	return (0);
}
