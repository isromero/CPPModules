/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:34:44 by isromero          #+#    #+#             */
/*   Updated: 2024/04/12 21:17:26 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
public:
	HumanB(std::string const &name);
	~HumanB();
	void attack() const;
	void setWeapon(Weapon &weapon);

private:
	std::string _name;
	// Ya que es posible a veces que no esté armado utilizamos un puntero.
	// De esta manera podemos inicializar _weapon en NULL, es decir,
	// cuando un objeto es opcional. Es muy útil utilizar punteros en estos casos
	// de opcionalidad para  en un futuro apuntar a una instancia de weapon
	// y tener a HumanB armado. Esto se debe a que no estamos tratando con una
	// instancia real del objeto, sino con el puntero.
	// (Una instancia objeto no puede ser NULL)
	Weapon *_weapon;
};

#endif
