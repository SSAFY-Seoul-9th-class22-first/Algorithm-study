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

		// ���� ���� ���� ã��
		for (int i = 0; i < N; i++) {
			if (mx < tree[i]) mx = tree[i];
		}

		// ���� ���� ���� - ���� ����, ���� 2�� �ִ��� ����
		for (int i = 0; i < N; i++) {
			num2 += (mx - tree[i]) / 2;
			num1 += (mx - tree[i]) % 2;
		}

		int days_min = 10000;
		while (num2 >= 0) {
			// ���̰� 2�� ������ ���ٸ�
			if (num2 >= num1) {
				// �Ҹ��ϼ��� ���̰� 2�� �������� * 2
				int days = 2 * num2;
				if (days < days_min) days_min = days;
			}
			// ���̰� 1�� ������ ���ٸ�
			else {
				// �Ҹ��ϼ��� ���̰� 1�� �������� * 2 - 1
				int days = 2 * num1 - 1;
				if (days < days_min) days_min = days;
			}
			// ���̰� 2�� ������ �ϳ��� ���̰�, ���̰� 1�� ������ �ΰ��� �÷����� ����
			num2--;
			num1 += 2;
		}

		cout << "#" << test_case << " " << days_min << '\n';
		for (int i = 0; i < N; i++) tree[i] = 0;

	}
}
