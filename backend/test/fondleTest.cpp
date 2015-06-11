#include <cppunit/extensions/HelperMacros.h>
#include <fruit/fruit.h>
#include "user.hpp"
#include "userfondler.hpp"
#include "dependencyprovider.hpp"

class FondleTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE( FondleTest );
  CPPUNIT_TEST(testFunctionality);
  CPPUNIT_TEST(testUnbrokenLastName);
  CPPUNIT_TEST(testUnbrokenUserName);
  CPPUNIT_TEST(testUnbrokenId);
  CPPUNIT_TEST(testChangedLength);
  CPPUNIT_TEST(testEmpty);
  CPPUNIT_TEST_SUITE_END();
public:
  void setUp() override
  {
      fruit::Injector<UserFondler> fondlerInjector(DependencyProvider::getFondlerComponent());
      UserFondler *f(fondlerInjector);
      fondler = f;

      user = new User;

      user->setFirstName("Zsolt");
      user->setLastName("Vitalyos");
      user->setUserName("viti");
      user->setId(1992);
  }

  void tearDown () override
  {
      delete user;
      user = nullptr;
  }

  void testFunctionality ()
  {
      User fondled = fondler->fondle(*user);
      CPPUNIT_ASSERT_EQUAL (fondled.firstName(), std::string("Zsoltike"));
  }

  void testUnbrokenLastName ()
  {
      User fondled = fondler->fondle(*user);
      CPPUNIT_ASSERT_EQUAL (fondled.lastName(), user->lastName());
  }

  void testUnbrokenUserName ()
  {
      User fondled = fondler->fondle(*user);
      CPPUNIT_ASSERT_EQUAL (fondled.userName(), user->userName());
  }

  void testUnbrokenId ()
  {
      User fondled = fondler->fondle(*user);
      CPPUNIT_ASSERT_EQUAL (fondled.id(), user->id());
  }

  void testChangedLength ()
  {
      User fondled = fondler->fondle(*user);
      CPPUNIT_ASSERT_EQUAL (fondled.firstName().length(), user->firstName().length() + 2);
  }

  void testEmpty ()
  {
      CPPUNIT_ASSERT (true);
  }

private:
  UserFondler * fondler;
  User * user;
};
CPPUNIT_TEST_SUITE_REGISTRATION( FondleTest );
