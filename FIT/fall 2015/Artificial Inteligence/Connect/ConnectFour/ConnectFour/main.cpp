//
//  main.cpp
//  ConnectFour
//
//  Created by Danilo Mendes on 10/21/15.
//  Copyright (c) 2015 Danilo Mendes. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "connectFour.h"

enum {HUMAN = 0, COMPUTER = 1};

static void printb(int width, int height);

int main(int argc, const char * argv[]) {
 
    int players[2], levels[2], turn = 0, num_of_players, move;
    int width, height, num_to_connect;
    width = 7;
    height = 6;
    num_to_connect = 4;
    int x1, y1, x2, y2;
    char buffer[80];
    
    printf("Enter the number of human players (0 or 1): ");
    
    do{
        scanf("%d",&num_of_players);
    }while (num_of_players > 1 && num_of_players < 0);

    
    if (num_of_players) {

        players[0] = HUMAN;
        players[1] = COMPUTER;
        levels[1] = 10;
        
        char op;
        do {
            printf("Would you like to go first [y]? ");
            scanf(" %c",&op);
            fflush(stdin);
            op = tolower(op);
        } while (op != 'y' && op != 'n');
        
        turn = (op == 'n')? 1 : 0;

    }else{
        players[0] = players[1] = COMPUTER;
        levels[0] = levels[1] = 10;
        turn = 0;
    }
    

    c4_new_game(width, height, num_to_connect);
    
    do {
        printb(width, height);
        
        if (players[turn] == HUMAN) {
            
            do {
                printf("Drop in which column");
                do{
                    scanf("%d",&move);
                    move--;
                }while(move < 0 || move > width);
            
            }while (!c4_make_move(turn, move, NULL));
            
        }
        else {
            
            printf("Thinking.");
            
            fflush(stdout);
            c4_auto_move(turn, levels[turn], &move, NULL);
            
            if (num_of_players == 1)
                printf("\n\nI dropped my piece into column %d.\n", move+1);
            else
                printf("\n\nPlayer %c dropped its piece into column %d.\n",
                       piece[turn], move+1);
        }
        
        turn = !turn;
        
    } while (!c4_is_winner(0) && !c4_is_winner(1) && !c4_is_tie());
    
    printb(width, height);
    
    if (c4_is_winner(0)) {
        
        if (num_of_players == 1)
            printf("You won!");
        else
            printf("Player %c won!", piece[0]);
       
    }
    else if (c4_is_winner(1)) {
        
        if (num_of_players == 1)
            printf("I won!");
        else
            printf("Player %c won!", piece[1]);
        
    }
    else {
        printf("There was a tie!\n\n");
    }
    
    c4_end_game();
    return 0;
    
    
}

static void printb(int width, int height) {
    int x, y;
    char **board;
    
    board = c4_board();
    
    printf("\n");
    for (y=height-1; y>=0; y--) {
        
        printf("|");
        for (x=0; x<width; x++) {
            if (board[x][y] == C4_NONE){
                printf("   |")
            }else{
                int b = board[x][y];
                printf(" %c |",piece[b]);
            }
        }
        printf("\n");
        
        printf("+");
        for (x=0; x<width; x++)
            printf("---+");
        printf("\n");
    }
    
    printf(" ");
    for (x=0; x<width; x++)
        printf(" %d  ", x+1);
    if (width > 9) {
        printf("\n ");
        for (x=0; x<width; x++)
            printf("    ");
    }
    
    printf("\n\n");
}

