project(finance-stat)

find_package(Boost REQUIRED COMPONENTS system)

file(GLOB SOURCES src/*.cpp src/*.hpp)
add_executable(${PROJECT_NAME} ${SOURCES} "src/routes_manager.h" "src/iservice.h" "src/routes_manager.cpp" "src/registration_service.h" "src/registration_service.cpp" "src/files_service.h" "src/files_service.cpp" "src/data_base_service.h" "src/data_base_service.cpp")

target_link_libraries(${PROJECT_NAME} PRIVATE Boost::system)
