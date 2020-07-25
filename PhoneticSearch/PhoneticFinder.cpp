//
// Created by LioraPinkhasov on 23/07/2020.
//
#include <iostream>
#include <stdexcept>
#include <string>
#include "PhoneticFinder.hpp"
using namespace std;

//we are using namespace to organize code into logical groups and to prevent name collisions that can occur.
namespace phonetic
{
    //this is our main function, here
    string find(string text, string word)
    {
        //check if the text is not empty,
        //if found that the text is empty it returns a notification massage
        //and throw runtime error
        if (word.length() == 0)
        {
            string errorMessage1 = string("No words found in text");
            throw runtime_error(errorMessage1);
        }


        //string originalWord = word; //temp string witch contains the original word.
        string lowword = wordlowercase(word); //new string that contains the word in lower case.
        text = text + ' '; // Added delimiter for partition.

        // Init vector of strings , which are words from the text.
        vector<string> wordsArray = wordsfromt(text);/*init the vector of sttrings
                                                     //with the words from the text
                                                     by using the method wordfromt*/

        int numOfWords = wordsArray.size(); //contains the number of words.
        if (numOfWords == 0) // Check if there are no words in the text
                             // if so it send a notifcation and throw runtime error
        {
            string errorMessage2 = string("No words found in text");
            throw runtime_error(errorMessage2);
        }
        bool found = false; // For match found use.


        for (int i = 0; i < numOfWords ; i++) // Check if any word in my txt match
        {

            if(lowword.length() == wordsArray[i].length())// Check only on words with matching size
            {
                int match = checkWord(lowword,wordsArray[i]); //send words to match
                if( match == 0 ) // wordFound!
                {
                    found = true;
                    return wordsArray[i];
                }

            }

        }

        if (!found) // if no word was found !
        {
            string errorMessage3 = string("Did not find the word ") + word + (" in the text");
            throw runtime_error(errorMessage3);
        }

        return "no";
    }


    /**
    this method get text string and return vector of strings.
    This method  split the text by the delimiter space " " , and put the split words into the
    vector of strings.
    */
    vector<string> wordsfromt(string text)
    {
        int index = 0;
        int i = 0;//counter
        vector<string> wordsfromtext;//vector of strings

        //we go in a for loop on the text and every time when we find the delimiter ' '
        //we put the word from index to i-index into the vector.
        for (int i = 0; i < text.size(); i++)
        {
            if (text.at(i) == ' ')
            {
                wordsfromtext.push_back(text.substr(index, (i - index)));
                index = i + 1;/*add 1 becouse we want our new index be after the delimiter ' '
                              as we know the i stop at text.at(i)== ' ').
                              so we add 1 to begin the index where the new word begin.*/
            }
        }
        return wordsfromtext;
    }


    /**
    this method get word string and return this word in lower case.
    this method lower case.
    */
    string wordlowercase(string word)
    {
        char low='a';
        /*by using the for loop we go thorge the word
          and turn every letter into a lower case letter.*/
        for (size_t i = 0; i < word.length(); i++)
        {
            low = word.at(i);//use as temp
            word.at(i) = tolower(low);//turn the orignal word letter into lower case.
        }
        return word;
    }


    /**
    this method gets a text string and turn it into a lower case.
    */
    string textlowercase(string text)
    {
        char low ='a';
        //by using for loop we go on every single latter in the text and
        //turn it into lower case.
        for (size_t i = 0; i < text.length(); i++)
        {
            low = text.at(i);//use as temp
            text.at(i) = tolower(low);//change the orignal latter into lower case one.
        }
        return text;
    }


    /**
    this metod is get char from two words and return true if equal
    we use this method as a helper method to define if two given chars are equal
    regardless if "curr" is lower or upper case.
    */
    bool upLowCaseCheck(char wrdChar, char curr)
    {
        return (curr == wrdChar || // Lower case
                (curr + 32) == wrdChar); // Upper case
    }


