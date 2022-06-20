project(finance-stat)

find_package(Boost REQUIRED COMPONENTS system)

file(GLOB SOURCES src/*.cpp src/*.hpp)
add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE Boost::system)
