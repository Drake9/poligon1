#include "Transaction.h"

using namespace std;

/**----- GETTERS & SETTERS ------**/

int Transaction::getUserID(){
    return userID;
}

Date Transaction::getDate(){
    return date;
}

string Transaction::getItem(){
    return item;
}

Money Transaction::getAmount(){
    return amount;
}


void Transaction::setUserID(int newID){
    userID = newID;
}

void Transaction::setDate(string newDate){
    date.setDate(newDate);
}

void Transaction::setItem(string newItem){
    item = newItem;
}

void Transaction::setAmount(string newAmount){
    amount.setAmount(newAmount);
}

/**--------------------------------**/

string Income::serialize(){
    CMarkup xml;
    xml.AddElem("income");
    xml.IntoElem();
    xml.AddElem("incomeID", incomeID);
    xml.AddElem("userID", userID);
    xml.AddElem("date", date.getDateAsString());
    xml.AddElem("item", "wynagrodzenie" );
    xml.AddElem("amount", amount.getAmountAsString());
    xml.OutOfElem();

    return xml.GetDoc();
}

void Income::deserialize(string strSubDoc){

    CMarkup xml( strSubDoc );

    xml.FindElem(); // income
    xml.IntoElem();

    if ( xml.FindElem("incomeID" ) )
        incomeID = SupportiveMethods::convertStringToInt(xml.GetData());
    else
        incomeID = 0;

    if ( xml.FindElem("userID" ) )
        userID = SupportiveMethods::convertStringToInt(xml.GetData());
    else
        userID = 0;

    if ( xml.FindElem("date") )
        date.setDate(xml.GetData());
    else
        date.setDate("2001-01-01");

    if ( xml.FindElem("item") )
        item = xml.GetData();
    else
        item = "";

    if ( xml.FindElem("amount") )
        amount.setAmount(xml.GetData());
    else
        amount.setAmount(0);

}

void Transaction::printTransaction(){
    cout << "userID: " << userID << endl;
    date.print();
    cout << "item: " << item << endl;
    cout << "amount: " << amount.getAmountAsString() << endl;
}

/**------------ INCOME ----------------**/

void Income::setIncomeID(int newID){
    incomeID = newID;
}

int Income::getIncomeID(){
    return incomeID;
}

void Income::printIncome(){
    cout << endl << "incomeID: " << incomeID << endl;
    printTransaction();
}

Income & Income::operator = (const Income &income2){
    this->incomeID = income2.incomeID;
    this->userID = income2.userID;
    this->date = income2.date;
    this->item = income2.item;
    this->amount = income2.amount;
}
