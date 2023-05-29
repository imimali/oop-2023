cmake_minimum_required(VERSION 3.24)
project(seminar6_chat)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/opt/homebrew/bin/")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(seminar6_chat main.cpp user.h message.h observer.h chat_session.h chat_window.h statistics.h)
target_link_libraries(seminar6_chat
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

