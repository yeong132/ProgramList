#include <iostream>
#include <vector>
#include <map>
#include <algorithm> // iterator ���� ������ ����ϱ� ���� �߰�!

using namespace std;

int main() {
    // ���Ϳ� �� ������ ����
    vector<int> vec = { 10, 20, 30, 40, 50 };
    map<string, int> mp = {
        {"Alice", 90},
        {"Bob", 85},
        {"Charlie", 95}
    };

    cout << "���� ������ ���!" << endl;
    // ���� ������
    for(vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl << endl;
    cout << "���� ������ ���!" << endl;
    // ���� ������
    for(vector<int>::reverse_iterator rit = vec.rbegin(); rit != vec.rend(); ++rit) {
        cout << *rit << " ";
    }
    cout << endl << endl;
    cout << "�� ������ ���!" << endl;
    // �� ������
    for (map<string, int>::iterator it = mp.begin(); it != mp.end(); ++it) {
        cout << it->first << ": " << it->second << " ";
    }
    cout << endl << endl;
    cout << "�� ������ ���!" << endl;
    // �� ������
    for (map<string, int>::reverse_iterator it = mp.rbegin(); it != mp.rend(); ++it) {
        cout << it->first << ": " << it->second << " ";
    }
    cout << endl << endl;

    return 0;
}

