#include <iostream>
#include <time.h>
#include <conio.h>
#include "Markup.h"
#include "SupportiveMethods.h"
#include "SimpleDate.h"
#include "Money.h"

using namespace std;

class Transaction{

protected:

    int userID;
    Date date;
    string item;
    Money amount;

public:

    int getUserID();
    Date getDate();
    string getItem();
    Money getAmount();

    void setUserID(int newID);
    void setDate(string newDate);
    void setItem(string newItem);
    void setAmount(string newAmount);

    void printTransaction();

};

class Income :public Transaction{

    int incomeID;

public:

    int getIncomeID();
    void setIncomeID(int newID);
    void printIncome();

    string serialize();
    void deserialize(string strSubDoc);

    Income &operator = (const Income &income2);
};
