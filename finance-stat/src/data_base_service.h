#pragma once

#include "iservice.h"

namespace http {
	namespace server {
		class data_base_service : public iservice
		{
		public:
			data_base_service();

			int getPriority() override;
			std::vector<std::string> getRoutes() override;
			reply run(const request& req) override;

		private:
			std::vector<std::string> routes_;
		};
	}
}