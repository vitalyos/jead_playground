#include <glog/logging.h>

#include "downloader.hpp"
#include "curlcppdownloader.hpp"
#include "dataimporter.hpp"
#include "jsondataimporter.hpp"
#include "user.hpp"
#include "dependencyprovider.hpp"
#include  "userfondler.hpp"

int main(int /*argc*/, const char **argv) {
    google::InitGoogleLogging(argv[0]);
    FLAGS_logtostderr = true;

    fruit::Injector<DataImporter> dataInjector(DependencyProvider::getImporter());
    DataImporter * di (dataInjector);

    fruit::Injector<UserFondler> fondlerInjector(DependencyProvider::getFondlerComponent());
    UserFondler * f (fondlerInjector);

    auto users = di->getAllUsers();
    for (auto & user : users)
    {
        LOG (INFO) << user;
        LOG (WARNING) << f->fondle(user);
    }

    return 0;
}
