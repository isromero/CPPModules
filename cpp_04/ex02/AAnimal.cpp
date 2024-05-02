/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 12:54:59 by isromero          #+#    #+#             */
/*   Updated: 2024/05/02 08:50:14 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("unknown")
{
	std::cout << "An AAnimal was created" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other) : _type(other._type)
{
	std::cout << "An AAnimal copy was created" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
	if (this != &other)
		this->_type = other._type;
	std::cout << "AAnimal type: " << this->_type << " = "
			  << "AAnimal type: " << other._type << std::endl;
	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << "An AAnimal was destroyed" << std::endl;
}

const std::string &AAnimal::getType() const
{
	return (this->_type);
}
