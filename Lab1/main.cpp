#include <iostream>
#include <string>
using namespace std;
#include "Playlist.h"

int main() {
    cout << "Enter playlist's title:" << endl;
    string playlistTitle;
    getline(cin, playlistTitle);
    cout << "\n";
    Playlist p;

    //for testing
    // p.AddSong(new PlaylistNode("1", "hi there", "chris young", 5));
    // p.AddSong(new PlaylistNode("2", "bye bye", "chris young", 7));
    // p.AddSong(new PlaylistNode("3", "good bye", "albert tambalo", 8));
    // p.AddSong(new PlaylistNode("4", "bad time", "albert tambalo", 6));
    // p.AddSong(new PlaylistNode("5", "ba dum tss", "kimberly yang", 1));
    // p.AddSong(new PlaylistNode("6", "bad song", "kimberly yang", 2));

    string input; 

    while (true) {
        p.PrintMenu(playlistTitle);
        cin >> input;
        cin.ignore();

        if (input == "a") { // add song
            cout << "ADD SONG" << endl;
            cout << "Enter song's unique ID:" << endl;
            string uniqueID;
            getline(cin, uniqueID);
            cout << "Enter song's name:" << endl;
            string songName;
            getline(cin, songName);
            cout << "Enter artist's name:" << endl;
            string artistName;
            getline(cin, artistName);
            cout << "Enter song's length (in seconds):" << endl;
            int songLength;
            cin >> songLength;
            p.AddSong(new PlaylistNode(uniqueID, songName, artistName, songLength));
            cout << "\n";
        }
        else if (input == "d") { // remove song
            cout << "REMOVE SONG" << endl;
            cout << "Enter song's unique ID:" << endl;
            string uniqueID;
            cin >> uniqueID;
            if (!p.RemoveSong(uniqueID)) {
                cout << uniqueID << " not found" << endl;
            }
            cout << "\n";
        }
        else if (input == "c") { // reposition song
            cout << "CHANGE POSITION OF SONG" << endl;
            cout << "Enter song's current position:" << endl;
            int currLoc;
            cin >> currLoc;
            cout << "Enter new position for song:" << endl;
            int newLoc;
            cin >> newLoc;
            p.RepositionSong(currLoc, newLoc);
            cout << "\n";
        }
        else if (input == "s") { // filter by artist
            cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
            cout << "Enter artist's name:" << endl;
            string artistName;
            getline(cin, artistName);
            cout << "\n";
            p.PrintByArtist(artistName);
        }
        else if (input == "t") { // compute playlist duration
            cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
            cout << "Total time: " << p.GetTotalTime() << " seconds" << endl;
            cout << "\n";
        }
        else if (input == "o") { // output playlist
            cout << playlistTitle << " - OUTPUT FULL PLAYLIST" << endl;
            p.PrintPlaylist();
        }
        else if (input == "q") { // quit
            break;
        }
    }

    return 0;
}