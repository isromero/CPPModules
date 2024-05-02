/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:21:18 by isromero          #+#    #+#             */
/*   Updated: 2024/05/02 11:38:23 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	std::cout << "Character was created" << std::endl;
}

Character::Character(Character const &other) : _name(other._name)
{
	std::cout << "Character copy was created" << std::endl;
}

Character &Character::operator=(Character const &other)
{
	if (this != &other)
		this->_name = other._name;
	std::cout << "Character name: " << this->_name << " = "
			  << "Character name: " << other._name << std::endl;
	return (*this);
}

Character::~Character()
{
	std::cout << "Character was destroyed" << std::endl;
}

std::string const &Character::getName() const
{
	return (this->_name);
}
