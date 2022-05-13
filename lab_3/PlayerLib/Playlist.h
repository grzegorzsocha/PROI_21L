#pragma once
#include <string>
#include <vector>
#include "Song.h"

class Playlist
{
private:
	std::vector<Song> songs;
public:
	Playlist();
	Playlist(std::vector<Song> new_songs);
	bool alreadyInPLaylist(Song song);
	void addSong(std::string title, double length = 0);
	void removeSong(Song song);
	std::vector<Song> getSongs();

	Playlist operator=(Playlist new_songs);
	Playlist operator+(Playlist new_songs);

	bool operator==(Playlist new_songs);
	bool operator!=(Playlist new_songs);
};
