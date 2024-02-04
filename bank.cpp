//
//  bank.cpp
//  Bank management
//
//  Created by Mekial Khan on 16/12/2022.
//

#include "bank.hpp"
#include <fstream>
#include <iostream>

using std::cout;
using std::endl;

bank::bank(){
    Cl_Accounts acnt;
    std::ifstream infile;
    infile.open("bank.data");
    if(!infile){
        std::cout<< "No file found"<<endl;
        return;
    }
    while (!infile.eof()){
        infile>>acnt;
        accounts_cl.insert(std::pair<long, Cl_Accounts>(acnt.getAccNo(), acnt));
    }
    Cl_Accounts::setLstAccntNo(acnt.getAccNo());
    infile.close();
}

Cl_Accounts bank::Cl_Open_Account(std::string fname, std::string lname, float balance){
    std::ofstream outfile;
    Cl_Accounts acnt (fname, lname, balance);
    accounts_cl.insert(std::pair<long, Cl_Accounts>(acnt.getAccNo(), acnt));
    outfile.open("bank.data", std::ios::trunc);
    std::map<long, Cl_Accounts>::iterator itr;
    for (itr=accounts_cl.begin(); itr!=accounts_cl.end(); itr++){
        outfile<<itr->second;
    }
    outfile.close();
    return acnt;
}
Cl_Accounts bank::Cl_Balance_Enquiry(long Accnt_No){
    std::map<long, Cl_Accounts>::iterator itr;
    itr = accounts_cl.find(Accnt_No);
    return itr->second;
}
Cl_Accounts bank::Deposit (long Accnt_No, float amt){
    std::map<long, Cl_Accounts>::iterator itr;
    itr = accounts_cl.find(Accnt_No);
    itr->second.deposit(amt);
    return itr->second;
    
}
Cl_Accounts bank::Withdraw (long Accnt_No, float amt){
    std::map<long, Cl_Accounts>::iterator itr;
    itr = accounts_cl.find(Accnt_No);
    itr->second.withdraw(amt);
    return itr->second;
}
void bank::CloseAccount(long Accnt_No){
    std::map<long, Cl_Accounts>::iterator itr;
    accounts_cl.erase(Accnt_No);
}

void bank::ShowAllAccounts(){
    std::map<long, Cl_Accounts>::iterator itr;
    for (itr=accounts_cl.begin(); itr!=accounts_cl.end(); itr++){
        cout<<"Account: "<<itr->first<<endl;
        cout<<itr->second<<endl;
    }
}

bank::~bank(){
    std::ofstream outfile;
    outfile.open("bank.data", std::ios::trunc);
    std::map<long, Cl_Accounts>::iterator itr;
    for (itr=accounts_cl.begin(); itr!=accounts_cl.end(); itr++){
        outfile<<itr->second;
    }
    outfile.close();
}
