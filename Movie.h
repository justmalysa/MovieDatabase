#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <vector>

class Movie
{
public:
	std::string title;
	int year;
	int rating;
	bool watched;

	Movie(std::string xtitle, int xyear, int xrating, bool xwatched);
	void print(void);
	static void print_vector(std::vector<Movie>& movies);
};

#endif
