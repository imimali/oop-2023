cmake_minimum_required(VERSION 3.24)
project(seminar7_2)

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

add_executable(seminar7_2 main.cpp user.h message.h chat_window.h custom_model.h)
target_link_libraries(seminar7_2
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

