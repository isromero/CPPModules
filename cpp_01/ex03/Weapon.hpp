/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 13:34:02 by isromero          #+#    #+#             */
/*   Updated: 2023/09/09 13:34:02 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
public:
  Weapon(const std::string &type) : type(type) {}
  ~Weapon(void) {}

  const std::string &getType() const;

  void setType(const std::string &type);

private:
  std::string type;
};

#endif
