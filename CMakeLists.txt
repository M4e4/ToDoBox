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
    Resources.qrc

    src/main.cpp

    src/view/taskListView.h                     src/view/taskListView.cpp
    src/view/backgroundWidgetView.h             src/view/backgroundWidgetView.cpp
    src/view/titleWidgetView.h                  src/view/titleWidgetView.cpp
    src/view/contentWidgetView.h                src/view/contentWidgetView.cpp

    src/model/taskListModel.h                   src/model/taskListModel.cpp
    src/model/task.h                            src/model/task.cpp

    src/controller/taskListController.h         src/controller/taskListController.cpp
    src/controller/backgroundWidgetController.h src/controller/backgroundWidgetController.cpp
    src/controller/titleWidgetController.h      src/controller/titleWidgetController.cpp
    src/controller/contentWidgetController.h    src/controller/contentWidgetController.cpp

    src/backgroundWidget.h                      src/backgroundWidget.cpp
    src/titleWidget.h                           src/titleWidget.cpp
    src/taskList.h                              src/taskList.cpp
    src/contentWidget.h                         src/contentWidget.cpp
    src/editingwidget.h                         src/editingwidget.cpp
    src/approvedwidget.h                        src/approvedwidget.cpp
    src/mainWidget.h                            src/mainWidget.cpp

    src/utils/utils.h
    src/model/contentWidgetModel.h src/model/contentWidgetModel.cpp
    src/model/taskListProxyModel.h src/model/taskListProxyModel.cpp
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
add_subdirectory(Test)
