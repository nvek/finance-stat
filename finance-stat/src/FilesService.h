#pragma once

#include "IService.h"

namespace http
{
namespace server
{
class FilesService : public IService
{
  public:
    explicit FilesService(const std::string& doc_path);

    int get_priority() override;
    std::vector<std::string> get_routes() const override;
    Reply run(const Request& req) override;

  private:
    std::string doc_root_;
};
} // namespace server
} // namespace http
