#ifndef MANAGERXML_H
#define MANAGERXML_H

#include <vector>
#include <string>
#include "Movie.h"
#include "pugixml.hpp"

class ManagerXML
{
public:
	std::vector<Movie> read(std::string xml_path);
	void write(std::string xml_path, std::vector<Movie> movies_vec);
	std::vector<Movie> parse_OMDb_response(std::string xml_response);
};

#endif
