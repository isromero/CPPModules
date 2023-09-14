/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 21:04:19 by isromero          #+#    #+#             */
/*   Updated: 2023/09/14 21:04:19 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
public:
  Fixed() : value(0) {}
  ~Fixed() {}
  Fixed(const Fixed &copy) : value(copy.value) {}
  Fixed &operator=(const Fixed &other);

  int getRawBits() const;
  void setRawBits(int const raw);

private:
  int value;
  static const int rawBits = 8;

};

#endif