/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:06:22 by isromero          #+#    #+#             */
/*   Updated: 2024/05/26 14:34:02 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	Account::_displayTimestamp();
	this->_amount = initial_deposit;
	Account::_totalAmount += initial_deposit;
	this->_accountIndex = Account::_nbAccounts;
	std::cout << "index:" << this->_accountIndex
			  << ";amount:" << this->_amount
			  << ";created" << std::endl;
	Account::_nbAccounts++;
}

Account::Account()
{
	Account::_displayTimestamp();
	this->_amount = 0;
	this->_accountIndex = Account::_nbAccounts;
	std::cout << "index:" << this->_accountIndex
			  << ";amount:" << this->_amount
			  << ";created" << std::endl;
	Account::_nbAccounts++;
}

Account::~Account()
{
	Account::_displayTimestamp();
	std::cout << "index;" << this->_accountIndex
			  << ";amount:" << this->_amount
			  << ";closed" << std::endl;
}

int Account::getNbAccounts()
{
	return (Account::_nbAccounts);
}

int Account::getTotalAmount()
{
	return (Account::_totalAmount);
}

int Account::getNbDeposits()
{
	return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals()
{
	return (Account::_totalNbWithdrawals);
}

void Account::displayAccountsInfos()
{
	Account::_displayTimestamp();
	std::cout
		<< "accounts:" << Account::_nbAccounts
		<< ";total:" << Account::_totalAmount
		<< ";deposits:" << Account::_totalNbDeposits
		<< ";withdrawals:" << Account::_totalNbWithdrawals
		<< std::endl;
}

void Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  << ";p_amount:" << this->_amount
			  << ";deposit:" << deposit;
	this->_amount += deposit;
	std::cout << ";amount:" << this->_amount;
	this->_nbDeposits++;
	std::cout << ";nb_deposits:" << this->_nbDeposits << std::endl;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
}

bool Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	if (withdrawal > this->_amount || withdrawal < 0)
	{
		std::cout << "index:" << this->_accountIndex
				  << ";p_amount:" << this->_amount
				  << ";withdrawal:refused" << std::endl;
		return (false);
	}
	else
	{
		std::cout << "index:" << this->_accountIndex
				  << ";p_amount:" << this->_amount
				  << ";withdrawal:" << withdrawal;
		this->_amount -= withdrawal;
		std::cout << ";amount:" << this->_amount;
		this->_nbWithdrawals++;
		std::cout << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		Account::_totalNbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		return (true);
	}
}

int Account::checkAmount() const
{
	return (this->_amount);
}

void Account::displayStatus() const
{
	Account::_displayTimestamp();

	std::cout << "index:" << this->_accountIndex
			  << ";amount:" << this->_amount
			  << ";deposits:" << this->_nbDeposits
			  << ";withdrawals:" << this->_nbWithdrawals
			  << std::endl;
}

void Account::_displayTimestamp(void)
{
	std::time_t t = std::time(0);
	std::tm *now = std::localtime(&t);

	std::cout << '['
			  << (now->tm_year + 1900) << std::setfill('0') << std::setw(2) << (now->tm_mon + 1)
			  << std::setfill('0') << std::setw(2) << now->tm_mday << '_'
			  << std::setfill('0') << std::setw(2) << now->tm_hour
			  << std::setfill('0') << std::setw(2) << now->tm_min
			  << std::setfill('0') << std::setw(2) << now->tm_sec << "] ";
}
