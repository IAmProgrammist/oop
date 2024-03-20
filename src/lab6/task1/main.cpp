#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include <algorithm>
#include <windows.h>

void space_adder(std::vector<char>& val, std::mutex& m) {
    while (1) {
        m.lock();

        auto spaceFind = std::find(val.begin(), val.end(), ' ');
        while (spaceFind != val.end()) {
            val.erase(spaceFind);

            spaceFind = std::find(val.begin(), val.end(), ' ');
        }

        int newSpaces = val.size();
        for (int i = 0; i < newSpaces; i++) {
            int randIndex = val.size() * 1.0 * rand() / RAND_MAX;

            val.insert(val.begin() + randIndex, ' ');
        }

        m.unlock();

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

void move_val(std::vector<char>& val, std::mutex& m) {
    while (1) {
        m.lock();

        char b = val[0];
        val.erase(val.begin());
        val.push_back(b);

        m.unlock();

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

void outputter(std::vector<char>& val, std::mutex& m) {
    while (1) {
        m.lock();

        for (auto& ch : val) {
            std::cout << ch;
        }
        std::cout << "\n";

        m.unlock();

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    std::mutex m;
    std::vector<char> val = {'H', 'e', 'l', 'l', 'o'};
    std::thread th1(space_adder, std::ref(val), std::ref(m));
    std::thread th2(move_val, std::ref(val), std::ref(m));
    std::thread th3(outputter, std::ref(val), std::ref(m));

    th1.detach();
    th2.detach();
    th3.detach();

    int a;
    std::cin >> a;

    return 0;
}

