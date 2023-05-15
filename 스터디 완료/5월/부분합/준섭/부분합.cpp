#include <iostream>
#include <algorithm>

using namespace std;

int arr[101010];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, s;

	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] >= s) {
			cout << 1;
			return 0;
		}
	}

	int si = 0;
	int ei = 0;
	int ans = 987654321;
	int sum = 0;

	while (si <= ei) {
		if (sum >= s) {
			ans = min(ans, ei - si);
			sum -= arr[si++];
		}

		else if (ei == n) break;
		else sum += arr[ei++];
	}

	if (ans == 987654321) cout << 0;
	else cout << ans;

	return 0;
}