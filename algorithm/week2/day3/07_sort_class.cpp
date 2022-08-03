#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// sort
// ���� �˰��� ��¥ ���� !!
// ���� ����, ���� ����, ���� ���� --> ȿ�� ���� ���� --> n^2
// ���� ����, ����Ʈ --> ȿ�� ���� ���� --> nlogn

// stl���� �����ϴ� sort --> ���� ���������� nlogn

// �츮�� �� C++������ sort �˰���
// BASE : Intro Sort + Quicksort + Heap sort
// Quicksort -> nlogn�� �Ѿ�� heap sort�� ��ȯ
// �迭�� ũ�Ⱑ �ʹ� ũ�� -> Intro sort

int arr[] = { 3, 4, 5, 1, 2 };
vector<int> v = { 3, 4, 5, 1, 2 };
char c[] = { 'A' , 'B', 'D', 'F', 'Z' };

bool cmp(int a, int b) {
	// a: ���ʿ� �ִ� ��
	// b: �����ʿ� �ִ� ��
	// ��Ȳ�� �°� return
	// ���� �� a�� b�� ���� �� -> ���� ���ϴ� �������� ��Ȳ -> true
	// �ƴϴ�. ���� �̰� �ٲ����Ѵ� -> �߸��� ��Ȳ�̴� -> false

	if (a > b) // ������ �������� �� ũ�� --> ���� ��������.
	{
		return true;
	} 
	// ** ���� ** 
	// �׻� �ݴ� ��Ȳ�鵵 ���� �־�� �Ѵ� !
	// ���������� ��߳��� ��Ȳ
	if (a < b) {
		return false;
	}

	// �� ������ �ƴϸ� false
	return false;
}

int main() {
	// ���� -> algorithm ���̺귯�� �ҷ��´�!!!
	
	// 1. ��������
	// sort(������, ������) 
	// -> sort(�迭 �̸�, �迭 �̸� + �迭 ũ��) 
	// -> sort(ù��° ����� �ּҰ�, ������ ����� �ּҰ�)
	sort(arr, arr + 5);
	for (int i = 0; i < 5; i++)
		cout << arr[i] << ' ';

	cout << '\n';
	// ���� ���� -> sort(������ ����, ������ ��)
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << ' ';

	// ���ڿ�
	cout << '\n';
	sort(c, c + 5);
	for (int i = 0; i < 5; i++)
		cout << c[i] << " ";

	// 2. ��������
	// sort(������, ������, �Լ� ������) 
	// -> sort(ù��° ����� �ּҰ�, ������ ����� �ּҰ�, ���� ���� �Լ�)
	cout << '\n';
	sort(arr, arr + 5, cmp);
	for (int i = 0; i < 5; i++)
		cout << arr[i] << ' ';

	cout << '\n';
	// ���� ���� -> sort(������ ����, ������ ��)
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << ' ';

	// ���ڿ�
	cout << '\n';
	sort(c, c + 5, cmp);
	for (int i = 0; i < 5; i++)
		cout << c[i] << " ";

	return 0;
}