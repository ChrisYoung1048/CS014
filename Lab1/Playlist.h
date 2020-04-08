#ifndef PLAYLIST_H
#define PLAYLIST_H

//#include "PlaylistNode.h"
using namespace std;

class PlaylistNode {
    private:
        string uniqueID;
        string songName;
        string artistName;
        int songLength;
        PlaylistNode* nextNodePtr;
    public:
        PlaylistNode();
        PlaylistNode(string uniqueID, string songName, string artistName, int songLength);
        void InsertAfter(PlaylistNode* nodeLoc);
        void SetNext(PlaylistNode* nextNode);
        string GetID();
        string GetSongName();
        string GetArtistName();
        int GetSongLength();
        PlaylistNode* GetNext();
        void PrintPlaylistNode();
};

class Playlist {
    private:
        PlaylistNode* head;
        PlaylistNode* tail;
        string playlistTitle;
    public:
        Playlist() : head(nullptr), tail(nullptr) {}
        void AddSong(PlaylistNode* song);
        bool RemoveSong(string uniqueID);
        void RepositionSong(int currLoc, int newLoc);
        void PrintByArtist(string artistName);
        int GetTotalTime();
        void PrintPlaylist();
        void PrintMenu(string playlistTitle);
};

#endif