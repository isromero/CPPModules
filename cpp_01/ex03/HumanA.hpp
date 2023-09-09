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

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
public:
  HumanA(const std::string &name, Weapon &weapon) : weapon(weapon), name(name) {}
  ~HumanA(void) {}

  void attack();

private:
  Weapon &weapon; // We know that is going to exist so we use & (reference needs to exist)
  std::string name;
};

#endif