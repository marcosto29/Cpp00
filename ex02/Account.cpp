
#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
    _accountIndex = _nbAccounts;
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;

    _totalAmount += _amount;
    _nbAccounts += 1;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              << "amount:" << _amount << ";"
              << "created\n";

}

Account::Account()
{
    _accountIndex = _nbAccounts;
    _amount = 0;
    _nbDeposits = 0;
    _nbWithdrawals = 0;

    _nbAccounts += 1;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              << "amount:" << _amount << ";"
              << "created\n";
}

Account::~Account( void )
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              << "amount:" << _amount << ";"
              << "closed\n";
}

int  Account::getNbAccounts(void)
{
    return (_nbAccounts);
}

int  Account::getNbDeposits(void)
{
    return (_totalNbDeposits);
}

int  Account::getNbWithdrawals(void)
{
    return (_totalNbWithdrawals);
}

int  Account::getTotalAmount(void)
{
    return (_totalAmount);
}

void    Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";"
              << "total:" << _totalAmount << ";"
              << "deposits:" << _totalNbDeposits << ";"
              << "withdrawals:" << _totalNbWithdrawals << "\n";
}

void    Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              << "amount:" << _amount << ";"
              << "deposits:" << _nbDeposits << ";"
              << "withdrawals:" << _nbWithdrawals << "\n";
}

void    Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              << "p_amount:" << _amount << ";"
              << "deposit:" << deposit << ";";
    _amount += deposit;
    _totalAmount += deposit;
    std::cout << "amount:" << _amount << ";";
    _nbDeposits += 1;
    _totalNbDeposits += 1;
    std::cout << "nb_deposits:" << _nbDeposits << "\n";
}

bool	Account::makeWithdrawal( int withdrawal )
{
    int status;

    if (withdrawal < _amount)
    {

    }
    else
        status = 0;
    
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              << "p_amount:" << _amount << ";"
              << "withdrawal:";
    if (status == 0)
    {
        std::cout << "refused\n";
        return (false);
    }
    std::cout << withdrawal << ";";
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    std::cout << "amount:" << _amount << ";";
    _nbWithdrawals += 1;
    _totalNbWithdrawals += 1;
    std::cout << "nb_withdrawals:" << _nbWithdrawals << "\n";
    return (true);
}

void    Account::_displayTimestamp( void )
{
    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);
    char buffer[20];
    std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", now);
    std::cout << '[' << buffer << "] ";
}
