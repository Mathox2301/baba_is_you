cmake_minimum_required(VERSION 3.5)

enable_testing()
project(Baba_Project VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall -pedantic-errors")
set(CMAKE_CXX_STANDARD 20)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)


set(PROJECT_SOURCES
    ./model/Square.cpp ./model/Game.cpp ./model/Board.cpp ./model/Position.cpp ./model/Subject.h ./model/Game.h ./model/Facade.h ./view/abstractView.h
    ./view/View.h ./view/View.cpp ./view/mainwindow.cpp ./view/mainwindow.h ./view/mainwindow.ui ./controller/Controller.h ./controller/Controller.cpp ./model/Board.h ./model/Observer.h ./model/TypeCase.h
    ./model/Square.h ./model/Position.h ./controller/main.cpp ./model/tests.cpp )

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Baba_Project
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Baba_Project APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Baba_Project SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Baba_Project
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Baba_Project PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(Baba_Project PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

#install(TARGETS Baba_Project
#    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(TARGETS Baba_Project
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Baba_Project)
endif()



#Uncomment below and comment all of above to run in console

#cmake_minimum_required(VERSION 3.5)

#enable_testing()
#project(Baba_Project LANGUAGES CXX)

#set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_FLAGS "-Wall -pedantic-errors")

#add_executable(Baba_Project ./model/Square.cpp ./model/Game.cpp ./model/Board.cpp ./model/Position.cpp ./model/Subject.h ./model/Game.h ./model/Facade.h
#./view/View.h ./view/View.cpp ./controller/Controller.h ./controller/Controller.cpp ./model/Board.h ./model/Observer.h ./model/TypeCase.h
#./model/Square.h ./model/Position.h ./controller/main.cpp ./model/tests.cpp)

#install(TARGETS Baba_Project
#    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

