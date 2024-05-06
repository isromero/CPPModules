/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 13:07:51 by isromero          #+#    #+#             */
/*   Updated: 2024/05/05 13:17:38 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", false, 25, 5), _target("default")
{
	std::cout << "PresidentialPardonForm"
			  << " was created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm("PresidentialPardonForm", false, 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm"
			  << " was created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other), _target(other._target)
{
	std::cout << "PresidentialPardonForm"
			  << " copy created" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	std::cout << "PresidentialPardonForm"
			  << " = " << other.getName() << std::endl;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm"
			  << " was destroyed" << std::endl;
}

void PresidentialPardonForm::performExecution() const
{
	std::cout << this->_target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
