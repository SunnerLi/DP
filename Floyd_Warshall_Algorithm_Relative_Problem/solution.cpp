/*
	written by SunnerLi
	This code is the All-pair shortest path problem.
	Solved by Floyd-Warshall algorithm 
*/
#include <iostream>
#define MAX 65536
using namespace std;

int main(){
	// initialize the variable
	int n, m, map[201][201] = {0}, o, p;
	cin >> n >> m;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			if(i!=j)
				map[i][j] = MAX;
	for(int i=1; i<=m; i++){
		cin >> o >> p;
		cin >> map[o][p];
	}

	// Floyd-Warshall
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			for(int k=1; k<=n; k++)
				if(map[j][k] > map[j][i]+map[i][k])
					map[j][k] = map[j][i]+map[i][k];

	// show result
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(map[i][j]<MAX)
				cout << map[i][j] << ' ';
			else
				cout << 'N' << ' ';
		}
		cout << endl;
	}
}