project(finance-stat)

find_package(Boost REQUIRED system)

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
	"src/mime_types.cpp"
	"src/CostsHandler.h"
	"src/CostsHandler.cpp")

target_link_libraries(${PROJECT_NAME} PUBLIC Boost::system)