/*
 
 0 -> libre
 1 -> mur
 2 -> brick
 
 
 
 
 0  - Top Left      -> 1
 1  - Top Right     -> 1
 2  - Top 1         -> 1
 3  - Top 2         -> 1
 4  - Top 3         -> 1
 
 5  - Bottom Left   -> 1
 6  - Bottom Right  -> 1
 7  - Bottom 1      -> 1
 8  - Bottom 2      -> 1
 9  - Bottom 3      -> 1
 
 10 - Left 1        -> 1
 11 - Left 2        -> 1
 12 - Left 3        -> 1
 13 - Right 1       -> 1
 14 - Right 2       -> 1
 
 15 - Right 3       -> 1
 16 - Wall 1        -> 1
 17 - Wall 2 (inv)  -> 1
 18 - Ground        -> 1
 19 - Ground Sh1    -> 1
 
 20 - Ground Sh2    -> 1
 21 - Bricks        -> 2
 22 - Blow 1        -> 2
 23 - Blow 2        -> 2
 24 - Blow 3        -> 2
 
 25 - Blow 4        -> 2
 26 - Blow 5        -> 2
 27 - Blow 6        -> 2
 28 - Ext Ground 1  -> 0
 29 - Ext Ground 2  -> 0
 
 31 - Ext Ground 3  -> 0
 31 - Ext Ground 4  -> 0
 32 - Ext Ground 5  -> 0
 33 - Ext Ground 6  -> 0
 34 - Ext Ground 7  -> 0
 35 - Ext Ground 8  -> 0
 
 36 - Ext Ground 9  -> 0
 37 - Ext Ground 10 -> 0
 
 */

