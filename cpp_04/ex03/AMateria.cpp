/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:32:24 by isromero          #+#    #+#             */
/*   Updated: 2024/05/02 10:54:45 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) : _type(type)
{
	std::cout << "AMateria was created" << std::endl;
}

AMateria::AMateria(AMateria const &other) : _type(other._type)
{
	std::cout << "AMateria copy was created" << std::endl;
}

AMateria &AMateria::operator=(AMateria const &other)
{
	if (this != &other)
		this->_type = other._type;
	std::cout << "Materia type: " << this->_type << " = "
			  << "Materia type: " << other._type << std::endl;
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "AMateria was destroyed" << std::endl;
}

std::string const &AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter &target)
{
	std::cout << "This is a generic use for AMateria" << std::endl;
}
