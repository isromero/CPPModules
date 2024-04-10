/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:54:28 by isromero          #+#    #+#             */
/*   Updated: 2024/04/10 20:59:49 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	std::string name;

	std::cout << "Zombie in stack: "
			  << "Zombie name-> ";
	std::cin >> name;

	Zombie zombieStack(name);

	std::cout << "Zombie in heap: "
			  << "Zombie name-> ";
	std::cin >> name;

	Zombie *zombieHeap = newZombie(name);
	zombieHeap->announce();
	delete zombieHeap;

	std::cout << "randomChump() incoming:" << std::endl;
	randomChump("woup");
	return (0);
}
