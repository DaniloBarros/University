//
//  connectFour.h
//  ConnectFour
//
//  Created by Danilo Mendes on 10/21/15.
//  Copyright (c) 2015 Danilo Mendes. All rights reserved.
//

#ifndef ConnectFour_connectFour_h
#define ConnectFour_connectFour_h

#include <time.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <assert.h>

#define C4_NONE      2
#define C4_MAX_LEVEL 20

/* See the file "c4.c" for documentation on the following functions. */

#define other(x)        ((x) ^ 1)
#define real_player(x)  ((x) & 1)

#define pop_state() \
(current_state = &state_stack[--depth])

#define goodness_of(player) \
(current_state->score[player] - current_state->score[other(player)])

typedef struct {
    
    char **board;
    int *(score_array[2]);
    int score[2];
    short int winner; 
    int num_of_pieces;
    
} Game_state;

int size_x, size_y, total_size;
int num_to_connect;
int win_places;

int ***map;

int magic_win_number;
bool game_in_progress = false, move_in_progress = false;
clock_t poll_interval, next_poll;
Game_state state_stack[C4_MAX_LEVEL+1];
Game_state *current_state;
int depth;
int states_allocated = 0;
int *drop_order;

void c4_new_game(int width, int height, int num);
void update_score(int player, int x, int y);
bool c4_make_move(int player, int column, int *row);
int drop_piece(int player, int column);
bool c4_auto_move(int player, int level, int *column, int *row);
void push_state(void);

/*-------------------------------------------------*/

void c4_new_game(int width, int height, int num) {
    
    int i, j, k, x;
    int win_index, column;
    int *win_indices;
    
    size_x = width;
    size_y = height;
    total_size = width * height;
    num_to_connect = num;
    magic_win_number = 1 << num_to_connect;
    win_places = 69;//num_of_win_places(size_x, size_y, num_to_connect);
    
    srand((unsigned int)time(NULL));
    
    depth = 0;
    current_state = &state_stack[0];
    
    current_state->board = (char **) malloc(size_x * sizeof(char *));
    for (i=0; i<size_x; i++) {
        current_state->board[i] = (char *) malloc(size_y);
        for (j=0; j<size_y; j++)
            current_state->board[i][j] = C4_NONE;
    }
    
    current_state->score_array[0] = (int *) malloc(win_places * sizeof(int));
    current_state->score_array[1] = (int *) malloc(win_places * sizeof(int));
    for (i=0; i<win_places; i++) {
        current_state->score_array[0][i] = 1;
        current_state->score_array[1][i] = 1;
    }
    
    current_state->score[0] = current_state->score[1] = win_places;
    current_state->winner = C4_NONE;
    current_state->num_of_pieces = 0;
    
    states_allocated = 1;
    
    map = (int ***) malloc(size_x * sizeof(int **));
    for (i=0; i<size_x; i++) {
        map[i] = (int **) malloc(size_y * sizeof(int *));
        for (j=0; j<size_y; j++) {
            map[i][j] = (int *) malloc((num_to_connect*4 + 1) * sizeof(int));
            map[i][j][0] = -1;
        }
    }
    
    win_index = 0;
    
    /* Fill in the horizontal win positions */
    for (i=0; i<size_y; i++)
        for (j=0; j<size_x-num_to_connect+1; j++) {
            for (k=0; k<num_to_connect; k++) {
                win_indices = map[j+k][i];
                for (x=0; win_indices[x] != -1; x++)
                    ;
                win_indices[x++] = win_index;
                win_indices[x] = -1;
            }
            win_index++;
        }
    
    /* Fill in the vertical win positions */
    for (i=0; i<size_x; i++)
        for (j=0; j<size_y-num_to_connect+1; j++) {
            for (k=0; k<num_to_connect; k++) {
                win_indices = map[i][j+k];
                for (x=0; win_indices[x] != -1; x++)
                    ;
                win_indices[x++] = win_index;
                win_indices[x] = -1;
            }
            win_index++;
        }
    
    /* Fill in the forward diagonal win positions */
    for (i=0; i<size_y-num_to_connect+1; i++)
        for (j=0; j<size_x-num_to_connect+1; j++) {
            for (k=0; k<num_to_connect; k++) {
                win_indices = map[j+k][i+k];
                for (x=0; win_indices[x] != -1; x++)
                    ;
                win_indices[x++] = win_index;
                win_indices[x] = -1;
            }
            win_index++;
        }
    
    /* Fill in the backward diagonal win positions */
    for (i=0; i<size_y-num_to_connect+1; i++)
        for (j=size_x-1; j>=num_to_connect-1; j--) {
            for (k=0; k<num_to_connect; k++) {
                win_indices = map[j-k][i+k];
                for (x=0; win_indices[x] != -1; x++)
                    ;
                win_indices[x++] = win_index;
                win_indices[x] = -1;
            }
            win_index++;
        }
    
    for (int z=0; z<size_x; z++) {
        for (int i=0; i<size_y; i++) {
            for (int j=0; j<num_to_connect*4 + 1; j++) {
                printf("\t%d", map[z][i][j]);
            }printf("\n");
        }printf("\n\n");
    }

    drop_order = (int *) malloc(size_x * sizeof(int));
    column = (size_x-1) / 2;
    for (i=1; i<=size_x; i++) {
        drop_order[i-1] = column;
        column += ((i%2)? i : -i);
    }
    
    game_in_progress = true;
}


bool c4_make_move(int player, int column, int *row){
    
    if (column >= size_x || column < 0)
        return false;
    
    int result = drop_piece(real_player(player), column);
    if (row != NULL && result >= 0)
        *row = result;
    return (result >= 0);
}


