#pragma once

#include <ostream>
#include <vector>

namespace todolist {
    struct ttime {
        time_t time;
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
        bool completed;
      
        public:
        task(date beg, date end, std::string description);
        date get_begin();
        date get_end();
        std::string get_description();
        status get_status();
        int get_id();
        void set_destription(std::string description);
        void set_begin(date beg);
        void set_end(date end);
        void set_completed(bool completed);

        static bool task_cmp(task a, task b);

        friend std::ostream& operator<<(std::ostream& out, task& task);
    };

    struct schedule {
        public:
        void add_task(task task);
        void delete_task(int task_id);
        task get_task(int task_id);
        
        friend std::ostream& operator<<(std::ostream& out, schedule& task);

        private:
        std::vector<task> tasks;
    };
}
