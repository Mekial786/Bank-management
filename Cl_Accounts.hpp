//
//  Cl_Accounts.hpp
//  Bank management
//
//  Created by Mekial Khan on 21/12/2022.
//

#ifndef Cl_Accounts_hpp
#define Cl_Accounts_hpp
#include <string>

#include <stdio.h>

class Cl_Accounts{
    
private:
    long Accnt_No;
    std::string client_fname;
    std::string client_lname;
    float client_balance;
    static long Nxt_Accnt_No;
    
public:
    static void setLstAccntNo(long Accnt_No);
    static long getLstAccntNo();
    friend std::ifstream& operator>>(std::ifstream& ifs, Cl_Accounts& acc);
    friend std::ofstream& operator<<(std::ofstream& ofs, Cl_Accounts& acc);
    friend std::ostream& operator<<(std::ostream& os, Cl_Accounts& acc);
    std::string get_Fname();
    std::string get_Lname();
    long getAccNo();
    float getBlnce();
    void deposit(float amt);
    void withdraw(float amt);
    Cl_Accounts(){};
    Cl_Accounts(std::string fname,std::string lname,float client_balance);
};


#endif /* Cl_Accounts_hpp */
