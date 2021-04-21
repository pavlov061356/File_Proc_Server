
cmake_minimum_required(VERSION 3.10.2)
project(File_Proc_Client)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_PREFIX_PATH "/home/vladimir/Qt/5.15.2/gcc_64")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

enable_testing()

set(SEND_TIMEOUT 1)

#add_test(Correct_Input ./File_Proc_Client /home/vladimir/Work/send.txt hash ) #|../File_PRoc_Server/File_Proc_Server ~/upStorage/)

add_test(Correct_Input /home/vladimir/Work/File_Proc_Client/Correct_Input.sh)

#add_test(Incorrect_Input ../File_PRoc_Server/File_Proc_Server ~/upStorage/ | ./File_Proc_Client /home/vladimir/Work/send.txt has)

add_test(Incorrect_Input /home/vladimir/Work/File_Proc_Client/Incorrect_Input.sh)

set_tests_properties(Correct_Input PROPERTIES
PASS_REGULAR_EXPRESSION "The hashes match, transmission successfully completed!"
FAIL_REGULAR_EXPRESSION "Aborting transmission!")

set_tests_properties(Incorrect_Input PROPERTIES
PASS_REGULAR_EXPRESSION "Aborting transmission!")

set(QT_VERSION 5)
set(REQUIRED_LIBS Core WebSockets)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::WebSockets)

add_executable(${PROJECT_NAME} main.cpp websocketclient.cpp websocketclient.h)

if (NOT CMAKE_PREFIX_PATH)
    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
endif ()

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})
