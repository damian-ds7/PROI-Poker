cmake_minimum_required(VERSION 3.5)

project(PokerUI VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# only works if you have Qt installed in the default location
set(CMAKE_PREFIX_PATH "C:/Qt/6.7.1/msvc2019_64")
# C:/Qt/6.7.1/msvc2019_64
# C:/Qt/6.7.0/mingw_64
# C:/QtMSVC/6.7.1/msvc2019_arm64
#set(QT_QMAKE_EXECUTABLE "C:/QtMSVC/6.7.1/msvc2019_64/bin/qmake.exe")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)


set(PROJECT_SOURCES
        main.cpp
        widget.cpp
        widget.h
        widget.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(PokerUI
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        background.qrc
        cards.qrc
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET PokerUI APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(PokerUI SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(PokerUI
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(PokerUI PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Gui)
# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.PokerUI)
endif()
set_target_properties(PokerUI PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
)

include(GNUInstallDirs)
install(TARGETS PokerUI
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

target_compile_options(PokerUI PUBLIC "/Zc:__cplusplus" "-permissive-")

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(PokerUI)
endif()
