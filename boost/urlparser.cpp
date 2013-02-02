/* urlparser.cpp */

#include "urlparser.hpp"

/**
 * UrlParser
 *
 */
UrlParser::UrlParser(const string& url):
    m_url(url),
    m_queryString(""),
    m_path(""),
    m_protocol(""),
    m_host(""),
    m_port("80")
{
    if (url.length() == 0)
        return;

    // parse the url
    parse(url);
}

void UrlParser::parse(const string &url)
{
    // protocol
    size_t pos = url.find("://");
    if (pos == string::npos) {
        m_protocol = "http";
        m_url = "http://" + url;
        pos = 0;
    }
    else {
        m_protocol = url.substr(0, pos);
        pos += 3;
    }

    // host
    string path = url.substr(pos);
    size_t pathStart = path.find("/");
    if (pathStart == string::npos) {
        m_host = path;
    }
    else {
        m_host = path.substr(0, pathStart);
    }

    // port
    size_t port = m_host.find(":");
    if (port != string::npos) {
        m_port = m_host.substr(port + 1);
        m_host = m_host.substr(0, port);
    }
    path = path.substr(pathStart + 1);

    // get query start
    size_t queryStart = path.find("?", pos);
    if (queryStart == string::npos) {
        m_path = path;
    }
    else {
        m_path = path.substr(0, queryStart);
        m_queryString = path.substr(queryStart + 1);
    }

    // get extension of the url string path
    pos = m_path.find_last_of(".");
    if (pos == string::npos) {
        m_extension = "";
    }
    else {
        m_extension = m_path.substr(pos+1);
    }
}

UrlParser::~UrlParser()
{
}

string UrlParser::getUrl()
{
    return m_url;
}

string UrlParser::getQueryString()
{
    return m_queryString;
}

string UrlParser::getPath()
{
    return m_path;
}

string UrlParser::getExtension()
{
    return m_extension;
}

string UrlParser::getProtocol()
{
    return m_protocol;
}

string UrlParser::getHost()
{
    return m_host;
}

string UrlParser::getPort()
{
    return m_port;
}
