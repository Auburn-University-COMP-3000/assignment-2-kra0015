#include <iostream>
#include <iomanip>
using namespace std;

double convertToMPH(int minutes, int seconds);
double convertToMPH(double kph);

int main() {
	int minutes = 0,
	    seconds = 0;
	double kph = 0.0;

    // Prompts the user to enter a running pace in minutes and seconds 
    cout << "Enter a mile running pace in minutes and seconds below." << endl;
    cout << "Minutes: ";
    cin >> minutes;
    while (minutes < 0 || minutes > 59){
        cout << "Please enter a valid amount of minutes (0 to 59): ";
        cin >> minutes;
    }
    cout << "Seconds: ";
    cin >> seconds;
    while (seconds < 0 || seconds > 59){
        cout << "Please enter a valid amount of seconds (0 to 59): ";
        cin >> seconds;
    }
    cout << "Your running pace is " << convertToMPH(minutes, seconds) << " miles per hour." << endl;

    // Prompts the user to enter a running pace in kilometers per hour
    cout << "\nEnter a running pace in kilometers per hour: ";
    cin >> kph;
    cout << "Your running pace is " << convertToMPH(kph) << " miles per hour." << endl;

	return 0;
}

double convertToMPH(int minutes, int seconds) {
	// There are 3600 seconds in an hour
	return (3600.0 / ((minutes * 60) + seconds));
}

double convertToMPH(double kph) {
	return (kph / 1.61);
}