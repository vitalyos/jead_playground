#ifndef BASEREPOSITORY
#define BASEREPOSITORY

#include <vector>

template <typename T, typename I>
class BaseRepository
{
public:
   virtual std::vector<T>& getAll () = 0;
   virtual T& getById (const I &id) = 0;
   virtual void insert (const T &element) = 0;
   virtual void update (const T &element) = 0;
   virtual void remove (const T &element) = 0;
   virtual ~BaseRepository() {}
};

#endif // BASEREPOSITORY

