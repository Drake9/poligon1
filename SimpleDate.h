#include <iostream>
#include <time.h>
#include <conio.h>
#include "Markup.h"
#include "SupportiveMethods.h"

using namespace std;

class Date{

    const int MINIMAL_YEAR = 2000;
    const int MINIMAL_MONTH = 1;
    const int MAXIMAL_MONTH = 12;
    const int MINIMAL_DAY = 1;

    int year;
    int month;
    int day;

    bool validateString(string text);
    bool validateDate(int customYear, int customMonth, int customDay);
    int countDaysInMonth(int customYear, int customMonth);

public:

    Date();
    Date(string newDate);

    void setDate(string newDate);

    string getDateAsString();

    string serialize();
    void deserialize(string strSubDoc);
    void print();

    friend bool operator == (const Date &date1, const Date &date2);
    friend bool operator != (const Date &date1, const Date &date2);
    friend bool operator < (const Date &date1, const Date &date2);
    friend bool operator > (const Date &date1, const Date &date2);
    friend bool operator <= (const Date &date1, const Date &date2);
    friend bool operator >= (const Date &date1, const Date &date2);
};
