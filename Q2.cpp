#include <iostream>
using namespace std;

void computeCoin(int coinValue, int& number, int& amountLeft);
void printOutput(int coinValue, int number);

int main() {
	char compute_again = 'N';
	int number = 0,
	    amountLeft = 0;

	do {
		cout << "Enter the amount of change: ";
		cin  >> amountLeft;
		while (amountLeft < 1 || amountLeft > 99) {
			cout << "Enter a value between 1 and 99: ";
			cin  >> amountLeft;
		}

		cout << "\nChange can be given as:" << endl;
		computeCoin(25,number,amountLeft);
		printOutput(25,number);
		computeCoin(10,number,amountLeft);
		printOutput(10,number);
		computeCoin(1,number,amountLeft);
		printOutput(1,number);

		cout << "\nDo you want to make change again?" << endl
		     << "Enter Y to convert again and any other key to exit: ";
		cin  >> compute_again;

	} while(compute_again == 'Y' || compute_again == 'y');
	return 0;
}

void computeCoin(int coinValue, int& number, int& amountLeft) {
	number = amountLeft/coinValue;
	amountLeft -= number * coinValue;
}

void printOutput(int coinValue, int number) {
	switch(coinValue) {
		case 25:
			if (number == 1)
				cout << number << " quarter" << endl;
			else
				cout << number << " quarters" << endl;
			break;
		case 10:
			if (number == 1)
				cout << number << " dime" << endl;
			else	
				cout << number << " dimes" << endl;
			break;
		case 1:
			if (number == 1)
				cout << number << " penny" << endl;
			else
				cout << number << " pennies" << endl;
			break;
	}
}