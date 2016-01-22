/*
	written by SunnerLi
	This code is the rod cutting problem
*/
#include <iostream>
#include <list>
using namespace std;

int main(){
	int length;				// the length of the rod
	int price[101]={0};		// the price of each piece
	int value[101]={0};		// the highest value of each piece
	int divide[101]={0};	// the devide length for each method

	//get each price of the length
	cin >> n;
	for(int i=1; i<=n; i++)
		cin >> price[i];

	//calculate the highest value(DP method)
	for(int i=1; i<=n; i++){
		int h = -1;
		for(int j=1; j<=i; j++){
			if(h < price[j] + value[i-j]){
				h = price[j] + value[i-j];
				divide[i] = j;
			}
		}
		value[i] = h;
	}

	//calculate the number of piece
	int length = n;
	while(length>0){
		ll.push_back(divide[length]);
		length -= divide[length];
	}
	ll.sort();
	ll.reverse();

	//print the result
	cout << value[n] << endl << ll.size() << endl;
	cout << n << '=';
	for(;;){
		cout << ll.front();
		ll.pop_front();
		if(ll.size()<1)
			break;
		cout << '+';
	}
	cout << endl;
}