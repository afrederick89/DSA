 /*      Author: Alexander Frederick *  Deck/Shuffle Assignment * Due: 30 Aug 2017
  *      CS1C Monday/Wednesday 1330 - 1620
  */

#ifndef HEADER_H_
#define HEADER_H_

#include <iostream>
#include <string>
using namespace std;


string suits[] {"Hearts", "Diamonds", "Clubs", "Spades"};
string ranks[]	{"Ace", "Two", "Three", "Four", "Five", "Six", "Seven",
		         "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
//Structure to contain the card data
struct card {
	string suit;
	string rank;
};
//Deck class to contain 52 cards and initialize them in order of suits
//and rank.
class deck {
public :
	deck();
	~deck();
	void printDeck();
	void shuffleDeck();
	bool compareDeck(const deck& otherDeck) const;
private :
	card cDeck[52];
};

//Class methods
deck::deck() {
	int k = 0;
	for(int i = 0; i < 4; ++i) {
		for(int j = 0; j < 13; ++j){
			cDeck[k].suit = suits[i];
			cDeck[k].rank = ranks[j];
			++k;
		}
	}
};

deck::~deck() {

};

void deck::printDeck() {
	int k = 0;
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 13; j++) {
			cout << cDeck[k].rank << " of " << cDeck[k].suit << '\n';
			++k;
		}
	}
	cout << endl << endl;
};

void deck::shuffleDeck() {

	card fHalf[26];
	card sHalf[26];
	for(int i = 0; i < 26; ++i) {
		fHalf[i].suit = cDeck[i].suit;
		fHalf[i].rank = cDeck[i].rank;
		sHalf[i].suit = cDeck[i+26].suit;
		sHalf[i].rank = cDeck[i+26].rank;
	}
	for(int j = 0; j < 26; ++j) {
		cDeck[j*2].suit = fHalf[j].suit;
		cDeck[j*2].rank = fHalf[j].rank;
		cDeck[j*2+1].suit = sHalf[j].suit;
		cDeck[j*2+1].rank = sHalf[j].rank;

	}

};

bool deck::compareDeck(const deck& otherDeck) const {
	bool diff = false;
	int i = 0;
	while(i < 52 && diff == false) {
		if(this->cDeck[i].suit == otherDeck.cDeck[i].suit &&
		   this->cDeck[i].rank == otherDeck.cDeck[i].rank){
			diff = false;
		} else {
			diff = true;
		}
		++i;
	}
	return diff;
};

#endif /* HEADER_H_ */
