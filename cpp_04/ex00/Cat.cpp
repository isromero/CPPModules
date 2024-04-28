/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 12:54:59 by isromero          #+#    #+#             */
/*   Updated: 2024/04/28 13:09:13 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->_type = "Cat";
	std::cout << "A Cat was created" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "A Cat copy was created" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
		Animal::operator=(other);
	std::cout << "Cat type: " << this->_type << " = "
			  << "Cat type: " << other._type << std::endl;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "A Cat was destroyed" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Miau miau" << std::endl;
}
