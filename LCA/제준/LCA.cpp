#include <iostream>
#include <vector>
using namespace std;

int parent[50505]; // index는 child value는 부모
vector<int> parents_a;
vector<int> parents_b;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	parent[1] = 1;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		if (parent[a] == 0) parent[a] = b;
		else parent[b] = a;
	}

	int M;
	cin >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		parents_a.reserve(50000);
		parents_b.reserve(50000);
		parents_a.push_back(a);
		parents_b.push_back(b);
		while (1) {
			if (a == 1) break;
			parents_a.push_back(parent[a]);
			a = parent[a];
		}
		while (1) {
			if (b == 1) break;
			parents_b.push_back(parent[b]);
			b = parent[b];
		}

		int temp = 1;
		while (1) {
			if (parents_a.size() < temp || parents_b.size() < temp) break;
			if (parents_a[parents_a.size() - temp] != parents_b[parents_b.size() - temp]) break;
			temp++;
		}
		temp--;
		cout << parents_a[parents_a.size() - temp] << '\n';
		parents_a.clear();
		parents_b.clear();
	}
}