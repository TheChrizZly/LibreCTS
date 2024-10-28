cmake_minimum_required(VERSION 3.28)
project(OpenCTViz)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -march=native")
# 1. Specify the include directory
include_directories(${PROJECT_SOURCE_DIR}/lib/libtorch/include)

# 2. Specify the library directory
link_directories(${PROJECT_SOURCE_DIR}/lib/libtorch/lib)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")

find_package(Torch REQUIRED)
find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)
add_executable(OpenCTViz main.cpp
        src/ui/ui_mainwindow.h
        src/CTImage.cpp
        src/CTImage.h
        src/ErrorHandler.cpp
        src/ErrorHandler.h
        src/ui/mainwindow.cpp
        src/ui/mainwindow.h
        src/ui/ctimageviewer.cpp
        src/ui/ctimageviewer.h
)
target_link_libraries(OpenCTViz
        Qt::Core
        Qt::Gui
        Qt::Widgets
        "${TORCH_LIBRARIES}"
)
