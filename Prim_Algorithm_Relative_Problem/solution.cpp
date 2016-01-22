/*
	written by SunnerLi
	This code is the MST problem solved by prim algorithm 
*/
#include <iostream>
#include <vector>
#include <list>
#define MAX 65536
using namespace std;

int start[201] = {0}, end[201] = {0}, weight[201] = {0};	// store input info
int key[201] = {0}, exist[201] = {0}, parent[201] = {0};	// output & help array
int n, m, s;

// Check if whole node is considered
bool isNull(){
	for(int i=1; i<=n; i++)
		if(exist[i] == 0)
			return false;
	return true;
}

// Get the node that has minimum weight
int ExtractMin(){
	int min = MAX, index = -1;
	for(int i=1; i<=n; i++){
		if(key[i]<min && (!exist[i])){
			index = i;
			min = key[i];
		}
	}
	return index;
}

int main(){
	// get the input adjancency list
	cin >> n >> m;
	for(int i=1; i<=m; i++)
		cin >> start[i] >> end[i] >> weight[i];
	cin >> s;

	// initialize the key
	for(int i=0; i<=n; i++)
		key[i] = MAX;
	key[s] = 0;

	// Prim
	for(int j=1; j<=n && !isNull(); j++){
		int u = ExtractMin();
		for(int i=1; i<=m; i++){
			// Find the neighbor(non-direct)
			if(start[i] == u){
				if((!exist[end[i]]) && weight[i]<key[end[i]]){
					key[end[i]] = weight[i];
					parent[end[i]] = u;
				}
			}
			// the opposite direction should be consider too
			if(end[i] == u){
				if((!exist[start[i]]) && weight[i]<key[start[i]]){
					key[start[i]] = weight[i];
					parent[start[i]] = u;
				}
			}
		}
		exist[u] = 1;
	}

	// show result
	for(int i=1; i<=n; i++)
		cout << parent[i] << ' ';
	cout << endl;
	int sum = 0;
	for(int i=1; i<=n; i++)
		sum += key[i];
	cout << sum << endl;
}