#include "piece_table.hpp"

#include <algorithm>
#include <stdexcept>
#include <string>

namespace KUNI {

std::string Piece_table::get_text_piece(Piece piece) {
    return piece.which_buffer == ORIGINAL
               ? m_original_text.substr(piece.start, piece.start + piece.length)
               : m_added_text.substr(piece.start, piece.start + piece.length);
}

std::string Piece_table::get_text() {
    std::string text{};
    for (const auto& piece : m_piece_table) {
        text.append(get_text_piece(piece));
    }

    return text;
}

bool Piece_table::latest_piece_is_last_in_new_buffer() {
    auto latest_piece{m_piece_table.back()};
    return latest_piece.which_buffer == NEW &&
           latest_piece.start + latest_piece.length == m_added_text.length();
}

void Piece_table::append(std::size_t start, std::size_t length) {
    if (latest_piece_is_last_in_new_buffer()) {
        m_piece_table.back().length += length;
    } else {
        m_piece_table.emplace_back(NEW, start, length);
    }
}

void Piece_table::insert_between(const std::size_t text_insertion_index,
                                 const std::size_t start_within_buffer,
                                 const std::size_t length) {
    // TODO: use the insert method of std::list to add one or more elements to
    // the piece table. Note: the first two overloads of the insert method takes
    // a constant iterator as a position and will therefore be constant in time
    // complexity (excluding the traversal to the position).

    // If the place to insert is the first or last character of a piece, a
    // single piece will be added. If the place to insert is within a piece, but
    // not the first or last, the existing piece needs to be split into two and
    // the new piece will be inserted between the pieces that resulted from the
    // splitting.

    // 1. Find the piece that represents the correct index within the text.
    // 2. Check if the insertion index is the first or last character within the
    // piece.
    // 3. If it is the first character within the piece, add a new piece before
    // it, else split the existing piece into two and add the new piece between
    // the two.

    auto current{m_piece_table.begin()};
    auto end{m_piece_table.end()};

    std::size_t current_piece_start{0};
    std::size_t current_piece_end{current->length - 1};

    while (current != end) {
        if (text_insertion_index <= current_piece_end) break;

        current_piece_start += current->length;
        std::advance(current, 1);
        current_piece_end += current->length;
    }

    if (text_insertion_index == current_piece_start) {
        m_piece_table.insert(current, {NEW, start_within_buffer, length});
    } else {
        auto left_piece_length{text_insertion_index - current_piece_start};
        auto right_piece_length{current->length - left_piece_length};

        // Shorten existing piece
        current->length = {left_piece_length};

        // Create the middle (new) piece
        m_piece_table.insert(std::next(current, 1),
                             {NEW, start_within_buffer, length});

        // Create the right piece
        m_piece_table.insert(
            std::next(current, 2),
            {current->which_buffer, current->start + left_piece_length,
             right_piece_length});
    }
}

void Piece_table::insert(const std::string_view& to_add, const std::size_t at) {
    const auto added_length{to_add.length()};
    const auto start_within_buffer{m_added_text.size()};

    if (at == 0) {
        m_piece_table.emplace_front(NEW, start_within_buffer, added_length);
    } else if (at == length()) {
        append(start_within_buffer, added_length);
    } else {
        insert_between(at, start_within_buffer, added_length);
    }

    m_length += added_length;
    m_added_text.append(to_add);
}

std::size_t Piece_table::length() { return m_length; }

std::size_t Piece_table::piece_count() { return m_piece_table.size(); }
}  // namespace KUNI