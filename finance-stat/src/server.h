#pragma once

#include "Connection.h"
#include "ConnectionManager.h"
#include "RequestHandler.h"
#include <boost/asio.hpp>
#include <string>

namespace http
{
namespace server
{

/// The top-level class of the HTTP server.
class server
{
  public:
    server(const server&) = delete;
    server& operator=(const server&) = delete;

    /// Construct the server to listen on the specified TCP address and port, and
    /// serve up files from the given directory.
    explicit server(const std::string& address, const std::string& port, const RequestHandlerPtr& requestHandler);

    /// Run the server's io_service loop.
    void run();

  private:

    void do_accept();
      
    /// Wait for a request to stop the server.
    void do_await_stop();

    /// The io_service used to perform asynchronous operations.
    boost::asio::io_service io_service_;

    /// The signal_set is used to register for process termination notifications.
    boost::asio::signal_set signals_;

    /// Acceptor used to listen for incoming connections.
    boost::asio::ip::tcp::acceptor acceptor_;

    /// The connection manager which owns all live connections.
    ConnectionManager connection_manager_;

    /// The next socket to be accepted.
    boost::asio::ip::tcp::socket socket_;

    /// The handler for all incoming requests.
    RequestHandlerPtr requestHandler_;
};

} // namespace server
} // namespace http