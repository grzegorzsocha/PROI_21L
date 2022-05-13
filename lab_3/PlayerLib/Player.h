#pragma once
#include "Playlist.h"
#include "Song.h"


class Player
{
private:
	Playlist currentPlaylist;
public:
	Player();
	Player(Playlist playlist);
	void playOneSong(Song song);
	void playAll();
	void playAllReverse();
	void newPlaylist(Playlist playlist);
	Playlist getPlaylist();
};