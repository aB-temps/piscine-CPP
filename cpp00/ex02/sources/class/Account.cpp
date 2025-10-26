/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 23:10:31 by abetemps          #+#    #+#             */
/*   Updated: 2025/10/25 23:36:35 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <ctime>
#include "Account.hpp"

using	std::cout;
using	std::endl;

int Account::_nbAccounts = 0;
int Account::_totalAmount= 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(void)
{
	this->_accountIndex = _nbAccounts;
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	++_nbAccounts;

	_displayTimestamp();
	cout	<< " index:"	<< this->_accountIndex
			<< ";amount:"	<< "0"
			<< ";created"	<< endl;
}

Account::Account( int initial_deposit )
{
	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 1;
	this->_nbWithdrawals = 0;

	++_nbAccounts;
	++_totalNbDeposits;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	cout	<< " index:"	<< this->_accountIndex
			<< ";amount:"	<< this->_amount
			<< ";created"	<< endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	cout	<< " index:"	<< this->_accountIndex
			<< ";amount:"	<< this->_amount
			<< ";closed"	<< endl;
}

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();

	cout	<< " index:"		<< this->_accountIndex
			<< ";amount:"		<< this->_amount
			<< ";deposits:"		<< this->_totalNbDeposits
			<< ";withdrawals:"	<< this->_totalNbWithdrawals
			<< endl;
}

void	Account::_displayTimestamp( void )
{
	char		now_formatted[18];
	time_t		now_ts;
	
	std::time(&now_ts);
	std::strftime(now_formatted, sizeof(now_formatted), "[%Y%m%d_%H%M%S]", localtime(&now_ts));
	cout <<	now_formatted;
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	cout	<< " accounts:"		<< getNbAccounts()
			<< ";total:"		<< getTotalAmount()
			<< ";deposits:"		<< getNbDeposits()
			<< ";withdrawals:"	<< getNbWithdrawals()
			<< endl;
}

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

void	Account::makeDeposit( int deposit )
{
	this->_amount += deposit;
	++this->_nbDeposits;

	++_totalNbDeposits;
	_totalAmount += deposit;

	_displayTimestamp();
	cout	<< " index:"		<< getNbAccounts()
			<< ";p_amount:"		<< checkAmount() - deposit
			<< ";deposit:"		<< deposit
			<< ";amount:"		<< checkAmount()
			<< ";nb_deposits:"	<< getNbDeposits()
			<< endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	if (checkAmount() - withdrawal < 0)
	{	
		_displayTimestamp();
		cout	<< " index:"			<< getNbAccounts()
				<< ";p_amount:"			<< checkAmount()
				<< ";withdrawal:"		<< "refused"
				<< endl;
		return (false);
	}

	this->_amount -= withdrawal;
	++this->_nbWithdrawals;
	
	++_totalNbWithdrawals;
	_totalAmount -= withdrawal;


	_displayTimestamp();
	cout	<< " index:"			<< getNbAccounts()
			<< ";p_amount:"			<< checkAmount() + withdrawal
			<< ";withdrawal:"		<< withdrawal
			<< ";amount:"			<< checkAmount()
			<< ";nb_withdrawals:"	<< getNbWithdrawals()
			<< endl;

	return (true);
}
