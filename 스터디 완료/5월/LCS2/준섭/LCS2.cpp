#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int arr[1010][1010];

int main() {

	string str1, str2;
	cin >> str1 >> str2;

	for (int i = 1; i <= str1.size(); i++) {
		for (int j = 1; j <= str2.size(); j++) {
			if (str1[i - 1] == str2[j - 1]) arr[i][j] = arr[i - 1][j - 1] + 1;
			else arr[i][j] = max(arr[i][j - 1], arr[i - 1][j]);
		}
	}

	string ans = "";

	int i = str1.size();
	int j = str2.size();

	while (i != 0 || j != 0) {
		if (i && j && str1[i - 1] == str2[j - 1]) {
			ans += str1[i - 1];
			i--, j--;
		}
		else if (j && arr[i][j] == arr[i][j - 1]) j--;
		else i--;
	}
	

	reverse(ans.begin(), ans.end());
	cout << arr[str1.size()][str2.size()] << "\n" << ans;


	return 0;
}