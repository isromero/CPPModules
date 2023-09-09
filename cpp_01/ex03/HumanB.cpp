/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 13:34:47 by isromero          #+#    #+#             */
/*   Updated: 2023/09/09 13:34:47 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void HumanB::setWeapon(Weapon &weapon)
{
  this->weapon = &weapon;
}

void HumanB::attack(void)
{
  std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}