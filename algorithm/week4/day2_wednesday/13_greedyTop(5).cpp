#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Schedule {
	int startTime, endTime;
}schedule;
vector<Schedule> scheduler;
bool cmp (Schedule a, Schedule b) {
	if (a.endTime < b.endTime) return true;
	if (a.endTime > b.endTime) return false;

	if (a.startTime < b.startTime) return true;
	if (a.startTime > b.startTime) return false;

	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int numSchedule;
	cin >> numSchedule;

	for (int i = 0; i < numSchedule; i++) {
		cin >> schedule.startTime >> schedule.endTime;
		scheduler.push_back(schedule);
	}

	sort(scheduler.begin(), scheduler.end(), cmp);

	int cnt = 1;
	Schedule currTime = scheduler[0];
	for (int j = 1; j < scheduler.size(); j++) {
		if (currTime.endTime <= scheduler[j].startTime) {
			currTime = scheduler[j];
			cnt++;
		}
	}
	cout << cnt << '\n';
	return 0;

}
