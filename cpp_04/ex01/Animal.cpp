/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 12:54:59 by isromero          #+#    #+#             */
/*   Updated: 2024/04/28 13:44:35 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("unknown")
{
	std::cout << "An Animal was created" << std::endl;
}

Animal::Animal(const Animal &other) : _type(other._type)
{
	std::cout << "An Animal copy was created" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	if (this != &other)
		this->_type = other._type;
	std::cout << "Animal type: " << this->_type << " = "
			  << "Animal type: " << other._type << std::endl;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "An Animal was destroyed" << std::endl;
}

const std::string &Animal::getType() const
{
	return (this->_type);
}

void Animal::makeSound() const
{
	std::cout << "Animal " << this->_type << " made an unknown sound" << std::endl;
}
