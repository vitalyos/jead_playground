#include <glog/logging.h>
#include <sstream>

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
        std::stringstream stream;
        stream << user.id () << " | "
               << user.firstName ()<< " | "
               << user.lastName () << " | "
               << user.userName ();
        LOG (INFO) << stream.str();
    }
    delete di;
    delete d;
    return 0;
}
