add_library(alg todolist/todolist.cpp date/date.cpp goods/goods.cpp
    calculator/calculator.cpp
    mathparser/mathparser.cpp )

target_include_directories(alg PRIVATE ../boost)
