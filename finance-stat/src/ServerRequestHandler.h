#pragma once

#include "RequestHandler.h"
#include "RoutesManager.h"

#include <string>

namespace http
{
namespace server
{

struct Reply;
struct Request;

/// The common handler for all incoming requests.
class ServerRequestHandler : public RequestHandler
{
  public:
    ServerRequestHandler(const ServerRequestHandler&) = delete;
    ServerRequestHandler& operator=(const ServerRequestHandler&) = delete;

    /// Construct with a directory containing files to be served.
    explicit ServerRequestHandler(const std::string& doc_root);
    ~ServerRequestHandler();

    /// Handle a request and produce a reply.
    void handle_request(const Request& req, Reply& rep) override;

  private:
    RoutesManager routes_mgr_;
    /// The directory containing the files to be served.
    std::string doc_root_;
};

} // namespace server
} // namespace http
