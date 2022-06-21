#pragma once

#include "iservice.h"

namespace http {
	namespace server {
		class files_service : public iservice
		{
		public:
			explicit files_service(const std::string& doc_path);

			int getPriority() override;
			std::vector<std::string> getRoutes() override;
			reply run(const request& req) override;

		private:
			std::string doc_root_;
		};
	}
}