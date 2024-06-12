/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:53:29 by isromero          #+#    #+#             */
/*   Updated: 2024/06/12 21:34:19 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>

template <typename T>
int easyfind(T &container, int integer)
{
	typename T::const_iterator it = std::find(container.begin(), container.end(), integer);
	// Como no alteramos los elementos del contenedor, usamos const_iterator, que no permite modificar los elementos (ya que es solo una búsqueda)

	if (it != container.end())
		return (*it);
	throw std::exception();
}

#endif
