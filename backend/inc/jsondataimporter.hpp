#ifndef JSONDATAIMPORTER_H
#define JSONDATAIMPORTER_H

#include <fruit/fruit.h>
#include "dataimporter.hpp"

class Downloader;

class JsonDataImporter : public DataImporter
{
public:
    JsonDataImporter(Downloader * downloader);
    ~JsonDataImporter() = default;
    std::vector<User> getAllUsers() override;

    // Dependency injection
    using Inject = JsonDataImporter (Downloader*);
private:
    Downloader *m_downloader;
};

#endif // JSONDATAIMPORTER_H
