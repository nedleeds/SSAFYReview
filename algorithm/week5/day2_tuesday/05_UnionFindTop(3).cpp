#include <iostream>
using namespace std;

int population[100001];
int captain[100001];

int Find(int node) {
	if (captain[node] == node)
		return node;

	captain[node] = Find(captain[node]);
	return captain[node];
}

void Union(int a, int b) {
	int aCap = Find(a);
	int bCap = Find(b);

	if (aCap == bCap) return;

	captain[bCap] = aCap;
	population[aCap] += population[bCap];
	population[bCap] = population[aCap];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int numNode;
	cin >> numNode;

	for (int i = 0; i < numNode; i++)
		captain[i] = i;

	for (int country = 0; country < numNode; country++)
		cin >> population[country];

	int situation = 0;
	cin >> situation;
	for (int i = 0; i < situation; i++) {
		string status;
		char node1, node2;
		cin >> status >> node1 >> node2;

		if (status == "alliance") {
			Union(node1 - 'A', node2 - 'A');
		}
		else {
			int node1Population = population[Find(node1 - 'A')];
			int node2Population = population[Find(node2 - 'A')];
			// 인원수 더 큰 곳이 살아 남는다 -> 적은 곳은 죽음
			if (node1Population > node2Population) {
				//node1 이 살아 남는다 -> node2 멸망
				for (int i = 0; i <= numNode; i++)
					if (Find(i) == (node2 - 'A'))
						population[i] = 0;
			}
			else if (node1Population < node2Population) {
				//node2 가 살아 남는다 -> node1 멸망
				for (int i = 0; i <= numNode; i++)
					if (Find(i) == (node1 - 'A'))
						population[i] = 0;
			}
			else {
				// node1, node2 둘다 멸망
				for (int i = 0; i <= numNode; i++) {
					if (Find(i) == (node1 - 'A'))
						population[i] = 0;
					if (Find(i) == (node2 - 'A'))
						population[i] = 0;
				}
			}
		}
	}

	int ans=0;
	for (int i = 0; i < numNode; i++)
		if (population[i] != 0)
			ans++;

	cout << ans;

	int de = 1;
	return 0;
}