#include<iostream>
#include <fstream>
#include <string>
#include "account_system.pb.h"
#include <set>
#include <map>

class AccountManager
{
  public:
    AccountManager(char*&);
    ~AccountManager(){};
    void createAccount();
    void displayAccount(int& acc_number);
    void deleteAccount(int& acc_number);
    
  private: 
    general::Bank bank;
    int current_accounts;
    std::set<int> activeAccountNumbers;
    std::map<int, int> accNumberToIndexMapping;
    char* file_name;
    int generate_account_number() { return current_accounts+1; };
    
};
