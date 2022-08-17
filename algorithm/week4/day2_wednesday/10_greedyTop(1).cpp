#include <iostream>
using namespace std;
// 3:20 ~ 3:50 break
// 3:50 ~ 4:10 lecture(greedy)
// ~4:14 (clear)
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	
	int money;
	cin >> money;

	int cnt = 0;
	while (money != 0){
		if (money >= 500) {
			money -= 500;
			cnt++;
		}else if (money >= 100) {
			money -= 100;
			cnt++;
		}
		else if (money >= 50) {
			money -= 50;
			cnt++;
		}
		else if (money >= 10) {
			money -= 10;
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}