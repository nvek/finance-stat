#pragma once

#include "Reply.h"
#include "Request.h"
#include "RequestHandler.h"
#include "RequestParser.h"
#include <boost/asio.hpp>
#include <array>
#include <memory>

namespace http
{
namespace server
{

class ConnectionManager;

/// Represents a single connection from a client.
class Connection : public std::enable_shared_from_this<Connection>
{
  public:
    Connection(const Connection&) = delete;
    Connection& operator=(const Connection&) = delete;

    /// Construct a connection with the given socket.
    explicit Connection(boost::asio::ip::tcp::socket socket, ConnectionManager& manager,
                        const RequestHandlerPtr& handler);

    /// Start the first asynchronous operation for the connection.
    void start();

    /// Stop all asynchronous operations associated with the connection.
    void stop();

  private:
    /// Perform an asynchronous read operation.
    void do_read();

    /// Perform an asynchronous write operation.
    void do_write();

    /// Socket for the connection.
    boost::asio::ip::tcp::socket socket_;

    /// The manager for this connection.
    ConnectionManager& connection_manager_;

    /// The handler used to process the incoming request.
    const RequestHandlerPtr request_handler_;

    /// Buffer for incoming data.
    std::array<char, 8192> buffer_;

    /// The incoming request.
    Request request_;

    /// The parser for the incoming request.
    RequestParser request_parser_;

    /// The reply to be sent back to the client.
    Reply reply_;
};

using ConnectionPtr = std::shared_ptr<Connection>;

} // namespace server
} // namespace http
