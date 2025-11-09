cmake_minimum_required(VERSION 3.16)

project(CalcDemo LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

if(MSVC)
    # 静态运行时库
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded")
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()


set(ANTLR_BUILD_CPP_TESTS OFF)
set(ANTLR_BUILD_SHARED OFF)
add_subdirectory(3rd/antlr4/runtime/Cpp/)


add_executable(CalcDemo
  main.cpp
  anltr/CalcBaseListener.cpp anltr/CalcBaseListener.h anltr/CalcBaseVisitor.cpp anltr/CalcBaseVisitor.h anltr/CalcLexer.cpp anltr/CalcLexer.h anltr/CalcListener.cpp anltr/CalcListener.h anltr/CalcParser.cpp anltr/CalcParser.h anltr/CalcVisitor.cpp anltr/CalcVisitor.h
  EvalVisitor.h
  SemanticVisitor.h
  CodeGenVisitor.h
  TestObject.h TestObject.cpp
)
target_link_libraries(CalcDemo
    PRIVATE
    antlr4_static
    Qt${QT_VERSION_MAJOR}::Widgets
)

include(GNUInstallDirs)
install(TARGETS CalcDemo
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
