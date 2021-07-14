 /*  Author: Alexander Frederick * Deck/Shuffle Assignment * Due: 30 Aug 2017
  *  CS1C Monday/Wednesday 1330 - 1620
  */

#include "header.h"

int main(){

	deck myDeck; // User's Deck
	deck compDeck; // Initialized deck used for comparison
	int choice = 0; // INPUT - Users menu choice


	while(choice != 4) {
		cout << "\nWelcome to the shuffle simulator"
				"\nWhat would you like to do?\n";
		cout << "(1)View your deck\n(2)Shuffle your deck\n"
				"(3)Compare your deck\n(4)Exit\n";
		cin >> choice;
		//Error checking for invalid entry
		if(choice < 1 || choice > 4 || cin.fail()) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "\nInvalid entry please enter 1 through 4 to continue.\n";
		} else {
		  switch(choice) {
		  case 1 : myDeck.printDeck();
		    break;
		  case 2 : cout << "\nShuffling\n";
		           myDeck.shuffleDeck();
		    break;
	   	  case 3 : if(myDeck.compareDeck(compDeck)){
			         cout << "\nYour deck is different than initialized state.\n";
		           } else {
		               cout << "\nYour deck is the same as initialized state.\n";
		           }
		    break;
		  case 4 : cout << "\nExiting\n";
		 	  break;
		  }// END switch(choice)
		}// END IF ELSE if(choice < 1 || choice > 4 || cin.fail()
	} // END while(choice != 4)

	return 0;
}
