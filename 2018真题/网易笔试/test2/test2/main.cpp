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

typedef vector<vector<long long> > mat;
typedef vector<long long> vec;

// �������
void printVector(const vector<long long>& vec) {
	long long m = vec.size();
	for (long long i = 0; i < m; i++)
		cout << vec[i] << endl;
	//cout << endl;
}

// ���һ������
void printMatrix(const vector<vector<long long> >& matrix) {
	long long m = matrix.size();
	if (m == 0)
		return;
	long long n = matrix[0].size();
	for (long long i = 0; i < m; i++) {
		for (long long j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

bool myfunction(vector<long long> v1, vector<long long> v2)	{
	if (v1[1] < v2[1])
		return true;
	return false;
}

void printSet(unordered_set<int> set) {
	for (auto& x : set) 
		cout << x << " " ;
	cout << endl;
	
}

int main() {

	int N;
	int M;
	cin >> N >> M;

	mat jobs(N, vector<long long>(2, 0));
	vec p(M, 0);
	vector<long long> salary;

	for (long long i = 0; i < N; i++) 
		cin >> jobs[i][0] >> jobs[i][1];

	for (long long i = 0; i < M; i++)
		cin >> p[i];
	
	sort(jobs.begin(), jobs.end(), myfunction);
	
	unordered_set<int> donotchoose;
	// �϶�����ѡ��Ĺ���
	for (long long i = N-2; i >= 0; i--) {
		if (jobs[i][0] >= jobs[i+1][0]) {
			donotchoose.insert(i);
		}
	}
	// ��ÿ���˽��д���
	for (long long i = 0; i < M; i++) {
		int temp = salary.size();
		for (long long j = N - 1; j >= 0; j--) {
			if (donotchoose.find(j) != donotchoose.end())
				continue;
			if (jobs[j][0] <= p[i]) {
				salary.push_back(jobs[j][1]);
				break;
			}
		}
		if (salary.size() == temp)
			salary.push_back(0);
	}

	printVector(salary);
	//cout << "����ѡ��Ĺ���";
	//printSet(donotchoose);
	//cout << "���������Թ�������"<< endl;
	//printMatrix(jobs);
	system("pause");
	return 0;
}
