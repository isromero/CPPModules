/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 08:42:45 by isromero          #+#    #+#             */
/*   Updated: 2024/05/02 09:05:28 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : AAnimal()
{
	this->_type = "Cat";
	this->_brain = new Brain();
	std::cout << "A Cat was created" << std::endl;
}

// Evitamos copias superficiales creando un nuevo cerebro al copiar
Cat::Cat(const Cat &other) : AAnimal(other), _brain(new Brain(*other._brain))
{
	std::cout << "A Cat copy was created" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		AAnimal::operator=(other);
		// Creamos un nuevo cerebro y eliminamos el anterior para evitar copias superficiales
		Brain *newBrain = new Brain(*other._brain);
		delete this->_brain;
		this->_brain = newBrain;
	}
	std::cout << "Cat type: " << this->_type << " = "
			  << "Cat type: " << other._type << std::endl;
	return (*this);
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << "A Cat was destroyed" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Miau miau" << std::endl;
}

void Cat::changeIdea(const std::string &newIdea, int index)
{
	this->_brain->changeIdea(newIdea, index);
}

void Cat::printBrain() const
{
	this->_brain->printBrain();
}
