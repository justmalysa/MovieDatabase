#include "ManagerDataBase.h"
#include <iostream>

ManagerDataBase::ManagerDataBase(const char* database_path)
{
	int status = sqlite3_open(database_path, &db);
	if (status)
	{
		std::cout << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
	}
	else
	{
		std::cout << "Database opened successfully" << std::endl;
	}
}

std::vector<Movie> ManagerDataBase::export_database(void)
{
	sqlite3_stmt* stmt;
	sqlite3_prepare_v2(db, "select * from tab", -1, &stmt, NULL);

	int status;
	std::vector<Movie> movies;
	while ((status = sqlite3_step(stmt)) != SQLITE_DONE)
	{
		movies.push_back(Movie(
			std::string((const char*)sqlite3_column_text(stmt, 0)),
			sqlite3_column_int(stmt, 1),
			sqlite3_column_int(stmt, 2),
			sqlite3_column_int(stmt, 3)));
	}
	sqlite3_finalize(stmt);
	return movies;
}

void ManagerDataBase::add_movie(Movie xmovie)
{
	char* zErrMsg = 0;
	char buffer[128];
	snprintf(buffer, sizeof(buffer), "insert into tab values('%s',%d, %d, %d)",
		(xmovie.title).c_str(), xmovie.year, xmovie.rating, xmovie.watched);
	int status = sqlite3_exec(db, buffer, NULL, 0, &zErrMsg);
	if (status)
	{
		std::cout << "Movie added: " << sqlite3_errmsg(db) << " failed" << std::endl;
	}
	else
	{
		std::cout << "Movie added successfully" << std::endl;
		std::cout << std::endl;
	}
}

void ManagerDataBase::delete_movie_by_title(const char* xtitle)
{
	char* zErrMsg = 0;
	char buffer[128];
	snprintf(buffer, sizeof(buffer), "DELETE FROM `tab` WHERE `title` = '%s'", xtitle);
	int status = sqlite3_exec(db, buffer, NULL, 0, &zErrMsg);
	if (status)
	{
		std::cout << "Delete: " << sqlite3_errmsg(db) << " failed" << std::endl;
	}
	else
	{
		std::cout << "Deleted successfully" << std::endl;
	}
}

std::vector<Movie> ManagerDataBase::sort_by_title(void)
{
	sqlite3_stmt* stmt;
	sqlite3_prepare_v2(db, "SELECT * FROM tab ORDER BY title ASC", -1, &stmt, NULL);

	int status;
	std::vector<Movie> movies;
	while ((status = sqlite3_step(stmt)) != SQLITE_DONE)
	{
		movies.push_back(Movie(
			std::string((const char*)sqlite3_column_text(stmt, 0)),
			sqlite3_column_int(stmt, 1),
			sqlite3_column_int(stmt, 2),
			sqlite3_column_int(stmt, 3)));
	}
	sqlite3_finalize(stmt);
	return movies;
}

std::vector<Movie> ManagerDataBase::sort_by_year(void)
{
	sqlite3_stmt* stmt;
	sqlite3_prepare_v2(db, "SELECT * FROM tab ORDER BY year ASC", -1, &stmt, NULL);

	int status;
	std::vector<Movie> movies;
	while ((status = sqlite3_step(stmt)) != SQLITE_DONE)
	{
		movies.push_back(Movie(
			std::string((const char*)sqlite3_column_text(stmt, 0)),
			sqlite3_column_int(stmt, 1),
			sqlite3_column_int(stmt, 2),
			sqlite3_column_int(stmt, 3)));
	}
	sqlite3_finalize(stmt);
	return movies;
}

std::vector<Movie> ManagerDataBase::sort_by_rating(void)
{
	sqlite3_stmt* stmt;
	sqlite3_prepare_v2(db, "SELECT * FROM tab ORDER BY rating DESC", -1, &stmt, NULL);

	int status;
	std::vector<Movie> movies;
	while ((status = sqlite3_step(stmt)) != SQLITE_DONE)
	{
		movies.push_back(Movie(
			std::string((const char*)sqlite3_column_text(stmt, 0)),
			sqlite3_column_int(stmt, 1),
			sqlite3_column_int(stmt, 2),
			sqlite3_column_int(stmt, 3)));
	}
	sqlite3_finalize(stmt);
	return movies;
}

void ManagerDataBase::give_rating_by_title(int xrating, const char* xtitle)
{
	char* zErrMsg = 0;
	char buffer[128];
	snprintf(buffer, sizeof(buffer), "UPDATE tab SET rating = %d WHERE title = '%s'", xrating, xtitle);
	int status = sqlite3_exec(db, buffer, NULL, this, &zErrMsg);
	if (status)
	{
		std::cout << "Giving a rating: " << sqlite3_errmsg(db) << " failed" << std::endl;
	}
	else
	{
		std::cout << "Giving a rating successfully" << std::endl;
		std::cout << std::endl;
	}
}

void ManagerDataBase::set_watched_by_title(bool xwatched, const char* xtitle)
{
	char* zErrMsg = 0;
	char buffer[128];
	snprintf(buffer, sizeof(buffer), "UPDATE tab SET watched = %d WHERE title = '%s'", xwatched, xtitle);
	int status = sqlite3_exec(db, buffer, NULL, this, &zErrMsg);
	if (status)
	{
		std::cout << "Add to watched movies: " << sqlite3_errmsg(db) << " failed" << std::endl;
	}
	else
	{
		std::cout << "Add to watched movies successfully" << std::endl;
		std::cout << std::endl;
	}
}

bool ManagerDataBase::check_if_movie_exist(std::string xtitle)
{
	sqlite3_stmt* stmt;
	char buffer[128];
	snprintf(buffer, sizeof(buffer), "SELECT COUNT(1) FROM tab WHERE title = '%s'", xtitle.c_str());
	sqlite3_prepare_v2(db, buffer, -1, &stmt, NULL);

	sqlite3_step(stmt);
	int count = sqlite3_column_int(stmt, 0);
	sqlite3_finalize(stmt);

	if (count != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool ManagerDataBase::validate_rating(int xrating)
{
	if (xrating >= 0 && xrating <= 10)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int ManagerDataBase::get_rating_by_title(std::string xtitle)
{
	sqlite3_stmt* stmt;
	char buffer[128];
	snprintf(buffer, sizeof(buffer), "SELECT rating FROM tab WHERE title = '%s'", xtitle.c_str());
	sqlite3_prepare_v2(db, buffer, -1, &stmt, NULL);

	sqlite3_step(stmt);
	int count = sqlite3_column_int(stmt, 0);
	sqlite3_finalize(stmt);

	return count;
}
