/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 13:34:51 by isromero          #+#    #+#             */
/*   Updated: 2023/09/09 13:34:51 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
public:
  HumanB(const std::string& name) : name(name) {}
  ~HumanB(void) {}

  void attack(void);

  void setWeapon(Weapon &weapon);

private:
  Weapon *weapon; // We don't know if it's going to exists, so we use * (can be NULL)
  std::string name;
};

#endif