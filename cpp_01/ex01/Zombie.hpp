/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 18:49:58 by isromero          #+#    #+#             */
/*   Updated: 2023/09/08 18:49:58 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
public:
  Zombie(void) {}
  ~Zombie(void);

  void setName(std::string name);
  void announce(void);

private:
  std::string name;
};

Zombie *zombieHorde(int N, std::string name);

#endif