#include<iostream>
#include<String>
using namespace std;

bool isLeapYear(int year);
int getCenturyValue(int year);
int getYearValue(int year);
int getMonthValue(int month, int year);

int main() {
    
    int month = 0,
        day = 0,
        year = 0,
        sum = 0,
        day_of_week = 0;
    string day_string = "";

    // Ask the user to enter the month
    cout << "Enter the month: ";
    cin >> month;
    while (month < 1 || month > 12){
        cout << "Please enter a valid month (between 1 and 12): ";
        cin >> month;
    }

    // Ask the user to enter the day
    cout << "Enter the day: ";
    cin >> day;
    if (month == 2){
        while (day < 1 || day > 29){
            cout << "Please enter a valid day (between 1 and 28): ";
            cin >> day;
        }
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11){
        while (day < 1 || day > 30){
            cout << "Please enter a valid day (between 1 and 30): ";;
            cin >> day;
        }
    }
    else{
        while (day < 1 || day > 31){
            cout << "Please enter a valid day (between 1 and 31): ";
            cin >> day;
        }
    }

    // Ask the user to enter the year
    cout << "Enter the year: ";
    cin >> year;
    while (year < 1 || year > 2021){
        cout << "Please enter a valid year: ";
        cin >> year;
    }
    while (isLeapYear(year) == false && month == 2 && day == 29){
        cout << year << " is not a leap year, so February 29th is not a valid day. Please enter a valid year: ";
        cin >> year;
    }

    // Calculate the day of the week
    sum = day + getMonthValue(month,year) + getYearValue(year) + getCenturyValue(year);
    day_of_week = sum % 7;

    // Find the corresponding day name
    switch(day_of_week) {
        case 0:
            day_string = "Sunday";
            break;
        case 1: 
            day_string = "Monday";
            break;
        case 2:
            day_string = "Tuesday";
            break;
        case 3:
            day_string = "Wednesday";
            break;
        case 4:
            day_string = "Thursday";
            break;
        case 5:
            day_string = "Friday";
            break;
        case 6:
            day_string = "Saturday";
            break;
    }

    cout << "The day of the week corresponding to " << month << "/" << day << "/" << year << " is " << day_string << ".";
    return 0;
}


bool isLeapYear(int year){
    // Leap year is divisible by 400 or divisible by 4 and not 100
    return ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
}

int getCenturyValue(int year){
    int century;
    int centValue;
    century = (year/100) % 4;
    centValue = (3 - century) * 2;
    return centValue;
}

int getYearValue(int year){
    int yearValue = 0;
    int rem = year % 100;
    yearValue = (rem/4) + rem;
    return yearValue;
}

int getMonthValue(int month, int year){
    switch(month) {
        case 1:
            if (isLeapYear(year))
                return 6;
            else
                return 0;
        case 2:  
            if (isLeapYear(year))
                return 2;
            else
                return 3;
        case 3:
            return 3;
        case 4:
            return 6;
        case 5: 
            return 1;
        case 6:
            return 4;
        case 7:
            return 6;
        case 8:
            return 2;
        case 9:
            return 5;
        case 10:
            return 0;
        case 11:
            return 3;
        case 12:
            return 5;
    }
}

