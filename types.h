//
// Created by Ibai on 10/04/2023.
//


#ifndef ENHACEDPGNS_TYPES_H
#define ENHACEDPGNS_TYPES_H
 #define MAX_MOVES 4096
 #define LINES 1024

 //Required data structures to handle PGN files

 typedef  struct DATE
 {
    unsigned day, month, year;
 } DATE;

 typedef struct DURATION
 {
     unsigned hours, minutes, seconds;
 } DURATION;

 typedef struct TC
 {
     DURATION time;
     unsigned increment;
 } TC;

 typedef struct PGN
 {
    char event[LINES], site[LINES], white[LINES], black[LINES], opening [LINES];
    char moves[MAX_MOVES];

    char ECO_CODE[4];
    unsigned round, plycount;

    DATE date;
    DURATION TotalGameDuration;
    TC TimeControl;
 } PGN;

 typedef struct NODE
 {
     PGN pgn;
     struct NODE *sig;
 } NODE;

 typedef struct ENHANCED_PGN
 {
     NODE *start;
     unsigned  numGames;
 } ENHANCED_PGN;

 //Functions to scan durations and times

 void scanDate(DATE * );
 void scanDuration(DURATION * );
 void scanTC(TC * );

 //Functions to handle with PGN files using enhanced lists

 NODE *new(PGN * );
 bool isEmpty(ENHANCED_PGN * );
 void initList(ENHANCED_PGN * );

#endif //ENHACEDPGNS_TYPES_H
