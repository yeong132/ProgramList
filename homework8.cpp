#include <iostream>
#include <string>

using namespace std;

// Student 클래스가 StudentPrinter 밑에 선언되었다면 컴파일러가 
// StudentPrinter클래스의 메서드에 있는 `Student&`<< 이거를 인식하지 못해 오류가 날 것이다.
// 그러니까 이런거 잘 생각해서 코드를 짜자.
class Student {
private:
	string name;
	int age;
public:
	// 생성자
	Student(string studentName, int studentAge) : name(studentName), age(studentAge) {}

	string getName() {
		return name;
	}

	int getAge() {
		return age;
	}
};

class StudentPrinter {
public:
	// 학생의 정보 출력
	void print(Student& student) {
		cout << "학생 이름 : " << student.getName() << endl;
		cout << "학생 나이 : " << to_string(student.getAge()) << endl << endl;
	}
};

int main() {
	// 학생 객체 생성!!
	Student student1("철수", 13);
	Student student2("영희", 14);

	// 프린터 객체는 1번만 생성해도 됨! 그 안의 메서드가 학생 객체를 인자로 받으니까!
	StudentPrinter stPrt;

	// .print()의 괄호 안에는 객체를 받아야 하기 때문에 만든 객체를 넣어준다!
	stPrt.print(student1);
	stPrt.print(student2);

	return 0;
}