#include <iostream>
#include "Account.hpp"

Account::Account(int initial_deposit) 
{
    _accountIndex = _nbAccounts;
    _nbAccounts++;
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    std::cout << "index :" << _accountIndex << ";amount:" << _amount << "created" << std::endl;
}

Account::~Account(void) {
    std::cout << "index :" << _accountIndex << ";amount:" << _amount << "closed" << std::endl;
}

int Account::getNbAccounts(void)
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

void	Account::displayAccountsInfos(void)
{
    std::cout << "accounts:" << _nbAccounts << ";total:"<< _totalAmount << ";deposits:"<< _totalNbDeposits <<";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::displayStatus(void) const
{
    std::cout << "index:" << _accountIndex << ";amount:"<< _amount << ";deposits:"<< _nbDeposits <<";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit)
{
    _nbDeposits++;
    int sum = deposit + _amount;
    std::cout << "index:" << _accountIndex << ";p_amount:"<< _amount << ";deposit:"<< deposit <<";amount:" << sum <<";nb_deposits:" << _nbDeposits << std::endl;
    _amount = sum;
}

bool	Account::makeWithdrawal(int withdrawal)
{
    if (withdrawal > _amount) {
        std::cout << "index:" << _accountIndex << ";p_amount:"<< _amount << ";withdrawal:refused" << std::endl;
        return (false);
    }
    _nbWithdrawals++;
    int sum = _amount - withdrawal;
    std::cout << "index:" << _accountIndex << ";p_amount:"<< _amount << ";withdrawal:"<< withdrawal <<";amount:" << sum <<";nb_withdrawals:" << _nbWithdrawals << std::endl;
    _amount = sum;
    return (true);
}
int		Account::checkAmount(void) const {return (0);};