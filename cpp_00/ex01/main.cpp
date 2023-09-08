/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classes.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 20:37:18 by isromero          #+#    #+#             */
/*   Updated: 2023/09/03 20:37:18 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
  PhoneBook phoneBook;
  std::string input;

  while (1)
  {
    std::cout << "Choose: [ADD, SEARCH or EXIT]: ";
    if (!std::getline(std::cin, input) || input == "EXIT")
      return 0;
    if (input == "ADD")
      phoneBook.Add();
    else if (input == "SEARCH")
      phoneBook.Search();
  }
  return 0;
}
