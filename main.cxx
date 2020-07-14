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
    cout<<"Select one option below ";
    cout<<"\n\t1-->Create Account";
    cout<<"\n\t2-->Display Account";
    cout<<"\n\t3-->Search Record from file";
    cout<<"\n\t4-->Update Record";
    cout<<"\n\t5-->Delete Record";
    cout<<"\n\t6-->Quit";
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
        cout<<"\n\tEnter Account Number";
        cin>>acc_number;
        acc_manager.displayAccount(acc_number);
        break;
      }
    //   case 3:
    //     a_query.SearchRecord();
    //     break;
    //   case 4:
    //     a_query.edit_rec();
    //     break;
    //   case 5:
    //     a_query.delete_rec();
    //     break;
        case 3:
        {
          exit(0);
          break;
        }
        default:
        {
          cout<<"\nEnter correct choice";
          exit(0);
        }
      }
  }
  
  return 0;
}