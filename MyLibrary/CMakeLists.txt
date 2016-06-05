set(sources lib1.cpp lib2.cpp)
add_library(MyLibrary STATIC ${sources})
set_property(TARGET MyLibrary PROPERTY CXX_STANDARD 11)
target_include_directories(MyLibrary PUBLIC ${CMAKE_SOURCE_DIR}/doctest/doctest )

# This does not work : it links but the test list is empty !
add_executable(MyLibrary_DocTest ${CMAKE_SOURCE_DIR}/doctest_main/doctest_main.cpp)
target_link_libraries(MyLibrary_DocTest MyLibrary)

# This works, but it requires to re-compile all the source files and to re-define
# exactly the same compile options as for the library (linked library, compile definition, etc);
# this can be tedious
#add_executable(MyLibrary_DocTest ${sources} ${CMAKE_SOURCE_DIR}/doctest/doctest_main.cpp)
#target_include_directories(MyLibrary_DocTest PUBLIC ${CMAKE_SOURCE_DIR}/doctest )
