/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 21:04:52 by isromero          #+#    #+#             */
/*   Updated: 2023/09/14 21:04:52 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int Fixed::getRawBits() const
{
  std::cout << "getRawBits member function called" << std::endl;
  return this->value;
}

void Fixed::setRawBits(int raw)
{
  this->value = raw;
}
