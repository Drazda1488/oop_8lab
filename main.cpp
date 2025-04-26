#include <iostream>
#include <string>
#include <vector>

// Класс для человека
class Person {
public:
    // Конструктор - вызывается при создании объекта Person
    Person(std::string name, int age) {
        this->name = name; // Сохраняем имя
        this->age = age;   // Сохраняем возраст
    }

    // Функция для вывода информации о человеке
    void printInfo() {
        std::cout << "Имя: " << name << std::endl;
        std::cout << "Возраст: " << age << std::endl;
    }

private:
    std::string name; // Имя человека
    int age;       // Возраст человека
};

// Класс для студента (наследуется от Person)
class Student : public Person {
public:
    // Конструктор для студента (вызывает конструктор Person)
    Student(std::string name, int age, float rating) : Person(name, age) {
        this->rating = rating; // Сохраняем рейтинг
    }

    // Переопределяем функцию printInfo, чтобы добавить рейтинг
    void printInfo() {
        Person::printInfo(); // Сначала выводим информацию о человеке
        std::cout << "Рейтинг: " << rating << std::endl; // Добавляем рейтинг
    }

private:
    float rating; // Рейтинг студента
};

// Класс для группы людей (или студентов)
class Group {
public:
    // Конструктор
    Group() {
        // Ничего не делаем при создании
    }

    // Функция для добавления человека (или студента) в группу
    void addPerson(Person* person) {
        people.push_back(person); // Добавляем указатель на человека в вектор
    }

    // Функция для вывода информации о всех в группе
    void printGroupInfo() {
        std::cout << "Информация о группе:" << std::endl;
        // Проходим по всем людям в группе
        for (int i = 0; i < people.size(); i++) {
            std::cout << "Человек " << i + 1 << ":" << std::endl;
            people[i]->printInfo(); // Вызываем функцию вывода информации для каждого человека
            std::cout << std::endl;
        }
    }

private:
    std::vector<Person*> people; // Вектор для хранения указателей на людей
};

int main() {
    // Создаем группу
    setlocale(LC_ALL, "RU");
    Group myGroup;

    // Создаем несколько людей и студентов
    Person* person1 = new Person("Иван", 20);
    Student* student1 = new Student("Петр", 22, 4.5);
    Person* person2 = new Person("Мария", 19);

    // Добавляем их в группу
    myGroup.addPerson(person1);
    myGroup.addPerson(student1);
    myGroup.addPerson(person2);

    // Выводим информацию о группе
    myGroup.printGroupInfo();

    // Важно! Освобождаем память, чтобы не было утечек
    delete person1;
    delete student1;
    delete person2;

    return 0;
}
