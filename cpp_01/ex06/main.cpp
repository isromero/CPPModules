/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:34:30 by isromero          #+#    #+#             */
/*   Updated: 2024/04/14 20:04:27 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#include "Harl.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: Usage: ./harl <DEBUG|INFO|WARNING|ERROR>" << std::endl;
		return (1);
	}
	Harl harl;
	harl.complain(argv[1]);
	return (0);
}
