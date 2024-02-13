#include <algorithm>
#include <sstream>
#include <chrono>

#include "todolist.h"

namespace todolist {

    date date::now() {
        return {std::chrono::system_clock::to_time_t(std::chrono::system_clock::now())};
    }

    date date::plus(ttime plusTime) {
        return {this->time.time + plusTime.time};
    }

    std::ostream& operator<<(std::ostream& out, date& task) {
        std::tm * ptm = std::localtime(&task.time.time);
        char buffer[32];
        std::strftime(buffer, 32, "%a, %d.%m.%Y %H:%M:%S", ptm);

        out << std::string(buffer);
        return out;
    }



    int task::id_counter = 0;

    task::task(date beg, date end, std::string description) {
        if (end.time.time < beg.time.time) 
            throw std::invalid_argument("Completion time can't be bigger than beginning time");
        
        this->begin = beg;
        this->end = end;
        this->description = description;
        this->id = task::id_counter++;
        this->completed = false;
    }

    date task::get_begin() {
        return this->begin;
    }

    date task::get_end() {
        return this->end;
    }

    std::string task::get_description() {
        return this->description;
    }

    void task::set_destription(std::string description) {
        this->description = description;
    }

    void task::set_begin(date beg) {
        if (this->end.time.time < beg.time.time) 
            throw std::invalid_argument("Completion time can't be bigger than beginning time");

        this->begin = beg;
    }
    
    void task::set_end(date end) {
        if (end.time.time < this->begin.time.time) 
            throw std::invalid_argument("Completion time can't be bigger than beginning time");

        this->end = end;
    }

    void task::set_completed(bool completed) {
        this->completed = completed;
    }

    status task::get_status() {
        if (this->completed) return status::completed;

        date now_time = date::now();
        if (now_time.time.time < this->begin.time.time)
            return status::awaits;
        if (now_time.time.time < this->end.time.time)
            return status::in_progress;
        return status::overdue;
    }

    int task::get_id() {
        return this->id;
    }

    std::ostream& operator<<(std::ostream& out, task& task) {
        std::stringstream buf;
        buf << "Task:        " << task.id << "\n";
        buf << "Begin:       " << task.begin << "\n";
        buf << "End:         " << task.end << "\n";
        buf << "Description: " << task.description << "\n";

        out << buf.str();

        return out;
    }

    bool task::task_cmp(task a, task b) {
        return a.id == b.id;
    }

    void schedule::add_task(task task) {
        auto pos = std::find_if(this->tasks.begin(), this->tasks.end(), [&task](struct task item) {
            return task::task_cmp(task, item);
        });

        if (pos == this->tasks.end())
            this->tasks.push_back(task);
        else
            this->tasks[pos - this->tasks.begin()] = task;
    }

    void schedule::delete_task(int task_id) {
        auto pos = std::find_if(this->tasks.begin(), this->tasks.end(), [&task_id](struct task item) {
            return item.get_id() == task_id;
        });

        if (pos == this->tasks.end())
            throw std::invalid_argument("Task with such id doesn't exists");
        else
            this->tasks.erase(pos);
    }

    task schedule::get_task(int task_id) {
        auto pos = std::find_if(this->tasks.begin(), this->tasks.end(), [&task_id](struct task item) {
            return item.get_id() == task_id;
        });

        if (pos == this->tasks.end())
            throw std::invalid_argument("Task with such id doesn't exists");
        else
            return this->tasks[pos - this->tasks.begin()];
    }
}
