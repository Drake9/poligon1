#include <iostream>
#include "UsersFile.h"
#include "SimpleDate.h"
#include "Money.h"

using namespace std;

int main(){

    Date currentDate;
    string customDateString = "";

    cout << "Dzisiaj jest " << currentDate.getDateAsString() << "." << endl;

    while(true){
        cout << "Podaj pierwsza date: ";
        cin >> customDateString;
        Date customDate1(customDateString);

        cout << "Podaj druga date: ";
        cin >> customDateString;
        Date customDate2(customDateString);

        if(customDate1 >= customDate2)
            cout << "Pierwsza wieksza lub rowna." << endl;
        else
            cout << "Nieprawda." << endl;

    }

    /*********************/

    vector<User> users;

    UsersFile usersFile("users.xml");

    users = usersFile.loadUsersFromFile();

    for(vector <User>::iterator itr = users.begin(); itr != users.end(); itr++){
        itr->view();
    }

    return 0;
}
