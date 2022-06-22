#include "RegistrationService.h"

namespace http
{
namespace server
{
int RegistrationService::get_priority()
{
    return 0;
}

std::vector<std::string> RegistrationService::get_routes() const
{
    return {};
}

Reply RegistrationService::run(const Request& req)
{
    return {};
}
} // namespace server
} // namespace http
