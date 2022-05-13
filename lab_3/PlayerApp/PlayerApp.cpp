#include <iostream>
#include <string>
#include "../PlayerLib/Player.h"
#include "../PlayerLib/Playlist.h"
#include "../PlayerLib/Song.h"

int main()
{
    int action;
    bool out = true;
    std::string tempTitle;
    double tempLength;
    Song tempSong;
    Playlist rock, classic;
    Player musicPlayer;

    classic.addSong("Fur Elise", 6.25);
    classic.addSong("Four Seasons", 12.47);
    classic.addSong("Symphony No. 5", 9.53);
    classic.addSong("Ave Maria", 7.12);
    classic.addSong("Sonata", 4.20);

    rock.addSong("Bohemian rapsody", 5.20);
    rock.addSong("Highway to hell", 3.29);
    rock.addSong("Smells like teen spirit", 5.01);
    rock.addSong("Smoke on the water", 7.12);
    rock.addSong("Stairway to heaven", 8.02);


    std::cout << "Welcome to music player!\n";
    while (out)
    {
        std::cout << "Please choose your action\n";
        std::cout << "1. Listen rock playlist.\n2. Listen rock playlist in reverse.\n";
        std::cout << "3. Listen classic music playlist.\n4. Listen classic music playlist in reverse.\n";
        std::cout << "5. Add song to rock playlist.\n6. Delete song from rock playlist.\n";
        std::cout << "7. Add song to classic music playlist.\n8. Delete song from classic music playlist in reverse.\n";
        std::cout << "9. Exit.\n";
        std::cin >> action;
        std::cin.get();
        system("cls");
        switch (action)
        {
        case 1:
            musicPlayer.newPlaylist(rock);
            musicPlayer.playAll();
            break;
        case 2:
            musicPlayer.newPlaylist(rock);
            musicPlayer.playAllReverse();
            break;
        case 3:
            musicPlayer.newPlaylist(classic);
            musicPlayer.playAll();
            break;
        case 4:
            musicPlayer.newPlaylist(classic);
            musicPlayer.playAllReverse();
            break;
        case 5:
            std::cout << "Enter song title.\n";
            getline(std::cin, tempTitle);
            std::cout << "Enter song length.\n";
            std::cin >> tempLength;
            rock.addSong(tempTitle, tempLength);
            system("cls");
            break;
        case 6:
            std::cout << "Enter song title.\n";
            getline(std::cin, tempTitle);
            std::cout << "Enter song length.\n";
            std::cin >> tempLength;
            tempSong = Song(tempTitle, tempLength);
            rock.removeSong(tempSong);
            system("cls");
            break;
        case 7:
            std::cout << "Enter song title.\n";
            getline(std::cin, tempTitle);
            std::cout << "Enter song length.\n";
            std::cin >> tempLength;
            classic.addSong(tempTitle, tempLength);
            system("cls");
            break;
        case 8:
            std::cout << "Enter song title.\n";
            getline(std::cin, tempTitle);
            std::cout << "Enter song length.\n";
            std::cin >> tempLength;
            tempSong = Song(tempTitle, tempLength);
            classic.removeSong(tempSong);
            system("cls");
            break;
        case 9:
            out = false;
            std::cout << "Goodbye.";
            break;
        default:
            std::cout << "Invalid input. Try again.\n";
        }
    }
}
