#ifndef CURLCPPDOWNLOADER_H
#define CURLCPPDOWNLOADER_H

#include "downloader.hpp"
#include <fruit/fruit.h>

class CurlcppDownloader : public Downloader
{
public:
    CurlcppDownloader();
    ~CurlcppDownloader() = default;
    std::string download(const std::string &url) override;

    using Inject = CurlcppDownloader ();
};

#endif // CURLCPPDOWNLOADER_H
