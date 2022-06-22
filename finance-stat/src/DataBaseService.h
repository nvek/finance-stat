#pragma once

#include "IService.h"

namespace http
{
namespace server
{

class DataBaseService : public IService
{
  public:
    DataBaseService();

    int get_priority() override;
    std::vector<std::string> get_routes() const override;
    Reply run(const Request& req) override;

  private:
    std::vector<std::string> routes_;
};

} // namespace server
} // namespace http