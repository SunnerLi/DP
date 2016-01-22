/*
	written by SunnerLi
	This code is the huffman coding problem
*/
#include <iostream>
#include <list>
#include <stack>
#define‬ MAX 101
using namespace std;

stack<int> sta;			// the object to store the huffman code
list<HuffmanTree> ll;	// the list to record the whole sub-tree 

class HuffmanTree{	// the class difinition of huffman tree
	public:
		// value
		// Ignore the warning while it doesn't matter
		int freq = 0, c = 0;
		HuffmanTree *left = 0, *right = 0;

		// method
		// 3 types of constructor( 0 is represent null )
		HuffmanTree(const HuffmanTree &h){
			freq = h.freq;
			c = h.c;
			left = h.left;
			right = h.right;
		}
		HuffmanTree(int i, int cc){
			freq = i;
			c = cc;
		}
		HuffmanTree(HuffmanTree *h1, HuffmanTree *h2){
			freq = h1->freq + h2->freq;
			left = h1;
			right = h2;
		}
};

// the compare method used in list.sort
bool compare(const HuffmanTree& a, const HuffmanTree& b){
	if(a.freq != b.freq)
		return (a.freq < b.freq);
	else
		return (a.c < b.c);
}

// print the huffman code by the stack
void printH(stack<int> s){
	stack<int> temp;
	while(s.size()>0){
		int _ = s.top();
		s.pop();
		temp.push(_);
	}
	while(temp.size()>0){
		cout << temp.top();
		temp.pop();
	}
	cout << ' ';
}

// show the tree inorder walk
void inorder(HuffmanTree *h, int pat){
	if(h!=NULL){
		sta.push(0);
		inorder(h->left, pat);
		sta.pop();

		if(h->c == pat)
			printH(sta);

		sta.push(1);
		inorder(h->right, pat);
		sta.pop();
}

int main(){
	// input char list
	int freq[MAX] = {0};	// the frequency list
	int n;					// the number of symbol
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> freq[i];

	// build tree list
	HuffmanTree *h1, *h2;
	for(int i=0; i<n; i++){
		h1 = new HuffmanTree(freq[i], i);
		ll.push_back(*h1);
	}
	ll.sort(compare);

	// huffman tree construct
	while(ll.size()>1){
		h1 = new HuffmanTree(ll.front());
		ll.pop_front();
		h2 = new HuffmanTree(ll.front());
		ll.pop_front();
		HuffmanTree h3(h1, h2);
		ll.push_back(h3);
		ll.sort(compare);
	}

	// show result
	cout << n << endl;
	for(int i=0; i<n; i++)
		inorder(&ll.front(), i);
	cout << endl;
}