#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

vector< vector<int> > v;

struct compare {
	bool operator()(vector<int> &a, vector<int> &b) {
		if (a[1] == b[1]) {
			return a[0] > b[0];
		}
		return a[1] >= b[1];
	}
};

int main() {
	priority_queue<vector<int>, vector< vector<int> >, compare> T;
	int number;
	int a, b;
	cin >> number;

	for (int i = 0; i < number; i++) {
		cin >> a >> b;
		vector<int> v;
		v.push_back(a);
		v.push_back(b);
		T.push(v);
	}

	int count = 1;
	vector<int> c = T.top();
	vector<int> d;

	while(!T.empty()) {
		T.pop();
		if (T.empty()) {
			cout << count << endl;
			return 0;
		}
		else {
			d = T.top();
			if (c[1] <= d[0]) {
				c = d;
				count++;
			}
		}
	}
}