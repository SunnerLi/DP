/*
	written by SunnerLi
	This code is the single-source shortest path problem.
	Solved by Bellman-Ford algorithm 
*/
#include <iostream>
#define MAX 65536
using namespace std;

int start[201] = {0}, end[201] = {0}, weight[201] = {0};// store input info
int key[201] = {0}, exist[201] = {0}, parent[201] = {0};// output & help array
int n, m, s;

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

	// Bellman-Ford( relex for |V|-1 times )
	for(int i=1; i<n; i++){
		for(int j=1; j<=m; j++){
			if(key[end[j]]>key[start[j]]+weight[j]){
				key[end[j]] = key[start[j]]+weight[j];
				parent[end[j]] = start[j];
			}
		}
	}
	
	// check if there's negative circle
	bool circle = false;
	for(int j=1; j<=m; j++)
		if( key[end[j]]>key[start[j]]+weight[j] )
			circle = true;

	// show result
	if(circle)
		cout << "There is a negative weight cycle in the graph" << endl;
	else{
		for(int i=1; i<=n; i++)
			cout << key[i] << ' ';
		cout << endl;
		for(int i=1; i<=n; i++)
			cout << parent[i] << ' ';
		cout << endl;
	}
}