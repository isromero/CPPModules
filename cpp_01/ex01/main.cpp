/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:20:46 by isromero          #+#    #+#             */
/*   Updated: 2023/09/09 12:20:46 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
  int N = 5;
  Zombie *horde = zombieHorde(N, "Juan");

  for (int i = 0; i < N; i++)
    horde[i].announce();
  delete[] horde;
  return 0;
}