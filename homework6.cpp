#include <iostream>

using namespace std;

class Fraction {
private:
	int numerator; // 분자 선언
	int denominator; // 분모 선언

	// gcd 함수 구현 (유클리드 호제법) 인터넷에 있던거 참조함.
	int gcd(int a, int b) {
		while (b != 0) {
			int temp = b;
			b = a % b;
			a = temp;
		}
		return a;
	}

public:
	// 기본 생성자 분자, 분모 초기화
	Fraction(): numerator(0), denominator(1) {}

	// 생성자
	Fraction(int numer, int denomin): numerator(numer), denominator(denomin){}

	// 현재 분수를 출력하는 함수
	void display() {
		cout << "현재 분수 : " << numerator << "/" << denominator << endl;
	}

	// 기약 분수 형태로 만드는 함수
	void simplify() {
		int gcdValue = gcd(numerator, denominator);
		numerator /= gcdValue;
		denominator /= gcdValue;
		cout << "기약 분수로 만들었습니다!" << endl;
	}

	// 두 분수를 곱하고 기약분수로 만드는 함수
	Fraction multiply(const Fraction& other) {
		// 분자끼리 곱해서 다시 분자로
		int resultNumer = numerator * other.numerator;
		// 분모끼리 곱해서 다시 분모로
		int resultDenomin = denominator * other.denominator;

		// 두 분수를 곱한 결과의 객체 생성
		Fraction result(resultNumer, resultDenomin);

		return result;
	}
};

int main() {
	// 분수를 가진 객체 2개 생성!
	Fraction fraction1(1,2);
	Fraction fraction2(3,6);
	fraction1.display();
	fraction2.display();

	// 새로운 객체에 두 객체의 분수를 곱한 새 분수 값 저장
	Fraction result = fraction1.multiply(fraction2);
	result.display();
	result.simplify();
	result.display();

	return 0;
}