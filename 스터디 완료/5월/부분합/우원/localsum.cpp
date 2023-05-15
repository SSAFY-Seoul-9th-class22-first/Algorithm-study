#include<iostream>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
#include<map>
#include<cmath>

#define R first
#define C second
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, s;
int len;
int arr[100100];

void input() {
	cin >> n >> s;
	for (int i = 0; i < n; ++i) cin >> arr[i];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	int minlen = 21e8;
	int l = 0;
	int r = l+1;
	int len = 1;
	int cumsum = arr[0];
	while (r <= n && l<=r) {
		if (cumsum < s) {
			cumsum += arr[r]; r++;
		}
		else { 
			len = r - l;
			minlen = min(minlen, len);
			cumsum -= arr[l]; l++;
		}
	}
	if (minlen == 21e8) cout << 0;
	else cout << minlen;
	
	return 0;
}
