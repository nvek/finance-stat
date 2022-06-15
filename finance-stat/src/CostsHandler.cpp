#include "CostsHandler.h"

void http::server::CostsHandler::run(reply& rep)
{
    rep.status = reply::ok;

    rep.content = "[{\"id\":1,\"amount\":10000,\"categoryId\":12,\"date\":\"2021-01-30T08:30:00Z\"},{\"id\":2,\"amount\":20000,\"categoryId\":12,\"date\":\"2021-01-31T08:30:00Z\"},{\"id\":3,\"amount\":1000,\"categoryId\":12,\"date\":\"2021-02-01T08:30:00Z\"},{\"id\":4,\"amount\":100000,\"categoryId\":12,\"date\":\"2021-02-02T08:30:00Z\"}]";

    //rep.content = "[{ \
    //        \"id\": 1, \
    //        \"amount\" : 10000, \
    //        \"categoryId\" : 12, \
    //        \"date\" : \"2021-01-30T08:30:00Z\" \
    //                }]";

    rep.headers.resize(1);
    rep.headers[0].name = "Content-Type";
    rep.headers[0].value = "application/json";
}
