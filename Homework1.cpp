#include <iostream>
using namespace std;

class MyClass {
private:
    int* ptr;

public:
    // 생성자
    MyClass() {
        ptr = new int(10); // 동적 메모리 할당
        cout << "메모리 할당 완료!" << endl;
    }

    // 소멸자
    ~MyClass() {
        delete ptr; // 메모리 해제 추가!!
    }

    void print() const {
        cout << "값: " << *ptr << endl;
    }
};

int main() {
    MyClass obj;
    obj.print();

    // main 함수 종료
    return 0;
}
