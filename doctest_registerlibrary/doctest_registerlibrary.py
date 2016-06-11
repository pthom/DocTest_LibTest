#!/bin/python
import sys
import uuid
import os.path

FileCode = """
// This code was added by doctest_registerlibrary.cmake in order to ensure that the tests are properly run by DocTest.
// Please commit it if needed, it will be added only once, and never modified.
// Before committing, you can remove this comment, as long as you leave the function below.
int DocTestRegister_GUID() { return 0; }
"""

DocTestRegisterCppCode = """
// This file is autogenerated.
// It was added by doctest_registerlibrary.cmake in order to ensure that the tests are properly run by DocTest.
// Please commit it if needed, it will be modified only if new files are added.

[DeclareRegisterFunctions]

int DocTestRegister()
{
  int dummy_sum = 0;
[CallRegisterFunctions]
  return dummy_sum;
}
"""

def ProcessFile(filename):
    #print("ProcessFile " + filename)
    if (filename == "doctest_registerlibrary.cpp"):
        return
    with open(filename, 'r') as f:
        lines = f.readlines()

    tokenPresent = False
    for line in lines:
        if ("int DocTestRegister_" in line):
            tokenPresent = True

    if (not tokenPresent) :
        id = str(uuid.uuid4())
        id = id.replace("-", "_")
        with open(filename, 'a') as f:
            codeWithUuid = FileCode.replace("GUID", id)
            f.write(codeWithUuid)
            print(filename + " was modified (added DocTestRegister_ function()")



def ProcessLibrary(sourcesFiles):
    print("ProcessLibrary ")
    guidList = []
    for filename in sourcesFiles:
        guid = ""
        with open(filename, 'r') as f:
            lines = f.readlines()
        for line in lines:
            if ("int DocTestRegister_" in line):
                line = line.replace("int", "")
                line = line.replace("(", "")
                line = line.replace(")", "")
                words = line.split()
                for word in words:
                    if ("DocTestRegister_" in word):
                        guid = word.replace("DocTestRegister_", "")
        if (guid != ""):
            guidList.append(guid)

    declareRegisterFunctions = ""
    callRegisterFunctions = ""
    for guid in guidList:
        declareRegisterFunctions = declareRegisterFunctions + "int DocTestRegister_" + guid + "();\n"
        callRegisterFunctions = callRegisterFunctions + "  dummy_sum += DocTestRegister_" + guid + "();\n";

    codeWithGuidList = DocTestRegisterCppCode
    codeWithGuidList = codeWithGuidList.replace("[DeclareRegisterFunctions]", declareRegisterFunctions)
    codeWithGuidList = codeWithGuidList.replace("[CallRegisterFunctions]", callRegisterFunctions)
    #print(codeWithGuidList)

    if (not os.path.isfile("doctest_registerlibrary.cpp") ):
        print("doctest_registerlibrary.cpp was created (you can add it to source control, or ignore it, as preferred)")
    with open("doctest_registerlibrary.cpp", "w") as f:
        f.write(codeWithGuidList)



def help():
    helpMessage = """
        Usage :
            _command_ -file file.cpp
                Will add a DocTestRegister_GUID() to a cpp file
            _command_ -library file1.cpp file2.cpp file3.cpp ...
                Will create a doctest_registerlibrary.cpp file with one function that calls all DocTestRegister_GUID() functions
    """
    helpMessage = helpMessage.replace("_command_", sys.argv[0])
    print(helpMessage)

def main():
    if (len(sys.argv) == 0):
        help()
    if (sys.argv[1] == "-file"):
        file = sys.argv[2]
        ProcessFile(file)
    elif (sys.argv[1] == "-library"):
        ProcessLibrary(sys.argv[2:])
    else:
        help()

main()
