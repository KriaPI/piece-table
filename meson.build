project('template', 'cpp',
    default_options: ['cpp_std=c++17', 'warning_level=everything']
)

gtest_subproject = subproject('gtest')
gtest_dependency = gtest_subproject.get_variable('gtest_main_dep')

template_include_path = include_directories('source/template')
template_library = library('template', 'source/template/template.cpp', include_directories: template_include_path)

template_test = executable('template_test', 'tests/test.cpp', 
    link_with: [template_library], 
    include_directories: template_include_path,
    dependencies: [
        gtest_dependency
    ]
)
test('Unit test 0', template_test)

executable('main', 'source/main.cpp', link_with: template_library, include_directories: template_include_path)