#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

#include "UserInterface.h"

void UserInterface::run() {

	bool loop = true;
	do {

		int choice1;
		bool keepOn1 = true;
		bool drinkPicked = false;

		while (keepOn1) {
			cout << "########## DRINK MENU ###########" << endl;
			cout << "1 - Coffee" << endl;
			cout << "2 - Espresso" << endl;
			cout << "3 - Tea" << endl;
			cout << "4 - Chocolate" << endl;
			cout << "0 - Quit" << endl;

			while (!(cin >> choice1) || choice1 < 0 || choice1 > 4) {
				cin.clear();
				cin.ignore(cin.rdbuf()->in_avail());
				cout << "That is not a valid option. Please choose again." << endl;
			}

			switch (choice1) {
			case 1:	firstComp = new CoffeComponent(); keepOn1 = false; drinkPicked = true; break;
			case 2:	firstComp = new EspressoComponent(); keepOn1 = false; drinkPicked = true; break;
			case 3: firstComp = new TeaComponent(); keepOn1 = false; drinkPicked = true; break;
			case 4: firstComp = new ChocolateComponent(); keepOn1 = false; drinkPicked = true; break;
			case 0:	keepOn1 = false; loop = false; break;
			}
	
		}

		int choice2;
		bool keepOn2 = true;
		while (keepOn2 && drinkPicked) {


			cout << "########## CONDIMENTS ###########" << endl;
			cout << "1 - Sugar" << endl;
			cout << "2 - Milk" << endl;
			cout << "3 - Cream" << endl;
			cout << "4 - Whipped Cream" << endl;
			cout << "0 - Finished" << endl;

			while (!(cin >> choice2) || choice2 < 0 || choice2 > 4) {
				cin.clear();
				cin.ignore(cin.rdbuf()->in_avail());
				cout << "That is not a valid option. Please choose again." << endl;
			}

			switch (choice2) {
			case 1: firstComp = new SugarDecorator(firstComp);	break;
			case 2: firstComp = new MilkDecorator(firstComp); break;
			case 3: firstComp = new CreamDecorator(firstComp); break;
			case 4: firstComp = new WhippedCreamDecorator(firstComp); break;
			case 0: keepOn2 = false; break;
			}  
		} 

		cout << "Your order: ";
		printDesc();
		cout << "Price: ";
		printCost();
		cout << " kr" << endl;

	} while (loop);
}