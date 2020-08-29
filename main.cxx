#include "transactions.h"
#include <fstream>
#include <cstdlib>
#include <iostream>


using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::ofstream;
using std::ifstream;
using std::ios;

void mainMenu(char*&);
void manageTransactions(AccountManager&);

int main(int argc, char* argv[]) {

  
  if (argc != 2) {
    std::cerr << "Usage:  " << argv[0] << " Name of existing bank file or new file name to be created" << endl;
    return -1;
  }

  mainMenu(argv[1]);  

  return 0;
}

void mainMenu(char*& file_name) {
  int choice;
  cout<<"***Banking System***"<<endl;
  while(true) {
    cout<<"Select one option:- ";
    cout<<"\n\t1-->Create Account";
    cout<<"\n\t2-->Display Account";
    cout<<"\n\t3-->Delete Account";
    cout<<"\n\t4-->Make Transaction";
    cout<<"\n\t5-->Quit";
    cout<<"\nEnter your choice: ";
    cin>>choice;
     switch(choice) {
       case 1:
       {
          AccountManager acc_manager(file_name);
          acc_manager.createAccount();
          break;
        }

      case 2:  {
        int acc_number;            
        AccountManager acc_manager(file_name);
        cout<<"\nEnter Account Number: ";
        cin>>acc_number;
        acc_manager.displayAccount(acc_number);
        break;
      }
      case 3:  {
        int acc_number;            
        AccountManager acc_manager(file_name);
        cout<<"\nEnter Account Number: ";
        cin>>acc_number;
        acc_manager.deleteAccount(acc_number);
        break;
      }
      case 4: {
        AccountManager acc_manager(file_name);
        manageTransactions(acc_manager);

      }
      case 5:  {
        exit(0);
        break;
      }
      default: {
        cout<<"\nInvalid Choice \n";  
      }
    }
  }
}

void manageTransactions(AccountManager& am) {
  int choice;
  cout<<"*************  Transaction Menu   *************"<<endl;
  while(true) {
    cout<<"Select one option:- ";
    cout<<"\n\t1-->Make Withdrawal";
    cout<<"\n\t2-->Make Deposit";
    cout<<"\n\t3-->Check Balance";
    cout<<"\n\t5-->Back";
    cout<<"\nEnter your choice: ";
    cin>>choice;
     switch(choice) {
       case 1:
       {
         TransactionManager tm;
         tm.makeWithdrawal(am);
         break;
      }

      case 2:  {
        TransactionManager tm;
        tm.makeDeposit(am);
        break;
      }
      
      case 3:  {
        TransactionManager tm;
        tm.checkBalance(am);
        break;
      }
      
      case 4:  {
        break;
      }
      
      default: {
        cout<<"\n***************************         Invalid Choice        ***************************\n";  
      }
    }
  } 
}