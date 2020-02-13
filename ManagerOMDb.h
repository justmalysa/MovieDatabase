#ifndef MANAGEROMDB_H
#define MANAGEROMDB_H

#include <string>

class ManagerOMDb
{
private:
	static size_t write(void* ptr, size_t size, size_t nmemb, std::string* data);
public:
	std::string search_by_title(std::string xtitle);
};

#endif
