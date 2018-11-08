/*
    Q.5: Some of your friends have gotten into the burgeoning field of time-series
    data mining, in which one looks for patterns in sequences of events that occur
    over time. Purchases at stock exchanges --- what's being bought --- are one
    source of data with a natural ordering in time.

    Given a long sequence S of such events, your friends want an efficient way to
    detect certain "patterns" in them --- e.g. they may want to know if the four events
              buy Yahoo, buy eBay, buy Yahoo, buy Oracle
    occur in this sequence S, in order but not necessarily consecutively. They begin
    with a finite collection of possible events (e.g. the possible transactions) and a
    sequence S of n of these events. A given event may occur multiple times in S (e.g.
    Yahoo stock may be bought many times in a single sequence S). We will say that a
    sequence S' is a subsequence of S if there is a way to delete certain of the events
    from S so that the remaining events, in order, are equal to the sequence S'. So for
    example, the sequence of four events above is a sub-sequence of the sequence
          buy Amazon, buy Yahoo, buy eBay, buy Yahoo, buy Yahoo, buy Oracle

    Their goal is to be able to dream up short sequences and quickly detect whether they
    are subsequences of S. So this is the problem they pose to you: Give an algorithm
    that takes two sequences of events --- S' of length m and S of length n, each possibly
    containing an event more than once --- and decides in time O (m + n) whether S' is a
    subsequence of S.

    Submitted By: Anjali Bansal (04)
*/

#include <iostream>
using namespace std;

//******************************
//function declaration
//******************************

bool isSubsequence(string sequence, string subsequence);


//******************************
//main function
//******************************

int main () {
    /*
        Objective       : To check for subsequence in a given string
        Input parameters: None
        Return Value    : Integer
    */

    string sequence;        //for sequence S
    string subsequence;     //for subsequence S'

    cout << "\n Enter Sequence(S): ";
    getline(cin,sequence);
    cout << "\n Enter Subsequence(S'): ";
    getline(cin,subsequence);

    cout << "\n Sequence(S): " << sequence;
    cout << "\n Subsequence(S'): " << subsequence;
    //check if subsequence or not
    if(isSubsequence(sequence, subsequence)) {
        cout << "\n\n Subsequence detected. S' is subsequence of S!";
    }
    else {
        cout << "\n\n S' is not a subsequence of S!";
    }

    cout << endl;
    return 0;
}


//******************************
//function definition
//******************************

bool isSubsequence(string sequence, string subsequence) {
    /*
        Objective       : To check for subsequence in a given string
        Input parameters: sequence - string, sequence S
                          subsequence - string, subsequence S'
        Return Value    : true, if subsequence found
                          otherwise, false
    */

    int n = sequence.length();      //length of sequence
    int m = subsequence.length();   //length of subsequence

    int j = 0;
    //for loop till length of sequence
    for(int  i = 0; i < n; ++i) {
    	//break if all chars of subsequence are checked
        if(j == m) {
            break;
        }
        //increment j if subsequence[j] is equal to sequence[i]
        if(subsequence[j] == sequence[i]) {
            j++;
        }
    }

    //subsequence found if j is equal to length of subsequence
    if(j == m) {
        return true ;
    }

    return false;
}
