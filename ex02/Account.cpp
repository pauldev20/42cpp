/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:41:35 by pgeeser           #+#    #+#             */
/*   Updated: 2023/03/25 23:05:56 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <chrono>
#include <iomanip>
#include <iostream>
#include "Account.hpp"

/* -------------------------------------------------------------------------- */
/*                            Statics Initalization                           */
/* -------------------------------------------------------------------------- */

int		Account::_nbAccounts = 0;
int		Account::_totalAmount = 0;
int		Account::_totalNbDeposits = 0;
int		Account::_totalNbWithdrawals = 0;

/* -------------------------------------------------------------------------- */
/*                                Class Methods                               */
/* -------------------------------------------------------------------------- */

/**
 * It initializes the account with the given initial deposit, and prints a message to the console
 * 
 * @param initial_deposit the initial deposit amount
 */
Account::Account(int initial_deposit) : _accountIndex(Account::_nbAccounts++), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
	Account::_displayTimestamp();
	Account::_totalAmount += initial_deposit;
	std::cout	<< "index:" << this->_accountIndex
				<< ";amount:" << this->_amount
				<< ";created" << std::endl;
}

/**
 * It displays a timestamp, then displays the account index, amount, and the word "closed"
 */
Account::~Account(void) {
	Account::_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex 
				<< ";amount:" << this->_amount 
				<< ";closed" << std::endl;
}

/* -------------------------------------------------------------------------- */
/*                                   Getters                                  */
/* -------------------------------------------------------------------------- */

/**
 * It returns the number of accounts
 * 
 * @return The number of accounts.
 */
int		Account::getNbAccounts(void) {
	return (Account::_nbAccounts);
}

/**
 * It returns the value of the static attribute _totalAmount.
 * 
 * @return The static variable _totalAmount.
 */
int		Account::getTotalAmount(void) {
	return (Account::_totalAmount);
}

/**
 * It returns the number of deposits made on all accounts.
 * 
 * @return The number of deposits made on all accounts.
 */
int		Account::getNbDeposits(void) {
	return (Account::_totalNbDeposits);
}

/**
 * GetNbWithdrawals returns the total number of withdrawals made on all accounts
 * 
 * @return The number of withdrawals made on all accounts.
 */
int		Account::getNbWithdrawals(void) {
	return (Account::_totalNbWithdrawals);
}

/* -------------------------------------------------------------------------- */
/*                               Private Methods                              */
/* -------------------------------------------------------------------------- */

/**
 * It displays the current date and time in the format [YYYYMMDD_HHMMSS]
 */
void	Account::_displayTimestamp(void) {
	time_t time = std::time(NULL);
	std::cout << std::put_time(std::localtime(&time), "[%Y%m%d_%H%M%S] ");
}

/* -------------------------------------------------------------------------- */
/*                               Public Methods                               */
/* -------------------------------------------------------------------------- */

/**
 * It displays the number of accounts, the total amount of money in all accounts, the total number of
 * deposits and the total number of withdrawals
 */
void	Account::displayAccountsInfos(void) {
	Account::_displayTimestamp();
	std::cout	<< "accounts:" << Account::_nbAccounts
				<< ";total:" << Account::_totalAmount
				<< ";deposits:" << Account::_totalNbDeposits
				<< ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

/**
 * It displays a timestamp, increments the total number of deposits and the total amount of deposits,
 * and then displays the account index, the previous amount, the deposit, the new amount, and the
 * number of deposits
 * 
 * @param deposit the amount of money to deposit
 */
void	Account::makeDeposit(int deposit) {
	Account::_displayTimestamp();
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
	std::cout	<< "index:" << this->_accountIndex 
				<< ";p_amount:" << this->_amount 
				<< ";deposit:" << deposit 
				<< ";amount:" << this->_amount + deposit 
				<< ";nb_deposits:" << ++this->_nbDeposits << std::endl;
}

/**
 * It checks if the amount to withdraw is less than the current amount, if it is, it withdraws the
 * amount and returns true, otherwise it returns false
 * 
 * @param withdrawal the amount to withdraw
 * 
 * @return A boolean.
 */
bool	Account::makeWithdrawal(int withdrawal) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:";
	if (this->_amount < withdrawal) {
		std::cout << "refused" << std::endl;
		return (false);
	}
	Account::_totalNbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	std::cout	<< withdrawal << ";amount:" << this->_amount - withdrawal
				<< ";nb_withdrawals:" << ++this->_nbWithdrawals << std::endl;
	return (true);
}

/**
 * It returns the amount of money in the account
 * 
 * @return The amount of money in the account.
 */
int		Account::checkAmount(void) const {
	return (this->_amount);
}

/**
 * It displays the timestamp, the account index, the amount, the number of deposits and the number of
 * withdrawals
 */
void	Account::displayStatus(void) const {
	Account::_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex
				<< ";amount:" << this->_amount
				<< ";deposits:" << this->_nbDeposits
				<< ";withdrawals:" << this->_nbWithdrawals << std::endl;
}
