/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:34:44 by isromero          #+#    #+#             */
/*   Updated: 2024/04/12 20:58:31 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon
{
public:
	Weapon(std::string const &type);
	~Weapon();
	const std::string &getType() const;
	void setType(std::string const &type);

private:
	std::string _type;
};

#endif
