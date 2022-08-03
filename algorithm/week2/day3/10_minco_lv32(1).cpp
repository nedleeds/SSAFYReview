#include <iostream>
#include <algorithm>
using namespace std;

struct SET {
	int x;
	char a;
};

bool cmp(SET a, SET b) {
	if (a.x < b.x){
		return true;
	}else if (a.x > b.x){
		return false;
	}else{
		if (a.a < b.a)
			return true;
		else
			return false;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	SET s[100];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i].x >> s[i].a;
	}
	//s[100]까지 세팅.

	sort(s, s + n, cmp);

	for (int i = 0; i < n; i++) {
		cout << s[i].x << ' ' << s[i].a << '\n';
	}

	return 0;
}