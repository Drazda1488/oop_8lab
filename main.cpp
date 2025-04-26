#include <iostream>
#include <string>
#include <vector>

// ����� ��� ��������
class Person {
public:
    // ����������� - ���������� ��� �������� ������� Person
    Person(std::string name, int age) {
        this->name = name; // ��������� ���
        this->age = age;   // ��������� �������
    }

    // ������� ��� ������ ���������� � ��������
    void printInfo() {
        std::cout << "���: " << name << std::endl;
        std::cout << "�������: " << age << std::endl;
    }

private:
    std::string name; // ��� ��������
    int age;       // ������� ��������
};

// ����� ��� �������� (����������� �� Person)
class Student : public Person {
public:
    // ����������� ��� �������� (�������� ����������� Person)
    Student(std::string name, int age, float rating) : Person(name, age) {
        this->rating = rating; // ��������� �������
    }

    // �������������� ������� printInfo, ����� �������� �������
    void printInfo() {
        Person::printInfo(); // ������� ������� ���������� � ��������
        std::cout << "�������: " << rating << std::endl; // ��������� �������
    }

private:
    float rating; // ������� ��������
};

// ����� ��� ������ ����� (��� ���������)
class Group {
public:
    // �����������
    Group() {
        // ������ �� ������ ��� ��������
    }

    // ������� ��� ���������� �������� (��� ��������) � ������
    void addPerson(Person* person) {
        people.push_back(person); // ��������� ��������� �� �������� � ������
    }

    // ������� ��� ������ ���������� � ���� � ������
    void printGroupInfo() {
        std::cout << "���������� � ������:" << std::endl;
        // �������� �� ���� ����� � ������
        for (int i = 0; i < people.size(); i++) {
            std::cout << "������� " << i + 1 << ":" << std::endl;
            people[i]->printInfo(); // �������� ������� ������ ���������� ��� ������� ��������
            std::cout << std::endl;
        }
    }

private:
    std::vector<Person*> people; // ������ ��� �������� ���������� �� �����
};

int main() {
    // ������� ������
    setlocale(LC_ALL, "RU");
    Group myGroup;

    // ������� ��������� ����� � ���������
    Person* person1 = new Person("����", 20);
    Student* student1 = new Student("����", 22, 4.5);
    Person* person2 = new Person("�����", 19);

    // ��������� �� � ������
    myGroup.addPerson(person1);
    myGroup.addPerson(student1);
    myGroup.addPerson(person2);

    // ������� ���������� � ������
    myGroup.printGroupInfo();

    // �����! ����������� ������, ����� �� ���� ������
    delete person1;
    delete student1;
    delete person2;

    return 0;
}
