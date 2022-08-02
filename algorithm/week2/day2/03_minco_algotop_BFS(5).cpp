#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int adjMtx[101][101];
int visited[101];
vector<int> check[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int numNode, numEdge;
	cin >> numNode >> numEdge;

	for (int i = 0; i < numEdge; i++) {
		int from, to;
		cin >> from >> to;
		adjMtx[from][to] = 1;
		adjMtx[to][from] = 1;
	}

	int coco, somebody;
	cin >> coco >> somebody;

	queue<int> q;
	q.push(coco);
	visited[coco] = 1;

	int cnt = 0;
	int group = 0;
	vector<int> checklist[101];
	for (int i = 1; i <= numNode; i++) {
		/*
		현재 노드가 체크안되어있으면 
		시작 노드로 설정.
		*/
		if (visited[i] != 1) {
			//cout << '\n';
			q.push(i);
			visited[i] = 1;
		}
		else {
			continue;
		}
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			//cout << now << ' ';
			cnt++;
			checklist[group].push_back(now);
			for (int next = 1; next <= numNode; next++) {
				if (adjMtx[now][next] == 0) continue;
				if (visited[next] != 0) continue;

				visited[next] = 1;
				q.push(next);
			}
		}
		group += 1;
	}

	int coco_group=0, someone_group=0;
	for (int i = 0; i <= numNode; i++) {
		for (int j = 0; j < checklist[i].size(); j++) {
			if (checklist[i][j] == coco)
				coco_group = i;
			if (checklist[i][j] == somebody)
				someone_group = i;
		}
	}

	if (coco_group == someone_group)
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';

	return 0;
}