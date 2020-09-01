
#include"banking.h"



AccountManager::AccountManager(char*& inputx) {
   
   std::fstream input(inputx, std::ios::in | std::ios::binary);
   if (input){
        bank.ParseFromIstream(&input);
        current_accounts = bank.totalaccounts();

        for(int i = 0; i < bank.accounts_size();i++){

            if (bank.accounts(i).active() == true) {
              activeAccountNumbers.insert(bank.accounts(i).account_number());
              accNumberToIndexMapping.insert(std::make_pair(bank.accounts(i).account_number(),i));
            }
        } 
    }
    else {
      file_name = inputx;
      current_accounts = 0;
    }
    
}

void AccountManager::createAccount() {
    
    std::string excess;
    getline(std::cin,excess);
    general::Account* account = bank.add_accounts();
    std::cout<<"\nEnter First Name: "<<std::endl;
    getline(std::cin,*account->mutable_first_name());
    std::cout<<"\nEnter Last Name: "<<std::endl;
    getline(std::cin,*account->mutable_last_name());
    int curr_account_number = generate_account_number();
    account->set_account_number(curr_account_number);
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
      account->set_type(general::Account::Savings);
      std::cout << "Unknown account type.  Using default." << std::endl;
    }
    account->set_active(true);
    current_accounts++;
    bank.set_totalaccounts(current_accounts);
    std::cout << "\n********************          Account Created successfully         ********************" << std::endl;
    std::cout << "\n********************          Your account number is "<< curr_account_number<<"          ********************" << std::endl;

    std::fstream output(file_name, std::ios::out | std::ios::trunc | std::ios::binary);
    if (!bank.SerializeToOstream(&output)) {
        std::cerr << "\nFailed to write address book." << std::endl;
    }
}

void AccountManager::displayAccount(int &account_number) {
    std::string excess;
    getline(std::cin,excess);
    if (accNumberToIndexMapping.find(account_number)!=accNumberToIndexMapping.end()) {
        int index_of_account = accNumberToIndexMapping[account_number];
        std::cout << "\n********************          First Name: " << bank.accounts(index_of_account).first_name() << "          ********************" << std::endl;
        std::cout << "\n********************          Last Name: " << bank.accounts(index_of_account).last_name() << "           ********************" << std::endl;
        std::cout << "\n********************          Account Number: " << account_number << "             ********************" << std::endl;
        std::cout << "\n********************          Balance " << bank.accounts(index_of_account).balance() << "                ********************" << std::endl;
        std::string account_type((bank.accounts(index_of_account).type() == 0) ? "savings" : (bank.accounts(index_of_account).type() == 1) ? "checking" : "loan");
        std::cout << "\n********************          Type of Account: " << account_type << "      ********************" << std::endl;
        std::cout <<" Hit Enter to continue " << std::endl;
        std::cin.get();
    }
    else {
        std::cout << "\n****************          Enter Correct Account Number           ********************" << std::endl;
    }
 }


void AccountManager::deleteAccount(int& account_number) {
  std::string excess;
  getline(std::cin,excess);
  if (accNumberToIndexMapping.find(account_number) != accNumberToIndexMapping.end()) {
    
    int index_of_account = accNumberToIndexMapping[account_number];
    bank.mutable_accounts(index_of_account)->set_active(false);
    std::cout << "\n***************          Account Closed Successfully          *********************" << std::endl;
    std::fstream output(file_name, std::ios::out | std::ios::trunc | std::ios::binary);
    if (!bank.SerializeToOstream(&output)) {
        std::cerr << "\nFailed to write address book." << std::endl;
    }
  }
  else {
    std::cout<< "*********        Account Does Not Exist        *************" << std::endl;
  }
}

void AccountManager::updateBalance(int& acc_number,float& diff) {
  std::string excess;
  getline(std::cin,excess);
  if (accNumberToIndexMapping.find(acc_number) != accNumberToIndexMapping.end()) {
    
    int index_of_account = accNumberToIndexMapping[acc_number];
    int curr_balance = bank.mutable_accounts(index_of_account)->balance();
    curr_balance = curr_balance + diff;
    bank.mutable_accounts(index_of_account)->set_balance(curr_balance);
    std::cout << "\n***************          Account Closed Successfully          *********************" << std::endl;
    std::fstream output(file_name, std::ios::out | std::ios::trunc | std::ios::binary);
    if (!bank.SerializeToOstream(&output)) {
        std::cerr << "\n*************************        Houston! We have a problem          ***************************" << std::endl;
    }
  }
}

void AccountManager::fetchAccountBalance(int& acc_number) {
  std::string excess;
    getline(std::cin,excess);
    if (accNumberToIndexMapping.find(acc_number)!=accNumberToIndexMapping.end()) {
        int index_of_account = accNumberToIndexMapping[acc_number];
        std::cout << "\n********************          Account Number: " << acc_number << "             ********************" << std::endl;
        std::cout << "\n********************          Balance " << bank.accounts(index_of_account).balance() << "                ********************" << std::endl;
        std::cout <<" Hit Enter to continue " << std::endl;
        std::cin.get();
    }
    else {
        std::cout << "\n****************          Enter Correct Account Number           ********************\n\n\n" << std::endl;
    } 
}