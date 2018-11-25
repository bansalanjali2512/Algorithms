/*
    Q.8 : Your friends are starting a security company that needs to obtain licenses for
    n different pieces of cryptographic software. Due to regulations, they can only obtain
    these licenses at the rate of at most one per month. Each license is currently selling
    for a price of $100 . However, they are all becoming more expensive according to
    exponential growth curves: in particular, the cost of license j increases by a factor of
    rj greater than 1 each month, where rj is a given parameter. This means that if license %
    is purchased + months from now, it will cost 100.rj(t). We will assume that all the price
    growth rates are distinct; that is ri ≠ rj for license i ≠ j(even though they start at
    the same price of $100). The question is that: Given that the company can only buy at
    most one license a month, in which order should it buy the license so that the total
    amount of money it spends is as small as possible.

    Give an algorithm that takes the n rates of price growth r1, r2,..., rn and computes an
    order in which to buy the license so that the total amount of spent is minimized. The
    running time of the algorithm should be polynomial in n.

    Submitted By: Anjali Bansal (04)
*/

#include<iostream>
#include<math.h>

using namespace std;

struct license{
	// Objective: structure to store license no. along with rate of growth of its price
	int license_no;
	float rate_of_growth;
};

//******************************
//function declaration
//******************************

int findMax(license l_arr[], int n);
void printOrder(license l_arr[], int n);
float amount(license l_arr[], int n);


//******************************
//main function
//******************************

int main(){
    /*
        Objective       : To solve license purchase problem
        Input parameters: None
        Return Value    : Integer
    */

	int n;
	cout << "\n License Purchase Problem \n";

	while(true) {
		cout << "\n Enter number of cryptographic softwares: ";
		cin >> n;
        //number of software must be atleast 1
		if(n >= 1) {
			break;
		}
		else {
			cout << "\n Number of softwares should be atleast 1!";
		}
	}

	license *l = new license[n];
	//input rate
	for(int i=0; i<n; i++) {
		float temp;
		cout << "\n Enter rate of growth for license " << i+1 << " : ";
		cin >> temp;

		//test whether rate entered is greater than 1 or not
		if(temp <= 1) {
			cout << "\nrate must be greater than 1!";
			i--;
			continue;
		}
		l[i].license_no = i+1;
		l[i].rate_of_growth = temp;
	}

	cout << "\n Order of buying license: ";
	printOrder(l, n);
	cout<<"\n Minimized amount is: $" << amount(l, n);
}


//******************************
//function definition
//******************************

int findMax(license l_arr[], int n) {
    /*
        Objective       : To find license number with maximum rate_of_growth
        Input parameters: l_arr - array of objects of license type
                          n - number of objects in array l_arr
        Return Value    : the license_no of software having maximum rate_of_growth value in l_arr
    */

	//max stores the index of license with most expensive license growth rate in array l
	int max = 0;

	//tranversing entire array to find most expensive license
	for(int i = 1; i < n;i++) {
		if(l_arr[i].rate_of_growth > l_arr[max].rate_of_growth) {
			max = i;
		}
	}

	//Now, max index has most expensive license in l_arr, so swap it with first license object of l_arr
	swap(l_arr[0].rate_of_growth, l_arr[max].rate_of_growth);
	swap(l_arr[0].license_no, l_arr[max].license_no);

	//return the license of first license object in array l_arr
	return l_arr[0].license_no;
}

void printOrder(license l_arr[], int n) {
    /*
        Objective       : To find and print the order of buying license
        Input parameters: l_arr - array of objects of license type
                          n - number of objects in array l_arr
        Return Value    : None
    */

	for(int i = 0; i < n; i++) {
		//call to find maximum from the remaining array l[i..n-1]
		cout << "\n License "<<findMax((l_arr+i), n-i);
		cout << "  : Rate "<<l_arr[i].rate_of_growth<<endl;
	}
}

float amount(license l_arr[], int n) {
    /*
        Objective       : To find the total minimized amount to be spend to buy license
        Input parameters: l_arr - array of objects of license type
                          n - number of objects in array l_arr
        Return Value    : the total minimized amount to be spend to buy license
    */

	float amount  = 0;
	for(int i = 0; i < n; i++) {
		amount += pow(l_arr[i].rate_of_growth, i);
	}

	return amount*100;
}
