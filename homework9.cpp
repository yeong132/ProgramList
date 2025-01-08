#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Task는 IStorage에서 쓰이므로 제일 앞에 선언되야 함.
class Task {
private:
    string description;
    bool completed;
public:
    // Task 생성자
    Task(const string& descrip) : description(descrip), completed(false){}

    // 할 일 완료 처리
    void complete(){ completed = true; }

    // 할 일 내용 반환
    // 여기서 const는 상수니까 멤버 함수 안에서는 대입을 할 수 없다는 뜻
    // 그러니 당연히 함수 안에서 멤버 변수의 수정이 불가능하다.
    string getDescription() const { return description; }

    // 할 일 완료 여부
    bool isCompleted(){
        return completed;
    }
};

// IStorage랑 Task는 TaskManager에서 쓰이므로 그 클래스보다 앞에 선언되야 함.
class IStorage {
public:
    virtual void addTask(Task task) = 0;  // 할 일 추가 메서드 선언
    virtual vector<Task> getTasks() = 0;  // 할 일 목록이 담길 벡터 선언
    virtual string getStorageType() = 0;  // 저장소의 타입을 반환할 스트링 선언

    // 소멸자
    virtual ~IStorage(){
        cout << "객체가 소멸되었습니다!" << endl;
    }
};

class MemoryStorage : public IStorage {
private:
    vector<Task> tasks;
public:
    void addTask(Task task) override{
        tasks.push_back(task);
    }

    vector<Task> getTasks() override {
        return tasks;
    }

    string getStorageType() override {
        return "메모리 저장소";
    }
};

class DBStorage : public IStorage {
private:
    vector<Task> tasks;
public:
    void addTask(Task task) override {
        tasks.push_back(task);
    }

    vector<Task> getTasks() override {
        return tasks;
    }

    string getStorageType() override {
        return "DB 저장소";
    }
};

class TaskManager {
private:
    IStorage* storage;

public:
    // TaskManager 생성자
    TaskManager(IStorage* s) : storage(s) {}

    // 새로운 할 일 추가
    // 여기서 Task(description)은 Task task와 같은 역할이라 보면 된다.
    void addTask(const string& description) {
        storage->addTask(Task(description));
    }

    // 현재 할 일 목록 출력
    void showTasks() {
        cout << "저장 방식: " << storage->getStorageType() << "\n";

        // IStorage* storage에 MemoryStorage나 DBStorage 객체를 담을 수 있는 이유
        // MemoryStorage와 DBStorage가 IStorage를 상속받은 구현 클래스이기 때문
        // 상속받은 클래스는 부모 클래스(IStorage) 타입으로도 간주될 수 있다.
        // IStorage* 를 통해 다형성이 적용되어, storage->getTasks() 처럼 호출이 가능
        vector<Task> tasks = storage->getTasks();

        // size_t는 부호가 없는 정수 타입이다. 즉, 음수를 제외한 0포함, 양의 정수 타입이다.
        // 그래서 음수가 필요 없는 메모리 크기나 인덱스를 쓸 때 많이 쓰는 듯하다.
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].getDescription();
            if (tasks[i].isCompleted()) cout << " [완료]";
            cout << "\n";
        }
    }

    // 특정 할 일을 완료 처리
    // index는 0부터 들어갈 수 있는데 맘에 안들어서 order로 변경하였다.
    // 코드를 읽을 때 이해가 더 잘된다.
    void completeTask(size_t order) {
        vector<Task> tasks = storage->getTasks();
        if (order > 0 && order <= tasks.size()) {
            tasks[order - 1].complete();
            storage->addTask(tasks[order - 1]); // 변경된 할 일 저장
        }
        else {
            cout << "잘못된 번호입니다.\n";
        }
    }
};

// 메인 함수
int main() {
    cout << "=== MemoryStorage로 작업 ===\n";
    MemoryStorage memoryStorage;

    // &는 변수의 메모리 주소를 가져오는 거여서 
    // 인자로 메모리주소를 받기 위해 이렇게 쓸 수 있다!
    TaskManager manager1(&memoryStorage);

    manager1.addTask("C++ 과제 작성하기");
    manager1.addTask("SOLID 원칙 공부하기");

    cout << "\n현재 할 일 목록:\n";
    manager1.showTasks();

    // 예상이 맞다면 1번째 할일인 C++ 과제 작성하기 뒤에 [완료]가 붙어야 한다.
    manager1.completeTask(1);

    cout << "\n업데이트된 할 일 목록:\n";
    manager1.showTasks();

    cout << "\n=== DBStorage로 작업 ===\n";
    DBStorage dbStorage;
    TaskManager manager2(&dbStorage);

    manager2.addTask("DB 작업 테스트");
    manager2.addTask("To-Do 목록 추가");

    cout << "\n현재 할 일 목록:\n";
    manager2.showTasks();

    // 예상이 맞다면 2번째 할일인 To-Do 목록 추가 뒤에 [완료]가 붙어야 한다.
    manager2.completeTask(2);

    cout << "\n업데이트된 할 일 목록:\n";
    manager2.showTasks();

    return 0;
}
