#include "ServerRequestHandler.h"
#include "FilesService.h"
#include "MimeTypes.h"
#include "RegistrationService.h"
#include "Reply.h"
#include "Request.h"
#include <fstream>
#include <sstream>
#include <string>

namespace http
{
namespace server
{

ServerRequestHandler::ServerRequestHandler(const std::string& doc_root) : routes_mgr_()
{
    routes_mgr_.reg_service(std::make_shared<RegistrationService>());
    routes_mgr_.reg_service(std::make_shared<FilesService>(doc_root));
}

ServerRequestHandler::~ServerRequestHandler()
{
    routes_mgr_.clear_all_services();
}

void ServerRequestHandler::handle_request(const Request& req, Reply& rep)
{
    rep = routes_mgr_.run_route(req);
    /*
    // Decode url to path.
    std::string request_path;
    if (!url_decode(req.uri, request_path))
    {
        rep = reply::stock_reply(reply::bad_request);
        return;
    }

    if (request_path == "/costs")
    {
        return CostsHandler::run(rep);
    }

    // Request path must be absolute and not contain "..".
    if (request_path.empty() || request_path[0] != '/'
        || request_path.find("..") != std::string::npos)
    {
        rep = reply::stock_reply(reply::bad_request);
        return;
    }

    // If path ends in slash (i.e. is a directory) then add "index.html".
    if (request_path[request_path.size() - 1] == '/')
    {
        request_path += "index.html";
    }

    // Determine the file extension.
    std::size_t last_slash_pos = request_path.find_last_of("/");
    std::size_t last_dot_pos = request_path.find_last_of(".");
    std::string extension;
    if (last_dot_pos != std::string::npos && last_dot_pos > last_slash_pos)
    {
        extension = request_path.substr(last_dot_pos + 1);
    }

    // Open the file to send back.
    std::string full_path = doc_root_ + request_path;
    std::ifstream is(full_path.c_str(), std::ios::in | std::ios::binary);
    if (!is)
    {
        rep = reply::stock_reply(reply::not_found);
        return;
    }

    // Fill out the reply to be sent to the client.
    rep.status = reply::ok;
    char buf[512];
    while (is.read(buf, sizeof(buf)).gcount() > 0)
        rep.content.append(buf, is.gcount());
    rep.headers.resize(2);
    rep.headers[0].name = "Content-Length";
    rep.headers[0].value = std::to_string(rep.content.size());
    rep.headers[1].name = "Content-Type";
    rep.headers[1].value = mime_types::extension_to_type(extension);
    */
}

} // namespace server
} // namespace http
