#ifndef STUDENTSLIST_H
#define STUDENTSLIST_H

#include <string>
#include <vector>
#include <functional>

class Student {
public:
    std::string name;
    int age;
    int mark;

    Student(std::string name,
            int age,
            int mark) : name(name), age(age), mark(mark) {};
};

class StudentsList
{
    std::vector<Student> students;
public:
    StudentsList() {};

    void add(Student student);
    template <typename T>
    std::vector<Student> find(T val, std::function<bool (Student&, Student&)> sort_func, std::function<bool (Student&, T&)> filter);
};

void StudentsList::add(Student student) {
    this->students.push_back(student);
}

template <typename T>
std::vector<Student> StudentsList::find(T val, std::function<bool (Student&, Student&)> sort_func, std::function<bool (Student&, T&)> filter) {
    std::vector<Student> result;
    for (auto& student : this->students)
        if (filter(student, val))
            result.push_back(student);

    std::sort(result.begin(), result.end(), sort_func);

    return result;
}

#endif // STUDENTSLIST_H
