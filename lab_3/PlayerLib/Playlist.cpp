#include <string>
#include <vector>
#include "Playlist.h"

Playlist::Playlist()
{
	songs = {};
}

Playlist::Playlist(std::vector<Song> new_songs)
{
	this->songs = new_songs;
}

bool Playlist::alreadyInPLaylist(Song song)
{
	for (int i = 0; i < this->songs.size(); ++i)
		if (songs[i] == song)
			return true;
	return false;
}

void Playlist::addSong(std::string title, double length)
{
	Song song(title, length);
	if (alreadyInPLaylist(song) == false)
		this->songs.push_back(song);
}

void Playlist::removeSong(Song song)
{
	this->songs.erase(std::remove(this->songs.begin(), this->songs.end(), song), this->songs.end());
}

Playlist Playlist::operator=(Playlist playlist)
{
	return this->songs = playlist.getSongs();
}

Playlist Playlist::operator+(Playlist playlist)
{
	for (int i = 0; i < playlist.songs.size(); ++i)
		this->songs.push_back(playlist.songs[i]);
	return this->songs;
}

bool Playlist::operator==(Playlist playlist)
{
	if (songs.size() != playlist.songs.size())
		return false;
	for (int i = 0; i < songs.size(); i++)
	{
		if (songs[i].getTitle() != playlist.songs[i].getTitle())
			return false;
		if (songs[i].getLength() != playlist.songs[i].getLength())
			return false;
	}
	return true;
}

bool Playlist::operator!=(Playlist playlist)
{
	if (songs.size() != playlist.songs.size())
		return true;
	for (int i = 0; i < songs.size(); i++)
	{
		if (songs[i].getTitle() != playlist.songs[i].getTitle())
			return false;
		if (songs[i].getLength() != playlist.songs[i].getLength())
			return true;
	}
	return false;
}

std::vector<Song> Playlist::getSongs()
{
	return songs;
}