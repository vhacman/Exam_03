/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 09:12:26 by apintaur          #+#    #+#             */
/*   Updated: 2025/06/06 09:12:27 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int deposit)
: _accountIndex(_nbAccounts), _amount(deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	++_nbAccounts;
	_totalAmount += deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";";
	std::cout << "amount:" << _amount;
	std::cout << ";";
	std::cout << "created";
	std::cout << std::endl;
}

void	Account::_displayTimestamp( void )
{
	std::cout << "[19920104_091532] ";
}

int Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits ( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts;
	std::cout << ";";
	std::cout << "total:" << _totalAmount;
	std::cout << ";";
	std::cout << "deposits:" << _totalNbDeposits;
	std::cout << ";";
	std::cout << "withdrawals:" << _totalNbWithdrawals;
	std::cout << std::endl;
}
void	Account::makeDeposit( int deposit )
{
	int p_amount = _amount;
	_amount += deposit;

	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";";
	std::cout << "p_amount:" << p_amount;
	std::cout << ";";
	std::cout << "deposit:" << deposit;
	std::cout << ";";
	std::cout << "amount:" << _amount;
	std::cout << ";";
	std::cout << "nb_deposits:" << _nbDeposits;
	std::cout << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	int p_amount = _amount;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";";
	std::cout << "p_amount:" << p_amount;
	std::cout << ";";
	if ( _amount < withdrawal )
	{
		std::cout << "withdrawal:refused" << std::endl;
		return false;
	}

	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;

	std::cout << "withdrawal:" << withdrawal;
	std::cout << ";";
	std::cout << "amount:" << _amount;
	std::cout << ";";
	std::cout << "nb_withdrawals:" << _nbWithdrawals;
	std::cout << std::endl;
	return true;
}
int	Account::checkAmount( void ) const
{
	return (_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";";
	std::cout << "amount:" << _amount;
	std::cout << ";";
	std::cout << "deposits:" << _nbDeposits;
	std::cout << ";";
	std::cout << "withdrawals:" << _nbWithdrawals;
	std::cout << std::endl;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";";
	std::cout << "amount:" << _amount;
	std::cout << ";";
	std::cout << "closed";
	std::cout << std::endl;
}
