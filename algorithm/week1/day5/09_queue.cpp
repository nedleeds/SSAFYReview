#include <iostream>
#include <queue>
using namespace std;

queue<int> q;
int main(){
	q.push(1); // insert the value to the queue.
	q.push(3); // insert the value to the queue.

	// first element of queue.
	cout << "First : " << q.front() << '\n'; 
	// last element of queue.
	cout << "Last : " << q.back() << '\n';
	// size of queue.
	cout << "Size : " << q.size() << '\n';
	// is queue empty ?
	cout << "isEmpty? : " << q.empty() << '\n';
	// remove the queue element.(the first one)
	q.pop();

	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}

	return 0;
}