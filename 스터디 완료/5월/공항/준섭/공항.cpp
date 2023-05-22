#include <iostream>

using namespace std;

int parent[101010];

int Find(int num) {
	if (num == parent[num]) return num;
	return parent[num] = Find(parent[num]);
}

int main() {
 
	int G, P;
	int input;
	cin >> G >> P;
	int ans = 0;

	for (int g = 1; g <= G; g++) {
		parent[g] = g;
	}

	for (int p{}; p < P; p++) {
		
		cin >> input;
		if (Find(input) == 0) break;
		else {
			ans++;
			parent[Find(input)] = Find(Find(input) - 1);
		}
	}
	cout << ans;
	return 0;
}