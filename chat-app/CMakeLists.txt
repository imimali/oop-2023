cmake_minimum_required(VERSION 3.24)
project(chat_app)

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

add_executable(chat_app main.cpp)
target_link_libraries(chat_app
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

