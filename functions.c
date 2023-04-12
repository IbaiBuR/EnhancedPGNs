//
// Created by Ibai on 11/04/2023.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "types.h"

NODE * new(PGN *pgn, NODE *siguiente)
{
    NODE *node = (NODE*) malloc(sizeof(NODE));

    strncpy(node->pgn.event, pgn->event, LINES);
    strncpy(node->pgn.site, pgn->site, LINES);
    strncpy(node->pgn.white, pgn->white, LINES);
    strncpy(node->pgn.black, pgn->black, LINES);
    strncpy(node->pgn.opening, pgn->opening, LINES);

    strncpy(node->pgn.moves, pgn->moves, MAX_MOVES);
    strncpy(node->pgn.ECO_CODE, pgn->ECO_CODE, 4);

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


    node->sig = siguiente;

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

unsigned numElementos(ENHANCED_PGN *list)
{
    return list->numGames;
}

void deletePGN(ENHANCED_PGN *list, PGN *pgn)
{
    NODE *actual = list->start;
    NODE *anterior = NULL;

    while(actual && &actual->pgn != pgn)
    {
        anterior = actual;
        actual = actual->sig;
    }

    if(actual)
    {
        if(actual == list->start)
        {
            list->start = list->start->sig;
        }
        else
        {
            anterior->sig = actual->sig;
        }

        free(actual);
        list->numGames--;
    }
}

void insert(ENHANCED_PGN *list, PGN *pgn)
{
    NODE *create = new(pgn, NULL);

    if(isEmpty(list))
    {
        list->start = create;
    }
    else
    {
        NODE *actual = list->start;

        while(actual->sig)
        {
            actual = actual->sig;
        }

        actual->sig = create;
    }

    list->numGames++;
}

int getPosition(ENHANCED_PGN *list, PGN *pgn)
{
    NODE *actual = list->start;

    int position = 0;
    int result = -1;

    while(actual && &actual->pgn != pgn)
    {
        actual = actual->sig;
        position++;
    }

    if(actual)
    {
        result = position;
    }

    return result;
}

bool contains(ENHANCED_PGN *list, PGN *pgn)
{
    return getPosition(list, pgn) >= 0;
}





