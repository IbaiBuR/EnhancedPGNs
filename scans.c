//
// Created by Ibai on 11/04/2023.
//

#include <stdio.h>
#include "types.h"

void scanDate(DATE *date)
{
    printf("\nIntroduce the date of the game (yy.mm.dd): ");
    scanf("%u.%u.%u", &date->year, &date->month, &date->day);
}

void scanDuration(DURATION *TotalGameDuration)
{
    printf("\nIntroduce the game duration of the game (hours:minutes:seconds): ");
    fflush(stdin);
    scanf("%u:%u:%u", &TotalGameDuration->hours, &TotalGameDuration->minutes, &TotalGameDuration->seconds);
}

void scanTC(TC *TimeControl)
{
    printf("\nIntroduce the increment used for the game: ");
    scanf("%u", &TimeControl->increment);
    scanDuration(&(TimeControl->time));
}

