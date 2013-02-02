/* urlparser.h */

#ifndef URLPARSER_H
#define URLPARSER_H

#include <string>
#include <boost/python.hpp>
using namespace boost::python;
//#include "http.hpp"

using namespace std;

/**
 * UrlParser class parses url-string of http request
 */
class UrlParser
{
public:
    /**
     * Constructor
     */
    UrlParser(const string& url);
    /**
     * Destructor
     */
    ~UrlParser();

    /**
     * Parsing the url-string of http request
     */
    void parse(const string& url);
    /**
     * Returns full url string of the http request
     */
    string getUrl();
    /**
     * Returns query string of the url string
     */
    string getQueryString();
    /**
     * Returns path of the url string
     */
    string getPath();
    /**
     * Returns extension of the url string path
     */
    string getExtension();
    /**
     * Returns protocol of the url string
     */
    string getProtocol();
    /**
     * Returns host name/address of the url string
     */
    string getHost();
    /**
     * Returns port of the url string
     */
    string getPort();

private:
    string m_url;          // full url string of the http request
    string m_queryString;  // query string of the url string
    string m_path;         // path of the url string
    string m_extension;    // extension of the url string path
    string m_protocol;     // protocol of the url string
    string m_host;         // host name/address of the url string
    string m_port;         // port of the url string
};

BOOST_PYTHON_MODULE(_url_parser)
{
    class_<UrlParser>("UrlParser", init<const string& >())
        .def("parse", &UrlParser::parse)
        .add_property("url", &UrlParser::getUrl)
        .add_property("queryString", &UrlParser::getQueryString)
        .add_property("path", &UrlParser::getPath)
        .add_property("extension", &UrlParser::getExtension)
        .add_property("protocol", &UrlParser::getProtocol)
        .add_property("host", &UrlParser::getHost)
        .add_property("port", &UrlParser::getPort)
    ;
}

#endif // URLPARSER_H
