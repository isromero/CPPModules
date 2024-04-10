/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:54:28 by isromero          #+#    #+#             */
/*   Updated: 2024/04/10 21:20:44 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int N = 5;

	Zombie *horde = zombieHorde(N, "Juan");
	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete[] horde;
}
