#include "tennis_game_2.h"
#include <string.h>
#include <stdlib.h>
#include <math.h>

tennis_game_2_t create_tennis_game_2(const char *player1_name, const char *player2_name)
{
    tennis_game_2_t result;

    strcpy(result.player1_name, player1_name);
    strcpy(result.player2_name, player2_name);
    result.player1_result = "";
    result.player2_result = "";
    result.player1_point = 0;
    result.player2_point = 0;

    return result;
}

void won_point_2(tennis_game_2_t *tennis_game, const char *player_name)
{
    if (strcmp(tennis_game->player1_name, player_name) == 0) {
        tennis_game->player1_point++;
    } else {
        tennis_game->player2_point++;
    }
}

const char *get_score_2(tennis_game_2_t *tennis_game)
{
    char *score = (char *) calloc(20, sizeof(char));

    if (tennis_game->player1_point == tennis_game->player2_point) {
        if (tennis_game->player1_point == 0)
            strcpy(score, "Love-All");
        if (tennis_game->player1_point == 1)
            strcpy(score, "Fifteen-All");
        if (tennis_game->player1_point == 2)
            strcpy(score, "Thirty-All");
        if (tennis_game->player1_point == 3)
            strcpy(score, "Forty-All");
        if (tennis_game->player1_point >= 4)
            strcpy(score, "Deuce");

        return score;

    }

    if (tennis_game->player2_point != tennis_game->player1_point && tennis_game->player1_point < 4 && tennis_game->player2_point < 4) {
        if (tennis_game->player1_point == 0)
            tennis_game->player1_result = "Love";
        if (tennis_game->player1_point == 1)
            tennis_game->player1_result = "Fifteen";
        if (tennis_game->player1_point == 2)
            tennis_game->player1_result = "Thirty";
        if (tennis_game->player1_point == 3)
            tennis_game->player1_result = "Forty";
        if (tennis_game->player2_point == 0)
            tennis_game->player2_result = "Love";
        if (tennis_game->player2_point == 1)
            tennis_game->player2_result = "Fifteen";
        if (tennis_game->player2_point == 2)
            tennis_game->player2_result = "Thirty";
        if (tennis_game->player2_point == 3)
            tennis_game->player2_result = "Forty";

        strcpy(score, tennis_game->player1_result);
        strcat(score, "-");
        strcat(score, tennis_game->player2_result);
        return score;
    }

    int score_diff = abs(tennis_game->player1_point - tennis_game->player2_point);

    if (score_diff >=2) {
        if (tennis_game->player1_point > tennis_game->player2_point) {
            strcpy(score, "Win for player1");
        } else {
            strcpy(score, "Win for player2");
        }
    } else {
        if (tennis_game->player1_point > tennis_game->player2_point) {
            strcpy(score, "Advantage player1");
        } else {
            strcpy(score, "Advantage player2");
        }
    }

    return score;
}