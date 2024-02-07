#include <fstream>
#include <vector>

#define N 3

int main() {
    std::ifstream dataIn("data.txt");
    std::vector<int> divThree;
    std::vector<int> modThreeOne;

    if (!dataIn.is_open()) return 1;

    while (!dataIn.eof()) {
        int num;
        dataIn >> num;

        if (num % 3 == 0) divThree.push_back(num);
        else if (num % 3 == 1) modThreeOne.push_back(num);
    }

    dataIn.close();

    std::ofstream dataOut("data.txt");
    
    for (auto& num : divThree)
        dataOut << num << " ";

    for (auto& num : modThreeOne)
        dataOut << num << " ";

    dataOut.flush();
    dataOut.close();
}