#include <glog/logging.h>
#include <sstream>
#include "curl_easy.h"
#include "curl_form.h"
#include "curl_pair.h"
#include "curl_receiver.h"
#include "curl_sender.h"

#include <json/value.h>

using curl::curl_form;
using curl::curl_easy;
using curl::curl_sender;
using curl::curl_receiver;

int main(int argc, const char **argv) {
       google::InitGoogleLogging(argv[0]);
       FLAGS_logtostderr = true;
       std::stringstream stream;
       curl_writer writer(stream);
    curl_easy easy(writer);
    easy.add(curl_pair<CURLoption,string>(CURLOPT_URL,"http://localhost:8080/bibliospring-api/rest/user/") );
    easy.add(curl_pair<CURLoption,long>(CURLOPT_FOLLOWLOCATION,1L));

    try {
        easy.perform();
    } catch (curl_easy_exception error) {
        // If you want to get the entire error stack we can do:
        vector<pair<string,string>> errors = error.get_traceback();
        // Otherwise we could print the stack like this:
        error.print_traceback();
        // Note that the printing the stack will erase it
    }
    LOG (INFO) << stream.str();
    return 0;
}
