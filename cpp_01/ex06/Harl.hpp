/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 21:22:53 by isromero          #+#    #+#             */
/*   Updated: 2023/09/12 21:22:53 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class Harl
{
public:
  Harl(void) {}
  ~Harl(void) {}

  void complain(std::string level);

private:
  void debug(void);
  void info(void);
  void warning(void);
  void error(void);
};

typedef void (Harl::*t_func)(void);

#endif