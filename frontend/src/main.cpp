#include <glog/logging.h>
#include "user.hpp"

int main(int argc, char *argv[])
{
   google::InitGoogleLogging(argv[0]);
   FLAGS_logtostderr = true;
   User u;
   u.setFirstName("valaki");
   u.setLastName("valami");
   u.setUserName("vmi");
   LOG (INFO) << "Hello application";
   return 0;
}

