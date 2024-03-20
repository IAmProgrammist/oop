#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include <algorithm>
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);

    std::vector<char> val = {'H', 'e', 'l', 'l', 'o'};

    while (1) {
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

        char b = val[0];
        val.erase(val.begin());
        val.push_back(b);

        for (auto& ch : val) {
            std::cout << ch;
        }
        std::cout << "\n";

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    return 0;
}

