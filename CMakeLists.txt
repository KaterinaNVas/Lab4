cmake_minimum_required(VERSION 3.16)
project(Lab4 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(MSVC)
    add_compile_options(/utf-8)
endif()

add_library(Lab4.Library
    Lab4.Library/Department.cpp
    Lab4.Library/Group.cpp
    Lab4.Library/LaboratoryWork.cpp
    Lab4.Library/Person.cpp
    Lab4.Library/Student.cpp
    Lab4.Library/Teacher.cpp
    Lab4.Library/University.cpp
)
target_include_directories(Lab4.Library PUBLIC Lab4.Library)

add_executable(Lab4.Console
    Lab4.Console/main.cpp
)
target_link_libraries(Lab4.Console PRIVATE Lab4.Library)

enable_testing()
add_executable(Lab4.Tests
    Lab4.Tests/DepartmentTests.cpp
    Lab4.Tests/GroupTests.cpp
    Lab4.Tests/PersonTests.cpp
    Lab4.Tests/StudentTests.cpp
    Lab4.Tests/TeacherTests.cpp
    Lab4.Tests/UniversityTests.cpp
    Lab4.Tests/TestMain.cpp
)
target_link_libraries(Lab4.Tests PRIVATE Lab4.Library)
add_test(NAME Lab4.Tests COMMAND Lab4.Tests)