const static int level[9][21][35]=
{
    {//classique
        {  0,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  1},
        { 10, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 13},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 13},
        { 10, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 13},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 13},
        { 10, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 13},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 13},
        { 10, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 13},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 13},
        { 10, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20 ,18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 13},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 13},
        { 10, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 13},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 13},
        { 10, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 13},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 13},
        { 10, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 13},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 13},
        { 10, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 13},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 13},
        { 10, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 13},
        { 5,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  6}
    },
    {
        {  0,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  1},
        { 10, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 13},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 13},
        { 10, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 13},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 13},
        { 10, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 13},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 13},
        { 10, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 13},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 13},
        { 10, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20 ,18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 13},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 13},
        { 10, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 13},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 13},
        { 10, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 13},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 13},
        { 10, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 13},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 13},
        { 10, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 13},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 13},
        { 10, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 13},
        { 5,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  6}
    },
    {//underwater
        {  0,  2,  2,  2,  2,  2,  3, 18,  4,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  3, 18,  4,  2,  2,  2,  2,  2,  1},
        { 10, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 13},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 13},
        { 10, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 13},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 13},
        { 10, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 13},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 13},
        { 10, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 13},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 13},
        { 10, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20 ,18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 13},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 13},
        { 10, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 13},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 13},
        { 10, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 13},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 13},
        { 10, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 13},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 13},
        { 10, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 13},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 13},
        { 10, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 13},
        { 5,  7,  7,  7,  7,  7,  8,  18,  9,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  8, 18,  9,  7,  7,  7,  7,  7,  6}
    },
    {
        {  0,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  1},
        { 10, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 13},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 13},
        { 10, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 13},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 13},
        { 10, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 13},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 13},
        { 10, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 13},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 13},
        { 10, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20 ,18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 13},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 13},
        { 10, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 13},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 13},
        { 10, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 13},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 13},
        { 10, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 13},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 13},
        { 10, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 13},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 13},
        { 10, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 13},
        {  5,  7,  8,  7,  8,  7,  8,  7,  8,  7,  8,  7,  8,  7,  8,  7,  8,  7,  8,  7,  8,  7,  8,  7,  8,  7,  8,  7,  8,  7,  8,  7,  8,  7,  8}
    },
    { //snow
        {  0,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  1},
        { 11, 19, 19, 19, 19, 19, 19, 18, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 19, 19, 19, 19, 19, 19, 14},
        { 10, 18, 16, 18, 16, 18, 16, 18, 17, 18, 17, 18, 16, 18, 16, 18, 17, 18, 17, 18, 16, 18, 16, 18, 17, 18, 17, 18, 16, 18, 16, 18, 16, 18, 13},
        { 11, 18, 20, 18, 20, 18, 20, 18, 20, 40, 20, 18, 20, 18, 20, 18, 20, 40, 20, 18, 20, 18, 20, 18, 20, 40, 20, 18, 20, 18, 20, 18, 20, 18, 14},
        { 10, 18, 16, 18, 16, 18, 16, 18, 17, 18, 17, 18, 16, 18, 16, 18, 17, 18, 17, 18, 16, 18, 16, 18, 17, 18, 17, 18, 16, 18, 16, 18, 16, 18, 13},
        { 11, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 18, 18, 14},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 13},
        { 11, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 14},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 17, 18, 17, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 13},
        { 11, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 40, 20 ,18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 14},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 17, 18, 17, 18, 16, 18, 16, 18, 17, 18, 17, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 13},
        { 11, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 40, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 14},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 17, 18, 17, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 13},
        { 11, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 14},
        { 10, 18, 16, 18, 17, 18, 17, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 17, 18, 17, 18, 16, 18, 16, 18, 13},
        { 11, 18, 20, 18, 20, 40, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 40, 20, 18, 20, 18, 20, 18, 14},
        { 10, 18, 16, 18, 17, 18, 17, 18, 16, 18, 16, 18, 16, 18, 16, 18, 17, 18, 17, 18, 16, 18, 16, 18, 16, 18, 17, 18, 17, 18, 16, 18, 16, 18, 13},
        { 11, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 40, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 14},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 17, 18, 17, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 13},
        { 11, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 14},
        { 5,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  6}
    },
    {
        {  0,  2,  2,  2,  2,  2,  3, 19,  4,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  3, 19,  4,  2,  2,  2,  2,  2,  1},
        { 11, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 14},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 13},
        { 11, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 14},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 13},
        { 11, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 14},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 13},
        { 11, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 14},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 13},
        { 11, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18 ,18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 14},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 13},
        { 11, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 14},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 13},
        { 11, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 14},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 13},
        { 11, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 14},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 13},
        { 11, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 14},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 13},
        { 11, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 14},
        {  5,  9,  7,  8,  9,  7,  8, 20,  9,  7,  8,  9,  7,  8,  9,  7,  8,  9,  7,  8,  9,  7,  8,  9,  7,  8,  8, 20,  9,  7,  8,  9,  7,  8,  6}
    },
    {
        {  0,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  1},
        { 10, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 13},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 13},
        { 10, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 13},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 13},
        { 10, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 13},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 13},
        { 10, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 13},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 13},
        { 10, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20 ,18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 13},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 13},
        { 10, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 13},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 13},
        { 10, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 13},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 13},
        { 10, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 13},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 13},
        { 10, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 13},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 13},
        { 10, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 13},
        { 5,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  6}
    },
    {
        {  0,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  1},
        { 10, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 13},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 13},
        { 10, 18, 18, 18, 18, 30, 31, 31, 31, 29, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 30, 31, 29, 18, 18, 18, 18, 18, 18, 18, 18, 13},
        { 10, 18, 16, 18, 16, 33, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 33, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 13},
        { 10, 18, 18, 30, 31, 34, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 30, 31, 34, 18, 18, 18, 18, 18, 18, 28, 32, 18, 18, 13},
        { 10, 18, 16, 33, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 33, 16, 18, 16, 18, 16, 18, 16, 18, 16, 33, 16, 18, 13},
        { 10, 18, 18, 33, 18, 18, 18, 30, 31, 31, 31, 32, 18, 18, 18, 18, 18, 18, 18, 18, 18, 35, 31, 32, 18, 18, 18, 18, 18, 18, 18, 33, 18, 18, 13},
        { 10, 18, 16, 33, 16, 18, 16, 33, 16, 18, 16, 33, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 33, 16, 18, 16, 18, 16, 18, 16, 33, 16, 18, 13},
        { 10, 18, 18, 35, 31, 31, 31, 34, 18, 18, 28, 34, 18, 18, 18, 18, 18, 28, 31, 31, 31, 32, 18 ,35, 31, 32, 18, 18, 18, 30, 31, 34, 18, 18, 13},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 33, 16, 18, 16, 33, 16, 18, 16, 33, 16, 18, 16, 18, 13},
        { 10, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 30, 31, 29, 18, 18, 18, 18, 18, 18, 18, 35, 31, 31, 31, 34, 18, 18, 28, 34, 18, 18, 18, 18, 13},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 33, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 13},
        { 10, 18, 18, 18, 18, 18, 18, 18, 18, 28, 31, 34, 18, 30, 29, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 13},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 33, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 13},
        { 10, 18, 18, 18, 28, 32, 18, 18, 18, 18, 18, 18, 18, 33, 18, 18, 18, 18, 18, 28, 31, 31, 31, 32, 18, 18, 18, 18, 18, 30, 31, 29, 18, 18, 13},
        { 10, 18, 16, 18, 16, 33, 16, 18, 16, 18, 16, 18, 16, 33, 16, 18, 16, 18, 16, 18, 16, 18, 16, 33, 16, 18, 16, 18, 16, 33, 16, 18, 16, 18, 13},
        { 10, 18, 18, 18, 18, 35, 31, 31, 31, 32, 18, 30, 31, 34, 18, 18, 18, 18, 18, 18, 18, 18, 18, 35, 31, 31, 31, 32, 18, 33, 18, 18, 18, 18, 13},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 33, 16, 33, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 33, 16, 33, 16, 18, 16, 18, 13},
        { 10, 18, 18, 18, 18, 18, 18, 18, 18, 35, 31, 34, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 35, 31, 34, 18, 18, 18, 18, 13},
        { 5,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  6}
    },
    { //water
        {  0,  2,  2,  2,  2,  2,  3, 18,  4,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  3, 18,  4,  2,  2,  2,  2,  2,  1},
        { 11, 19, 19, 19, 19, 19, 19, 18, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 19, 19, 19, 19, 19, 19, 13},
        { 11, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 14},
        { 10, 18, 20, 18, 20, 18, 20, 18, 20, 40, 20, 18, 20, 18, 20, 18, 20, 40, 20, 18, 20, 18, 20, 18, 20, 40, 20, 18, 20, 18, 20, 18, 20, 18, 13},
        { 11, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 13},
        { 11, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 18, 18, 15},
        { 11, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 13},
        { 10, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 14},
        { 11, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 15},
        { 11, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 40, 20, 18, 20, 18, 20, 18, 20, 40, 20 ,18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 13},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 14},
        { 10, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 40, 20, 18, 20, 18, 20, 18, 20, 40, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 13},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 14},
        { 11, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 15},
        { 11, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 15},
        { 10, 18, 20, 18, 20, 40, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 40, 20, 18, 20, 18, 20, 18, 13},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 14},
        { 11, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 40, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 13},
        { 10, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 16, 18, 15},
        { 10, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 20, 18, 13},
        { 5,  7,  6,   6,  5,  7,  8, 18,  9,  7,  6,  6,  7,  7,  5,  7,  7,  5,  6,  6,  6,  7,  7,  5,  7,  7,  8, 18,  9,  7,  6,  6,  7,  5,  6}
    }
};


