//
//  bank.hpp
//  Bank management
//
//  Created by Mekial Khan on 16/12/2022.
//

#ifndef bank_hpp
#define bank_hpp
#include "Cl_Accounts.hpp"
#include <stdio.h>
#include <fstream>
#include <map>


class bank{
private:
    std::map<long, Cl_Accounts> accounts_cl;
public:
    bank();
    Cl_Accounts Cl_Open_Account(std::string fname,std::string lname,float balance);
    Cl_Accounts Cl_Balance_Enquiry(long Accnt_No);
    Cl_Accounts Deposit (long Accnt_No, float amt);
    Cl_Accounts Withdraw (long Accnt_No, float amt);
    void CloseAccount(long Accnt_No);
    void ShowAllAccounts();
    ~bank();
};
#endif /* bank_hpp */
