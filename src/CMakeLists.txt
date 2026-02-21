set(SOURCES
    circle.cpp
    ellipse.cpp
    helix.cpp
)

add_library(curves_lib ${SOURCES})
target_include_directories(curves_lib PUBLIC ${CMAKE_SOURCE_DIR}/include)