const int reservedSpot[21][35] ={
    {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
    {  0,  2,  1,  0,  0,  0,  0,  0,  0,  0,  1,  2,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  2,  1,  0,  0,  0,  0,  0,  0,  0,  1,  2,  0},
    {  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0},
    {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
    {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
    {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
    {  0,  0,  0,  0,  0,  0,  0,  2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,  0,  0,  0,  0,  0,  0,  0},
    {  0,  0,  0,  0,  0,  0,  1,  1,  1,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  0,  0,  0,  0,  0,  0},
    {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
    {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  0},
    {  0,  2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,  0},
    {  0,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
    {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
    {  0,  0,  0,  0,  0,  0,  1,  1,  1,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  0,  0,  0,  0,  0,  0},
    {  0,  0,  0,  0,  0,  0,  0,  2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,  0,  0,  0,  0,  0,  0,  0},
    {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
    {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
    {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
    {  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0},
    {  0,  2,  1,  0,  0,  0,  0,  0,  0,  0,  1,  2,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  2,  1,  0,  0,  0,  0,  0,  0,  0,  1,  2,  0},
    {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0}
};


const float startPlayer[16][2] = {
    {  1.5,  1.5},
    { 11.5,  1.5},
    { 23.5,  1.5},
    { 33.5,  1.5},
    {  7.5,  7.5},
    { 17.5,  6.5},
    { 27.5,  6.5},
    {  1.5,  10.5},
    { 33.5, 10.5},
    {  7.5, 14.5},
    { 17.5, 14.5},
    { 27.5, 14.5},
    {  1.5, 19.5},
    { 11.5, 19.5},
    { 23.5, 19.5},
    { 33.5, 19.5}
};

/*
	deathBonus		= 0,
	rollerBonus		= 1,
	fireBonus		= 2,
	fireMaxBonus	= 3,
	bombeBonus		= 4,
	radioBombeBonus	= 5,
	kickBonus		= 6,
	gloveBonus		= 7,
	bubbleBonus		= 8,
	powerBombeBonus	= 9,
	getaBonus		= 10,
	ghostBonus		= 11,
	eggsBonus		= 12,
*/

const int bonusByLevel[9][13]={
	//{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  90,  90,  0},
	{  3, 12, 18,  0, 18,  0, 12,  0,  0,  0,  0,  0, 15},
	{  3,  6, 15,  0, 18,  3,  9,  6,  6,  0,  0,  0, 15},
	{  3, 12, 18,  0, 18,  0,  6,  0,  0,  0,  0,  0, 15},
	{  3, 12, 18,  0, 18,  0,  6,  0,  6,  0,  0,  0, 15},
	{  3,  6, 18,  0, 18,  0,  6,  6,  0,  0,  0,  0, 15},
	{  3, 12, 18,  0, 18,  0, 18,  0,  0,  0,  0,  0, 15},
	{  3,  6, 18,  0, 18,  3,  9,  0,  6,  0,  0,  0, 15},
	{  3, 12, 18,  0, 18,  0,  6,  6,  3,  0,  0,  0, 15},
	{  3,  9,  0,  0, 18,  0,  9,  0,  6,  0,  0,  0, 15},
};
