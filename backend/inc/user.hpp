#ifndef USER_H
#define USER_H

#include <string>
#include <ostream>

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

    long id() const;
    void setId(long id);

    friend std::ostream & operator << (std::ostream & os, const User & u);

private:
    std::string m_userName;
    std::string m_firstName;
    std::string m_lastName;
    long m_id;
};

#endif // USER_H
