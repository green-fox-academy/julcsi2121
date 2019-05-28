//
// Created by Varga Júlia on 2019-05-27.
//

#ifndef APPLES_TENNIS_GAME_2_H
#define APPLES_TENNIS_GAME_2_H

typedef struct {
    int player1_point;
    int player2_point;
    char *player1_result;
    char *player2_result;
    char player1_name[30];
    char player2_name[30];
} tennis_game_2_t;


tennis_game_2_t create_tennis_game_2(const char *player1_name, const char *player2_name);

void won_point_2(tennis_game_2_t *tennis_game, const char *player_name);

const char *get_score_2(tennis_game_2_t *tennis_game);

#endif //APPLES_TENNIS_GAME_2_H
