#pragma once

#include "Connection.h"
#include <set>

namespace http
{
namespace server
{

/// Manages open connections so that they may be cleanly stopped when the server
/// needs to shut down.
class ConnectionManager
{
  public:
    ConnectionManager(const ConnectionManager&) = delete;
    ConnectionManager& operator=(const ConnectionManager&) = delete;

    /// Construct a connection manager.
    ConnectionManager();

    /// Add the specified connection to the manager and start it.
    void start(ConnectionPtr c);

    /// Stop the specified connection.
    void stop(ConnectionPtr c);

    /// Stop all connections.
    void stop_all();

  private:
    /// The managed connections.
    std::set<ConnectionPtr> connections_;
};

} // namespace server
} // namespace http
