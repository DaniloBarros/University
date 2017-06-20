//
//  tweet_decoder.cpp
//  Assigment3
//
//  Created by Danilo Mendes on 2/1/16.
//  dbarrosmende2015@my.fit.edu
//  Copyright © 2016 Danilo Mendes. All rights reserved.
//

/*
 
 Prompt user for tweet
 Get tweet from user
 Check if the tweet is equal to LOL, BFN, FTW, IRL,
 B4, BTW, BR, EM, F2F, YOYO or other
 If is any of the described tweet prompt the translation
 
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    
    string origTweet;
    cout << "Enter abbreviation from tweet: " << endl;
    cin >> origTweet;
    
    if (origTweet == "LOL")
        cout << "LOL = laughing out loud" << endl;
    else if (origTweet == "BFN")
        cout << "BFN = bye for now" << endl;
    else if (origTweet == "FTW")
        cout << "FTW = for the win" << endl;
    else if (origTweet == "IRL")
        cout << "IRL = in real life" << endl;
    
    else if(origTweet == "B4")
        cout << "B4 = Before"<<endl;
    else if(origTweet == "BTW")
        cout << "BTW = By the way" << endl;
    else if(origTweet == "BR")
        cout << "BR = Best regards" << endl;
    else if(origTweet == "EM")
        cout << "EM = e-mail" << endl;
    else if(origTweet == "F2F")
        cout << "F2F = face to face" << endl;
    else if(origTweet == "YOYO")
        cout << "YOYO = You're on your own" << endl;
    else
        cout << "Sorry, don't know that one." << endl;
 
    return 0;
}