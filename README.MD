# Static/ dynamic library "doctesting" made easy

#### Motivation
The doctest documentation says rightfully:
> Tests can be considered a form of documentation and should be able to reside near the production code which they test.*

In the case of a static library, this means that the tests code should reside directly inside the library source files (and not inside separate source files).

Unfortunately, the self-registration of the tests does not work as desired when you link a static library : your tests might not be launched at all! This is due to the fact that the linker often strips the self-registration code when it is inside a library.
For a more thorough explanation, see : https://github.com/onqtam/doctest/issues/21


This project provides a solution, based on the further assumption that :
> Adding tests to a library should be straightforward. Optimaly, it should be possible to do it by using a one-liner instruction in the library's CMakeList' file.


#### Quick usage instruction

`doctest_registerlibrary.cmake` provides several cmake functions that make it possible to add tests to a library, using a one-liner instruction in your `CMakeList.txt` file.

For example :
```
add_library(MyLibrary STATIC lib1.cpp lib2.cpp)
# The line below will activate the tests for the library !
doctest_registerlibrary(MyLibrary)  
```

This one-liner will :
- ensure that all tests are actually run
- append the doctest include path to your library
- create an exectuable test target for your library
- register it as a cmake test (so that `ctest` or `make test`) will launch it.



## Detailed Usage instuctions :

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
