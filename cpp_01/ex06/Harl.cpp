/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 21:22:45 by isromero          #+#    #+#             */
/*   Updated: 2023/09/12 21:22:45 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void)
{
  std::cout << "[ DEBUG ]" << std::endl;
  std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-picklespecial-ketchup burger. I really do!" << std::endl << std::endl;
}

void Harl::info(void)
{
  std::cout << "[ INFO ]" << std::endl;
  std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl << std::endl;
}

void Harl::warning(void)
{
  std::cout << "[ WARNING ]" << std::endl;
  std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl << std::endl;
}

void Harl::error(void)
{
  std::cout << "[ ERROR ]" << std::endl;
  std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
}

void Harl::complain(std::string level)
{
  t_func funcs[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
  std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
  int found = 0;

  for (int i = 0; i < 4; i++)
  {
    if (levels[i] == level)
    {
      found = 1;
      switch (i)
      {
        case 0:
          for (int j = 0; j < 4; j++)
            (this->*funcs[j])();
          break;
        case 1:
          for (int j = 1; j < 4; j++)
            (this->*funcs[j])();
          break;
        case 2:
          for (int j = 2; j < 4; j++)
            (this->*funcs[j])();
          break;
        case 3:
          (this->*funcs[3])();
          break;
        default:
          break ;
      }
      break ;
    }
  }
  if (!found)
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}
