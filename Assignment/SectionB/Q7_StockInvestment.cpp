/*
    Q.7: You are consultant working for a small computation-intensive investment company,
    and they have the following type of problem they want to solve over and over. A
    typical instance of the problem is the following. They are doing a simulation in
    which they look at n consecutive days of a given stock, at some point in the past.
    Let’s number the days  = 1,2,...; for each day i, they have a price "() per
    share for the stock on that day (For simplicity, the price was same during each day).

    Suppose during this time period, they wanted to buy 1000 shares on some day and sell
    all these shares on some (later) day. They want to know: When should they have bought
    and when should they have sold in order to have made as much money as possible. (If
    there was no way to make money during the n days, you should report this instead). For
    example, suppose n = 3, p(1)=9, p(2)= 1, p(3)= 5. Then you should return  “Buy on day 2
    and selling on day 3” means that they would have made $4 per share. Show how to find
    the correct numbers  and % in time &('().

    Submitted By: Anjali Bansal (04)
*/

#include <bits/stdc++.h>

using namespace std;

//******************************
//function declaration
//******************************

int maxProfit(vector<int> price);


//******************************
//main function
//******************************

int main()
{
    /*
        Objective       : To solve stock investment problem
        Input parameters: None
        Return Value    : Integer
    */

    int size;   //number of days
    int pricePerDay;
    vector<int> price;

    //input number of days
    cout << "\n Enter number of days: ";
    cin >> size;

    //check if days >= 2 or not
    while(size < 2) {
        cout << "\n Invalid Input! Days can be 2 or more!";
        cout << "\n Enter number of days again: ";
        cin >> size;
    }

    //input price for stocks
    cout << "\n Enter Price for stock: \n";
    for(int i=0;i < size;i++) {
        cout << "\n Enter price at day " << i+1 << ": ";
        cin >> pricePerDay;
        price.push_back(pricePerDay);
    }

    int shareNum = 1000;
    cout<<"\n Number of Shares: " << shareNum;

    int maxP = maxProfit(price);
    if(maxP > 0) {
        cout << "\n Maximum Profit Earned: " << shareNum * maxP;
    }

    cout<<endl;
    return 0;
}


//******************************
//function definition
//******************************

int maxProfit(vector<int> price) {
    /*
        Objective       : To find maximum profilt
        Input parameters: Vector, price
        Return Value    : Integer, maximum profit
    */

    int size = price.size();
    int buy = 0;       //initialize buy day
    int sell = 1;      //initialize sell day
    int temp = 0;
    int maxDiff = price[1] - price[0];
    int minEl = price[0];
    for(int i = 1; i < size; i++) {

        //compare current maximum difference with difference of each day's price with minimum
     	if (price[i] - minEl > maxDiff) {
       		maxDiff = price[i] - minEl;
       		buy = temp;    //update buy day
       		sell = i;      //update sell day
        }

        if (price[i] < minEl) {
       		minEl = price[i];
       		temp = i;
        }
    }

    if(maxDiff < 1) {
     	cout << "\n No Maximum Profit!";
    }
    else {
     	cout << "\n Buy Day: " << buy+1 << " and Sell Day:  " << sell+1;
    }

    cout << endl;
    return maxDiff;
}
