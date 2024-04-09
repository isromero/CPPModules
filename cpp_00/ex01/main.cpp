/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 20:25:08 by isromero          #+#    #+#             */
/*   Updated: 2024/04/08 20:38:20 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

int main()
{
	PhoneBook phoneBook;
	std::string input;

	while (1)
	{
		std::cout << "Enter a command: ADD, SEARCH or EXIT -> ";
		if (!std::getline(std::cin, input) || input == "EXIT")
			break;
		else if (input == "ADD")
			phoneBook.addContact();
		else if (input == "SEARCH")
			phoneBook.searchContact();
		else
			std::cout << "Command: " << input << " does not exist" << std::endl;
	}
	return (0);
}
