/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 12:54:59 by isromero          #+#    #+#             */
/*   Updated: 2024/04/28 13:44:35 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("unknown")
{
	std::cout << "A WrongAnimal was created" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : _type(other._type)
{
	std::cout << "A WrongAnimal copy was created" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
		this->_type = other._type;
	std::cout << "WrongAnimal type: " << this->_type << " = "
			  << "WrongAnimal type: " << other._type << std::endl;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "A WrongAnimal was destroyed" << std::endl;
}

const std::string &WrongAnimal::getType() const
{
	return (this->_type);
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal " << this->_type << " made an unknown sound" << std::endl;
}
