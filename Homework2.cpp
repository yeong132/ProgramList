#include <iostream>;
#include <string>;
#include <memory>; // unique_ptr�� ��ߵż� ����

using namespace std;

// 1. �����ڿ� �Ҹ��ڿ� new, delete�� �ʿ����. unique_ptr�� �ش� ����� ���ԵǾ� �ִ�!

class Logger {
	private:
		int logCount; // �α��� �� ����
	public:
		Logger() :logCount(0) {}   // ������

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

		// �Ҹ���
		~Logger() {
			cout << "Logger ��ü�� �Ҹ�Ǿ����ϴ�!" << endl;
		}
};

int main() {
	// new�� delete�� unique_ptr�� �˾Ƽ� ó������.
	unique_ptr<Logger> myLogger = make_unique<Logger>();

	myLogger->logInfo("����� ���۵Ǿ����ϴ�.");
	myLogger->logWarning("��ũ�� ������ �����մϴ�!");
	myLogger->logError("������ ������ ���������ϴ�!!");

	// ��� �α� ��� �� �̶����� ��µ� �α� ���� ���
	myLogger->showTotalLogs();

	return 0;
}
