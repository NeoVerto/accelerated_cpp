#ifndef GUARD_find_urls_h
#define GUARD_find_urls_h

#include <string>
#include <vector>
bool not_url_char(char);
std::string::const_iterator
url_end(std::string::const_iterator, std::string::const_iterator);
std::string::const_iterator
url_begin(std::string::const_iterator, std::string::const_iterator);
std::vector<std::string> find_urls(const std::string&);

#endif  // GUARD_find_urls_h