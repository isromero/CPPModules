/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 20:46:06 by isromero          #+#    #+#             */
/*   Updated: 2024/04/22 21:02:06 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed a;

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	Fixed const b(Fixed(5.05f) + Fixed(2));
	Fixed const c(Fixed(5.05f) - Fixed(2));
	Fixed const d(Fixed(5.05f) * Fixed(2));
	Fixed const e(Fixed(5.05f) / Fixed(2));

	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << e << std::endl;

	Fixed const f(Fixed(5.05f) > Fixed(2));
	Fixed const g(Fixed(5.05f) < Fixed(2));
	Fixed const h(Fixed(5.05f) >= Fixed(5.05f));
	Fixed const i(Fixed(5.05f) <= Fixed(2));
	Fixed const j(Fixed(5.05f) != Fixed(2));
	Fixed const k(Fixed(5.05f) == Fixed(2));

	std::cout << f << std::endl;
	std::cout << g << std::endl;
	std::cout << h << std::endl;
	std::cout << i << std::endl;
	std::cout << j << std::endl;
	std::cout << k << std::endl;

	/* std::cout << Fixed::max(a, b) << std::endl; */
	return (0);
}
