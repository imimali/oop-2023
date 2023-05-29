cmake_minimum_required(VERSION 3.24)
project(simulation_practice)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/opt/homebrew/bin")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(simulation_practice main.cpp car.h tests.h repository.h service.h ui.h)
target_link_libraries(simulation_practice
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

