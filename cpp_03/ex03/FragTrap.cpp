/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 11:36:32 by isromero          #+#    #+#             */
/*   Updated: 2024/04/27 13:00:45 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap " << this->_name << " was created" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap " << this->_name << " copy created" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << "FragTrap " << this->_name << " = " << other._name << std::endl;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->_name << " was destroyed" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
	if (this->_hitPoints > 0 && this->_energyPoints > 0)
	{
		this->_energyPoints--;
		std::cout << "FragTrap " << this->_name << " attacks " << target << " causing "
				  << this->_attackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << "FragTrap " << this->_name << " doesn't have enough energy or hit points to attack" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << this->_name << " requests a positive high five" << std::endl;
}
