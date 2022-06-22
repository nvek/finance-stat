#include "DataBaseService.h"
#include <pqxx/pqxx>
#include <iostream>

namespace http
{
namespace server
{

DataBaseService::DataBaseService() : routes_()
{
    routes_.push_back("/costs");
}
int DataBaseService::get_priority()
{
    return 0;
}
std::vector<std::string> DataBaseService::get_routes() const
{
    return routes_;
}

Reply DataBaseService::run(const Request& req)
{
    Reply rep;
    rep.status = Reply::ok;

    try
    {
        pqxx::connection conn("dbname = testdb user = postgres password = 123 \
                                        hostaddr = 127.0.0.1 port = 5432");
        if (conn.is_open())
        {
            std::cout << "Opened database successfully: " << conn.dbname() << std::endl;

            pqxx::work txn(conn);
            // SELECT * FROM pg_catalog.pg_tables
            pqxx::result r{txn.exec("select * FROM public.\"CostCategory\"")};

            std::string result;

            for (const auto& row : r)
            {
                for (auto elm : row)
                {
                    result.append(elm.c_str());
                    result.append(" ");
                }
                // result.append("<<");
                // result.append("<<");
                // result.append(row["id"].c_str());
                // result.append(" -- ");
                // result.append(row["name"].c_str());
                // result.append(">>");
            }
            rep.content = result;
        }
        else
        {
            std::cout << "Can't open database" << std::endl;
            Reply rep;
            rep.status = Reply::bad_request;
            return rep;
        }

        conn.close();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        Reply rep;
        rep.status = Reply::bad_request;
        return rep;
    }

    return rep;
}
} // namespace server
} // namespace http
