#include "dependencyprovider.hpp"

fruit::Component<Downloader> DependencyProvider::getDownloaderComponent()
{
    return fruit::createComponent()
            .bind<Downloader, CurlcppDownloader>();
}

fruit::Component<fruit::Required<Downloader>, DataImporter> DependencyProvider::getDataImporterComponent()
{
    return fruit::createComponent()
            .bind<DataImporter, JsonDataImporter>();
}

fruit::Component<DataImporter> DependencyProvider::getImporter()
{
    return fruit::createComponent()
            .install(DependencyProvider::getDownloaderComponent())
            .install(DependencyProvider::getDataImporterComponent());
}

fruit::Component<UserFondler> DependencyProvider::getFondlerComponent()
{
    return fruit::createComponent()
            .bind<UserFondler, HungarianUserFondler>();
}
