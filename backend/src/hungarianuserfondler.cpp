#include "hungarianuserfondler.hpp"

User HungarianUserFondler::fondle(const User &other)
{
    User u(other);
    u.setFirstName(other.firstName().append("ke"));
    return u;
}
