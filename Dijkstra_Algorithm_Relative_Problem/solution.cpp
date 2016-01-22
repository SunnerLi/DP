/*
	written by SunnerLi
	This code is the single-source shortest path problem.
	Solved by Dijkstra algorithm 
*/
#include <iostream>
#include <vector>
#include <list>
#define MAX 65536
using namespace std;

int start[201] = {0}, end[201] = {0}, weight[201] = {0};// store input info
int key[201] = {0}, exist[201] = {0}, parent[201] = {0};// output & help array
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
	/*
		Some node that just have one-direction way.
		So if it's not the start node, the node cannot be access
		=> parent is -1
	*/
	for(int i=0; i<=n; i++){
		key[i] = MAX;
		parent[i] = -1;
	}
	key[s] = 0;
	parent[s] = 0;

	// Dijkstra
	for(int j=1; j<=n && !isNull(); j++){
		int u = ExtractMin();
		for(int i=1; i<=m; i++){
			if(start[i] == u){
				if((!exist[end[i]]) && weight[i]+key[u]<key[end[i]] ){
					key[end[i]] = weight[i]+key[u];
					parent[end[i]] = u;
				}
			}
		}
		exist[u] = 1;
	}

	// show result
	for(int i=1; i<=n; i++)
		cout << key[i] << ' ';
	cout << endl;
	for(int i=1; i<=n; i++)
		cout << parent[i] << ' ';
	cout << endl;
}