#ifndef JSONDATAIMPORTER_H
#define JSONDATAIMPORTER_H

#include "dataimporter.hpp"

class Downloader;

class JsonDataImporter : public DataImporter
{
public:
    JsonDataImporter(Downloader * downloader);
    std::vector<User> getAllUsers() override;
private:
    Downloader *m_downloader;
};

#endif // JSONDATAIMPORTER_H
