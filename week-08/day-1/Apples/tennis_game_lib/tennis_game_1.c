#include "tennis_game_1.h"
#include <string.h>
#include <stdlib.h>


//const kell?
tennis_game_1_t create_tennis_game_1(const char *player1_name, const char *player2_name) {
    tennis_game_1_t result;

    result.player1_name = player1_name;
    result.player2_name = player2_name;
    result.score1 = 0;
    result.score2 = 0;

    return result;
}

void won_point_1(tennis_game_1_t *tennis_game, const char *player_name) {
    if (player_name == tennis_game->player1_name) {
        tennis_game->score1++;
    } else {
        tennis_game->score2++;
    }
}

char *get_score_1(tennis_game_1_t *tennis_game) {
    char *score = (char *) calloc(20, sizeof(char));
    if (tennis_game->score1 == tennis_game->score2) {
        switch (tennis_game->score1) {
            case 0:
                strcat(score, "Love-All");
                break;
            case 1:
                strcat(score, "Fifteen-All");
                break;
            case 2:
                strcat(score, "Thirty-All");
                break;
            case 3:
                strcat(score, "Forty-All");
                break;
            case 4:
                strcat(score, "Deuce");
                break;

        }
    } else if (tennis_game->score1 >= 4 || tennis_game->score2 >= 4) {
        int score_diff = tennis_game->score1 - tennis_game->score2;

        //if kifejezés egész logikája jó így?
        if (score_diff == 1) {
            strcat(score, "Advantage player1");
        } else if (score_diff == -1) {
            strcat(score, "Advantage player2");
        } else if (score_diff >= 2) {
            strcat(score, "Win for player1");
        } else {
            strcat(score, "Win for player2");
        }
    } else {
        int temp_score = 0;
        for (int i = 0; i < 2; i++) {
            if (i == 0) {
                temp_score = tennis_game->score1;
            } else {
                strcat(score, "-");
                temp_score = tennis_game->score2;
            }

            switch (temp_score) {
                case 0:
                    strcat(score, "Love");
                    break;
                case 1:
                    strcat(score, "Fifteen");
                    break;
                case 2:
                    strcat(score, "Thirty");
                    break;
                case 3:
                    strcat(score, "Forty");
                    break;
            }
        }
    }
    return score;
}