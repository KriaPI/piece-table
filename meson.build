project('piece_table', 'cpp',
    default_options: ['cpp_std=c++17', 'warning_level=3']
)

add_project_arguments('-Wno-abi-tag', language: 'cpp')

gtest_subproject = subproject('gtest')
gtest_dependency = gtest_subproject.get_variable('gtest_main_dep')

piece_table_include_path = include_directories('source/piece_table')
piece_table_library = library('piece_table', 'source/piece_table/piece_table.cpp', include_directories: piece_table_include_path)

piece_table_test = executable('piece_table_test', 'tests/test.cpp', 
    link_with: [piece_table_library], 
    include_directories: piece_table_include_path,
    dependencies: [
        gtest_dependency
    ]
)
test('Unit test 0', piece_table_test)

executable('main', 'source/main.cpp', link_with: piece_table_library, include_directories: piece_table_include_path)