#include <iostream>
using namespace std;

class MyClass {
private:
    int* ptr;

public:
    // ������
    MyClass() {
        ptr = new int(10); // ���� �޸� �Ҵ�
        cout << "�޸� �Ҵ� �Ϸ�!" << endl;
    }

    // �Ҹ���
    ~MyClass() {
        delete ptr; // �޸� ���� �߰�!!
    }

    void print() const {
        cout << "��: " << *ptr << endl;
    }
};

int main() {
    MyClass obj;
    obj.print();

    // main �Լ� ����
    return 0;
}
