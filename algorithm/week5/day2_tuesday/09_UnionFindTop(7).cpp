#include <iostream>
#include <vector>
using namespace std;

int parents[20001];
struct IN { int command, from, to; };
vector<IN> query;

int Find(int node) {
	if (parents[node] == node)
		return node;

	return parents[node] = Find(parents[node]);
}

void Union(int a, int b) {
	int aParent = Find(a);
	int bParent = Find(b);

	if (aParent == bParent)
		return;

	parents[bParent] = aParent;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int N, Q;
	cin >> N >> Q;

	for (int i = 0; i < N; i++)
		parents[i] = i;

	vector<int> v;
	int parent, child;
	for (int i = 0; i < N - 1; i++) {
		if (i >= 1) {
			cin >> child;
			Union(parent, child);
			parent = child;
		}
		else {
			cin >> parent;
		}
	} // create trees (Union)

	// stacking all the Query
	for (int i = 0; i < N + Q - 1; i++) {
		int command;
		cin >> command;
		if (command == 0) {
			int num;
			cin >> num;
			query.push_back({ command, num, parents[num]});
		}
		else {
			int from, to;
			cin >> from >> to;
			query.push_back({ command, from, to });
		}
	}

	// pop + Do Union + check(command==1)
	// + cut all the edges
	vector<string> s;
	for (int i = 0; i < N; i++)
		parents[i] = i;

	while (!query.empty()) {
		IN input = query.back();
		query.pop_back();

		if (input.command == 0) {
			Union(input.from, input.to);
		}
		else
		{
			if (Find(input.from) == Find(input.to))
				s.push_back("YES\n");
			else
				s.push_back("NO\n");
		}
	}

	int de = 1;
	return 0;
}