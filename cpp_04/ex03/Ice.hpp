/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:44:17 by isromero          #+#    #+#             */
/*   Updated: 2024/05/02 11:20:26 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria, public ICharacter
{
public:
	Ice();
	Ice(Ice const &other);
	Ice &operator=(Ice const &other);
	~Ice();

	AMateria *clone() const;
	void use(ICharacter &target);
}

#endif
