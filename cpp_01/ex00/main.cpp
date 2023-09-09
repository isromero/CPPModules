/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 18:53:43 by isromero          #+#    #+#             */
/*   Updated: 2023/09/08 18:53:43 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
  randomChump("randomChumpZombie");
  Zombie *z1 = newZombie("Juan");
  Zombie *z2 = newZombie("María");
  z1->announce();
  z2->announce();
  delete z1;
  delete z2;
  return 0;
}
