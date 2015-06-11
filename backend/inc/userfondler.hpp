#ifndef USERFONDLER
#define USERFONDLER

#include "user.hpp"

class UserFondler
{
public:
    virtual ~UserFondler () = default;
    virtual User fondle (const User & other) = 0;
};

#endif // USERFONDLER

