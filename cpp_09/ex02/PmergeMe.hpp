/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 09:44:16 by isromero          #+#    #+#             */
/*   Updated: 2024/07/27 11:22:43 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <sstream>

class PMergeMe
{
public:
	PMergeMe();
	PMergeMe(const std::string &expression);
	PMergeMe(const PMergeMe &other);
	PMergeMe &operator=(const PMergeMe &other);
	~PMergeMe();

private:
	std::string _expression;
};

#endif
