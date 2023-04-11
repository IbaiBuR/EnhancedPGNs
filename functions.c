//
// Created by Ibai on 11/04/2023.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stdbool.h"
#include "types.h"


NODE *new(PGN *pgn)
{
    NODE *node = (NODE*)malloc(sizeof(NODE));

    strncpy(node->pgn.event, pgn->event, LINES);
    strncpy(node->pgn.site, pgn->site, LINES);
    strncpy(node->pgn.white, pgn->white, LINES);
    strncpy(node->pgn.black, pgn->black, LINES);
    strncpy(node->pgn.opening, pgn->opening, LINES);

    strncpy(node->pgn.moves, pgn->moves, MAX_MOVES);
    strncpy(node->pgn.ECO_CODE, pgn->ECO_CODE, 3);

    node->pgn.round = pgn->round;
    node->pgn.plycount = pgn->plycount;

    node->pgn.date.year = pgn->date.year;
    node->pgn.date.month = pgn->date.month;
    node->pgn.date.day = pgn->date.day;

    node->pgn.TotalGameDuration.hours = pgn->TotalGameDuration.hours;
    node->pgn.TotalGameDuration.minutes = pgn->TotalGameDuration.minutes;
    node->pgn.TotalGameDuration.seconds = pgn->TotalGameDuration.seconds;

    node->pgn.TimeControl.time = pgn->TimeControl.time;
    node->pgn.TimeControl.increment = pgn->TimeControl.increment;


    node->sig = NULL;

    return node;
}

bool isEmpty(ENHANCED_PGN *list)
{
    return list->start == NULL;
}

void initList(ENHANCED_PGN *list)
{
    list->start = NULL;
    list->numGames = 0;
}

