//
//  full_tweet_decoder.cpp
//  Assigment5
//
//  Created by Danilo Mendes on 2/11/16.
//  dbarrosmende2015@my.fit.edu
//  Copyright © 2016 Danilo Mendes. All rights reserved.
//

/*
 Prompt user for tweet
 Get tweet from user
 Check if it is less than 140 characters
 Search for the abreviations: LOL, BFN, FTW, IRL,
 B4, BTW, BR, EM, F2F, YOYO
 If it has any of the described tweet substitute the tweet
    for its translation
 Prompt the tranlated string for the user
 */

#include <iostream>
#include <string>

#define TWEET_SIZE 141
#define TWEETS 10
using namespace std;

void replaceAll(string& origStr, const string& abbreviation, const string& tweet) {
    
    if(abbreviation.empty() || origStr.empty())
        return;
    
    size_t start_pos = 0;
    
    while((start_pos = origStr.find(abbreviation, start_pos)) != string::npos) {
        origStr.replace(start_pos, abbreviation.length(), tweet);
        start_pos += tweet.length();
    }
    
}

int main(int argc, const char * argv[]) {
    
    string orig;
    string tweetsAbb[TWEETS] = {"LOL", "BFN", "FTW", "IRL", "B4", "BTW", "BR", "EM", "F2F", "YOYO"};
    string tweetsFull[TWEETS] = {"laughing out loud", "bye for now", "for the win", "in real life",
        "Before", "By the way", "Best regards", "e-mail", "face to face", "You're on your own"};
    
    char op;
    
    do{
        
        cout << "Enter tweet (Less than 140 characters): " << endl;
        getline(cin, orig);
        
        while(orig.length() >= TWEET_SIZE){
            
            cout << "Sorry! Tweet too long. Enter less than 140 characters." << endl;
            getline(cin, orig);
            
        }
        for(int i = 0; i < TWEETS; i++){
            replaceAll(orig, tweetsAbb[i], tweetsFull[i]);
        }
        
        cout << "Decoded tweet: "  << orig << endl;
        cout << "Want to continue? (Y/N): ";
        scanf(" %c", &op);
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
        
    }while(op != 'N');
    
    return 0;
}
