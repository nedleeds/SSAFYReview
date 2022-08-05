#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
	string name = "";
	int score = 0;
};

vector<Student> students;
void doSort(vector<Student> s) {
	for (int i = 1; i < s.size(); i++) {
		Student key = s[i];
		int j = i - 1;
		while (j >= 0 && s[j].score < key.score) {
			s[j] = key;
			j -= 1;
		}

		for (int k = 0; k < i; k++)
			cout << s[k].name << ' ';

		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int n;
	cin >> n;

	int MAX = -2134567890;
	
	for (int i = 0; i < n; i++) {
		Student now;
		cin >> now.name >> now.score;
		students.push_back(now);
	}
	
	doSort(students);

	return 0;
}
