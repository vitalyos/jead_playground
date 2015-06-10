#ifndef USER_H
#define USER_H

#include <string>
#include <hiberlite.h>

class User
{
    friend class hiberlite::access;
    template <class Archive>
    void hibernate (Archive & ar)
    {
        ar & HIBERLITE_NVP (m_userName);
        ar & HIBERLITE_NVP (m_firstName);
        ar & HIBERLITE_NVP (m_lastName);
        ar & HIBERLITE_NVP (m_age);
    }

public:
    User();
    std::string userName() const;
    void setUserName(const std::string &userName);

    std::string firstName() const;
    void setFirstName(const std::string &firstName);

    std::string lastName() const;
    void setLastName(const std::string &lastName);

private:
    std::string m_userName;
    std::string m_firstName;
    std::string m_lastName;
    unsigned int m_age;
};

HIBERLITE_EXPORT_CLASS (User)

#endif // USER_H
