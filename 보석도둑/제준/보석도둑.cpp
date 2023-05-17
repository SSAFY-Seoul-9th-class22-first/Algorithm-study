#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
	int weight;
	int cost;
	bool operator < (Node next) const {
		if (cost < next.cost) return true;
		if (cost > next.cost) return false;
		return false;
	}
};

Node jewel[303030];
int bags[303030];

bool cmp(Node first, Node second) {
	if (first.weight < second.weight) return true;
	if (first.weight > second.weight) return false;
	return false;
}

int main() {
	int N, K;
	long long sum = 0;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int m, v;
		cin >> m >> v;
		jewel[i] = { m, v };
	}
	for (int i = 0; i < K; i++) {
		int c;
		cin >> c;
		bags[i] = c;
	}
	// 무게가 작은순으로
	sort(jewel, jewel + N, cmp);
	sort(bags, bags + K);

	int index = 0;
	priority_queue<Node> pq;

	for (int i = 0; i < K; i++) {
		while (index < N && bags[i] >= jewel[index].weight) {
			pq.push({ jewel[index].weight, jewel[index].cost });
			index++;
		}
		if (!pq.empty()) {
			sum += pq.top().cost;
			pq.pop();
		}
	}

	cout << sum;
}