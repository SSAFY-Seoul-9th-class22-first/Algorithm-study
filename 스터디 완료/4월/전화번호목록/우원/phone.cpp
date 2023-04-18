#include<iostream>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
#include<set>

#define R first
#define C second
using namespace std;
using ll = long long;
using pii = pair<int, int>;


vector<string> numbers;
int n, T;

void input() {
    cin >> n;
    numbers.clear();
    for (int i = 0; i < n; ++i) {
        string a; cin >> a;
        numbers.push_back(a);
    }
}

int main() {
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        input();
        sort(numbers.begin(), numbers.end(), greater<string>());
        int flag = 0;
        int left = 0;
        int right = 1;
        while (right<=n-1){
            string str1 = numbers[left].size() >= numbers[right].size() ? numbers[left] : numbers[right];
            string str2 = numbers[left].size() >= numbers[right].size() ? numbers[right] : numbers[left];
            int ret = str1.find(str2);
            if (ret == 0) {
                flag = 1; break;
            }
            else {
                left++; right++;
            }

        }
        if (flag) cout << "NO\n";
        else cout << "YES\n";
    }




    return 0;
}
