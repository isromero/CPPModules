/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 12:54:59 by isromero          #+#    #+#             */
/*   Updated: 2024/04/28 13:09:13 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->_type = "Dog";
	this->_brain = new Brain();
	std::cout << "A Dog was created" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "A Dog copy was created" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
		Animal::operator=(other);
	std::cout << "Dog type: " << this->_type << " = "
			  << "Dog type: " << other._type << std::endl;
	return (*this);
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << "A Dog was destroyed" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Guau guau" << std::endl;
}