    /**
    this method is get two strings and check them
    by the rules of the assigment,
    if the words are match this func return 0 otherwise reutns -1.
    */
    int checkWord(string lword, string curr)
    {
        bool mistakeFound = false; // Flag to stop the loop if mistake found
        //by using for loop we are check every latter in the word and stop
        //the loop if we pass the all latters of if we find a mistake.
        for (int i = 0; i < lword.length() && !mistakeFound; i++)
        {
            switch (lword[i])//using switch case to check the words latter
                             //by the rules of the assigment.
            {
                case 'e':
                    mistakeFound = (!upLowCaseCheck('e', curr[i]));
                    break;

                case 't':
                    mistakeFound = (!phonetic::matchDT(curr[i]));
                    break;

                case 'a':
                    mistakeFound = (!upLowCaseCheck('a', curr[i]));
                    break;

                case 'o':
                    mistakeFound = (!phonetic::matchOU(curr[i]));
                    break;

                case 'i':
                    mistakeFound = (!phonetic::matchIY(curr[i]));
                    break;

                case 'n':
                    mistakeFound = (!upLowCaseCheck('n', curr[i]));
                    break;

                case 's':
                    mistakeFound = (!phonetic::matchSZ(curr[i]));
                    break;

                case 'h':
                    mistakeFound = (!upLowCaseCheck('h', curr[i]));
                    break;

                case 'r':
                    mistakeFound = (!upLowCaseCheck('r', curr[i]));
                    break;

                case 'd':
                    mistakeFound = (!phonetic::matchDT(curr[i]));
                    break;

                case 'l':
                    mistakeFound = (!upLowCaseCheck('l', curr[i]));
                    break;

                case 'c':
                    mistakeFound = (!phonetic::matchCKQ(curr[i]));
                    break;

                case 'u':
                    mistakeFound = (!phonetic::matchOU(curr[i]));
                    break;

                case 'm':
                    mistakeFound = (!upLowCaseCheck('m', curr[i]));
                    break;

                case 'w':
                    mistakeFound = (!phonetic::matchVW(curr[i]));
                    break;

                case 'f':
                    mistakeFound = (!phonetic::matchBFP(curr[i]));
                    break;

                case 'g':
                    mistakeFound = (!phonetic::matchGJ(curr[i]));
                    break;

                case 'y':
                    mistakeFound = (!phonetic::matchIY(curr[i]));
                    break;

                case 'p':
                    mistakeFound = (!phonetic::matchBFP(curr[i]));
                    break;

                case 'b':
                    mistakeFound = (!phonetic::matchBFP(curr[i]));
                    break;

                case 'v':
                    mistakeFound = (!phonetic::matchVW(curr[i]));
                    break;

                case 'k':
                    mistakeFound = (!phonetic::matchCKQ(curr[i]));
                    break;

                case 'j':
                    mistakeFound = (!phonetic::matchGJ(curr[i]));
                    break;

                case 'x':
                    mistakeFound = (!upLowCaseCheck('x', curr[i]));
                    break;

                case 'q':
                    mistakeFound = (!phonetic::matchCKQ(curr[i]));
                    break;

                case 'z':
                    mistakeFound = (!phonetic::matchSZ(curr[i]));
                    break;

                default:
                    string errorMessage3 = string("ERR:Illigal char '") +lword[i] + ("' in the word");
                    throw runtime_error(errorMessage3);

            }
        }
        if (mistakeFound)
            return -1;
        else
        {
            return 0;
        }
    }


    /**
    this method are compere betrween the commpared chear with the typo options we have.
    */
    bool matchVW(char compared)
    {
        return (
                (compared == 'w') ||
                (compared == 'W') ||
                (compared == 'v') ||
                (compared == 'V'));
    }
    bool matchSZ(char compared)
    {
        return (
                (compared == 's') ||
                (compared == 'S') ||
                (compared == 'z') ||
                (compared == 'Z'));
    }
    bool matchBFP(char compared)
    {
        return (
                (compared == 'f') ||
                (compared == 'F') ||
                (compared == 'p') ||
                (compared == 'P') ||
                (compared == 'b') ||
                (compared == 'B'));
    }
    bool matchCKQ(char compared)
    {
        return (
                (compared == 'c') ||
                (compared == 'C') ||
                (compared == 'k') ||
                (compared == 'K') ||
                (compared == 'q') ||
                (compared == 'Q'));
    }
    bool matchDT(char compared)
    {
        return (
                (compared == 't') ||
                (compared == 'T') ||
                (compared == 'd') ||
                (compared == 'D'));
    }
    bool matchIY(char compared)
    {
        return (
                (compared == 'i') ||
                (compared == 'I') ||
                (compared == 'y') ||
                (compared == 'Y'));
    }
    bool matchOU(char compared)
    {
        return (
                (compared == 'o') ||
                (compared == 'O') ||
                (compared == 'u') ||
                (compared == 'U'));
    }
    bool matchGJ(char compared)
    {
        return (
                (compared == 'g') ||
                (compared == 'G') ||
                (compared == 'j') ||
                (compared == 'J'));
    }



}

