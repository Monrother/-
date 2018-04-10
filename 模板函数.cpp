#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

// ��ȡһ������Ļ���ͼ
void initSumMatrix(vector<vector<int> > & sum, const vector<vector<int> >& matrix) {
	int m = matrix.size();
	for (int i = 0; i <= m; i++) {
	int n = matrix[0].size();
		for (int j = 0; j <= n; j++) {
			if (i == 0 || j == 0)
				sum[i][j] = 0;
			else
				sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + matrix[i - 1][j - 1];
		}
	}
}

// ��ȡ�Ӿ����
	// ��ȡ���Ͻ�Ϊx1, y1, ���½�Ϊx2, y2���Ӿ��������Ԫ�صĺ�
int getSubMatrixSum(vector<vector<int> >& matrix, vector<vector<int> >& sum, int x1, int y1, int x2, int y2) {
	x2++;
	y2++;
	return sum[x2][y2] - sum[x1][y2] - sum[x2][y1] + sum[x1][y1];
}

// �������
void printVector(const vector<int>& vec) {
	int m = vec.size();
	for (int i = 0; i < m; i++)
		cout << vec[i] << " ";
	cout << endl;
}

// ���һ������
template<class T>
void printMatrix(const vector<vector<T> >& matrix) {
	int m = matrix.size();
	if (m == 0)
		return;
	int n = matrix[0].size();
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}


// ����ת�ַ���
string int2str(int num) {
	string res;
	if (num == 0)
		res = "0";
	while (num != 0) {
		res = char(num % 10 + '0') + res;
		num /= 10;
	}
	return res;
}


// �ж�һ���ַ����Ƿ����
bool isPalindrome(const string &s, int left = 0, int right = -1){
	// params:
	//	s: Ҫ�жϵ��ַ���
	//	left: �Ӵ���������ַ������������û������Ϊ���ַ�����ͷ��ʼ
	//	right: �Ӵ������Ҷ��ַ������������û������Ϊ���ַ�����β
	if (right == -1){
		right = s.length() - 1;
	}
	while(left < right){
		if (s[left++] != s[right--])
			return false;
	}
	return true;
}


// ���������ַ�������
void Spread(const string &s, vector<vector<int>> &dp, int left, int right) {
	// �����ַ���s����dp�е�Ԫ�أ�ִ�����֮��dp[i][j]Ϊ1��ʾs[i]��s[j]Ϊ�����ַ�����dp[i][j]Ϊ0��ʾ���ǻ����ַ�����
	int len= s.length();
    while(left >= 0 && right < len){
        if(s[left]==s[right]){
            dp[left][right] = 1;
            left--;
            right++;
        }
        else
            break;
    }
}


void PalindromeMat(const string& s, vector<vector<int> >& dp) {
    int len = s.length();
    for (int i = 0; i < len; i++) {
        Spread(s, dp, i, i);
        Spread(s, dp, i, i + 1);
    }
}


int main() {

	system("pause");
	return 0;
}
