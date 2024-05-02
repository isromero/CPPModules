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

Dog::Dog() : AAnimal()
{
	this->_type = "Dog";
	this->_brain = new Brain();
	std::cout << "A Dog was created" << std::endl;
}

// Evitamos copias superficiales creando un nuevo cerebro al copiar
Dog::Dog(const Dog &other) : AAnimal(other), _brain(new Brain(*other._brain))
{
	std::cout << "A Dog copy was created" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		AAnimal::operator=(other);
		// Creamos un nuevo cerebro y eliminamos el anterior para evitar copias superficiales
		Brain *newBrain = new Brain(*other._brain);
		delete this->_brain;
		this->_brain = newBrain;
	}
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

void Dog::changeIdea(const std::string &newIdea, int index)
{
	this->_brain->changeIdea(newIdea, index);
}

void Dog::printBrain() const
{
	this->_brain->printBrain();
}
