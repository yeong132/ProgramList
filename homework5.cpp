#include <iostream>

using namespace std;

class Battery {
private:
	int charge;
public:
	// 생성자
	Battery(int inputCharge = 100):charge(inputCharge){}
	
	// 배터리 잔량 반환 메서드
	int getCharge() const {
		return charge;
	}

	// 배터리 사용 메서드
	void useBattery() {
		if (charge - 5 >= 0) {
			charge -= 5;
			cout << "Battery Used. Current Charge : " << getCharge() << "%" << endl;
		} 
		else {
			cout << "현재 배터리 잔량이 5%이상이어야 합니다. 배터리를 충전해주세요!" << endl;
		}
	}

	// 배터리 충전 메서드
	void chargeBattery() {
		if (charge + 7 <= 100) {
			charge += 7;
			cout << "Battery Charged. Current Charge : " << getCharge() << "%" << endl;
		}
		else {
			cout << "현재 배터리잔량이 93%이하이어야 합니다. 배터리를 사용해주세요!" << endl;
		}
	}
};

int main() {
	Battery battery;

	cout << "Initial charge : " << battery.getCharge() << "%" << endl;
	
	// 배터리 다 써보기
	for (int i = 0; i < 21; ++i) {
		battery.useBattery();
	}

	// 배터리 풀충전 해보기
	for (int i = 0; i < 15; ++i) {
		battery.chargeBattery();
	}

	return 0;
}