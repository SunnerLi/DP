/*
	written by SunnerLi
	This code is the activity selection problem
*/
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main(){
	int n = 0;				// the number of activity
	int start[101]={0};		// the start time of activity
	int end[101]={0};		// the end time of activity
	int change[101]={0};	// the object to record the greedy result
	list<int> ll;

	// get each activity's start and end time
	cin >> n;
	for(int i=1; i<=n; i++)
		cin >> start[i];
	for(int i=1; i<=n; i++)
		cin >> end[i];
	for(int i=1; i<=n; i++)
		change[i] = i;

	// sort the activity
	for(int i=1; i<=n; i++){
		for(int j=i+1; j<=n; j++){
			if(end[i]>end[j]){
				swap(start[i], start[j]);
				swap(end[i], end[j]);
				swap(change[i], change[j]);
			}
		}
	}

	// greedy select the activity
	ll.push_back(change[1]);
	for(int i=2, j=1; i<=n; i++){
		if(start[i] >= end[j]){
			ll.push_back(change[i]);
			j = i;
		}
	}
	ll.sort();

	// show the result
	cout << ll.size() << endl << '(';
	for(;;){
		cout << ll.front();
		ll.pop_front();
		if(ll.size()<1)
			break;
		cout << ',';
	}
	cout << ')' << endl;
}