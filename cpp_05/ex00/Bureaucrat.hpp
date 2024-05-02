/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 09:44:16 by isromero          #+#    #+#             */
/*   Updated: 2024/04/27 10:42:08 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
public:
	Bureaucrat();
	Bureaucrat(int &grade, const std::string &name);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat();

	std::string const &getName() const;
	int const &getGrade() const;

	void incrementGrade();
	void decrementGrade();

	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw();
	};

private:
	const std::string _name;
	int _grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif
