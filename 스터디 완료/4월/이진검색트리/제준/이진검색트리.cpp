#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int arr[10101];

void dfs(int start, int end) {
	if (start == end) return;
	if (start == end - 1) {
		cout << arr[start] << '\n';
		return;
	}

	int temp = start;
	while (temp < end) {
		temp++;
		if (arr[start] < arr[temp]) break;
	}

	dfs(start+1, temp);
	dfs(temp, end);
	cout << arr[start] << '\n';
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int index = 0;
	int num;
	while (cin >> num) {
		arr[index++] = num;
	}

	dfs(0, index);
}