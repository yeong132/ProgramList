#include <iostream>
#include <vector>
#include <map>
#include <algorithm> // iterator 관련 문법을 사용하기 위해 추가!

using namespace std;

int main() {
    // 벡터와 맵 데이터 정의
    vector<int> vec = { 10, 20, 30, 40, 50 };
    map<string, int> mp = {
        {"Alice", 90},
        {"Bob", 85},
        {"Charlie", 95}
    };

    cout << "벡터 순방향 출력!" << endl;
    // 벡터 순방향
    for(vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl << endl;
    cout << "벡터 역방향 출력!" << endl;
    // 벡터 역방향
    for(vector<int>::reverse_iterator rit = vec.rbegin(); rit != vec.rend(); ++rit) {
        cout << *rit << " ";
    }
    cout << endl << endl;
    cout << "맵 순방향 출력!" << endl;
    // 맵 순방향
    for (map<string, int>::iterator it = mp.begin(); it != mp.end(); ++it) {
        cout << it->first << ": " << it->second << " ";
    }
    cout << endl << endl;
    cout << "맵 역방향 출력!" << endl;
    // 맵 역방향
    for (map<string, int>::reverse_iterator it = mp.rbegin(); it != mp.rend(); ++it) {
        cout << it->first << ": " << it->second << " ";
    }
    cout << endl << endl;

    return 0;
}

