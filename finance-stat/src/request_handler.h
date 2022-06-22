//
// request_handler.hpp
// ~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2016 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef HTTP_REQUEST_HANDLER_HPP
#define HTTP_REQUEST_HANDLER_HPP

#include "routes_manager.h"
#include <string>

namespace http
{
namespace server
{

struct reply;
struct request;

/// The common handler for all incoming requests.
class request_handler
{
  public:
    request_handler(const request_handler&) = delete;
    request_handler& operator=(const request_handler&) = delete;

    /// Construct with a directory containing files to be served.
    explicit request_handler(const std::string& doc_root);
    ~request_handler();

    /// Handle a request and produce a reply.
    void handle_request(const request& req, reply& rep);

  private:
    routes_manager routes_mgr_;
    /// The directory containing the files to be served.
    std::string doc_root_;
};

} // namespace server
} // namespace http

#endif // HTTP_REQUEST_HANDLER_HPP