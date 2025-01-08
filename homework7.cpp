#include <iostream>
#include <vector>

using namespace std;

class Adventure {
public:
	virtual void useSkill() = 0;
	virtual ~Adventure() {
		cout << "객체가 소멸되었습니다!" << endl;
	}
};

class Warrior : public Adventure {
public:
	void useSkill() {
		cout << "Warrior : Warrior uses Slash!!" << endl;
	}
};

class Mage : public Adventure {
public:
	void useSkill() {
		cout << "Mage : Mage casts Fireball!!" << endl;
	}
};

class Archer : public Adventure {
public:
	void useSkill() {
		cout << "Archer : Archer shoots an Arrow!!" << endl;
	}
};

int main() {
	vector<Adventure*> adventures;
	adventures.push_back(new Warrior);
	adventures.push_back(new Mage);
	adventures.push_back(new Archer);

	// 각 모험가들의 스킬 사용!!
	for (int i = 0; i < adventures.size(); ++i) {
		adventures[i]->useSkill();
	}

	// 메모리 해제
	for (int i = 0; i < adventures.size(); ++i) {
		delete adventures[i];
	}

	return 0;
}