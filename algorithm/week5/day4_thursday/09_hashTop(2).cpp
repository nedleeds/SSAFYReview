//#include <iostream>
//#include <unordered_map>
//using namespace std;
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie();
//	cout.tie();
//
//	int N;
//	cin >> N;
//
//	struct TeamInfo { int cntPeople, totalScore; };
//	unordered_map<string, TeamInfo> teams;
//
//	for (int user = 0; user < N; user++) {
//		string teamColor;
//		int score;
//		cin >> teamColor >> score;
//		teams[teamColor].totalScore += score;
//		teams[teamColor].cntPeople += 1;
//	}
//
//	string cocoTeam, friendTeam;
//	cin >> cocoTeam >> friendTeam;
//	
//	cout << teams[cocoTeam].cntPeople << " " << teams[cocoTeam].totalScore << '\n';
//	cout << teams[friendTeam].cntPeople << " " << teams[friendTeam].totalScore << '\n';
//	if (teams[cocoTeam].totalScore > teams[friendTeam].totalScore)
//		cout << cocoTeam << "\n";
//	else
//		cout << friendTeam << "\n";
//
//	return 0;
//}