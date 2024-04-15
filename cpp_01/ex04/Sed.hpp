/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:39:58 by isromero          #+#    #+#             */
/*   Updated: 2024/04/15 19:48:48 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
#define SED_HPP

#include <iostream>
#include <fstream>
#include <string>

class Sed
{
public:
	Sed();
	~Sed();
	std::string const &replaceContent(std::string &content, std::string const &s1, std::string const &s2);
};

#endif
