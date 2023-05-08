cmake_minimum_required(VERSION 3.24)
project(seminar5_212)

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

add_executable(seminar5_212 main.cpp post.h repository.h service.h posts_ui.h posts_ui.cpp)
target_link_libraries(seminar5_212
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

