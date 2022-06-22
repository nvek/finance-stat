#include "routes_manager.h"

namespace http
{
namespace server
{
bool routes_manager::reg_service(const std::shared_ptr<iservice>& serv)
{
    if (!serv)
        return false;

    for (const auto& route : serv->getRoutes())
    {
        services_[route] = serv;
    }

    return true;
}

bool routes_manager::unreg_service(const std::shared_ptr<iservice>& serv)
{
    if (!serv)
        return false;

    for (const auto& route : serv->getRoutes())
    {
        auto service_it = services_.find(route);

        if (service_it == services_.end())
            continue;

        services_.erase(route);
    }

    return true;
}

reply routes_manager::runRoute(const request& req)
{
    std::string request_path;
    if (!url_decode(req.uri, request_path))
    {
        return reply::stock_reply(reply::bad_request);
    }

    auto service_it = services_.find(request_path);

    if (service_it != services_.end())
        return service_it->second->run(req);
    else
        return reply::stock_reply(reply::bad_request);
}

void routes_manager::clear_all_services()
{
    services_.clear();
}

bool routes_manager::url_decode(const std::string& in, std::string& out)
{
    out.clear();
    out.reserve(in.size());
    for (std::size_t i = 0; i < in.size(); ++i)
    {
        if (in[i] == '%')
        {
            if (i + 3 <= in.size())
            {
                int value = 0;
                std::istringstream is(in.substr(i + 1, 2));
                if (is >> std::hex >> value)
                {
                    out += static_cast<char>(value);
                    i += 2;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        else if (in[i] == '+')
        {
            out += ' ';
        }
        else
        {
            out += in[i];
        }
    }
    return true;
}
} // namespace server
} // namespace http
