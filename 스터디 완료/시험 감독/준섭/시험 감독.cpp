#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

int main() {
	// n개의 시험장
	// i번 시험장에 있는 응시자 수는 Ai명
	// 감독관 종류: 총감독관, 부감독관
	// 총감독관 한 시험장 감시 가능 응시자 수는 B
	// 부감독관은 C
	// 각각의 시험장에는 총감독관은 1명만
	// 부감독은 여러명 가능

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int input; cin >> input;
		v.push_back(input);
	}
	int b, c; cin >> b >> c;

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		ans++;
		v[i] = v[i] - b;
		if (v[i] > 0) {
			ans += v[i] / c;
			if (v[i] % c) ans++;
		}
	}
	cout << ans;

	return 0;
}