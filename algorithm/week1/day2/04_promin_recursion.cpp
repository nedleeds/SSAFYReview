#include <iostream>
using namespace std;

// path -> DAT
// index : �� ��ȣ
// value : ���� ���� ������ ���� ������ �������� ���� "������ ���"

char choice[] = { 'L', 'R' };
char path[10];

// level : �� -> ��� ������ �����ؾ� ����Ǵ°�? 
void func(int level) {
    // ���� ���� 
    if (level == 2) {
        // cout << "RETURN\n";

        // ���� ������ �����ߴٸ� -> ���ݱ����� choice�� ���
        cout << path << '\n';
        return;
    }

    // ��� ����
    // �ݺ��� -> ������ ����
    /*
    for (int i = 0; i < 2; i++)
        func(level + 1);
    */
    for (int i = 0; i < 2; i++) {
        /*char curchoice = choice[i];
        cout << "��� ���� : " << curchoice << '\n';*/

        // ���� ������ �����ϴ� ��� -> path�� ����
        // ���� choice�� ���� ���� 
        path[level] = choice[i];

        func(level + 1);

        // �ش� ��θ� ���ö� -> ���̽��� ����
        path[level] = 0;
    }
}

int main() {
    func(0);
}