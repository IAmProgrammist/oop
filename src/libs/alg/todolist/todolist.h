#pragma once

#include <chrono>
#include <vector>
#include <thread>
#include <future>

namespace todolist {
    struct ttime {
        std::time_t time; 
    };

    struct date {
        ttime time;
        static date now();
        date plus(ttime plusTime);

        friend std::ostream& operator<<(std::ostream& out, date& task);
    };

    enum status {
        awaits,
        in_progress,
        overdue,
        completed
    };

    struct task {
        private:
        static int id_counter;
        int id;
        date begin;
        date end;
        std::string description;
        status _status;
      
        public:
        task(date beg, date end);
        date get_begin();
        date get_end();
        std::string get_description;
        std::string set_destription;
        void set_begin(date begin);
        void set_end(date end);
        void update();
        void set_status(bool completed);
        status get_status();

        friend std::ostream& operator<<(std::ostream& out, task& task);
    };

    struct schedule {
        public:
        void add_task(task task);
        void delete_task(int task_id);
        
        friend std::ostream& operator<<(std::ostream& out, schedule& task);

        private:
        std::vector<task> tasks;
        void update();
        std::future<void> updater;
        std::mutex update_mutex;
        bool should_run;
    }
}