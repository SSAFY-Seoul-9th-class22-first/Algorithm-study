#include<iostream>
#include<algorithm>
#include<set>

using namespace std;
using pii = pair<int, int>;

int g, p;
int air[100100];
set<int> Set;

void input() {
	cin >> g >> p;
	for (int i = 1; i <= g; ++i) {
		Set.insert(-1*i);
	}
	for (int i = 0; i < p; ++i) {
		cin >> air[i];
		air[i] *= -1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int ret = 0;
	input();

	for (int i = 0; i < p; ++i) {
		int now = air[i];
		auto it = Set.lower_bound(now);
		if (it != Set.end()) {
			Set.erase(it);
			ret++;
		}
		else break;
	}

	cout << ret;

}
