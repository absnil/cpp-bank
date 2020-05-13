#include<iostream>
#include<fstream>
#include<cstdlib>
#include"banking.h"

using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::ofstream;
using std::ifstream;
using std::ios;

    void account_query::read_data()
    {
        cout<<"\nEnter Account Number: ";
        cin>>m_account_number;
        cout<<"Enter First Name: ";
        cin>>m_firstName;
        cout<<"Enter Last Name: ";
        cin>>m_lastName;
        cout<<"Enter Balance: ";
        cin>>m_total_Balance;
        cout<<endl;
    }

    void account_query::show_data()
    {
        cout<<"Account Number: "<<m_account_number<<endl;
        cout<<"First Name: "<<m_firstName<<endl;
        cout<<"Last Name: "<<m_lastName<<endl;
        cout<<"Current Balance: Rs.  "<<m_total_Balance<<endl;
        cout<<"-------------------------------"<<endl;
    }

    void account_query::write_rec()
    {
        ofstream outfile;
        outfile.open("record.txt", ios::binary|ios::app);
        read_data();
        outfile.write(reinterpret_cast<char *>(this), sizeof(*this));
        outfile.close();
    }

    void account_query::read_rec()
    {
        ifstream infile;
        infile.open("record.txt", ios::binary);
        if(infile)
        {
            
            cout<<"\n****Data from file****"<<endl;
            while(!infile.eof())
            {
                if(infile.read(reinterpret_cast<char*>(this), sizeof(*this)))
                {
                    show_data();
                }
            }
            infile.close();
            return;
        }
        
        cout<<"Error in Opening! File Not Found!!"<<endl;
        return;
    }

    void account_query::search_rec()
    {
        int n;
        ifstream infile;
        infile.open("record.txt", ios::binary);
        if(infile)
        {    
        
            infile.seekg(0,ios::end);
            int count = infile.tellg()/sizeof(*this);
            cout<<"\n There are "<<count<<" record in the file";
            cout<<"\n Enter Record Number to Search: ";
            cin>>n;
            infile.seekg((n-1)*sizeof(*this));
            infile.read(reinterpret_cast<char*>(this), sizeof(*this));
            show_data();
            return;
        }

        cout<<"\nError in opening! File Not Found!!"<<endl;
    }

    void account_query::edit_rec()
    {
        int n;
        fstream iofile;
        iofile.open("record.txt", ios::in|ios::binary);
        if(iofile)
        {
            
        
            iofile.seekg(0, ios::end);
            int count = iofile.tellg()/sizeof(*this);
            cout<<"\n There are "<<count<<" record in the file";
            cout<<"\n Enter Record Number to edit: ";
            cin>>n;
            iofile.seekg((n-1)*sizeof(*this));
            iofile.read(reinterpret_cast<char*>(this), sizeof(*this));
            cout<<"Record "<<n<<" has following data"<<endl;
            show_data();
            iofile.close();
            iofile.open("record.txt", ios::out|ios::in|ios::binary);
            iofile.seekp((n-1)*sizeof(*this));
            cout<<"\nEnter data to Modify "<<endl;
            read_data();
            iofile.write(reinterpret_cast<char*>(this), sizeof(*this));
            return;
        }

        cout<<"\nError in opening! File Not Found!!"<<endl;
            
    }

    void account_query::delete_rec()
    {
        int n;
        ifstream infile;
        infile.open("record.txt", ios::binary);
        if(infile)
        {
            
        
        infile.seekg(0,ios::end);
        int count = infile.tellg()/sizeof(*this);
        cout<<"\n There are "<<count<<" record in the file";
        cout<<"\n Enter Record Number to Delete: ";
        cin>>n;
        fstream tmpfile;
        tmpfile.open("tmpfile.txt", ios::out|ios::binary);
        infile.seekg(0);
        for(int i=0; i<count; i++)
        {
            infile.read(reinterpret_cast<char*>(this),sizeof(*this));
            if(i==(n-1))
                continue;
            tmpfile.write(reinterpret_cast<char*>(this), sizeof(*this));
        }
        infile.close();
        tmpfile.close();
        remove("record.txt");
        rename("tmpfile.txt", "record.txt");
        return;
        }
        cout<<"\nError in opening! File Not Found!!"<<endl;
        
    }

