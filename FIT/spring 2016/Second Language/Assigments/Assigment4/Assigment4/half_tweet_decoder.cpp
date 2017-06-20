//
//  half_tweet_decoder.cpp
//  Assigment4
//
//  Created by Danilo Mendes on 2/8/16.
//  dbarrosmende2015@my.fit.edu
//  Copyright © 2016 Danilo Mendes. All rights reserved.
//

/*
 
 Prompt user for tweet
 Get tweet from user
 Check if the tweet has the abreviations: LOL, BFN, FTW, IRL,
 B4, BTW, BR, EM, F2F, YOYO
 If it has any of the described tweet prompt the translation
 If not prompt an error
 
 */
#include <iostream>
#include <string>

#define TWEET_SIZE 141

using namespace std;

int main() {
    
    char origTweet[TWEET_SIZE];
    int count = 0;
    
    cout << "Enter tweet: " << endl;
    cin.getline(origTweet, TWEET_SIZE);
    
    
    if (strstr(origTweet, "LOL")){
        cout << "LOL = laughing out loud" << endl;
        count++;
    }
    if (strstr(origTweet, "BFN")){
        cout << "BFN = bye for now" << endl;
        count++;
    }
    if (strstr(origTweet, "FTW")){
        cout << "FTW = for the win" << endl;
        count++;
    }
    if (strstr(origTweet, "IRL")){
        cout << "IRL = in real life" << endl;
        count++;
    }
    if(strstr(origTweet, "B4")){
        cout << "B4 = Before"<<endl;
        count++;
    }
    if(strstr(origTweet, "BTW")){
        cout << "BTW = By the way" << endl;
        count++;
    }
    if(strstr(origTweet, "BR")){
        cout << "BR = Best regards" << endl;
        count++;
    }
    if(strstr(origTweet, "EM")){
        cout << "EM = e-mail" << endl;
        count++;
    }
    if(strstr(origTweet, "F2F")){
        cout << "F2F = face to face" << endl;
        count++;
    }
    if(strstr(origTweet, "YOYO")){
        cout << "YOYO = You're on your own" << endl;
        count++;
    }
    if(!count)
        cout << "Sorry, don't know that one." << endl;
    
    return 0;
}