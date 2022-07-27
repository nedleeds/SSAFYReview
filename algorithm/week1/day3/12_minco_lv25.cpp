#include <iostream>
using namespace std;

string src[5] = {
	"KFC", "MC", "BICMAC", "SHACK", "SONY"
};

string tgt[5] = {
	"#BBQ#", "#BBQ#", "#MACBOOK#", "#SHOCK#", "#NONY#"
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	string s;
	cin >> s;

	
	for (int i = 0; i < 5; i++) {
		int find_idx;
		while ( (find_idx = s.find(src[i])) != -1){
			s.replace(find_idx, src[i].length(), tgt[i]);
		}
	}

	cout << s << '\n';

	return 0;
}