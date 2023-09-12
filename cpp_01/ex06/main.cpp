/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 21:22:37 by isromero          #+#    #+#             */
/*   Updated: 2023/09/12 21:22:37 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
  Harl harl;
  if (argc == 2)
    harl.complain(argv[1]);
  else
    std::cout << "Usage: ./harlFilter <level>" << std::endl;
  return 0;
}
