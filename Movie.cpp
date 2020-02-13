#include "Movie.h"
#include <iostream>


Movie::Movie(std::string xtitle, int xyear, int xrating, bool xwatched)
	: title(xtitle), year(xyear), rating(xrating), watched(xwatched)
{
}

void Movie::print(void)
{
	std::cout << "title: " << title << std::endl;
	std::cout << "year: " << year << std::endl;
	std::cout << "rating: " << rating << std::endl;
	std::cout << "watched: " << watched << std::endl;
}

void Movie::print_vector(std::vector<Movie>& movies)
{
	for (size_t i = 0; i < movies.size(); i++)
	{
		movies[i].print();
	}
}
