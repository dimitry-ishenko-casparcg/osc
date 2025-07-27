cmake_minimum_required(VERSION 3.16) # focal
project(osc++ VERSION 1.3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(HEADERS
    lib/bundle.hpp
    lib/dispatch.hpp
    lib/element.hpp
    lib/elements_0.hpp
    lib/elements.hpp
    lib/errors.hpp
    lib/message.hpp
    lib/packet.hpp
    lib/types.hpp
    lib/value.hpp
    lib/values.hpp
)
set(OVERALL_HEADER lib/osc++.hpp)

set(SOURCES
    lib/bundle.cpp
    lib/dispatch.cpp
    lib/element.cpp
    lib/message.cpp
    lib/packet.cpp
    lib/value.cpp
)

include(GNUInstallDirs)

add_library(shared SHARED ${HEADERS} ${SOURCES})
set_target_properties(shared PROPERTIES
    OUTPUT_NAME ${PROJECT_NAME}
    VERSION     ${PROJECT_VERSION}
    SOVERSION   ${PROJECT_VERSION_MAJOR}
)

add_library(static STATIC ${HEADERS} ${SOURCES})
set_target_properties(static PROPERTIES
    OUTPUT_NAME ${PROJECT_NAME}
)

install(TARGETS shared static DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(FILES ${HEADERS} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME})
install(FILES ${OVERALL_HEADER} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(FILES LICENSE.md README.md DESTINATION ${CMAKE_INSTALL_DOCDIR})
