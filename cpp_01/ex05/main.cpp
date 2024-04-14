/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:34:30 by isromero          #+#    #+#             */
/*   Updated: 2024/04/14 20:25:32 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#include "Harl.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error: Usage: " << argv[0] << " <complain_level> [<complain_level> ...]" << std::endl;
		return (1);
	}
	Harl harl;

	for (int i = 1; i < argc; i++)
		harl.complain(argv[i]);
	return (0);
}
