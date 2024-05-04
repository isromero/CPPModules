/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:10:40 by isromero          #+#    #+#             */
/*   Updated: 2024/05/04 11:34:56 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class Form
{
public:
	Form();
	Form(std::string const name, bool isSigned, int const gradeRequiredToSign, int const gradeRequiredToExecute);
	Form(const Form &other);
	Form &operator=(const Form &other);
	~Form();

	std::string const &getName() const;
	bool const &getIsSigned() const;
	int const &getGradeRequiredToSign() const;
	int const &getGradeRequiredToExecute() const;

private:
	std::string const _name;
	bool _isSigned;
	int const _gradeRequiredToSign;
	int const _gradeRequiredToExecute;
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif
