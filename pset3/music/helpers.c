// Helper functions for music

#include <cs50.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int a = fraction[0] - '0' ;
    int b = fraction[2] - '0' ;
    return (8 / b) * a ;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    int octave = 0 , acc = 0 , letterlen = 0;
    char letter = 'A' ;
    if (strlen(note) == 2)
    {
        octave = note[1] - '0';
        letter = note[0] ;
        acc = 0 ;
    }
    else if (strlen(note) == 3)
    {
        octave = note[2] - '0';
        letter = note[0] ;
        if ( note[1] == '#' ) acc = 1 ;
        else acc = -1 ;
    }
    octave -= 4 ;
    switch (letter)
    {
        case 'A' :
            letterlen = 0 ;
            break ;
        case 'B' :
            letterlen = 2 ;
            break ;
        case 'G' :
            letterlen = -2 ;
            break ;
        case 'F' :
            letterlen = -4 ;
            break ;
        case 'E' :
            letterlen = -5 ;
            break ;
        case 'D' :
            letterlen = -7 ;
            break ;
        case 'C' :
            letterlen = -9 ;
            break ;
    }
    float freq =  440 * pow(2, octave) * pow(2 , ( letterlen + acc ) / 12.0) ;
    return round(freq) ;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (strcmp(s , "") == 0) return true ;
    else return false ;
}
