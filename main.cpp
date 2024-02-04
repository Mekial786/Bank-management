#include<iostream>
#include<fstream>
#include "bank.hpp"
#include "Cl_Accounts.hpp"
using std::cout;
using std::endl;
using std::cin;
using std::string;


int main(){
    int option;
    bank b;
    Cl_Accounts acc;
    string fname;
    string lname;
    float blnced;
    long account_no;
    float amnts;
    
    cout<<"***Bank Management System***"<<endl;
    do{
        cout<<"\n\tSelect One Option Below ";
        cout<<"\n\t1 Open an Account";
        cout<<"\n\t2 Balance Enquiry";
        cout<<"\n\t3 Deposit";
        cout<<"\n\t4 Withdrawal";
        cout<<"\n\t5 Close an Account";
        cout<<"\n\t6 Show All Accounts";
        cout<<"\n\t7 Quit";
        cout<<"\nEnter your choice: ";
        cin>>option;
    
    switch(option){
        case 1:
            cout<<"Enter First Name: ";
            cin>>fname;
            cout<<"Enter Last Name: ";
            cin>>lname;
            cout<<"Enter Initial Balance: ";
            cin>>blnced;
            acc = b.Cl_Open_Account(fname, lname , blnced);
            cout<<endl<<"Congratulations Account is Created"<<endl;
            cout<<acc;
            break;
        case 2:
            cout<<"Enter Account Number:";
            cin>>account_no;
            acc = b.Cl_Balance_Enquiry(account_no);
            cout<<endl<<"Your Account Details"<<endl;
            cout<<acc;
            break;
        case 3:
            cout<<"Enter Account Number:";
            cin>>account_no;
            cout<<"Enter Balance:";
            cin>>amnts;
            acc = b.Deposit(account_no, amnts);
            cout<<endl<<"Amount is Deposited"<<endl;
            cout<<acc;
            break;
        case 4:
            cout<<"Enter Account Number:";
            cin>>account_no;
            cout<<"Enter Balance:";
            cin>>amnts;
            acc = b.Withdraw(account_no, amnts);
            cout<<endl<<"Amount is Withdrawn"<<endl;
            cout<<acc;
            break;
        case 5:
            cout<<"Enter Account Number:";
            cin>>account_no;
            b.CloseAccount(account_no);
            cout<<endl<<"The account: "<<endl;
            cout<<acc;
            cout<<"is now closed"<<endl;
            break;
        case 6:
            b.ShowAllAccounts();
            break;
        case 7:
            cout<<"case 7";
            break;
    }
        
    }while (option != 7);
    
    return 0;
}
