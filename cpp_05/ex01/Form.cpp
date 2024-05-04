/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:10:28 by isromero          #+#    #+#             */
/*   Updated: 2024/05/04 11:34:56 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default name"), _isSigned(false), _gradeRequiredToSign(1), _gradeRequiredToExecute(1)
{
	std::cout << "Form " << this->_name << "was created" << std::endl;
}

Form::Form(std::string const name, bool isSigned, int const gradeRequiredToSign, int const gradeRequiredToExecute) : _name(name), _isSigned(isSigned), _gradeRequiredToSign(gradeRequiredToSign), _gradeRequiredToExecute(gradeRequiredToExecute)
{
	std::cout << "Form " << this->_name << "was created" << std::endl;
}

Form::Form(const Form &other) : _name(other._name), _isSigned(other._isSigned), _gradeRequiredToSign(other._gradeRequiredToSign), _gradeRequiredToExecute(other._gradeRequiredToExecute)
{
	std::cout << "Form " << this->_name << "copy created" << std::endl;
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_isSigned = other._isSigned;
		this->_gradeRequiredToSign = other._gradeRequiredToSign;
		this->_gradeRequiredToExecute = other._gradeRequiredToExecute;
	}
	std::cout << "Form " << this->_name << " = " << other._name << std::endl;
	return (*this);
}

Form::~Form()
{
	std::cout << "Form " << this->_name << "was destroyed" << std::endl;
}

std::string &Form::getName() const
{
	return (this->_name);
}

bool &Form::getIsSigned() const
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

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << "Form name: " << form.getName() << std::endl
	   << "Form grade: " << form.getGrade() << std::endl
	   << "Form isSigned: " << form.getIsSigned() << std::endl
	   << "Form gradeRequiredToSign: " << form.getGradeRequiredToSign() << std::endl
	   << "Form gradeRequiredToExecute: " << form.getGradeRequiredToExecute() << std::endl;
	return (os);
}
