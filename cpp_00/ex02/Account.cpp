/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 20:27:25 by isromero          #+#    #+#             */
/*   Updated: 2023/09/06 20:27:25 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
  _accountIndex = _nbAccounts++;
  _amount = initial_deposit;
  _totalAmount += _amount;
  _displayTimestamp();
  std::cout << "index:" << _accountIndex
            << ";amount:" << _amount
            << ";created"
            << std::endl;
  _nbDeposits = 0;
  _nbDeposits = 0;
}

Account::Account(void)
{
  _accountIndex = _nbAccounts++;
  _amount = 0;
  _nbDeposits = 0;
  _nbWithdrawals = 0;
}

Account::~Account(void)
{
  _totalAmount -= _amount;
  _displayTimestamp();
  std::cout << "index:" << _accountIndex
            << ";amount:" << _amount
            << ";closed"
            << std::endl;
}

int Account::getNbAccounts(void)
{
  return _nbAccounts;
}

int Account::getTotalAmount(void)
{
  return _totalAmount;
}

int Account::getNbDeposits(void)
{
  return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
  return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
  _displayTimestamp();
  std::cout << "accounts:" << getNbAccounts()
            << ";total:" << getTotalAmount()
            << ";deposits:" << getNbDeposits()
            << ";withdrawals:" << getNbWithdrawals()
            << std::endl;
}

void Account::makeDeposit(int deposit)
{
  _displayTimestamp();
  std::cout << "index:" << _accountIndex
            << ";p_amount:" << _amount;
  if (deposit < 0)
  {
    std::cout << "refused:" << std::endl;
    return;
  }
  _amount += deposit;
  _totalAmount += deposit;
  _totalNbDeposits++;
  _nbDeposits++;
  std::cout << ";deposit:" << deposit
            << ";amount:" << _amount
            << ";nb_deposits:" << _nbDeposits
            << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
  _displayTimestamp();
  std::cout << "index:" << _accountIndex
            << ";p_amount:" << _amount;
  if (withdrawal < 0 || checkAmount() < withdrawal)
  {
    std::cout << "refused:" << std::endl;
    return false;
  }
  _amount -= withdrawal;
  _totalAmount -= withdrawal;
  _totalNbWithdrawals++;
  _nbWithdrawals++;
  std::cout << ";withdrawal:" << withdrawal
            << ";amount:" << _amount
            << ";nb_withdrawals:" << _nbWithdrawals
            << std::endl;
  return true;
}

int Account::checkAmount(void) const
{
  return _amount;
}

void  Account::displayStatus(void) const
{
  _displayTimestamp();
  std::cout << "index:" << _accountIndex
            << ";amount:" << _amount
            << ";deposits:" << _nbDeposits
            << ";withdrawals:" << _nbWithdrawals
            << std::endl;
}

void  Account::_displayTimestamp(void)
{
  std::time_t t = std::time(nullptr);
  std::tm* now = std::localtime(&t);

  std::cout << '['
            << (now->tm_year + 1900) << std::setfill('0') << std::setw(2) << (now->tm_mon + 1)
            << std::setfill('0') << std::setw(2) << now->tm_mday << '_'
            << std::setfill('0') << std::setw(2) << now->tm_hour
            << std::setfill('0') << std::setw(2) << now->tm_min
            << std::setfill('0') << std::setw(2) << now->tm_sec << "] ";
}