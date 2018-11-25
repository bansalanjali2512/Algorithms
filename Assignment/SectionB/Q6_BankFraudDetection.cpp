/*
    Q.6:  Suppose you’re consulting for a bank that’s concerned about fraud detection,
    and they come to you with the following problem. They have a collection of n bank
    cards that they’ve confiscated, suspecting them of being used in fraud. Each bank
    card is a small plastic object, containing a magnetic stripe with some encrypted
    data, and it corresponds to a unique account in the bank. Each account can have many
    bank cards corresponding to it, and two bank cards are equivalent if they correspond
    to the same account. It’s very difficult to read the account number off a bank card
    directly, but the bank has a high-tech “equivalence tester” that takes two bank cards
    and, after performing some computations, determines whether they are equivalent.

    Their question is the following: among the collection of  cards, is there a set of
    more thann/2 of them that are all equivalent to one another? Assume that the only
    feasible operations you can do with the cards are to pick two of them and plug them
    in to the equivalence tester. Show how to decide the answer to their question with
    only O(n log n) invocations of the equivalence tester.

    Submitted By: Anjali Bansal (04)
*/

#include<iostream>
#include<math.h>

using namespace std;

//******************************
//function declaration
//******************************

int checkMajorityCard(int cards[], int n);
bool equivalenceTester(int card1, int card2);
int frequency(int card, int cards[], int n);


//******************************
//main function
//******************************

int main()
{
	/*
        Objective       : To solve bank fraud detection problem
        Input parameters: None
        Return Value    : Integer
    */

	int *bankCards, n;
	cout << "\n Enter number of bank cards: ";
    cin >> n;

    //input account number for each bank card
	bankCards = new int[n];
	for(int i = 0; i < n; i++) {
		cout << "\n Enter bank card " << (i + 1) << " account number: ";
		cin >> bankCards[i];
	}

	//check majority card exists in bankcards or not
	int result = checkMajorityCard(bankCards, n);
	if(result != -1) {
		cout << "\n Majority card exists!";
		cout << "\n Account Number is: " << result;
	}
	else {
		cout<<"\n Majority card not exists!";
	}

	cout << endl;
	return 0;
}


//******************************
//function definition
//******************************

int checkMajorityCard(int cards[], int n) {
	/*
        Objective       : To check for subsequence in a given string
        Input parameters: sequence - string, sequence S
                          subsequence - string, subsequence S'
        Return Value    : account number of majority  card or -1 if there is no majority card
    */

	// if there is only one card which is majority in itself
	if(n==1) {
		return cards[0];
	}

	int leftMajorityFreq;
	int rightMajorityFreq;
	int leftMajorityCard;
	int rightMajorityCard;
	int mid = floor(n/2);
	int *leftSubcards = new int[mid];
	int *rightSubcards = new int[n - mid];

	for(int i = 0; i < mid; i++) {
		leftSubcards[i] = cards[i];
	}
	int j = 0;
	for(int i = mid; i < n; i++) {
		rightSubcards[j++] = cards[i];
	}

	// Recursive calls to function checkMajorityCard
	leftMajorityCard = checkMajorityCard(leftSubcards,mid);
	rightMajorityCard = checkMajorityCard(rightSubcards,n-mid);

	if(equivalenceTester(leftMajorityCard, rightMajorityCard)) {
		return leftMajorityCard;
	}

	leftMajorityFreq = frequency(leftMajorityCard, cards, n);
	rightMajorityFreq = frequency(rightMajorityCard, cards, n);

	if(leftMajorityFreq > mid) {
		return leftMajorityCard;
	}
	if(rightMajorityFreq > mid) {
		return rightMajorityCard;
	}

	return -1;
}


bool equivalenceTester(int card1, int card2) {
	/*
        Objective       : To check whether two cards belong to same account
        Input parameters: card1 - account number for card 1
                          card2 - account number for card 2
        Return Value    : True, if both cards belong to same account otherwise, false
    */

	if(card1 == card2) {
		return true;
	}
	else {
		return false;
	}
}


int frequency(int card, int cards[], int n)
{
	/*
        Objective       : To calculate the number of cards associated to same account as that of the card passed to this function
        Input parameters: card - holds the account number of card to be tested
                          cards - array of cards
        Return Value    : number of cards associated to same account as that of the card passed to this function
    */

	int count = 0;
	for(int i = 0; i < n; i++) {
		if(equivalenceTester(cards[i],card))
			count++;
	}
	return count;
}
