#include "CppUnitTest.h"
#include "../PlayerLib/Player.h"
#include "../PlayerLib/Playlist.h"
#include "../PlayerLib/Song.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestPlayer
{
	TEST_CLASS(UnitTestPlayer)
	{
	public:
		
		TEST_METHOD(SongConstructorParameterless)
		{
			Song song;
			std::string text = "";
			Assert::AreEqual(text, song.getTitle());
			Assert::AreEqual(0.0, song.getLength());
		}
		TEST_METHOD(SongConstructorWithParameter)
		{
			Song song("sweater weather", 4.25);
			std::string text = "sweater weather";
			Assert::AreEqual(text, song.getTitle());
			Assert::AreEqual(4.25, song.getLength());
		}
		TEST_METHOD(SongGetTitle)
		{
			Song song("sweater weather", 4.25);
			std::string text = "sweater weather";
			Assert::AreEqual(text, song.getTitle());
		}
		TEST_METHOD(SongGetLength)
		{
			Song song("sweater weather", 4.25);
			Assert::AreEqual(4.25, song.getLength());
		}
		TEST_METHOD(SongSetTitle)
		{
			Song song("stairway to heaven", 4.25);
			song.setTitle("sweater weather");
			std::string text = "sweater weather";
			Assert::AreEqual(text, song.getTitle());
		}
		TEST_METHOD(SongSetLength)
		{
			Song song("sweater weather", 4.25);
			song.setLength(7.30);
			Assert::AreEqual(7.30, song.getLength());
		}
		TEST_METHOD(SongOperatorEqual)
		{
			bool result = false;
			Song song1("sweater weather", 4.25), song2("sweater weather", 4.25);
			if (song1 == song2)
				result = true;
			Assert::IsTrue(result);
		}
		TEST_METHOD(SongOperatorNotEqual)
		{
			bool result = false;
			Song song1("sweater weather", 4.25), song2("not sweater weather", 4.25);
			if (song1 != song2)
				result = true;
			Assert::IsTrue(result);
		}
		TEST_METHOD(PlaylistAlreadyInPlaylistTrue)
		{
			Song song1("asd", 4.25), song2("afs", 4.25);
			std::vector<Song> v = { song1, song2 };
			Playlist playlist(v);
			Assert::IsTrue(playlist.alreadyInPLaylist(song2));
		}
		TEST_METHOD(PlaylistAlreadyInPlaylistFalse)
		{
			Song song1("asd", 4.25), song2("afs", 4.25), song3("afsasd", 44.25);
			std::vector<Song> v = { song1, song2 };
			Playlist playlist(v);
			Assert::IsFalse(playlist.alreadyInPLaylist(song3));
		}
		TEST_METHOD(PlaylistAddSong)
		{
			Song song1("asd", 4.25), song2("afs", 4.25), song3("afsasd", 44.25);
			std::vector<Song> v = { song1, song2 };
			Playlist playlist(v);
			playlist.addSong("afsasd", 44.25);
			Assert::IsTrue(playlist.alreadyInPLaylist(song3));
		}
		TEST_METHOD(PlaylistRemoveSong)
		{
			Song song1("asd", 4.25), song2("afs", 4.25), song3("afsasd", 44.25);
			std::vector<Song> v = { song1, song2, song3};
			Playlist playlist(v);
			playlist.removeSong(song3);
			Assert::IsFalse(playlist.alreadyInPLaylist(song3));
		}
		TEST_METHOD(PlaylistOperatorEqualTrue)
		{
			Playlist playlist1, playlist2;
			playlist1.addSong("asd", 7.25);
			playlist2.addSong("asd", 7.25);
			Assert::IsTrue(playlist1 == playlist2);
		}
		TEST_METHOD(PlaylistOperatorEqualFalse)
		{
			Playlist playlist1, playlist2;
			playlist1.addSong("asd", 7.25);
			playlist2.addSong("asd", 6.25);
			Assert::IsFalse(playlist1 == playlist2);
		}
		TEST_METHOD(PlaylistOperatorNotEqualTrue)
		{
			Playlist playlist1, playlist2;
			playlist1.addSong("asd", 1.25);
			playlist2.addSong("asd", 7.25);
			Assert::IsTrue(playlist1 != playlist2);
		}
		TEST_METHOD(PlaylistOperatorNotEqualFalse)
		{
			Playlist playlist1, playlist2;
			playlist1.addSong("asd", 7.25);
			playlist2.addSong("asd", 7.25);
			Assert::IsFalse(playlist1 != playlist2);
		}
		TEST_METHOD(PlaylistOperatorEquals)
		{
			Playlist playlist1, playlist2, playlist3, playlist4;
			playlist1.addSong("asd", 4.25);
			playlist2.addSong("asd", 7.25);
			playlist3.addSong("asd", 7.25);
			playlist1 = playlist2;
			Assert::IsTrue(playlist1 == playlist3);
		}
		TEST_METHOD(PlaylistOperatorPlus)
		{
			Playlist playlist1, playlist2, playlist3, playlist4;
			playlist1.addSong("asd", 4.25);
			playlist2.addSong("afs", 7.25);
			playlist3.addSong("asd", 4.25);
			playlist3.addSong("afs", 7.25);
			playlist4 = playlist1 + playlist2;
			Assert::IsTrue(playlist3 == playlist4);
		}
		TEST_METHOD(PlayerConstructorWithParameter)
		{
			Playlist playlist1;
			playlist1.addSong("asd", 4.25);
			Player player(playlist1);
			Assert::IsTrue(player.getPlaylist() == playlist1);
		}
		TEST_METHOD(PlayerNewPlaylist)
		{
			Playlist playlist1, playlist2;
			playlist1.addSong("asd", 4.25);
			Player player(playlist1);
			player.newPlaylist(playlist2);
			Assert::IsTrue(player.getPlaylist() == playlist2);
		}
	};
}
