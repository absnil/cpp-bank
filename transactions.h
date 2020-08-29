#include<iostream>
#include <fstream>
#include <string>
#include "account_system.pb.h"
#include <set>
#include <map>
#include "banking.h"

class TransactionManager {

    public:
        void makeDeposit(AccountManager& am);
        void makeWithdrawal(AccountManager& am);
        void checkBalance(AccountManager& am);
    
    private:
        /*
        int generateTransactionId() {

        }

        int total_transactions;
        std::set<int> transaction_ids;
        std::map<int, set<int>> transaction history;
        */

};