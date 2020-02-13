#include "ManagerOMDb.h"
#include "curl.h"
#include <iostream>

size_t ManagerOMDb::write(void* ptr, size_t size, size_t nmemb, std::string* data) {
	data->append((char*)ptr, size * nmemb);
	return size * nmemb;
}

std::string ManagerOMDb::search_by_title(std::string xtitle)
{
	for (size_t i = 0; i < xtitle.length(); ++i) 
	{
		if (xtitle[i] == ' ')
		{
			xtitle[i] = '+';
		}
	}
	char buffer[256];
	snprintf(buffer, sizeof(buffer), "http://www.omdbapi.com/?apikey=8efe4481&s=%s&r=xml", xtitle.c_str());

	auto curl = curl_easy_init();
	curl_easy_setopt(curl, CURLOPT_URL, buffer);

	std::string response_string;
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);
	curl_easy_perform(curl);
	curl_easy_cleanup(curl);
	return response_string;
}
