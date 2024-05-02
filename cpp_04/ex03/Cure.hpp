/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:44:17 by isromero          #+#    #+#             */
/*   Updated: 2024/05/02 11:01:20 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria, public ICharacter
{
public:
	Cure();
	Cure(Cure const &other);
	Cure &operator=(Cure const &other);
	~Cure();

	AMateria *clone() const;
	void use(ICharacter &target);
}

#endif
