#include "FilesService.h"

namespace http
{
namespace server
{

FilesService::FilesService(const std::string& doc_path) : doc_root_(doc_path)
{
}

int FilesService::get_priority()
{
    return 0;
}

std::vector<std::string> FilesService::get_routes() const
{
    return {};
}

Reply FilesService::run(const Request& req)
{
    return {};
}

} // namespace server
} // namespace http
