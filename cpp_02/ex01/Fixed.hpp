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
#include <cmath>

class Fixed
{
public:
  Fixed() : value(0) 
  {
    std::cout << "Default constructor called" << std::endl;
  }
  ~Fixed()
  {
    std::cout << "Destructor called" << std::endl;
  }
  
  Fixed(const Fixed &copy) : value(copy.value)
  {
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
  } 
  /* Esto se hace así para que no se modifique el valor de la variable original en el 
  caso de que se modifique con alguna asignación dinámica */

  Fixed &operator=(const Fixed &other)
  {
    std::cout << "Assignation operator called" << std::endl;
    if (this != &other)
      this->value = other.getRawBits();
    return *this;
  }
  /* Esto es muy parecido al constructor de copia, pero en este caso se devuelve el objeto en 
  sí garantizando que el objeto original libere cualquier recurso que tenga asignado antes 
  de copiar el valor del nuevo objeto */

  Fixed(const int intValue) : value(intValue << fractionalBits)
  {
    std::cout << "Int constructor called" << std::endl;
  }
  
  Fixed(const float floatValue) : value(roundf(floatValue * (1 << fractionalBits)))
  {
    std::cout << "Float constructor called" << std::endl;
  }

  int getRawBits() const;
  void setRawBits(int const raw);

  float toFloat(void) const;
  int toInt(void) const;

private:
  int value;
  static const int fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &stream, const Fixed &value);

#endif
