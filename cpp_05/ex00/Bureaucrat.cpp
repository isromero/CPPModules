/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 09:48:11 by isromero          #+#    #+#             */
/*   Updated: 2024/04/27 11:06:32 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Best Bureaucrat"), _grade(1)
{
	std::cout << "Bureaucrat " << this->_name << " with grade: " << this->_grade << " was created" << std::endl;
}

Bureaucrat::Bureaucrat(int grade, const std::string &name) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << "Bureaucrat " << this->_name << " with grade: " << this->_grade << " was created" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
	std::cout << "Bureaucrat " << this->_name << " with grade: " << this->_grade << " copy created" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		this->_grade = other._grade;
	std::cout << "Bureaucrat " << this->_name << " = " << other._name << std::endl;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << this->_name << " with grade: " << this->_grade << " was destroyed" << std::endl;
}

std::string const &Bureaucrat::getName() const
{
	return (this->_name);
}

int const &Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::incrementGrade()
{
	if (this->_grade == 1)
		throw GradeTooLowException();
	this->_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->_grade == 150)
		throw GradeTooLowException();
	this->_grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade Too High!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low!");
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureucrat grade " << bureaucrat.getGrade() << std::endl;
	return (os);
}
