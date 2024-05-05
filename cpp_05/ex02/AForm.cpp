/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:10:28 by isromero          #+#    #+#             */
/*   Updated: 2024/05/05 10:58:47 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Default name"), _isSigned(false), _gradeRequiredToSign(1), _gradeRequiredToExecute(1)
{
	std::cout << "AForm " << this->_name << " was created" << std::endl;
}

AForm::AForm(std::string const name, bool isSigned, int const gradeRequiredToSign, int const gradeRequiredToExecute) : _name(name), _isSigned(isSigned), _gradeRequiredToSign(gradeRequiredToSign), _gradeRequiredToExecute(gradeRequiredToExecute)
{
	if (this->_gradeRequiredToSign < 1 || this->_gradeRequiredToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (this->_gradeRequiredToSign > 150 || this->_gradeRequiredToExecute > 150)
		throw AForm::GradeTooLowException();
	std::cout << "AForm " << this->_name << " was created" << std::endl;
}

AForm::AForm(const AForm &other) : _name(other._name), _isSigned(other._isSigned), _gradeRequiredToSign(other._gradeRequiredToSign), _gradeRequiredToExecute(other._gradeRequiredToExecute)
{
	std::cout << "AForm " << this->_name << " copy created" << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
		this->_isSigned = other._isSigned;
	std::cout << "AForm " << this->_name << " = " << other._name << std::endl;
	return (*this);
}

AForm::~AForm()
{
	std::cout << "AForm " << this->_name << " was destroyed" << std::endl;
}

std::string const &AForm::getName() const
{
	return (this->_name);
}

bool const &AForm::getIsSigned() const
{
	return (this->_isSigned);
}

int const &AForm::getGradeRequiredToSign() const
{
	return (this->_gradeRequiredToSign);
}

int const &AForm::getGradeRequiredToExecute() const
{
	return (this->_gradeRequiredToExecute);
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_gradeRequiredToSign)
		this->_isSigned = true;
	else
		throw AForm::GradeTooLowException();
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!this->_isSigned)
		throw FormNotSignedException();
	if (executor.getGrade() > this->_gradeRequiredToExecute)
		throw GradeTooLowException();
	performExecution();
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade Too High!");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low!");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("Form not signed!");
}

std::ostream &operator<<(std::ostream &os, const AForm &AForm)
{
	os << "AForm name: " << AForm.getName() << std::endl
	   << "AForm isSigned: " << AForm.getIsSigned() << std::endl
	   << "AForm gradeRequiredToSign: " << AForm.getGradeRequiredToSign() << std::endl
	   << "AForm gradeRequiredToExecute: " << AForm.getGradeRequiredToExecute();
	return (os);
}
