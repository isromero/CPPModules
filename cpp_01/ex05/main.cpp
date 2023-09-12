/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:18:38 by isromero          #+#    #+#             */
/*   Updated: 2023/09/09 18:18:38 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
  std::string args;
  Harl harl;
  std::cout << "Enter a [level]: <DEBUG> <INFO> <WARNING> <ERROR>: ";
  std::cin >> args;
  harl.complain(args);
  return 0;
}
