from __future__ import print_function
from abc import ABC, abstractmethod


class Matrix:
    def __init__(self):
        self.matrix = []

    def add_line(self, line: list) -> None:
        self.matrix.append(line)

    def get_height(self):
        return len(self.matrix)

    def get_min_width(self):
        return min(map(lambda x: len(x), self.matrix))

    def get_max_width(self):
        return max(map(lambda x: len(x), self.matrix))


class GroupMatricesPredicate(ABC):
    @abstractmethod
    def hash(self, matrix):
        pass


class GroupByEvenOddFactor(GroupMatricesPredicate):
    def hash(self, matrix):
        result = []

        for line in matrix.matrix:
            result.append(tuple(map(lambda x: x % 2 == 0, line)))

        return tuple(result)


class GroupMatrices:
    def __init__(self):
        self.matrices = []

    def add_matrix(self, matrix: Matrix):
        self.matrices.append(matrix)

    def group_by_predicate(self, predicate: GroupMatricesPredicate):
        result: dict = {}

        for matrix in self.matrices:
            hash = predicate.hash(matrix)

            if hash in result.keys():
                result[hash].append(matrix)
            else:
                result[hash] = [matrix]

        return result


def main():
    group_matrices = GroupMatrices()

    with open(input("Введите путь к файлу: "), "r") as f:
        tmp_matrix = Matrix()

        for line in f:
            if not line.strip():
                group_matrices.add_matrix(tmp_matrix)
                tmp_matrix = Matrix()
            else:
                tmp_matrix.add_line(list(map(lambda x: int(x), line.strip().split(" "))))

        if tmp_matrix.get_height() != 0:
            group_matrices.add_matrix(tmp_matrix)

    for group, matrices in group_matrices.group_by_predicate(GroupByEvenOddFactor()).items():
        print("Группа:")
        print(*group, "", sep="\n")

        print("Матрицы:")
        for matrix in matrices:
            print(*matrix.matrix, "", sep="\n")

        print("")


if __name__ == "__main__":
    main()
