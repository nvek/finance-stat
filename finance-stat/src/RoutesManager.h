#pragma once

#include "IService.h"
#include "Reply.h"
#include "Request.h"
#include <unordered_map>
#include <unordered_set>

namespace http
{
namespace server
{

class RoutesManager
{
  public:
    bool reg_service(const std::shared_ptr<IService>& serv);
    bool unreg_service(const std::shared_ptr<IService>& serv);
    Reply run_route(const Request& req);
    void clear_all_services();

  private:
    std::unordered_map<std::string, std::shared_ptr<IService>> services_;

    bool url_decode(const std::string& in, std::string& out);
};

} // namespace server
} // namespace http
