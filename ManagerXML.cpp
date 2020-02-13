#include "ManagerXML.h"
#include <iostream>


std::vector<Movie> ManagerXML::read(std::string xml_path)
{
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file(xml_path.c_str());
	std::cout << "Load result: " << result.description() << std::endl;
	pugi::xml_node movies = doc.first_child();

	std::vector<Movie> movies_vec;
	for (pugi::xml_node movie = movies.first_child(); movie; movie = movie.next_sibling())
	{
		pugi::xml_node movie_element = movie.first_child();

		std::string title = movie_element.child_value();
		movie_element = movie_element.next_sibling();

		int year = std::stoi(movie_element.child_value());
		movie_element = movie_element.next_sibling();

		int rating = std::stoi(movie_element.child_value());
		movie_element = movie_element.next_sibling();

		bool watched = std::stoi(movie_element.child_value());
		movie_element = movie_element.next_sibling();

		movies_vec.push_back(Movie(title, year, rating, watched));
	}
	return movies_vec;
}


void ManagerXML::write(std::string xml_path, std::vector<Movie> movies_vec)
{
	pugi::xml_document doc;
	pugi::xml_node node;
	pugi::xml_node title;
	pugi::xml_node year;
	pugi::xml_node rating;
	pugi::xml_node watched;

	pugi::xml_node root = doc.append_child("movies");

	for (size_t i = 0; i < movies_vec.size(); i++)
	{
		node = root.append_child("movie");

		title = node.append_child("title");
		title.append_child(pugi::node_pcdata).set_value((movies_vec[i].title).c_str());

		year = node.append_child("year");
		year.append_child(pugi::node_pcdata).set_value((std::to_string(movies_vec[i].year)).c_str());

		rating = node.append_child("rating");
		rating.append_child(pugi::node_pcdata).set_value((std::to_string(movies_vec[i].rating)).c_str());

		watched = node.append_child("watched");
		watched.append_child(pugi::node_pcdata).set_value((std::to_string(movies_vec[i].watched)).c_str());
	}
	doc.save_file(xml_path.c_str());
}

std::vector<Movie> ManagerXML::parse_OMDb_response(std::string xml_response)
{
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_string(xml_response.c_str());
	pugi::xml_node movies = doc.first_child();

	std::vector<Movie> movies_vec;

	for (pugi::xml_node movie = movies.first_child(); movie; movie = movie.next_sibling())
	{
		std::string xtitle = movie.attribute("title").value();
		bool already_in_vec = false;
		for (size_t i = 0; i < movies_vec.size(); i++)
		{
			if (movies_vec[i].title == xtitle)
			{
				already_in_vec = true;
				break;
			}
		}
		if (!already_in_vec)
		{
			movies_vec.push_back(Movie(xtitle, std::stoi(movie.attribute("year").value()), 0, false));
		}
	}
	return movies_vec;
}
