/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:54:35 by isromero          #+#    #+#             */
/*   Updated: 2024/04/10 20:53:54 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
public:
	Zombie(std::string name);
	~Zombie();
	void announce();

private:
	std::string _name;
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif
