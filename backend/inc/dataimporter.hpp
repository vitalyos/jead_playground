#ifndef DATAIMPORTER
#define DATAIMPORTER

#include <vector>
#include "user.hpp"

class DataImporter
{
public:
    DataImporter() = default;
    virtual std::vector <User> getAllUsers () = 0;
};

#endif // DATAIMPORTER

