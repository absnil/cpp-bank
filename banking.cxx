
#include"banking.h"



AccountManager::AccountManager(char*& inputx) {
   
   std::fstream input(inputx, std::ios::in | std::ios::binary);
   if (input){
        bank.ParseFromIstream(&input);
        current_accounts = bank.totalaccounts();
        for(int i =0; i < bank.accounts_size();i++){

            activeAccountNumbers.insert(bank.accounts(i).account_number());
            accNumberToIndexMapping.insert(std::make_pair(bank.accounts(i).account_number(),i));
        }
    }
    file_name = inputx;
}


void AccountManager::createAccount() {
    
    std::string excess;
    getline(std::cin,excess);
    general::Account* account = bank.add_accounts();
    std::cout<<"Enter First Name"<<std::endl;
    getline(std::cin,*account->mutable_first_name());
    std::cout<<"Enter Last Name"<<std::endl;
    getline(std::cin,*account->mutable_last_name());
    account->set_account_number(generate_account_number());
    account->set_balance(100);

    std::cout << "Is this a savings, checking, or loan account? ";
    std::string type;
    getline(std::cin, type);
    if (type == "savings") {
      account->set_type(general::Account::Savings);
    } else if (type == "loan") {
      account->set_type(general::Account::Loan);
    } else if (type == "checking") {
      account->set_type(general::Account::Checking);
    } else {
      std::cout << "Unknown account type.  Using default." << std::endl;
    }

    std::fstream output(file_name, std::ios::out | std::ios::trunc | std::ios::binary);
    if (!bank.SerializeToOstream(&output)) {
        std::cerr << "Failed to write address book." << std::endl;
    }
}




void AccountManager::displayAccount(int &account_number) {
    std::string excess;
    getline(std::cin,excess);
    if (accNumberToIndexMapping.find(account_number)!=accNumberToIndexMapping.end()) {
        int index_of_account = accNumberToIndexMapping[account_number];
        cout<<"Name: "<<bank.account(i)
    }

    std::fstream output(file_name, std::ios::out | std::ios::trunc | std::ios::binary);
    if (!bank.SerializeToOstream(&output)) {
        std::cerr << "Failed to write address book." << std::endl;
    }       



}

// void AccountManager::writeRec() {
        
// }

// void AccountManager::readRecord() {
        
// }

// void AccountManager::searchRecord() {
        
// }

// void AccountManager::editRecord() {
            
// }

// void AccountManager::deleteRecord()  {
        
        
// }

