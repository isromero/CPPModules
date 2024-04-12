/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:35:28 by isromero          #+#    #+#             */
/*   Updated: 2024/04/12 20:58:24 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string const &type) : _type(type)
{
}

Weapon::~Weapon()
{
}

const std::string &Weapon::getType() const
{
	return (this->_type);
}

void Weapon::setType(const std::string &type)
{
	this->_type = type;
}
