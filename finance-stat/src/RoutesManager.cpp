#include "RoutesManager.h"

namespace http
{
namespace server
{
bool RoutesManager::reg_service(const std::shared_ptr<IService>& serv)
{
    if (!serv)
        return false;

    for (const auto& route : serv->get_routes())
    {
        services_[route] = serv;
    }

    return true;
}

bool RoutesManager::unreg_service(const std::shared_ptr<IService>& serv)
{
    if (!serv)
    {
        return false;
    }

    for (const auto& route : serv->get_routes())
    {
        auto service_it = services_.find(route);

        if (service_it == services_.end())
            continue;

        services_.erase(route);
    }

    return true;
}

Reply RoutesManager::run_route(const Request& req)
{
    std::string request_path;
    if (!url_decode(req.uri, request_path))
    {
        return Reply::stock_reply(Reply::bad_request);
    }

    auto service_it = services_.find(request_path);

    if (service_it != services_.end())
        return service_it->second->run(req);
    else
        return Reply::stock_reply(Reply::bad_request);
}

void RoutesManager::clear_all_services()
{
    services_.clear();
}

bool RoutesManager::url_decode(const std::string& in, std::string& out)
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
