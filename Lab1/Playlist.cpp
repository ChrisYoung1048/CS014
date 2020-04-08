#include <iostream>
#include "Playlist.h"
using namespace std;

PlaylistNode::PlaylistNode() {
    uniqueID = "none";
    songName = "none";
    artistName = "none";
    songLength = 0;
    nextNodePtr = nullptr;
}

PlaylistNode::PlaylistNode(string uniqueID, string songName, string artistName, int songLength) {
    this->uniqueID = uniqueID;
    this->songName = songName;
    this->artistName = artistName;
    this->songLength = songLength;
    nextNodePtr = nullptr;
}

void PlaylistNode::InsertAfter(PlaylistNode* nodeLoc) {
    PlaylistNode* tempNode = this->nextNodePtr;
    this->nextNodePtr = nodeLoc;
    nodeLoc->nextNodePtr = tempNode;
}

void PlaylistNode::SetNext(PlaylistNode* nextNode) {
    nextNodePtr = nextNode;
}

string PlaylistNode::GetID() {
    return uniqueID;
}

string PlaylistNode::GetSongName() {
    return songName;
}

string PlaylistNode::GetArtistName() {
    return artistName;
}

int PlaylistNode::GetSongLength() {
    return songLength;
}

PlaylistNode* PlaylistNode::GetNext() {
    return nextNodePtr;
}

void PlaylistNode::PrintPlaylistNode() {
    cout << "Unique ID: " << uniqueID << endl;
    cout << "Song Name: " << songName << endl;
    cout << "Artist Name: " << artistName << endl;
    cout << "Song Length (in seconds): " << songLength << endl;
}

// ==============================================================

void Playlist::AddSong(PlaylistNode* song) { // if LinkedList is empty
    if (head == nullptr) {
        head = song;
        tail = song;
    }
    else if (tail == nullptr) { // if there is only 1 node
        tail = song;
        head->SetNext(tail);
    }
    else { // if there is at least 2 nodes
        tail->SetNext(song);
        tail = tail->GetNext();
    }
}

bool Playlist::RemoveSong(string uniqueID) { // return true if node removed, else return false
    if (head == nullptr) {
        return false;
    }
    else if (head->GetID() == uniqueID) { // if removing head
        cout << "\"" << head->GetSongName() << "\"" << " removed" << endl;
        if (head == tail) { // if there is only 1 node
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else { // if there is at least 2 nodes
            PlaylistNode* tempNode = head->GetNext();
            delete head;
            head = tempNode;
        }
        return true;
    }
    else if (tail->GetID() == uniqueID) { // when removing tail (given there is only a head and a tail)
        cout << "\"" << tail->GetSongName() << "\"" << " removed." << endl;
        if (head->GetNext() == tail) { // if tail is the 2nd node
            delete tail;
            tail = head;
            
        }
        else {
            PlaylistNode* currNode = head;
            PlaylistNode* prevNode = nullptr; //keeps track of node before tail
            while (currNode != tail) {
                prevNode = currNode;
                currNode = currNode->GetNext();
            }
            delete tail;
            tail = prevNode;
            tail->SetNext(nullptr);
        }
        return true;
    }
    else {
        PlaylistNode* currNode = head;
        while (currNode->GetNext() != nullptr) {
            if (currNode->GetNext()->GetID() == uniqueID) { //if the next node is to be deleted
                cout << "\"" << currNode->GetNext()->GetSongName() << "\"" << " removed." << endl;
                PlaylistNode* temp = currNode->GetNext()->GetNext(); // store the next next node
                delete currNode->GetNext(); // delete middle node
                currNode->SetNext(temp); // point current to next next
                return true;
            }
            currNode = currNode->GetNext();
        }
    }
    return false;
}

void Playlist::RepositionSong(int currLoc, int newLoc) {
    if (currLoc == newLoc)
        return;
    PlaylistNode* targetNode = head; // determine what type of node currLoc is
    PlaylistNode* prevNode = nullptr;
    for (unsigned i = 0; i < currLoc-1; ++i) {
        prevNode = targetNode; // keeps track of the node before the target node
        targetNode = targetNode->GetNext();
    }

    if (targetNode == head) { // if repositioning the head
        head = head->GetNext(); // first, set readjust for new head
        PlaylistNode* newLocNode = head; // then, find the new location for target
        for (unsigned i = 0; i < newLoc-2; ++i) {
            newLocNode = newLocNode->GetNext();
        }
        newLocNode->InsertAfter(targetNode); //!!!!!!!doesnt account for resetting tail when swapping 1 to 6
    }
    else if (targetNode == tail) { // if repositioning the tail
        tail = prevNode; // first, readjust for new tail
        tail->SetNext(nullptr);
        if (newLoc == 1) { // then, find the new location for target
            targetNode->SetNext(head);
            head = targetNode;
        }
        else {
            PlaylistNode* newLocNode = head; 
            for (unsigned i = 0; i < newLoc-2; ++i) { 
                newLocNode = newLocNode->GetNext(); 
            }
            newLocNode->InsertAfter(targetNode);
        }
    }
    else {
        prevNode->SetNext(targetNode->GetNext());
        if (newLoc == 1) { // if new location is a head
            targetNode->SetNext(head);
            head = targetNode;
        }
        else {
            PlaylistNode* newLocNode = head; // find the new location for target
            for (unsigned i = 0; i < newLoc-2; ++i) {
                newLocNode = newLocNode->GetNext();
            }
            if (newLocNode == tail) { // if new location is a tail
                newLocNode->InsertAfter(targetNode);
                tail = newLocNode->GetNext();
            }
            else { // if new location is between head and tail
                newLocNode->InsertAfter(targetNode);
            }
        }
    }
    cout << "\"" << targetNode->GetSongName() << "\"" << " moved to position " << newLoc << endl;
}

void Playlist::PrintByArtist(string artistName) {
    PlaylistNode* currNode = head;
    int songCount = 1;
    while (currNode != nullptr) {
        if (currNode->GetArtistName() == artistName) {
            cout << songCount << "." << endl;
            currNode->PrintPlaylistNode();
            cout << "\n";
        }
        currNode = currNode->GetNext();
        songCount++;
    }
}

int Playlist::GetTotalTime() {
    PlaylistNode* currNode = head;
    int totalTime = 0;
    while (currNode != nullptr) {
        totalTime += currNode->GetSongLength();
        currNode = currNode->GetNext();
    }
    return totalTime;
}

void Playlist::PrintPlaylist() {
    if (head == nullptr) {
        cout << "Playlist is empty" << endl << endl;
        return;
    }
    PlaylistNode* currNode = head;
    int songCount = 1;
    while (currNode != nullptr) {
        cout << songCount << "." << endl;
        currNode->PrintPlaylistNode();
        cout << "\n";
        currNode = currNode->GetNext();
        songCount++;
    }
}

void Playlist::PrintMenu(string playlistTitle) {
    cout << playlistTitle << " PLAYLIST MENU" << endl;
    cout << "a - Add song" << endl;
    cout << "d - Remove song" << endl;
    cout << "c - Change position of song" << endl;
    cout << "s - Output songs by specific artist" << endl;
    cout << "t - Output total time of playlist (in seconds)" << endl;
    cout << "o - Output full playlist" << endl;
    cout << "q - Quit" << endl;
    cout << "\nChoose an option:" << endl;
}