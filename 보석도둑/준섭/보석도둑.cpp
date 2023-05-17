#include <iostream>
#include <algorithm>
#include <deque>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

deque<int> bag;
deque<pii> item;

int main() {

	int n, k;
	cin >> n >> k;
	priority_queue<int> q;
	for (int i{}; i < n; i++) {
		int m, v;
		cin >> m >> v;
		item.push_back({ m, v });
	}

	for (int i{}; i < k; i++) {
		int w;
		cin >> w;
		bag.push_back(w);
	}

	sort(bag.begin(), bag.end());
	sort(item.begin(), item.end());

	long long ans = 0;
	int index = 0;
	for (int i{}; i < k; i++) {
		
		while (index < n and item[index].first <= bag[i]) q.push(item[index++].second);

		if (!q.empty()) {
			ans += q.top();
			q.pop();
		}
	}

	cout << ans;
	return 0;
}