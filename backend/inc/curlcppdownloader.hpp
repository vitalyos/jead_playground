#ifndef CURLCPPDOWNLOADER_H
#define CURLCPPDOWNLOADER_H

#include "downloader.hpp"

class CurlcppDownloader : public Downloader
{
public:
    CurlcppDownloader();
    std::string download(const std::string &url) override;
};

#endif // CURLCPPDOWNLOADER_H
