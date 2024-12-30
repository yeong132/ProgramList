#include <iostream>;
#include <string>;
#include <memory>; // unique_ptr을 써야돼서 넣음

using namespace std;

// 1. 생성자와 소멸자에 new, delete가 필요없다. unique_ptr에 해당 기능이 포함되어 있다!

class Logger {
	private:
		int logCount; // 로그의 총 개수
	public:
		Logger() :logCount(0) {}   // 생성자

		void logInfo(string message) {
			logCount++;
			cout << "[INFO]: " << message << endl;
		}

		void logWarning(string message) {
			logCount++;
			cout << "[WARNING]: " << message << endl;
		}

		void logError(string message) {
			logCount++;
			cout << "[ERROR]: " << message << endl;
		}

		void showTotalLogs() {
			cout << "Total Logs recorded: " << logCount << endl;
		}

		// 소멸자
		~Logger() {
			cout << "Logger 객체가 소멸되었습니다!" << endl;
		}
};

int main() {
	// new와 delete는 unique_ptr이 알아서 처리해줌.
	unique_ptr<Logger> myLogger = make_unique<Logger>();

	myLogger->logInfo("출력이 시작되었습니다.");
	myLogger->logWarning("디스크에 공간이 부족합니다!");
	myLogger->logError("서버와 연결이 끊어졌습니다!!");

	// 모든 로그 출력 후 이때까지 출력된 로그 갯수 출력
	myLogger->showTotalLogs();

	return 0;
}
