#include <iostream>

#include "piece_table.hpp"

int main() {
    KUNI::Piece_table document{"ABCE"};
    document.insert("F", document.length());
    document.insert("D", 3);
    std::cout << document.get_text() << '\n';

    std::exit(EXIT_SUCCESS);
}