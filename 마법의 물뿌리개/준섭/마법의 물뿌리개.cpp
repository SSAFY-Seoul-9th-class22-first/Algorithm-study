#include <iostream>

using namespace std;

int main() {

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {

        int n; cin >> n;
        int arr[101] = {0, };
        int MAX = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if (MAX < arr[i]) MAX = arr[i];
        }

        int two = 0; int one = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += (MAX - arr[i]);
            two += (MAX - arr[i]) / 2;
            one += (MAX - arr[i]) % 2;
        }

        ans = (ans * 2) - 1;
        while (two) {
            if (two >= one) {
                int d = 2 * two;
                if (d < ans) ans = d;
            }
            else {
                int d = 2 * one - 1;
                if (d < ans) ans = d;
            }
            two--;
            one += 2;
        }
        if (ans == -1) ans = 0;

        cout << "#" << t << " " << ans << endl;
    }

    return 0;
}