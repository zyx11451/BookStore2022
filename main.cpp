#include <iostream>
#include <vector>
#include "user.h"
#include "book.h"
#include "readandwrite.h"
block_linklist<user> users("users");
block_linklist<Book> books("books");
std::vector<selection> current;
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
