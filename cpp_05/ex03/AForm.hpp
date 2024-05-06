/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:10:40 by isromero          #+#    #+#             */
/*   Updated: 2024/05/05 10:49:46 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <fstream>

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
public:
	AForm();
	AForm(std::string const name, bool isSigned, int const gradeRequiredToSign, int const gradeRequiredToExecute);
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);
	virtual ~AForm();

	std::string const &getName() const;
	bool const &getIsSigned() const;
	int const &getGradeRequiredToSign() const;
	int const &getGradeRequiredToExecute() const;

	void beSigned(Bureaucrat &bureaucrat);

	virtual void execute(Bureaucrat const &executor) const;
	virtual void performExecution() const = 0;

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

	class FormNotSignedException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	class FormAlreadySignedException : public std::exception
	{
	public:
		const char *what() const throw();
	};

private:
	std::string const _name;
	bool _isSigned;
	int const _gradeRequiredToSign;
	int const _gradeRequiredToExecute;
};

std::ostream &operator<<(std::ostream &os, const AForm &AForm);

#endif
