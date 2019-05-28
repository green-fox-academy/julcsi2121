#include "tennis_game_3.h"
#include <string.h>
#include <stdlib.h>

tennis_game_3_t create_tennis_game_3(const char *player1_name, const char *player2_name)
{
    tennis_game_3_t result;
    result.player1_score = 0;
    result.player2_score = 0;
    result.player1_name = (char*)calloc(strlen(player1_name) + 1, sizeof(char));
    result.player2_name = (char*)calloc(strlen(player2_name) + 1, sizeof(char));
    strcpy(result.player1_name, player1_name);
    strcpy(result.player2_name, player2_name);
    return result;
}

void won_point_3(tennis_game_3_t *tennis_game, const char *player_name)
{
    strcmp(player_name, tennis_game->player1_name) ? tennis_game->player2_score++ : tennis_game->player1_score++;
}

const char * get_score_3(tennis_game_3_t *tennis_game)
{
    char *score;

    if (tennis_game->player1_score < 4 && tennis_game->player2_score < 4) {
        static const char *point_names[] = {"Love", "Fifteen", "Thirty", "Forty"};
        char temp_score[20];
        strcpy(temp_score, point_names[tennis_game->player1_score]);

        if (tennis_game->player1_score == tennis_game->player2_score) {
            strcat(temp_score, "-All");
        } else {
            strcat(temp_score, "-");
            strcat(temp_score, point_names[tennis_game->player2_score]);
        }

        score = calloc(strlen(temp_score) + 1, sizeof(char));
        strcpy(score, temp_score);
        return score;
    } else {
        if (tennis_game->player1_score == tennis_game->player2_score)
            return "Deuce";

        char ts[20];
        (tennis_game->player1_score > tennis_game->player2_score) ? strcpy(ts, tennis_game->player1_name) : strcpy(ts, tennis_game->player2_name);

        char ts2[15];
        ((tennis_game->player1_score - tennis_game->player2_score) * (tennis_game->player1_score - tennis_game->player2_score) == 1) ? strcpy(ts2, "Advantage ") : strcpy(ts2, "Win for ");

        score = calloc(strlen(ts) + strlen(ts2) + 1, sizeof(char));
        strcpy(score, ts2);
        strcat(score, ts);
        return score;
    }
}