bool c4_auto_move(int player, int level, int *column, int *row){
    int best_column = -1, goodness = 0, best_worst = -(INT_MAX);
    int num_of_equal = 0, real_player, current_column, result;
    
    real_player = real_player(player);
    
    if (current_state->num_of_pieces < 2 &&
        (current_state->num_of_pieces == 0 ||
         current_state->board[3][0] != C4_NONE)) {
            
            if (column != NULL)
                *column = 3;
            if (row != NULL)
                *row = current_state->num_of_pieces;
            drop_piece(real_player, 3);
            return true;
        }
    
    move_in_progress = true;
    
    for (int i=0; i<size_x; i++) {
        push_state();
        current_column = drop_order[i];
        
        result = drop_piece(real_player, current_column);
        
        /* If this column is full, ignore it as a possibility. */
        if (result < 0) {
            pop_state();
            continue;
        }
        
        /* If this drop wins the game, take it! */
        else if (current_state->winner == real_player) {
            best_column = current_column;
            pop_state();
            break;
        }
        
        /* Otherwise, look ahead to see how good this move may turn out */
        /* to be (assuming the opponent makes the best moves possible). */
        else {
            next_poll = clock() + poll_interval;
            goodness = evaluate(real_player, level, -(INT_MAX), -best_worst);
        }
        
        /* If this move looks better than the ones previously considered, */
        /* remember it.                                                   */
        if (goodness > best_worst) {
            best_worst = goodness;
            best_column = current_column;
            num_of_equal = 1;
        }
        
        /* If two moves are equally as good, make a random decision. */
        else if (goodness == best_worst) {
            num_of_equal++;
            if ((rand()>>4) % num_of_equal == 0)
                best_column = current_column;
        }
        
        pop_state();
    }
    
    move_in_progress = false;
    
    /* Drop the piece in the column decided upon. */
    
    if (best_column >= 0) {
        result = drop_piece(real_player, best_column);
        if (column != NULL)
            *column = best_column;
        if (row != NULL)
            *row = result;
        return true;
    }
    else
        return false;
}



int drop_piece(int player, int column){
    int y = 0;
    
    while (current_state->board[column][y] != C4_NONE && ++y < size_y)
        ;//find bottom
    
    if (y == size_y)
        return -1;
    
    current_state->board[column][y] = player;
    current_state->num_of_pieces++;
    update_score(player, column, y);
    
    return y;
}

void update_score(int player, int x, int y){
    int i;
    int win_index;
    int this_difference = 0, other_difference = 0;
    int **current_score_array = current_state->score_array;
    int other_player = other(player);
    
    for (i=0; map[x][y][i] != -1; i++) {
        win_index = map[x][y][i];
        this_difference += current_score_array[player][win_index];
        other_difference += current_score_array[other_player][win_index];
        
        current_score_array[player][win_index] <<= 1;
        current_score_array[other_player][win_index] = 0;
        
        if (current_score_array[player][win_index] == magic_win_number)
            if (current_state->winner == C4_NONE)
                current_state->winner = player;
    }
    
    current_state->score[player] += this_difference;
    current_state->score[other_player] -= other_difference;
}


int evaluate(int player, int level, int alpha, int beta) {
//    
//    if (poll_function != NULL && next_poll <= clock()) {
//        next_poll += poll_interval;
//        (*poll_function)();
//    }
    
    if (current_state->winner == player)
        return INT_MAX - depth;
    else if (current_state->winner == other(player))
        return -(INT_MAX - depth);
    else if (current_state->num_of_pieces == total_size)
        return 0; /* a tie */
    else if (level == depth)
        return goodness_of(player);
    else {
        /* Assume it is the other player's turn. */
        int best = -(INT_MAX);
        int maxab = alpha;
        for(int i=0; i<size_x; i++) {
            if (current_state->board[drop_order[i]][size_y-1] != C4_NONE)
                continue; /* The column is full. */
            push_state();
            drop_piece(other(player), drop_order[i]);
            int goodness = evaluate(other(player), level, -beta, -maxab);
            if (goodness > best) {
                best = goodness;
                if (best > maxab)
                    maxab = best;
            }
            pop_state();
            if (best > beta)
                break;
        }
        
        /* What's good for the other player is bad for this one. */
        return -best;
    }
}



void push_state(void){
    int i, win_places_array_size;
    Game_state *old_state, *new_state;
    
    win_places_array_size = win_places * sizeof(int);
    old_state = &state_stack[depth++];
    new_state = &state_stack[depth];
    
    if (depth == states_allocated) {
        
        /* Allocate space for the board */
        
        new_state->board = (char **) malloc(size_x * sizeof(char *));
        for (i=0; i<size_x; i++)
            new_state->board[i] = (char *) malloc(size_y);
        
        /* Allocate space for the score array */
        
        new_state->score_array[0] = (int *) malloc(win_places_array_size);
        new_state->score_array[1] = (int *) malloc(win_places_array_size);
        
        states_allocated++;
    }
    
    /* Copy the board */
    
    for (i=0; i<size_x; i++)
        memcpy(new_state->board[i], old_state->board[i], size_y);
    
    /* Copy the score array */
    
    memcpy(new_state->score_array[0], old_state->score_array[0],
           win_places_array_size);
    memcpy(new_state->score_array[1], old_state->score_array[1],
           win_places_array_size);
    
    new_state->score[0] = old_state->score[0];
    new_state->score[1] = old_state->score[1];
    new_state->winner = old_state->winner;
    new_state->num_of_pieces = old_state->num_of_pieces;
    
    current_state = new_state;
}




#endif
