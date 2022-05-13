#pragma once
#include <string>

class Song
{
private:
	std::string title;
	double length;
public:
	Song();
	Song(std::string title, double length);
	std::string getTitle();
	double getLength();
	void setTitle(std::string new_title);
	void setLength(double new_length);

	bool operator==(Song new_song);
	bool operator!=(Song new_song);
};

