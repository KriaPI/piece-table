#pragma once

#include <list>
#include <string>
#include <string_view>

namespace KUNI {
class Piece_table {
    enum text_orgin { ORIGINAL, NEW };

    class Piece {
       public:
        text_orgin which_buffer;
        std::size_t start;
        std::size_t length;
        Piece(text_orgin buffer, std::size_t starting_index,
              std::size_t piece_length)
            : which_buffer{buffer},
              start{starting_index},
              length{piece_length} {}
    };

    const std::string m_original_text;
    std::string m_added_text;
    std::list<Piece> m_piece_table;
    std::size_t m_length;

    std::string get_text_piece(Piece piece);

    bool latest_piece_is_last_in_new_buffer();
    void append(const std::size_t start, const std::size_t length);
    void insert_between(const std::size_t text_insertion_index,
                        const std::size_t start_within_buffer,
                        const std::size_t length);

   public:
    Piece_table(const std::string original)
        : m_original_text{original},
          m_added_text{},
          m_piece_table{},
          m_length{original.length() + 1} {
        m_piece_table.emplace_back(ORIGINAL, 0, original.length());
    }

    /// @brief Retrieve the text represented by the piece table as a string.
    /// @return A string containing the text stored by the piece table.
    std::string get_text();

    /// @brief Insert a string at index `at` within the text represented by the
    /// piece table. The first character within the string will be placed at
    /// index `at`. An index must be within the range `0` to `length` (the
    /// return value of the method `length()`).
    /// @param to_add String to be inserted.
    /// @param at Index specifying where `to_add` should be inserted.
    void insert(const std::string_view& to_add, const std::size_t at);

    /// @brief Erase all characters within the range [`from`, `to`]. Note that
    /// this includes the characters at index `from` and `to`.
    /// @param from Index refering to the first character within the range to
    /// remove.
    /// @param to Index refering to the last character within the range to
    /// remove.
    void erase(const std::size_t from, const std::size_t to);

    /// @brief Retrieve the length of the text represented by the piece table.
    /// This includes the null-terminator.
    /// @return The length of the text represented by the piece table, including
    /// null terminator.
    std::size_t length();

    /// @brief Retrieve the number of pieces in the piece table.
    /// @return The number of pieces in the piece table.
    std::size_t piece_count();
};
}  // namespace KUNI