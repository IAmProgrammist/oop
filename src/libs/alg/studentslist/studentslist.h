#ifndef STUDENTSLIST_H
#define STUDENTSLIST_H

#include "../matrix/matrix.tpp"

#include <string>
#include <vector>
#include <functional>

struct CharString {
    char val[50];
};

class Student {
public:
    CharString name;
    CharString age;
    CharString mark;

    Student(CharString name, CharString age, CharString mark) : name(name), age(age), mark(mark) {};
};

class StudentsList
{
    Matrix<CharString> students;
public:
    StudentsList() {
        students.resize_width(3);
    }

    void add(Student student);
    template <typename T>
    std::vector<Student> find(T val, std::function<bool (Student&, Student&)> sort_func, std::function<bool (Student&, T&)> filter);
};

void StudentsList::add(Student student) {
    this->students.push_back({student.name, student.age, student.mark});
}

template <typename T>
std::vector<Student> StudentsList::find(T val, std::function<bool (Student&, Student&)> sort_func, std::function<bool (Student&, T&)> filter) {
    std::vector<Student> result;
    for (int i = 0; i < this->students.get_height(); i++){
        Student student = {this->students(i, 0), this->students(i, 1), this->students(i, 2)};

        if (filter(student, val))
            result.push_back(student);
    }

    std::sort(result.begin(), result.end(), sort_func);

    return result;
}

#endif // STUDENTSLIST_H
