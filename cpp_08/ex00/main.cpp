/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:53:22 by isromero          #+#    #+#             */
/*   Updated: 2024/06/12 21:34:35 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	/* Bloque que encuentra elemento */
	{
		try
		{
			std::vector<int> vec; // Se puede utilizar cualquier contenedor que tenga iteradores
								  // (en este caso vector puede ser más eficiente que list ya que no vamos a insertar o borrar elementos, solo buscarlos)
			for (int i = 0; i < 43; i++)
				vec.push_back(i);
			int res = ::easyfind(vec, 42);
			std::cout << res << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Element not found" << std::endl;
		}
	}
	/* Bloque que no encuentra elemento */
	{
		try
		{
			std::vector<int> vec;
			for (int i = 0; i < 42; i++)
				vec.push_back(i);
			int res = ::easyfind(vec, 42);
			std::cout << res << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Element not found" << std::endl;
		}
	}
	return (0);
}
