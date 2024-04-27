/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 09:43:05 by isromero          #+#    #+#             */
/*   Updated: 2024/04/27 11:06:10 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

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
}
