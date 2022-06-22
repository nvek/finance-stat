#include "files_service.h"

namespace http
{
namespace server
{

files_service::files_service(const std::string& doc_path) : doc_root_(doc_path)
{
}

int files_service::getPriority()
{
    return 0;
}

std::vector<std::string> files_service::getRoutes()
{
    return std::vector<std::string>();
}

reply files_service::run(const request& req)
{
    return reply();
}

} // namespace server
} // namespace http