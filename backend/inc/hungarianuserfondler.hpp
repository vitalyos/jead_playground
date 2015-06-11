#ifndef HUNGARIANUSERFONDLER_H
#define HUNGARIANUSERFONDLER_H

#include <fruit/fruit.h>

#include "userfondler.hpp"

class HungarianUserFondler : public UserFondler
{
public:
    HungarianUserFondler() = default;
    ~HungarianUserFondler () = default;
    User fondle(const User &other) override;

    using Inject = HungarianUserFondler ();
};

#endif // HUNGARIANUSERFONDLER_H
