#include "iservice.h"
#include "reply.h"
#include "request.h"
#include <unordered_map>
#include <unordered_set>

namespace http
{
namespace server
{

class routes_manager
{
  public:
    bool reg_service(const std::shared_ptr<iservice>& serv);
    bool unreg_service(const std::shared_ptr<iservice>& serv);
    reply runRoute(const request& req);
    void clear_all_services();

  private:
    std::unordered_map<std::string, std::shared_ptr<iservice>> services_;

    bool url_decode(const std::string& in, std::string& out);
};

} // namespace server
} // namespace http