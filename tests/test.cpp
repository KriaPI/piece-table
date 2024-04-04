#include <gtest/gtest.h>

#include "piece_table.hpp"

TEST(piece_table, get_text_single_piece) {
    KUNI::Piece_table document{"I love water"};

    const auto expected{"I love water"};

    EXPECT_EQ(expected, document.get_text());
}

TEST(piece_table, get_text_two_pieces) {
    KUNI::Piece_table document{"I love water"};
    document.insert(" and bread.", document.length());

    const auto expected{"I love water and bread."};
    EXPECT_EQ(expected, document.get_text());
}

TEST(piece_table, insert_at_beginning) {
    KUNI::Piece_table document{"Three"};
    document.insert("Two ", 0);
    document.insert("One ", 0);

    const auto expected_string{"One Two Three"};
    const auto expected_piece_count{3};
    const auto expected_length{14};

    EXPECT_EQ(expected_string, document.get_text());
    EXPECT_EQ(expected_piece_count, document.piece_count());
    EXPECT_EQ(expected_length, document.length());
}

TEST(piece_table, insert_between_pieces_case_1) {
    // The expected behavior is that a new piece will be added before the
    // piece containing "dog.".
    KUNI::Piece_table document{"A cat"};
    document.insert("dog.", document.length());
    document.insert(" and a ", 5);

    const auto expected_string{"A cat and a dog."};
    const auto expected_piece_count{3};
    const auto expected_length{17};

    EXPECT_EQ(expected_string, document.get_text());
    EXPECT_EQ(expected_piece_count, document.piece_count());
    EXPECT_EQ(expected_length, document.length());
}

TEST(piece_table, insert_between_pieces_case_2_A) {
    // The expected behavior is that the existing piece containing the index
    // where we want to insert the new piece (or substring) into will be split
    // and the a new piece should be created and placed between the two.
    KUNI::Piece_table document{"ABCE"};
    document.insert("F", document.length());
    document.insert("D", 3);

    const auto expected_string{"ABCDEF"};
    const auto expected_piece_count{4};
    const auto expected_length{7};

    EXPECT_EQ(expected_string, document.get_text());
    EXPECT_EQ(expected_piece_count, document.piece_count());
    EXPECT_EQ(expected_length, document.length());
}

TEST(piece_table, insert_between_pieces_case_2_B) {
    KUNI::Piece_table document{"This (1245) is a number"};
    document.insert("3", 8);

    const auto expected_string{"This (12345) is a number"};
    const auto expected_piece_count{3};
    const auto expected_length{25};

    EXPECT_EQ(expected_string, document.get_text());
    EXPECT_EQ(expected_piece_count, document.piece_count());
    EXPECT_EQ(expected_length, document.length());
}

TEST(piece_table, insert_at_end) {
    KUNI::Piece_table document{"This is "};
    document.insert("cool and", document.length());
    document.insert(" epic.", document.length());

    const auto expected_string{"This is cool and epic."};
    const auto expected_piece_count{2};
    const auto expected_length{23};

    EXPECT_EQ(expected_string, document.get_text());
    EXPECT_EQ(expected_piece_count, document.piece_count());
    EXPECT_EQ(expected_length, document.length());
}
