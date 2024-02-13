#include <iostream>

#include "../libs/alg/todolist/todolist.h"

int main() {
    std::cout << "Type 0 to get help\n";
    std::cout << "Type 1 to get list of tasks\n";
    std::cout << "Type 2 to create task\n";
    std::cout << "Type 3 to switch task completion\n";
    std::cout << "Type 4 to delete task\n";
    std::cout << "Type 5 to exit" << std::endl;

    todolist::schedule schedule;

    while (true) {
        int action;
        std::cin >> action;

        if (action == 0) {
            std::cout << "Type 0 to get help\n";
            std::cout << "Type 1 to get list of tasks\n";
            std::cout << "Type 2 to create task\n";
            std::cout << "Type 3 to switch task completion\n";
            std::cout << "Type 4 to delete task\n";
            std::cout << "Type 5 to exit" << std::endl;
        } else if (action == 1) {
            std::cout << "Todolist: \n";
            std::cout << schedule << std::endl;
        } else if (action == 2) {
            std::cout << "Enter description: " << std::endl;
            std::string desc;
            std::cin.ignore();
            std::getline(std::cin, desc);
            std::cout << "Enter how soon should it start (in format \"h m s\"): " << std::endl;
            long long hb = 0, mb = 0, sb = 0;
            std::cin >> hb >> mb >> sb;
            std::cout << "Enter how soon should it last (in format \"h m s\"): " << std::endl;
            long long he = 0, me = 0, se = 0;
            std::cin >> he >> me >> se;
            todolist::task task(todolist::date::now().plus({hb * 3600 + mb * 60 + sb}),
                                todolist::date::now().plus({(he + hb) * 3600 + (me + mb) * 60 + se + sb}), desc);

            try {
                schedule.add_task(task);
                std::cout << "Task successfully created" << std::endl;
            } catch (std::invalid_argument &ex) {
                std::cout << ex.what();
                std::cout << std::endl;
            }
        } else if (action == 3) {
            std::cout << "Enter task id: " << std::endl;
            int id;
            std::cin >> id;

            try {
                auto t = schedule.get_task(id);
                t.set_completed(t.get_status() != todolist::completed);
                schedule.add_task(t);
                std::cout << "Task successfully marked" << std::endl;
            } catch (std::invalid_argument &ex) {
                std::cout << ex.what();
                std::cout << std::endl;
            }
        } else if (action == 4) {
            std::cout << "Enter task id: " << std::endl;
            int id;
            std::cin >> id;

            try {
                schedule.delete_task(id);
                std::cout << "Task successfully deleted" << std::endl;
            } catch (std::invalid_argument &ex) {
                std::cout << ex.what();
                std::cout << std::endl;
            }
        } else if (action == 5)
            break;
        else
            std::cout << "Action is not recognised" << std::endl;
    }

    std::cout << "Goodnight" << std::endl;
}
