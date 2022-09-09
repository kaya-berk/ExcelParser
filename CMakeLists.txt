cmake_minimum_required(VERSION 3.5)

project(QXlsxParser LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_subdirectory(QXlsx)
find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

add_executable(QXlsxParser main.cpp
indexPair.cpp indexPair.h
breakPointController.cpp breakPointController.h
listFileRec.cpp listFileRec.h)
target_link_libraries(QXlsxParser Qt5::Core QXlsx)
target_link_directories(QXlsxParser PUBLIC ${QXLSX_HEADERPATH})
install(TARGETS QXlsxParser)

