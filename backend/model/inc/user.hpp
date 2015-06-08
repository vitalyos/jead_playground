#ifndef USER_H
#define USER_H

#include <string>

class User
{
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
};

#endif // USER_H
