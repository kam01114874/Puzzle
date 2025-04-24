cmake_minimum_required(VERSION 3.16)
project(Puzzle)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

set(SOURCES
    main.cpp
    mainwindow.cpp
    board.cpp
    tile.cpp
    game.cpp
    animatedtile.cpp
    movingtile.cpp

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

    newgamedialog.h
    boardwidget.h
    ShuffleAlgorithm.h
    cli/consoleui.h
)

set(UIS
    mainwindow.ui
    newgamedialog.ui
)

set(RESOURCES resources.qrc)
qt_add_resources(RES_SOURCES ${RESOURCES})

add_executable(Puzzle
    ${SOURCES}
    ${HEADERS}
    ${UIS}
    ${RES_SOURCES}
    previewwindow.h previewwindow.cpp
)

target_link_libraries(Puzzle
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)

target_include_directories(Puzzle
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
)
