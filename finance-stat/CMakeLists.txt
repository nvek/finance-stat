project(finance-stat)

find_package(Boost REQUIRED COMPONENTS system)
find_package(libpqxx CONFIG REQUIRED)

file(GLOB SOURCES src/*.cpp src/*.h)
add_executable(${PROJECT_NAME} ${SOURCES}  "src/ServerRequestHandler.h")

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)

target_link_libraries(${PROJECT_NAME} PRIVATE Boost::system libpqxx::pqxx)
