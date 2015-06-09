#ifndef BASEREPOSITORYIMPL_H
#define BASEREPOSITORYIMPL_H

#include "baserepository.hpp"
#include <odb/database.hxx>

template <typename T, typename I>
class BaseRepositoryImpl : public BaseRepository<T, I>
{
public:
    BaseRepositoryImpl ()
    {

    }

    ~BaseRepositoryImpl()
    {

    }

    std::vector<T>& getAll ()
    {

    }

    T& getById (const I &id)
    {

    }

    void insert (const T &element)
    {

    }

    void update (const T &element)
    {

    }

    void remove (const T &element)
    {

    }

private:

};

#endif // BASEREPOSITORYIMPL_H
