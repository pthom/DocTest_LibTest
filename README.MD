# doctest_registerlibrary

## Motivation
The doctest documentation says rightfully:
> Tests can be considered a form of documentation and should be able to reside near the production code which they test.*

In the case of a static library, this means that the tests code should reside directly inside the library source files (and not inside separate source files).
Unfortunately, the self-registration of the tests does not work as desired when you link a static library : your tests might not be launched at all!  
For a more thorough explanation, see : https://github.com/onqtam/doctest/issues/21


#### How this project solves the issues for library testing

`doctest_registerlibrary/doctest_registerlibrary.cmake` provides a cmake function that make it possible to run test from inside a library.



## Usage instuctions :

#### Step 1 : in the main `CMakeLists.txt`
Enable tests in cmake, by adding the following line:
```
enable_testing()
```
##### Step 2 : in the `CMakeLists.txt` of your library
* Include "doctest_registerlibrary.cmake"
* Call `doctest_registerlibrary(MyLibrary)` (where MyLibrary is the name of your library)

Example :
```
include("${CMAKE_SOURCE_DIR}/doctest_registerlibrary/doctest_registerlibrary.cmake")

add_library(MyLibrary STATIC lib1.cpp lib2.cpp)
doctest_registerlibrary(MyLibrary)
```

##### What will doctest_registerlibrary.cmake do :
- It will append the doctest include path to the library
- It will add another executable target named "YourLibraryName_DocTest"
- It will register this exe as a test (so that `make test` or `ctest` will launch it)
- It will make some small changes to your cpp files in order to ensure that tests are actually run :
  - It will modify your cpp files by adding a dummy function DocTestRegister_xxx()
  - It will add a file doctest_registerlibrary.cpp that will call these dummy functions




Note : doctest is a submodule, so run `git submodule update --init` after cloning
