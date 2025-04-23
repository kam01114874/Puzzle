cmake_minimum_required(VERSION 3.30)
project(Puzzle)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Widgets
        REQUIRED)

set(SOURCES
    main.cpp
    mainwindow.cpp
    board.cpp
    tile.cpp
    game.cpp
    animatedtile.cpp
    movingtile.cpp
    selectabletile.cpp
    newgamedialog.cpp
    boardwidget.cpp
    cli/consoleui.cpp
)

set(HEADERS
    mainwindow.h
    board.h
    tile.h
    game.h
    animatedtile.h
    movingtile.h
    selectabletile.h
    newgamedialog.h
    boardwidget.h
    ShuffleAlgorithm.h
    cli/consoleui.h
)

set(UIS
    mainwindow.ui
    newgamedialog.ui
)

add_executable(Puzzle
    ${SOURCES}
    ${HEADERS}
    ${UIS}
)

target_link_libraries(Puzzle
        Qt::Core
        Qt${QT_VERSION_MAJOR}::Widgets
)

target_include_directories(Puzzle
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
)


#set(CMAKE_CXX_STANDARD 23)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)
#
#find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
#find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
#
#if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
#    qt_add_executable(Puzzle
#        MANUAL_FINALIZATION
#        ${PROJECT_SOURCES}
#    )
## Define target properties for Android with Qt 6 as:
##    set_property(TARGET Puzzle APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
##                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
## For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
#else()
#    if(ANDROID)
#        add_library(Puzzle SHARED
#            ${PROJECT_SOURCES}
#        )
## Define properties for Android with Qt 5 after find_package() calls as:
##    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    else()
#        add_executable(Puzzle
#            ${PROJECT_SOURCES}
#        )
#    endif()
#endif()
#
#target_link_libraries(Puzzle PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt::Core)
#
#
## Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
## If you are developing for iOS or macOS you should consider setting an
## explicit, fixed bundle identifier manually though.
#if(${QT_VERSION} VERSION_LESS 6.1.0)
#  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Puzzle)
#endif()
#set_target_properties(Puzzle PROPERTIES
#    ${BUNDLE_ID_OPTION}
#    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
#    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
#    MACOSX_BUNDLE TRUE
#    WIN32_EXECUTABLE TRUE
#)
#
#include(GNUInstallDirs)
#install(TARGETS Puzzle
#    BUNDLE DESTINATION .
#    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
#)
#
#if(QT_VERSION_MAJOR EQUAL 6)
#    qt_finalize_executable(Puzzle)
#endif()
#
#
