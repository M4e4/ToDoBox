cmake_minimum_required(VERSION 3.16)

project(ToDoBox LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

add_executable(ToDoBox
  main.cpp
  mainwidget.h mainwidget.cpp
  approvedwidget.h approvedwidget.cpp
  editingwidget.h editingwidget.cpp
  listitem.h listitem.cpp
  Resources.qrc
  topwidget.h topwidget.cpp
  framewidget.h framewidget.cpp




)

if (WIN32)
  target_sources(ToDoBox PRIVATE appicon.rc)
  set_target_properties(ToDoBox PROPERTIES WIN32_EXECUTABLE TRUE)
endif()

target_link_libraries(ToDoBox Qt${QT_VERSION_MAJOR}::Widgets)

include(GNUInstallDirs)
install(TARGETS ToDoBox
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
