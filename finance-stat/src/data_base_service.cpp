#include "data_base_service.h"
#include <pqxx/pqxx>

namespace http {
	namespace server {
		data_base_service::data_base_service()
			:routes_()
		{
			routes_.push_back("/costs");
		}
		int data_base_service::getPriority()
		{
			return 0;
		}
		std::vector<std::string> data_base_service::getRoutes()
		{
			return routes_;
		}
		reply data_base_service::run(const request& req)
		{
			reply rep;
			rep.status = reply::ok;

            try 
            {
                pqxx::connection conn("dbname = testdb user = postgres password = 123 \
                                        hostaddr = 127.0.0.1 port = 5432");
                if (conn.is_open()) {
                    std::cout << "Opened database successfully: " << conn.dbname() << std::endl;

                    pqxx::work txn(conn);
                    //SELECT * FROM pg_catalog.pg_tables
                    pqxx::result r{ txn.exec("select * FROM public.\"CostCategory\"") };

                    std::string result;

                    for (const auto& row : r)
                    {
                        for (auto elm : row)
                        {
                            result.append(elm.c_str());
                            result.append(" ");
                        }
                        //result.append("<<");
                        //result.append("<<");
                        //result.append(row["id"].c_str());
                        //result.append(" -- ");
                        //result.append(row["name"].c_str());
                        //result.append(">>");
                    }
                    rep.content = result;

                }
                else {
                    std::cout << "Can't open database" << std::endl;
                    return;
                }

                conn.close();
            }
            catch (const std::exception& e) {
                std::cerr << e.what() << std::endl;
                return;
            }

			return rep;
		}
	}
}