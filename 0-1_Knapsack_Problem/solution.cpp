/*
	written by SunnerLi
	This code is the 0-1 knapsack problem
*/
#include <iostream>
#include <cmath>
#include <list>
using namespace std;

int weight[101] = {0};		// the weight of each things
int value[101] = {0};		// the value of each things
int op[101][101] = {0};		// the things-weight matrix
int maxWeight = 0;			// the max weight(upper limit)
int numberOfThings = 0;		// the number of things in this ques.
bool pick[101] = {false};	// the list to store if it is picked

int main(){
	// get the weight and value
	cin >> numberOfThings;
	for(int i=1; i<=numberOfThings; i++)
		cin >> value[i];
	for(int i=1; i<=numberOfThings; i++)
		cin >> weight[i];
	cin >> maxWeight;

	//initialize the op matrix
	/*
		0 0 .... 0
		0 ? .... ?
		. ? .... ?
		. ? .... ?
		0 ? .... ?
	*/
	for(int i=0; i<=numberOfThings; i++){
		op[i][0] = 0;
		op[0][i] = 0;
	}

	// 0-1(As the pseudocode in NTPU algorithm ppt)
	for(int i=1; i<=numberOfThings; i++){
		for(int j=1; j<=maxWeight; j++){
			if(weight[i]>j)
				op[i][j] = op[i-1][j];
			else{
				if( op[i-1][j]<value[i]+op[i-1][j-weight[i]] )
					op[i][j] = value[i]+op[i-1][j-weight[i]];
				else
					op[i][j] = op[i-1][j];
			}
		}
	}

	// get the best solution
	/*
		if we cannot get the best solution continuously,
		this item must be selected.
	*/
	int numberOfPick = 1;
	for(int i=numberOfThings, j=maxWeight; i>0; i--){
		if( op[i][j]!=op[i-1][j] && op[i][j]!=0){
			numberOfPick++;
			j -= weight[i];
			pick[i] = true;
		}
	}

	// show result
	cout << op[numberOfThings][maxWeight] << endl;
	cout << numberOfPick-1 << endl << "(";
	for(int i=1, j=1; i<=numberOfThings; i++){
		if(pick[i]==true){
			cout << i;
			j++;
			if(j!=numberOfPick)
				cout << ',';
		}
	}
	cout << ")" << endl;
}