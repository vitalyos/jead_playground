#ifndef DEPENDENCYPROVIDER_H
#define DEPENDENCYPROVIDER_H

#include<fruit/fruit.h>

#include"downloader.hpp"
#include"curlcppdownloader.hpp"

#include"dataimporter.hpp"
#include"jsondataimporter.hpp"

#include"userfondler.hpp"
#include"hungarianuserfondler.hpp"

class DependencyProvider
{
public:
    static fruit::Component<Downloader> getDownloaderComponent ();
    static fruit::Component<fruit::Required<Downloader>, DataImporter> getDataImporterComponent();
    static fruit::Component<DataImporter> getImporter ();
    static fruit::Component<UserFondler> getFondlerComponent ();
};

#endif // DEPENDENCYPROVIDER_H
