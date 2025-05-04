cmake_minimum_required(VERSION 3.16)

project(ToDo1 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Gui Widgets Sql Multimedia)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Gui Widgets Sql Multimedia)

set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp mainwindow.h mainwindow.ui
    addwindow.cpp addwindow.h addwindow.ui
    deletewindow.cpp deletewindow.h deletewindow.ui
    staticticsinfo.cpp staticticsinfo.h staticticsinfo.ui
    taskswindow.cpp taskswindow.h taskswindow.ui
    calendarwindow.cpp calendarwindow.h calendarwindow.ui
    tasknotification.h tasknotification.cpp tasknotification.ui
    sound.qrc
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(ToDo1
        WIN32
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    add_executable(ToDo1 WIN32 ${PROJECT_SOURCES})
endif()

target_link_libraries(ToDo1 PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Gui
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Sql
    Qt${QT_VERSION_MAJOR}::Multimedia
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(ToDo1)
endif()
