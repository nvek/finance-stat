#include "registration_service.h"

namespace http {
	namespace server {
		int registration_service::getPriority()
		{
			return 0;
		}

		std::vector<std::string> registration_service::getRoutes()
		{
			return std::vector<std::string>();
		}

		reply registration_service::run(const request& req)
		{
			return reply();
		}
	}
}