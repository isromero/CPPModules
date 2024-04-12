/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:34:44 by isromero          #+#    #+#             */
/*   Updated: 2024/04/12 21:04:40 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
public:
	HumanA(std::string const &name, Weapon &weapon);
	~HumanA();
	void attack() const;

private:
	std::string _name;
	// Utilizamos una referencia para que sea más eficiente y podamos
	// tener una misma instancia de weapon compartida con la misma
	// referencia entre muchos HumanA, evitando copias innecesarias
	Weapon &_weapon;
};

#endif
