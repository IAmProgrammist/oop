#include <fstream>
#include <sstream>

#define N 3

int main() {
    std::ifstream dataIn("data.txt");
    std::stringstream buf;

    if (!dataIn.is_open()) return 1;

    while (!dataIn.eof()) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                float num;
                dataIn >> num;

                if (j == N - 1 || i == N - 1) continue;

                buf << num << " ";
            }

            if (i != N - 1)
                buf << "\n";
        }
    }

    dataIn.close();

    std::ofstream dataOut("data.txt");
    dataOut << buf.str();
    dataOut.flush();
    dataOut.close();
}