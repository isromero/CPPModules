/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 13:45:35 by isromero          #+#    #+#             */
/*   Updated: 2024/04/14 20:12:39 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl
{
public:
	Harl();
	~Harl();
	void complain(std::string const &level);

private:
	void debug();
	void info();
	void warning();
	void error();
	// Creamos un alias llamado functionPtr que servirá para
	// apuntar a cualquier función de Harl, y sin argumentos
	typedef void (Harl::*functionPtr)();
};

#endif
