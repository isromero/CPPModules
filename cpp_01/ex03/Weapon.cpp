/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 13:34:28 by isromero          #+#    #+#             */
/*   Updated: 2023/09/09 13:34:28 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

const std::string &Weapon::getType() const
{
    return this->type;
}

void Weapon::setType(const std::string &type)
{
    this->type = type;
}
