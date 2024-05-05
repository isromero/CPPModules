/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 09:43:05 by isromero          #+#    #+#             */
/*   Updated: 2024/05/05 11:01:03 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat bureaucrat(1, "Juan el burócrata");
		Form form("Papelito", false, 1, 1);

		std::cout << bureaucrat << std::endl;
		std::cout << form << std::endl;

		bureaucrat.signForm(form);
		std::cout << form.getIsSigned() << std::endl;

		Bureaucrat bureaucrat2(150, "Pepe el burócrata");
		Form form2("Papelito2", false, 140, 140);

		std::cout << bureaucrat2 << std::endl;
		std::cout << form2 << std::endl;

		bureaucrat2.signForm(form2);
		std::cout << form2.getIsSigned() << std::endl;
	}
	catch (std::exception &error)
	{
		std::cerr << error.what() << std::endl;
	}
	return (0);
}
