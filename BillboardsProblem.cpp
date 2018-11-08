/*
    Q.4:  Suppose you are managing the construction of billboards on the university
    road, a heavily travelled stretch of road that runs west-east for M miles. The
    possible sites for billboards are given by numbers x1, x2,...xn each in the interval
    [0,M] (specifying their position along the roads, measured in miles from its western
    end). If you place billboard at location xi, you receive revenue of ri > 0.

    Regulations imposed by the Delhi road authority require that no two billboards be within
    less than or equal to 5 miles of each other. You had like to place billboards at a
    subset of the sites so as to maximize your total revenue, subject to this restriction.

    Example: Suppose M=20, n=4
    {x1,x2,x3,x4} = {6,7,12,14} and {r1,r2,r3,r4} = {5,6,5,1}.
    Then the optimal solution would be to place billboards at x1 and x3 for total
    revenue of 10.

    Give an algorithm that takes an instance of this problem as input and returns the
    maximum total revenue that can be obtained from any valid subsets of sites.

    Submitted By: Anjali Bansal (04)
*/

#include <iostream>
using namespace std;

#define minDistance 5

//******************************
//function declaration
//******************************

int billboardMaxRevenue(int sites[], int revenue[], int m, int n, int minDist);


//******************************
//main function
//******************************

int main () {
    /*
        Objective       : To solve billboards problem
        Input parameters: None
        Return Value    : Integer
    */

    int m;          //total miles
    int n;          //total billboards

    cout << "\n Enter number of miles (m): ";
	cin >> m;
	cout << "\n Enter number of billboards (n): ";
	cin >> n;

    int sites[n];   //possible sites for billboards
    int revenue[n]; //revenue for each site

    cout << "\n Enter Billboard Sites: ";
	for(int i = 0; i < n; i++) {
		cin >> sites[i];
	}

	cout << "\n Enter Revenues: ";
	for(int i = 0; i < n; i++) {
		cin >> revenue[i];
	}

    cout << "\n Maximum Billboard Revenue: ";
    cout << billboardMaxRevenue(sites, revenue, m, n, minDistance);

    cout << endl;
    return 0;
}


//******************************
//function definition
//******************************

int billboardMaxRevenue(int sites[], int revenue[], int m, int n, int minDist) {
    /*
        Objective       : To solve billboards problem and calculate max revenue
        Input parameters: m - Integer, total miles
                          n - Integer, total billboards
                          minDist - Integer, minimum distance in two boards
                          sites - Integer array, possible sites for billboards
                          revenue - Integer array, revenue for each site
        Return Value    : Integer, maximum revenue
    */

	int maxRevenue[m+1];    //max revenue for m
	int nextBoard = 0;     //counter to check the placed billboards

	maxRevenue[0] = 0;
	for(int i = 1; i <= m; i++)
	{
	    //check if any billboard left to get placed
		if(nextBoard < n) {
            //if billboard not available for that site, store (i-1)th revenue
			if(sites[nextBoard] != i) {
				maxRevenue[i] = maxRevenue[i-1];
			}
			else {
                //if no billboard if placed till now
                if(maxRevenue[i-1] == 0) {
                    maxRevenue[i] = revenue[nextBoard];
                }
                else {
                    //check billboard can be placed or not
                    if(i <= minDist) {
                        maxRevenue[i] = max(maxRevenue[i-1], revenue[nextBoard]);
                    }
                    else {
                        maxRevenue[i] = max(maxRevenue[i-minDist-1]+revenue[nextBoard], maxRevenue[i-1]);
                    }
                }
				nextBoard++;
			}
        }
		else {
            //all boards placed, store the max revenue
			maxRevenue[i] = maxRevenue[i-1];
		}
	}

	return maxRevenue[m];
}
