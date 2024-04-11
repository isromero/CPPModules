/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:34:44 by isromero          #+#    #+#             */
/*   Updated: 2024/04/11 18:42:49 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Weapon
{
public:
	Weapon();
	~Weapon();
	const std::string &getType() const;
	void setType(const std::string &type);

private:
	std::string _type;
}
