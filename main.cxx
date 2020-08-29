#include"banking.h"
#include<fstream>
#include<cstdlib>
#include<iostream>


using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::ofstream;
using std::ifstream;
using std::ios;


int main(int argc, char* argv[]) {
  
  
  int choice;
  if (argc != 2) {
    std::cerr << "Usage:  " << argv[0] << " Name of existing bank file or new file name to be created" << endl;
    return -1;
  }
  cout<<"***Banking System***"<<endl;
  while(true) {
    cout<<"Select one option:- ";
    cout<<"\n\t1-->Create Account";
    cout<<"\n\t2-->Display Account";
    cout<<"\n\t3-->Delete Account";
    cout<<"\n\t4-->Quit";
    cout<<"\nEnter your choice: ";
    cin>>choice;
     switch(choice) {
       case 1:
       {
          AccountManager acc_manager(argv[1]);
          acc_manager.createAccount();
          break;
        }

      case 2:  {
        int acc_number;            
        AccountManager acc_manager(argv[1]);
        cout<<"\nEnter Account Number: ";
        cin>>acc_number;
        acc_manager.displayAccount(acc_number);
        break;
      }
      case 3:  {
        int acc_number;            
        AccountManager acc_manager(argv[1]);
        cout<<"\nEnter Account Number: ";
        cin>>acc_number;
        acc_manager.deleteAccount(acc_number);
        break;
      }
      case 4:  {
        exit(0);
        break;
      }
      default: {
        cout<<"\nInvalid Choice \n";  
      }
    }
  }
  
  return 0;
}