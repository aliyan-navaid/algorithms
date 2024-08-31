#include <iostream>
#include <string>
#include <cstdint>

class Student {
public:
    Student( const std::string& name="null", const std::string& date="null", std::int16_t score=0)
        : name(name), date(date), score(score) {}

    void displayDetails() const {
        std::cout << name << " " << date << " " << score << '\n';
    }

private:
    std::string name;
    std::string date;
    std::int16_t score;
};

class Exam {
public:
    Exam( std::int16_t count=0 ) {
        students = new Student[count];

        std::string name, date; std::int16_t score;
        for (int i=0; i<count; i++) {
            std::cout << "Name: ";
            std::cin >> name;
            std::cout << "Date: ";
            std::cin >> date;
            std::cout << "Score: ";
            std::cin >> score;
            std::cout << '\n';

            students[i] = Student(name, date, score);
        }
    }

    Exam(const Exam&) = default;

    void displayStudents() const {
        for (int i=0; i<count; i++)
            students[i].displayDetails();
    }

    void addressOfFirstStudent() const {
        std::cout << students << std::endl;
    }

    ~Exam() {
        delete [] students;
    }

private:
    Student* students;
    std::int16_t count;
};

int main() {
    Exam first(2);
    Exam second(first);

    /*
     * both point to same location in memory
     * address of pointer copied rather than values 
     * being pointed to 
    */
    first.addressOfFirstStudent();
    second.addressOfFirstStudent();

    return 0;
}