#pragma once

#include "Reply.h"
#include "Request.h"

namespace http
{
namespace server
{

class IService
{
  public:
    virtual int get_priority() = 0;
    virtual std::vector<std::string> get_routes() const = 0;
    virtual Reply run(const Request& req) = 0;
};

} // namespace server
} // namespace http
