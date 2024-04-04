#include "../../libs/alg/studentslist/studentslist.h"

#include <cstring>
#include <fstream>
#include <algorithm>
#include <iostream>

bool filter_by_name(Student& a, CharString & val) {
    return strcmp(a.name.val, val.val) == 0;
}

struct {
    bool operator()(const Student &a, const Student &b) const {
        int mark1 = std::atoi(a.mark.val);
        int mark2 = std::atoi(b.mark.val);

        return mark1 < mark2;
    }
} sort_by_mark;

int main() {
    StudentsList list;

    std::ifstream in("data.txt");
    while (!in.eof()) {
        std::string val;
        std::getline(in, val);
        auto space_pos = std::find(val.begin(), val.end(), ' ');
        std::string name = val.substr(0, space_pos - val.begin());
        CharString namec;
        strcpy(namec.val, name.c_str());

        auto old_space_pos = space_pos + 1;
        space_pos = std::find(old_space_pos, val.end(), ' ');
        std::string age = val.substr(old_space_pos - val.begin(), space_pos - old_space_pos);
        CharString agec;
        strcpy(agec.val, age.c_str());

        old_space_pos = space_pos + 1;
        std::string mark = (val.substr(old_space_pos - val.begin(), space_pos - old_space_pos));
        CharString markc;
        strcpy(markc.val, mark.c_str());

        list.add({namec, agec, markc});
    }
    in.close();
    CharString search_val = {"Christina"};

    auto search = list.find<CharString>(search_val, sort_by_mark, filter_by_name);

    for (auto& student : search)
        std::cout << student.name.val << " " << student.age.val << " " << student.mark.val << std::endl;
}
