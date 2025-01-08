#include <iostream>
#include <vector>

using namespace std;

class Animal {
public:
	virtual void speak() = 0;
	virtual ~Animal() {
		cout << "객체가 소멸되었습니다." << endl;
	}
};

class Dog : public Animal {
public:
	void speak() override {
		cout << "멍멍!" << endl;
	};
};

class Cat : public Animal {
	void speak() override {
		cout << "냐옹~" << endl;
	};
};

class Shark : public Animal {
	void speak() override {
		cout << "샤앜~" << endl;
	};
};

void printAnimalsSpeak(vector<Animal*>& animals) { // 벡터 복사 방지를 위해 & 참조자를 사용
	for(Animal* animal : animals) {
		animal->speak();
	}
	// 위 for문에 들어가는 타입을 auto를 쓰면 자동으로 넣을 수 있다!
	for(auto animal : animals) {
		delete animal;
	}
};

int main() {
	vector<Animal*> animals;

	animals.push_back(new Dog());
	animals.push_back(new Cat());
	animals.push_back(new Shark());

	printAnimalsSpeak(animals);

	return 0;
}