project(finance-stat)

set(BOOST_ROOT "D://Develop/vcpkg/installed/x86-windows")

find_package(Boost REQUIRED system)

message("boost libs:" ${Boost_LIBRARIES})

add_executable(${PROJECT_NAME} 
	"src/finance_stat.cxx"
	"src/server.hpp"
	"src/server.cpp"
	"src/connection.hpp"
	"src/connection.cpp"
	"src/connection_manager.hpp"
	"src/connection_manager.cpp"
	 "src/request.hpp" 
	 "src/header.hpp" 
	 "src/request_handler.hpp" 
	 "src/request_handler.cpp" 
	 "src/request_parser.cpp" 
	 "src/request_parser.hpp" 
	 "src/reply.hpp" 
	 "src/reply.cpp" 
	 "src/mime_types.hpp" 
	 "src/mime_types.cpp")

target_link_libraries(${PROJECT_NAME} PUBLIC Boost::system)