#include <iostream>
using namespace std;

long long nums[21][1010101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	long long N, M, K;
	cin >> N >> M >> K;

	// nums[0]에 다 저장
	// nums[1][0] = nums[0][0] + nums[0][1]
	// nums[1][1] = nums[0][2] + nums[0][3]
	// nums[2][0] -> nums[0][0] ~ nums[0][3]
	for (int i = 1; i <= N; i++) {
		cin >> nums[0][i];
	}
	for (int i = 1; i <= 20; i++) {
		for (int j = 0; j <= N / 2; j++) {
			nums[i][j] = nums[i - 1][2 * j] + nums[i - 1][2 * j + 1];
		}
	}

	for (int i = 0; i < M + K; i++) {
		long long a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			for (int i = 1; i <= 20; i++) {
				nums[i][b / (1 << i)] += (c - nums[0][b]);
			}
			nums[0][b] = c;
		}
		else if (a == 2) {
			long long sum_until_c = 0;
			long long sum_until_b_1 = 0;
			int flag = 0;
			c++;
			for (int i = 20; i >= 0; i--) {
				if (c / (1 << i) == 1) {
					flag = i;
					break;
				}
			}
			int temp_num = 0;
			for (int i = flag; i >= 0; i--) {
				if (c / (1 << i) == 1) {
					sum_until_c += nums[i][temp_num / (1 << i)];
					c -= (1 << i);
					temp_num += (1 << i);
				}
			}

			temp_num = 0;
			for (int i = 20; i >= 0; i--) {
				if (b / (1 << i) == 1) {
					flag = i;
					break;
				}
			}
			for (int i = flag; i >= 0; i--) {
				if (b / (1 << i) == 1) {
					sum_until_b_1 += nums[i][temp_num / (1 << i)];
					b -= (1 << i);
					temp_num += (1 << i);
				}
			}

			cout << sum_until_c - sum_until_b_1 << '\n';
		}
	}

}