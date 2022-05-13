#include <iostream>
#include <thread>
#include <chrono>
#include <iostream>
#include <vector>
#include "Player.h"
#include "Song.h"

Player::Player()
{
	currentPlaylist;
}

Player::Player(Playlist playlist)
{
	this->currentPlaylist = playlist;
}

void Player::playOneSong(Song song)
{
	system("cls");
	std::cout << "Now playing: " << song.getTitle() << " length: " << song.getLength();
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	system("cls");
}

void Player::playAll()
{
	std::vector<Song> songs = currentPlaylist.getSongs();
	for (int i = 0; i < songs.size(); ++i)
		playOneSong(songs[i]);
}

void Player::playAllReverse()
{
	std::vector<Song> songs = currentPlaylist.getSongs();
	for (int i = songs.size() - 1; i >= 0; --i)
		playOneSong(songs[i]);
}

void Player::newPlaylist(Playlist playlist)
{
	this->currentPlaylist = playlist;
}
Playlist Player::getPlaylist()
{
	return currentPlaylist;
}