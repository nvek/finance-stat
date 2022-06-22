#pragma once

#include "reply.h"
#include "request.h"

namespace http
{
namespace server
{

class iservice
{
  public:
    virtual int getPriority() = 0;
    virtual std::vector<std::string> getRoutes() = 0;
    virtual reply run(const request& req) = 0;
};

} // namespace server
} // namespace http