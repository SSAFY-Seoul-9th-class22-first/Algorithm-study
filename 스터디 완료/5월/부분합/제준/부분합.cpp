#include <iostream>
using namespace std;

int N, S;
int arr[101010];

int main() {
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int start = 0;
	int end = 1;
	int sum = arr[0];
	int shortest_cnt = 101010;

	while (end <= N) {
		if (sum >= S) {
			int temp = end - start;
			if (temp < shortest_cnt) shortest_cnt = temp;
			sum -= arr[start];
			start++;
		}
		else {
			sum += arr[end];
			end++;
		}
	}

	if (shortest_cnt == 101010) shortest_cnt = 0;
	cout << shortest_cnt;
}