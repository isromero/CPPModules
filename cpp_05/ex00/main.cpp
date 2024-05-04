/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 09:43:05 by isromero          #+#    #+#             */
/*   Updated: 2024/05/04 11:09:49 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat bureaucrat(2, "Juan El Burócrata");

		std::cout << "Info: " << bureaucrat << std::endl;

		std::cout << "I am " << bureaucrat.getName() << " and I have "
				  << bureaucrat.getGrade() << " grade" << std::endl;
		bureaucrat.incrementGrade();
		std::cout << bureaucrat.getName() << ": Let's go baby" << std::endl;
		std::cout << bureaucrat.getName() << ": If you increase one more I will shout an exception. I'm not that smart."
				  << std::endl;
		bureaucrat.incrementGrade();

		// Aquí no llegará nunca porque saltará el error
		std::cout << "This is not going to happen" << std::endl;
	}
	catch (std::exception &error)
	{
		std::cerr << error.what() << std::endl;
	}
	return (0);
}
