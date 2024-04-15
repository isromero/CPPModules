/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:42:27 by isromero          #+#    #+#             */
/*   Updated: 2024/04/15 19:49:32 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

Sed::Sed()
{
}

Sed::~Sed()
{
}

std::string const &Sed::replaceContent(std::string &content, std::string const &s1, std::string const &s2)
{
	if (s1.empty())
		return (content);
	size_t index = content.find(s1);
	while (index != std::string::npos)
	{
		content.erase(index, s1.size());
		content.insert(index, s2);
		index = content.find(s1);
	}
	return (content);
}
