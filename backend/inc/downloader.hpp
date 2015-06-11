#ifndef DOWNLOADER
#define DOWNLOADER

#include <string>

class Downloader
{
public:
  Downloader() = default;
  virtual ~Downloader () = default;
  virtual std::string download (const std::string &url) = 0;
};

#endif // DOWNLOADER

