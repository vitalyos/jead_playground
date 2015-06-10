#include <glog/logging.h>

int main(int argc, char *argv[])
{
   google::InitGoogleLogging(argv[0]);
   FLAGS_logtostderr = true;
   LOG (INFO) << "Hello application";
   return 0;
}

