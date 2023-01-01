project(bookstore)
set(CMAKE_CXX_STANDARD 20)

add_executable(code main.cpp
        log.cpp
        readandwrite.cpp
        user.cpp
        book.cpp
        error.cpp)
