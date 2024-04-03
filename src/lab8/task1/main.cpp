#include <iostream>

#include "../../libs/alg/matrix/matrix.tpp"

int main() {
    Matrix t({1, 2, 3,
              4, 5, 6,
              7, 8, 9}, 3, 3);

    t.push_back({10,11,12});

    std::cout << t(3, 2) << std::endl;
}
