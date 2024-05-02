/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:52:59 by isromero          #+#    #+#             */
/*   Updated: 2024/05/02 11:01:52 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("Cure")
{
	std::cout << "Cure was created" << std::endl;
}

Cure::Cure(Cure const &other) : AMateria(other)
{
	std::cout << "Cure copy was created" << std::endl;
}

Cure &Cure::operator=(Cure const &other)
{
	if (this != &other)
		AMateria::operator=(other);
	std::cout << "Cure = Cure" << std::endl;
	return (*this);
}

Cure::~Cure()
{
	std::cout << "Cure was destroyed" << std::endl;
}

AMateria Cure::*clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
