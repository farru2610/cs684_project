/* --- Generated the 9/4/2025 at 2:28 --- */
/* --- heptagon compiler, version 1.05.00 (compiled sun. mar. 9 17:3:22 CET 2025) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s main -hepts line_follower.ept --- */

#ifndef LINE_FOLLOWER_TYPES_H
#define LINE_FOLLOWER_TYPES_H

#include "stdbool.h"
#include "assert.h"
//#include "pervasives.h"
typedef enum {
  Line_follower__St_5_White,
  Line_follower__St_5_Black
} Line_follower__st_5;

Line_follower__st_5 Line_follower__st_5_of_string(char* s);

char* string_of_Line_follower__st_5(Line_follower__st_5 x, char* buf);

typedef enum {
  Line_follower__St_4_Stop,
  Line_follower__St_4_Pid,
  Line_follower__St_4_Parking,
  Line_follower__St_4_Obstacle,
  Line_follower__St_4_Intersection,
  Line_follower__St_4_Goright,
  Line_follower__St_4_Goleft,
  Line_follower__St_4_Forward
} Line_follower__st_4;

Line_follower__st_4 Line_follower__st_4_of_string(char* s);

char* string_of_Line_follower__st_4(Line_follower__st_4 x, char* buf);

typedef enum {
  Line_follower__St_3_RightTurn,
  Line_follower__St_3_LeftTurn,
  Line_follower__St_3_Halt,
  Line_follower__St_3_Forward,
  Line_follower__St_3_Final,
  Line_follower__St_3_Counter
} Line_follower__st_3;

Line_follower__st_3 Line_follower__st_3_of_string(char* s);

char* string_of_Line_follower__st_3(Line_follower__st_3 x, char* buf);

typedef enum {
  Line_follower__St_2_Start,
  Line_follower__St_2_Restart,
  Line_follower__St_2_Parkright,
  Line_follower__St_2_Parkleft,
  Line_follower__St_2_Goright,
  Line_follower__St_2_Goleft,
  Line_follower__St_2_Final,
  Line_follower__St_2_Check
} Line_follower__st_2;

Line_follower__st_2 Line_follower__st_2_of_string(char* s);

char* string_of_Line_follower__st_2(Line_follower__st_2 x, char* buf);

typedef enum {
  Line_follower__St_1_Stop,
  Line_follower__St_1_Pid,
  Line_follower__St_1_Goright,
  Line_follower__St_1_Goleft,
  Line_follower__St_1_Forward
} Line_follower__st_1;

Line_follower__st_1 Line_follower__st_1_of_string(char* s);

char* string_of_Line_follower__st_1(Line_follower__st_1 x, char* buf);

typedef enum {
  Line_follower__St_GoRight,
  Line_follower__St_GoLeft,
  Line_follower__St_FrontDetected,
  Line_follower__St_Exit,
  Line_follower__St_Done,
  Line_follower__St_BackOneLine
} Line_follower__st;

Line_follower__st Line_follower__st_of_string(char* s);

char* string_of_Line_follower__st(Line_follower__st x, char* buf);

static const long Line_follower__kp = 1;

static const long Line_follower__ki = 100;

static const long Line_follower__kd = 15;

static const long Line_follower__kpB = 1;

static const long Line_follower__kiB = 100;

static const long Line_follower__kdB = 15;

static const long Line_follower__left_turn_speed = 80;

static const long Line_follower__right_turn_speed = 80;

#endif // LINE_FOLLOWER_TYPES_H
