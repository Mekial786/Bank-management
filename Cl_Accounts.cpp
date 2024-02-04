//
//  Cl_Accounts.cpp
//  Bank management
//
//  Created by Mekial Khan on 21/12/2022.
//

#include "Cl_Accounts.hpp"
#include <string>
#include <fstream>
#include <iostream>

long Cl_Accounts::Nxt_Accnt_No=0;

std::ifstream& operator >> (std::ifstream &ifs, Cl_Accounts &acc){
    ifs>>acc.Accnt_No;
    ifs>>acc.client_fname;
    ifs>>acc.client_lname;
    ifs>>acc.client_balance;
    return ifs;
}

std::ofstream& operator <<(std::ofstream &ofs, Cl_Accounts &acc){
    ofs<<acc.Accnt_No<<std::endl;
    ofs<<acc.client_fname<<std::endl;
    ofs<<acc.client_lname<<std::endl;
    ofs<<acc.client_balance<<std::endl;
    return ofs;
}

std::ostream& operator<<(std::ostream& os, Cl_Accounts& acc){
    os<<"First Name: "<<acc.get_Fname()<<std::endl;
    os<<"Last Name: "<<acc.get_Lname()<<std::endl;
    os<<"Account Number:"<<acc.getAccNo()<<std::endl;
    os<<"Balance:"<<acc.getBlnce()<<std::endl;
    return os;
}

Cl_Accounts::Cl_Accounts(std::string fname, std::string lname, float client_balance){
    Nxt_Accnt_No++;
    Accnt_No = Nxt_Accnt_No;
    client_fname=fname;
    client_lname=lname;
    this->client_balance = client_balance;
}

std::string Cl_Accounts::get_Fname(){
    return client_fname;
}
std::string Cl_Accounts::get_Lname(){
    return client_lname;
}
long Cl_Accounts::getAccNo(){
    return Accnt_No;
}
float Cl_Accounts::getBlnce(){
    return client_balance;
}
void Cl_Accounts::deposit(float amt){
    client_balance += amt;
}
void Cl_Accounts::withdraw(float amt){
    client_balance -= amt;
}

void Cl_Accounts::setLstAccntNo(long Accnt_No){
    Nxt_Accnt_No = Accnt_No;
}
long Cl_Accounts::getLstAccntNo(){
    return Nxt_Accnt_No;
};


