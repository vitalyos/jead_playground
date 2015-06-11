#include "curlcppdownloader.hpp"
#include "curl_easy.h"
#include "curl_form.h"
#include "curl_pair.h"
#include "curl_receiver.h"
#include "curl_sender.h"

#include <sstream>

CurlcppDownloader::CurlcppDownloader()
{

}

std::string CurlcppDownloader::download(const std::string &url)
{
    std::stringstream stream;
    curl::curl_writer writer(stream);
    curl::curl_easy easy(writer);
    easy.add(curl_pair<CURLoption,string>(CURLOPT_URL, url) );
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
    return stream.str ();
}
