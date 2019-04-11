#include <iostream>
#include "SimpleDate.h"

using namespace std;

Date::Date(){
    time_t currentTime;
    struct tm * data;
    char dateAsTable[11];
    string dateAsString = "";

    time( & currentTime );
    data = localtime( & currentTime );

    strftime(dateAsTable, 11, "%Y-%m-%d", data);
    dateAsString = SupportiveMethods::convertTableToString(dateAsTable, 10);
    setDate(dateAsString);
}

Date::Date(string newDate){
   setDate(newDate);
}

/****************************************/

void Date::setDate(string newDate){
    bool success = false;

    if(validateString(newDate)){
        int yearToValidate = SupportiveMethods::convertStringToInt(newDate.substr(0,4));
        int monthToValidate = SupportiveMethods::convertStringToInt(newDate.substr(5,2));
        int dayToValidate = SupportiveMethods::convertStringToInt(newDate.substr(8,2));

        if(validateDate(yearToValidate, monthToValidate, dayToValidate)){
            year = yearToValidate;
            month = monthToValidate;
            day = dayToValidate;
            success = true;
        }
    }

    if(success == false){
        cout << "Podana data jest nieprawidlowa." << endl;
        year = 2000;
        month = 1;
        day = 1;
    }
};

/****************************************/

string Date::getDateAsString(){
    string date = "";
    date += SupportiveMethods::convertIntToString(year) + "-";
    if(month < 10)
        date += "0";
    date += SupportiveMethods::convertIntToString(month) + "-";
    if(day < 10)
        date += "0";
    date += SupportiveMethods::convertIntToString(day);
    return date;
};

/****************************************/

string Date::serialize(){
    CMarkup xml;
    string date = getDateAsString();
    xml.AddElem("date", date);

    return xml.GetDoc();
}

void Date::deserialize(string strSubDoc){

    CMarkup xml(strSubDoc);
    xml.FindElem();

    if(xml.FindElem("date"))
        setDate(xml.GetData());
}

/****************************************/

void Date::print(){
    cout << "date: " << year << "-" << month << "-" << day << endl;
}

bool Date::validateDate(int customYear, int customMonth, int customDay){
    if(customYear < MINIMAL_YEAR)
        return false;
    if(customMonth < MINIMAL_MONTH)
        return false;
    if(customMonth > MAXIMAL_MONTH)
        return false;
    if(customDay < MINIMAL_DAY)
        return false;
    if(customDay > countDaysInMonth(customYear, customMonth))
        return false;

    return true;
}

int Date::countDaysInMonth(int year, int month){
    int table[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(year%4 != 0)
        return table[month-1];
    else{
        if(year%100 != 0)
            return 29;
        else{
            if(year%400 != 0)
                return 28;
            else
                return 29;
        }
    }
}

bool Date::validateString(string text){
    if(text.size() != 10)
        return false;

    for(int i=0; i<10; i++){

        if(i == 4 || i == 7){
            if(text[i] != '-')
                return false;
        }
        else{
            if(text[i] < '0' || text[i] > '9')
                return false;
        }
    }

    return true;
}

/**--------------OPERATORS-------------**/

bool operator == (const Date &date1, const Date &date2){
    if(date1.year == date2.year
       && date1.month == date2.month
       && date1.day == date2.day)
        return true;
    else
        return false;
}

bool operator != (const Date &date1, const Date &date2){
    return !(date1 == date2);
}

bool operator < (const Date &date1, const Date &date2){
    if(date1.year < date2.year)
        return true;
    else if(date1.year > date2.year)
        return false;
    else{
        if(date1.month < date2.month)
            return true;
        else if(date1.month > date2.month)
            return false;
        else{
            if(date1.day < date2.day)
                return true;
            else
                return false;
        }
    }
}

bool operator > (const Date &date1, const Date &date2){
    return (date2 < date1);
}

bool operator <= (const Date &date1, const Date &date2){
    if(date1 == date2)
        return true;
    else
        return (date1 < date2);
}

bool operator >= (const Date &date1, const Date &date2){
    if(date1 == date2)
        return true;
    else
        return (date1 > date2);
}

Date & Date::operator = (const Date &date2){
    this->year = date2.year;
    this->month = date2.month;
    this->day = date2.day;
}
