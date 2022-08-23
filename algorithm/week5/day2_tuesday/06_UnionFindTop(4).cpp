//#include <iostream>
//#include <vector>
//using namespace std;
//
//int t; // �������� ����
//int n; // ���� ����
//
//int parent[100001]; 
//
//int Find(int node) {
//    if (node == parent[node])
//        return node;
//    return parent[node] = Find(parent[node]);
//}
//
//void Union(int a, int b) {
//    int pa = Find(a);
//    int pb = Find(b);
//    if (pa == pb)
//        return;
//    parent[pb] = pa; 
//}
//
//int main() {
//    cin >> t;
//    cin >> n; 
//
//    // parent setting
//    // ������ �ִ� ��ŭ parent setting
//    for (int i = 0; i <= t; i++)
//        parent[i] = i; 
//
//    int cnt = 0; 
//    for (int i = 0; i < n; i++) {
//        int car;
//        cin >> car;
//        // ���� ���� ���� ��� ����ɼ� �ִ°�? 
//        // Find -> ���� �����Ⱑ ����å���� passing�Ҽ� �ִ� �ٸ� �����⿡ �����°�? 
//        int charger = Find(car); 
//        // ���� ���̻� �����Ҽ� �ִ� ����ȣȯ �����Ⱑ ���ٸ� -> ����
//        if (charger == 0)
//            break; // �� �����ʹ� �� �����Ҽ� ����
//        // -------------------------------------
//        // �� ���� ��ŷ�� ��򰡿��� �ϴ� �����ϴ�! 
//        cnt++; // �� �ϳ��� �� ������ �� �ִ�!
//        // ����, ���� �갡 ����� ������� ����� �� X 
//        // �̰ź��� ���� ������ �������� ����ִ°��� �ִٸ� -> ����� passing�ϵ��� ����
//        // ���� ���ٸ� (�� �Ʒ��� ��������� ��� ���ִٸ�)--> 0������ ������ �ȴ�. 
//        Union(charger - 1, charger); 
//    }
//    cout << cnt;
//}
//
//// �� �ڵ�� �ð� �ʰ� ��
////int used[100001];
////int arrived[100001];
////vector<int> charger;
////
////int main() {
////	ios_base::sync_with_stdio(false);
////	cin.tie();
////	cout.tie();
////
////	int numCharger;
////	cin >> numCharger;
////
////	for (int i = 1; i < numCharger; i++) {
////		charger.push_back(i);
////	}
////
////	int carNum;
////	cin >> carNum;
////
////	int possible = 0;
////	for (int i = 0; i < carNum; i++) {
////		int car;
////		cin >> car; // ���� ���Դ�
////
////		int flag = false;
////
////		for (int charger = numCharger; charger > 0; charger--) { // ��� ������ Ž��
////			if (used[charger] == 0 && charger <= car) { // �̻�� + �� ������ ȣȯ
////				//v.erase(remove(v.begin(), v.end(), 3), v.end());
////				used[charger] = 1;
////				possible++;
////				flag = true;
////				break;
////			}
////		}
////		if (flag == false) {
////			cout << possible;
////			return 0;
////		}
////	}
////
////
////	return 0;
////}
///*
//[ PineApple�� ���� �� ]
//1. ���� ������ ������ ���� ������ ������ �����Ⱑ ȣȯ���� �ʴ´�.
//2. ������ �Ϸ�Ǳ������ �ſ� ���� �ð��� �ɸ���.
//3. �� �� �ִ� �����Ұ� ���� ��� ������ ���� ������ ��� ������ �����⿡ ������ �� ����.
//
//PineApple Car 1�� PineApple Car 2 �Ǵ� 3�� �����⸦ ����� �� ����.
//������ �ݴ�� ���� ������ ������ ���� ������ �����⸦ ����� �� �ִ�.
//PineApple Car 3�� PineApple Car 1 �Ǵ� 2�� �����⸦ ����� �� �ִ�.
//* ��-> �������� -> ���� ������ ������ �������� ������ϱ� ����
//
//�����ҿ����� �׻� ������ ���� ������ �����⿡ ���� ������ �õ�
//
//A������ �����ҿ��� G���� ������
//1������ G���������� �����Ⱑ �ϳ��� ��ġ
//
//ù ������ ������ ���� �����⿡ ��ŷ
//������ ������ �����⿡ ��ŷ�� �� ���ٸ�, ���� ������ �����⿡ ��ŷ�� �õ�
//������ ������ �����Ⱑ �������� ���� ���,
//�����ִ� ������ �տ� ��ŷ�� ������ ���� �ð��� ��ٸ� �� ���� ���� �����Ҹ� ���� �̵�
//
//A������ ������ �־����� ��, ������ ������ �ִ� �������� ���� ���ϴ� ���α׷��� �ۼ�
//[1][2][3][4] -> c1 + c4
//		  c4
// c1
// c1
// [ 1 ][ 2 ][ 3 ][ 4 ] -> c2 + c3 + c4
//  c4   c2    c3   c4
//	   c2    c3
//*/