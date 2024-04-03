#include "../../libs/alg/studentslist/studentslist.h"

#include <fstream>
#include <algorithm>
#include <iostream>

template <typename T>
bool compare(T a, T b) {
    return a > b;
}

template <typename T>
bool equals(T a, T b) {
    return a == b;
}

bool filter_by_name(Student& a, std::string& val) {
    return equals(a.name, val);
}

struct {
    bool operator()(const Student &a, const Student &b) const { return !compare(a.mark, b.mark); }
} sort_by_mark;

int main() {
    StudentsList list;

    std::ifstream in("data.txt");
    while (!in.eof()) {
        std::string val;
        std::getline(in, val);
        auto space_pos = std::find(val.begin(), val.end(), ' ');
        std::string name = val.substr(0, space_pos - val.begin());
        auto old_space_pos = space_pos + 1;
        space_pos = std::find(space_pos + 1, val.end(), ' ');
        int age = std::stoi(val.substr(old_space_pos - val.begin(), space_pos - val.begin()));
        old_space_pos = space_pos + 1;
        int mark = std::stoi(val.substr(old_space_pos - val.begin(), val.end() - val.begin()));

        list.add({name, age, mark});
    }
    in.close();

    auto search = list.find<std::string>("Glenda", sort_by_mark, filter_by_name);

    for (auto& student : search)
        std::cout << student.name << " " << student.age << " " << student.mark << std::endl;
}
