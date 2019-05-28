//
// Created by Varga Júlia on 2019-05-27.
//

#ifndef APPLES_TENNIS_GAME_3_H
#define APPLES_TENNIS_GAME_3_H

typedef struct
{
    int player1_score;
    int player2_score;
    char *player1_name;
    char *player2_name;
} tennis_game_3_t;

tennis_game_3_t create_tennis_game_3(const char *player1_name, const char *player2_name);
void won_point_3(tennis_game_3_t *tennis_game, const char *player_name);
const char * get_score_3(tennis_game_3_t *tennis_game);

#endif //APPLES_TENNIS_GAME_3_H
