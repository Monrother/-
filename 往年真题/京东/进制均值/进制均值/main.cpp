#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

int solve(int num, int radix) {
	// ���ؽ���ת��֮��ĸ�λ����֮��
	int cnt = 0;
	int remain = num;
	int sum = 0;
	while (remain != 0) {
		num = remain;
		int base = radix;
		while (num / radix != 0) {
			num /= radix;
			cnt++;
		}
		sum += num;
		remain -= num * 

	}
}

int main() {
	system("pause");
	return 0;
}
