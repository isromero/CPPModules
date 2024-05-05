/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:10:28 by isromero          #+#    #+#             */
/*   Updated: 2024/05/05 10:58:47 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default name"), _isSigned(false), _gradeRequiredToSign(1), _gradeRequiredToExecute(1)
{
	std::cout << "Form " << this->_name << " was created" << std::endl;
}

Form::Form(std::string const name, bool isSigned, int const gradeRequiredToSign, int const gradeRequiredToExecute) : _name(name), _isSigned(isSigned), _gradeRequiredToSign(gradeRequiredToSign), _gradeRequiredToExecute(gradeRequiredToExecute)
{
	if (this->_gradeRequiredToSign < 1 || this->_gradeRequiredToExecute < 1)
		throw Form::GradeTooHighException();
	else if (this->_gradeRequiredToSign > 150 || this->_gradeRequiredToExecute > 150)
		throw Form::GradeTooLowException();
	std::cout << "Form " << this->_name << " was created" << std::endl;
}

Form::Form(const Form &other) : _name(other._name), _isSigned(other._isSigned), _gradeRequiredToSign(other._gradeRequiredToSign), _gradeRequiredToExecute(other._gradeRequiredToExecute)
{
	std::cout << "Form " << this->_name << " copy created" << std::endl;
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
		this->_isSigned = other._isSigned;
	std::cout << "Form " << this->_name << " = " << other._name << std::endl;
	return (*this);
}

Form::~Form()
{
	std::cout << "Form " << this->_name << " was destroyed" << std::endl;
}

std::string const &Form::getName() const
{
	return (this->_name);
}

bool const &Form::getIsSigned() const
{
	return (this->_isSigned);
}

int const &Form::getGradeRequiredToSign() const
{
	return (this->_gradeRequiredToSign);
}

int const &Form::getGradeRequiredToExecute() const
{
	return (this->_gradeRequiredToExecute);
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_gradeRequiredToSign)
		this->_isSigned = true;
	else
		throw Form::GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade Too High!");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low!");
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << "Form name: " << form.getName() << std::endl
	   << "Form isSigned: " << form.getIsSigned() << std::endl
	   << "Form gradeRequiredToSign: " << form.getGradeRequiredToSign() << std::endl
	   << "Form gradeRequiredToExecute: " << form.getGradeRequiredToExecute();
	return (os);
}
