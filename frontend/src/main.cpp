#include <glog/logging.h>

#include "downloader.hpp"
#include "curlcppdownloader.hpp"
#include "dataimporter.hpp"
#include "jsondataimporter.hpp"
#include "user.hpp"

int main(int argc, const char **argv) {
    google::InitGoogleLogging(argv[0]);
    FLAGS_logtostderr = true;

    Downloader *d = new CurlcppDownloader;
    DataImporter *di = new JsonDataImporter(d);

    auto users = di->getAllUsers();
    for (auto & user : users)
    {
        LOG (INFO) << user;
    }
    delete di;
    delete d;
    return 0;
}
