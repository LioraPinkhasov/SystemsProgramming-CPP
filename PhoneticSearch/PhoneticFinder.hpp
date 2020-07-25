//
// Created by LioraPinkhasov on 23/07/2020.
//

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

namespace phonetic
{
    /*this method is use for finding word in a string
     so this method get text and word
     and return string which is the word from the text that if find(if not return a message)
    in this method we use: words format
                           wordlowercase
                           checkWord
    */
    string find(string text, string word);


    /*this method is get string and return it in low case*/
    string wordlowercase(string word);

    /*this method is take a text, and with a space delimter it
     split words and every word put into vector.*/
    vector <string> wordsfromt (string text);


    // this methods comere between chars
    bool matchVW(char compared );
    bool matchSZ(char compared );
    bool matchBFP(char compared);
    bool matchCKQ(char compared);
    bool matchDT(char compared );
    bool matchIY(char compared );
    bool matchOU(char compared );
    bool matchGJ(char compared );

    //This is a helper method to define if two given chars are equal ,
    // regardless if "curr" is lower or upper case.
    bool upLowCaseCheck(char wrdChar, char curr);

    /*this method is use only if we find that the word we want to find
    and the word we have in the vector have the same size of latters,
    so this method is check if they are equal*/
    int checkWord(string lword, string curr);
}