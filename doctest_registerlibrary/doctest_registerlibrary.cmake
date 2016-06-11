function (doctest_registerlibrary libraryName)
  #message("doctest_registerlibrary ${libraryName}")
  get_target_property(sources ${libraryName} SOURCES)

  # Step 1 : Modify cpp files in order to add register function (see doctest_register.py -file)
  foreach(source ${sources})
    execute_process(COMMAND python ${CMAKE_SOURCE_DIR}/doctest_registerlibrary/doctest_registerlibrary.py -file ${source} WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
  endforeach(source)

  # Step 2 : Create doctest_registerlibrary.cpp file (call doctest_register.py -library)
  execute_process(COMMAND python ${CMAKE_SOURCE_DIR}/doctest_registerlibrary/doctest_registerlibrary.py -library ${sources} WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

  # Step 3 : append doctest_registerlibrary.cpp to the library sources if needed
  if (NOT ";${SOURCES};" MATCHES ";doctest_registerlibrary.cpp;")
    set(sourcesWithRegisterDocTest ${SOURCES} doctest_registerlibrary.cpp)
    target_sources(${libraryName} PRIVATE ${sourcesWithRegisterDocTest})
  endif()

  # Step 4 : add new exe + add_test
  add_executable(${libraryName}_DocTest ${CMAKE_SOURCE_DIR}/doctest_registerlibrary/doctest_main.cpp)
  target_link_libraries(${libraryName}_DocTest ${libraryName})

  add_test(NAME ${libraryName}_DocTest COMMAND ${libraryName}_DocTest)

endfunction(doctest_registerlibrary)
