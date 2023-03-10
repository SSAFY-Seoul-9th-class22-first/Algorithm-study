#include <iostream>
using namespace std;

int T;
int N;
int tree[101] = {};


int main() {
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> N;
		for (int i = 0; i < N; i++) cin >> tree[i];

		int mx = 0;
		int num1 = 0;
		int num2 = 0;

		// 가장 높은 나무 찾기
		for (int i = 0; i < N; i++) {
			if (mx < tree[i]) mx = tree[i];
		}

		// 가장 높은 나무 - 현재 나무, 길이 2로 최대한 보관
		for (int i = 0; i < N; i++) {
			num2 += (mx - tree[i]) / 2;
			num1 += (mx - tree[i]) % 2;
		}

		int days_min = 10000;
		while (num2 >= 0) {
			// 길이가 2인 나무가 많다면
			if (num2 >= num1) {
				// 소모일수는 길이가 2인 나무개수 * 2
				int days = 2 * num2;
				if (days < days_min) days_min = days;
			}
			// 길이가 1인 나무가 많다면
			else {
				// 소모일수는 길이가 1인 나무개수 * 2 - 1
				int days = 2 * num1 - 1;
				if (days < days_min) days_min = days;
			}
			// 길이가 2인 나무를 하나씩 줄이고, 길이가 1인 나무를 두개씩 늘려가며 진행
			num2--;
			num1 += 2;
		}

		cout << "#" << test_case << " " << days_min << '\n';
		for (int i = 0; i < N; i++) tree[i] = 0;

	}
}
