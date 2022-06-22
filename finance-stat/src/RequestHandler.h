#pragma once

#include "RoutesManager.h"
#include <string>

namespace http
{
namespace server
{

struct Reply;
struct Request;

/// The common handler for all incoming requests.
class RequestHandler
{
  public:
    /// Handle a request and produce a reply.
    virtual void handle_request(const Request& req, Reply& rep) = 0;
};

using RequestHandlerPtr = std::shared_ptr<RequestHandler>;

} // namespace server
} // namespace http

