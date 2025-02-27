cmake_minimum_required(VERSION 3.5)

project(baba_is_you LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)


add_executable(baba_is_you model/gameState.h model/direction.h main.cpp
        model/elementType.h model/element.h model/position.cpp model/position.h model/square.cpp
        model/square.h controller/file.cpp controller/file.h
        model/board.cpp model/board.h model/babaIsyou.cpp model/babaIsyou.h model/elem.cpp model/elem.h
        controller/gameController.cpp
        controller/gameController.h  View/gameView.cpp View/gameView.h
        util/obs.h form.cpp form.h form.ui gameUi.cpp gameUi.h gameUi.ui win.cpp win.h win.ui
        lose.h lose.cpp lose.ui save.h save.cpp save.ui
        beggin.cpp beggin.h beggin.ui form.cpp)


    find_package (QT NAMES Qt6 REQUIRED COMPONENTS Widgets)
    find_package ( Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets )
    target_link_libraries (baba_is_you PRIVATE Qt${QT_VERSION_MAJOR}::Widgets )
