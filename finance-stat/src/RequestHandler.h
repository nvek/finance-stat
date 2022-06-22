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

#include "RoutesManager.h"
#include <string>

namespace http
{
namespace server
{

struct reply;
struct request;

/// The common handler for all incoming requests.
class RequestHandler
{
  public:
    
    /// Handle a request and produce a reply.
    virtual void handle_request(const request& req, reply& rep) = 0;
};

using RequestHandlerPtr = std::shared_ptr<RequestHandler>;

} // namespace server
} // namespace http

#endif // HTTP_REQUEST_HANDLER_HPP
