/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 09:43:05 by isromero          #+#    #+#             */
/*   Updated: 2024/04/27 13:04:08 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	ClapTrap Juan("Juan");

	Juan.attack("Miguel");
	Juan.takeDamage(3);
	Juan.attack("UltraMiguel");
	Juan.takeDamage(4);
	Juan.beRepaired(1);
	Juan.attack("MegaMiguel");
	Juan.attack("MiniMiguel");
	Juan.attack("ChiquiMiguel");
	Juan.attack("MiniMiguel");
	Juan.attack("MiniMiguel");
	Juan.attack("MiniMiguel");
	Juan.attack("UltraMiguel");
	Juan.takeDamage(4);
	Juan.attack("MiniMiguel");
	Juan.takeDamage(1);

	ScavTrap Juanito("Juanito");

	Juanito.attack("Miguel");
	Juanito.takeDamage(3);
	Juanito.attack("UltraMiguel");
	Juanito.takeDamage(4);
	Juanito.beRepaired(1);
	Juanito.attack("MegaMiguel");
	Juanito.attack("MiniMiguel");
	Juanito.attack("ChiquiMiguel");
	Juanito.attack("MiniMiguel");
	Juanito.attack("MiniMiguel");
	Juanito.attack("MiniMiguel");
	Juanito.attack("UltraMiguel");
	Juanito.takeDamage(4);
	Juanito.attack("MiniMiguel");
	Juanito.takeDamage(1);
	Juanito.guardGate();

	FragTrap Juanote("Juanote");

	Juanote.attack("Miguel");
	Juanote.takeDamage(3);
	Juanote.attack("UltraMiguel");
	Juanote.takeDamage(4);
	Juanote.beRepaired(1);
	Juanote.attack("MegaMiguel");
	Juanote.attack("MiniMiguel");
	Juanote.attack("ChiquiMiguel");
	Juanote.attack("MiniMiguel");
	Juanote.attack("MiniMiguel");
	Juanote.attack("MiniMiguel");
	Juanote.attack("UltraMiguel");
	Juanote.takeDamage(4);
	Juanote.attack("MiniMiguel");
	Juanote.takeDamage(1);
	Juanote.highFivesGuys();

	DiamondTrap Juanita("Juanita");

	Juanita.attack("Miguel");
	Juanita.takeDamage(3);
	Juanita.attack("UltraMiguel");
	Juanita.takeDamage(4);
	Juanita.beRepaired(1);
	Juanita.attack("MegaMiguel");
	Juanita.attack("MiniMiguel");
	Juanita.attack("ChiquiMiguel");
	Juanita.attack("MiniMiguel");
	Juanita.attack("MiniMiguel");
	Juanita.attack("MiniMiguel");
	Juanita.attack("UltraMiguel");
	Juanita.takeDamage(4);
	Juanita.attack("MiniMiguel");
	Juanita.takeDamage(1);
	Juanita.whoAmI();

	return (0);
}
