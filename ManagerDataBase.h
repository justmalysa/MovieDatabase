#ifndef MANAGERDATABASE_H
#define MANAGERDATABASE_H

#include "sqlite3.h"
#include "Movie.h"
#include <vector>

#define DATABASE_TITLE_INDEX 0
#define DATABASE_YEAR_INDEX 1
#define DATABASE_RATING_INDEX 2
#define DATABASE_WATCHED_INDEX 3

class ManagerDataBase
{
private:
	sqlite3* db;
public:
	ManagerDataBase(const char* database_path);
	std::vector<Movie> export_database(void);
	void add_movie(Movie xmovie);
	void delete_movie_by_title(const char* xtitle);
	std::vector<Movie> sort_by_title(void);
	std::vector<Movie> sort_by_year(void);	
	std::vector<Movie> sort_by_rating(void);
	void give_rating_by_title(int xrating, const char* xtitle);
	void set_watched_by_title(bool xwatched, const char* xtitle);
	bool check_if_movie_exist(std::string xtitle);
	bool validate_rating(int xrating);
	int get_rating_by_title(std::string xtitle);
};

#endif
