#include "Account.hpp"
#include <time.h>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" \
	<< _totalAmount << ";deposits:" << _totalNbDeposits \
	<< ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

int	Account::checkAmount(void) const
{
	return (this->_amount);
}

static	std::string	isSingleDigit(int i)
{
	if (i < 10)
		return ("0");
	else
		return ("");
}

void	Account::_displayTimestamp(void)
{
	struct tm	local;
	time_t		t;

	t = time(NULL);
	local = *localtime(&t);
	std::cout << "[" << 1900 + local.tm_year << isSingleDigit(local.tm_mon) << local.tm_mon \
	<< isSingleDigit(local.tm_mday) << local.tm_mday << "_" << isSingleDigit(local.tm_hour) \
	<< local.tm_hour << isSingleDigit(local.tm_min) << local.tm_min \
	<< isSingleDigit(local.tm_sec) << local.tm_sec << "] ";
}

Account::Account(int initial_deposit)
{
	this->_accountIndex = _nbAccounts;
	_nbAccounts++;
	this->_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex \
	<< ";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account(void)
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex \
	<< ";amount:" << this->_amount << ";closed" << std::endl;
	_nbAccounts--;
	_totalAmount -= this->_amount;
	_totalNbDeposits -= this->_nbDeposits;
	_totalNbWithdrawals -= this->_nbWithdrawals;
}

void	Account::displayStatus(void) const
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex \
	<< ";amount:" << this->_amount <<  ";desposits:" \
	<< this->_nbDeposits << ";withdrawals:" \
	<< this->_nbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex \
	<< ";p_amount:" << this->_amount << ";deposit:" << deposit;
	_totalAmount += deposit;
	this->_amount += deposit;
	this->_nbDeposits++;
	_totalNbDeposits++;
	std::cout << ";amount:" << this->_amount \
	<< ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex \
	<< ";p_amount:" << this->_amount << ";withdrawal:";
	if (this->_amount - withdrawal < 0)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	_totalAmount -= withdrawal;
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << withdrawal << ";amount:" << this->_amount \
	<< ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}