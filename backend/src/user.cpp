#include "user.hpp"

User::User()
{

}


std::string User::userName() const
{
    return m_userName;
}

void User::setUserName(const std::string &userName)
{
    m_userName = userName;
}

std::string User::firstName() const
{
    return m_firstName;
}

void User::setFirstName(const std::string &firstName)
{
    m_firstName = firstName;
}

std::string User::lastName() const
{
    return m_lastName;
}

void User::setLastName(const std::string &lastName)
{
    m_lastName = lastName;
}
long User::id() const
{
    return m_id;
}

void User::setId(long id)
{
    m_id = id;
}

std::ostream& operator << (std::ostream & os, const User & user)
{
    os << user.id () << " | "
       << user.firstName ()<< " | "
       << user.lastName () << " | "
       << user.userName ();
    return os;
}
