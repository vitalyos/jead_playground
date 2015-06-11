#include "jsondataimporter.hpp"
#include "downloader.hpp"

#include <json/value.h>
#include <json/reader.h>
#include <sstream>
#include <string>
#include <glog/logging.h>

JsonDataImporter::JsonDataImporter(Downloader *downloader)
    : m_downloader (downloader)
{

}

std::vector<User> JsonDataImporter::getAllUsers()
{
    std::string downloaded = m_downloader->download("http://localhost:8080/bibliospring-api/rest/user");
    std::stringstream stream;
    stream << "{\"array\":" << downloaded << "}";
    Json::Reader reader;
    Json::Value root;
    reader.parse(stream.str(), root);
    std::vector<User> users;
    for (auto & user : root["array"])
    {
        User u;
        u.setFirstName(user["firstName"].asString ());
        u.setLastName(user["lastName"].asString ());
        u.setUserName(user["userName"].asString ());
        u.setId(user["id"].asInt ());
        users.push_back(u);
    }
    return users;
}
