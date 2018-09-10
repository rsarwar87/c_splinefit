cmake_minimum_required(VERSION 3.0.0)
project(sfit VERSION 0.1.0)

include_directories(.)
link_directories(gsl)
add_definitions(-g )

add_executable(sfit main.c interp.c spline.c accel.c  cspline.c tridiag.c  )
target_link_libraries(sfit m libgsl.a)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
