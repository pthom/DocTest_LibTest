See https://github.com/onqtam/doctest/issues/21

If you run "MyLibrary_DocTest", no test is launched !

However, if you edit MyMLibrary/CMakeLists.txt the tests can be run :

Comment the lines :
```
add_executable(MyLibrary_DocTest ${CMAKE_SOURCE_DIR}/doctest/doctest_main.cpp)
target_link_libraries(MyLibrary_DocTest MyLibrary)
```

and uncomment the lines :
```
add_executable(MyLibrary_DocTest ${sources} ${CMAKE_SOURCE_DIR}/doctest/doctest_main.cpp)
target_include_directories(MyLibrary_DocTest PUBLIC ${CMAKE_SOURCE_DIR}/doctest )
```
