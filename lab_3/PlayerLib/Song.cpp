#include <String>
#include "Song.h"

Song::Song()
{
	title = "";
	length = 0;
}

Song::Song(std::string title, double length)
{
	this->title = title;
	this->length = length;
}

std::string Song::getTitle()
{
	return this->title;
}

double Song::getLength()
{
	return this->length;
}

void Song::setTitle(std::string new_title)
{
	this->title = new_title;
}

void Song::setLength(double new_length)
{
	this->length = new_length;
}

bool Song::operator==(Song new_song)
{
	if (this->title != new_song.title)
		return false;
	if (this->length != new_song.length)
		return false;
	return true;
}

bool Song::operator!=(Song new_song)
{
	if (this->title == new_song.title)
		return true;
	if (this->length == new_song.length)
		return true;
	return false;
}