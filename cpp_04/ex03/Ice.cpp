/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:52:59 by isromero          #+#    #+#             */
/*   Updated: 2024/05/02 11:20:19 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	this->_name = "ice";
	this->_idx = 0;
	std::cout << "Ice was created" << std::endl;
}

Ice::Ice(Ice const &other) : AMateria(other)
{
	std::cout << "Ice copy was created" << std::endl;
}

Ice &Ice::operator=(Ice const &other)
{
	if (this != &other)
		AMateria::operator=(other);
	std::cout << "Ice = Ice" << std::endl;
	return (*this);
}

Ice::~Ice()
{
	std::cout << "Ice was destroyed" << std::endl;
}

AMateria *Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
