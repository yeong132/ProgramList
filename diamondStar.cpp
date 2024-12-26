#include <iostream>
using namespace std;

int main() {
    // 목표: 다이아몬드로 별 만들기
    
    // 1. 상단 삼각형과 아래 삼각형을 나누자.
    // N을 입력이라고 두자.
    // 입력이 4면 상단 삼각형일 때 별이 1,3,5,7
    // 상단 삼각형은 for문이 돌때마다 (N-1)개의 공백 + 별(1) + (N-1)개의 공백이 찍히고 나서
    // (N-1)개의 공백 + (별+2) + (N-1)개의 공백이 찍혀야 한다.
  
    // 2. 일단 상단 삼각형 먼저 만들어보자..

    int circleHeight; // 삼각형의 높이 선언

    cout << "별의 높이를 정해주세요! 별 : ";
    cin >> circleHeight;  // 그 높이를 입력으로 넣기

    // 입력값 검증
    while (circleHeight <= 0) {
        cout << "잘못된 입력입니다. 양의 정수를 입력하세요." << endl;
        cin >> circleHeight;
    }

    // 다이아몬드 상단 출력
    for(int i = 1; i <= circleHeight; i++) {
        for (int j = 1; j <= circleHeight-i; j++) {
            cout << " "; // 공백 출력
        }
        for (int j = 1; j <= i*2-1; j++) {
            cout << "*";
        }
        cout << endl; // 줄바꿈
    }

    // 3. 입력이 4면 하단 삼격형은? 별이 5,3,1
    // for문이 돌때마다 (N-2)개의 공백 + 별(5) + (N-2)개의 공백이 찍히고 나서
    // ((N-1)개의 공백이 거꾸로.. + (별-2) + (N-1)개의 공백이 거꾸로.. 찍혀야 한다.
    
    // 다이아몬드 하단 출력
    for (int i = circleHeight-1; i >= 1; i--) {
        for (int j = 1; j <= circleHeight-i; j++) {
            cout << " "; // 공백 출력
        }
        for (int j = 1; j <= i*2-1; j++) {
            cout << "*";
        }
        cout << endl; // 줄바꿈
    }
    return 0;
}