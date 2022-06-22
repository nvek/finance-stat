#include "iservice.h"

namespace http
{
namespace server
{
class registration_service : public iservice
{
  public:
    int getPriority() override;
    std::vector<std::string> getRoutes() override;
    reply run(const request& req) override;

  private:
    std::string doc_root_;
};
} // namespace server
} // namespace http