#include <iostream>

#include "template.hpp"

auto main() -> int {
    std::cout
        << "Hi! I regret to inform you that 2 + 2 is not 5, it is in fact, "
        << placeholder::add(2, 2) << ".\n";
    std::exit(EXIT_SUCCESS);
}