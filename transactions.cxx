#include "transactions.h"



void TransactionManager::checkBalance(AccountManager& am) {
    int acc_number;
    std::cout << "Enter account Number"  << std::endl;
    std::cin >> acc_number;
    am.fetchAccountBalance(acc_number);
}

void TransactionManager::makeDeposit(AccountManager& am) {
    
    int acc_number;
    float deposit_amount;
    std::cout << "Enter account Number" << std::endl;
    std::cin >> acc_number;
    std::cout << "Enter Deposit Amount" << std::endl;
    std::cin >> deposit_amount;
    am.updateBalance(acc_number, deposit_amount);
}

void TransactionManager::makeWithdrawal(AccountManager& am) {
    int acc_number;
    float deposit_amount;
    std::cout << "Enter account Number" << std::endl;
    std::cin >> acc_number;
    std::cout << "Enter withdrawal Amount" << std::endl;
    std::cin >> deposit_amount;
    deposit_amount*= -1.0;
    am.updateBalance(acc_number, deposit_amount );
}


