cmake_minimum_required(VERSION 3.2)
project("simpleheaders" LANGUAGES C CXX)

include(GNUInstallDirs)

file(GLOB_RECURSE project_src CMAKE_CONFIGURE_DEPENDS "src/${PROJECT_NAME}/**")

add_library(${PROJECT_NAME} INTERFACE ${project_src})
target_include_directories(${PROJECT_NAME} INTERFACE "src")

set_target_properties(${PROJECT_NAME} PROPERTIES
PUBLIC_HEADER "${project_src}"
)

install( TARGETS ${PROJECT_NAME}
    PUBLIC_HEADER DESTINATION "include/${PROJECT_NAME}"
)