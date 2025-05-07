/* --- Generated the 9/4/2025 at 2:28 --- */
/* --- heptagon compiler, version 1.05.00 (compiled sun. mar. 9 17:3:22 CET 2025) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s main -hepts line_follower.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "line_follower_types.h"

Line_follower__st_5 Line_follower__st_5_of_string(char* s) {
  if ((strcmp(s, "St_5_White")==0)) {
    return Line_follower__St_5_White;
  };
  if ((strcmp(s, "St_5_Black")==0)) {
    return Line_follower__St_5_Black;
  };
}

char* string_of_Line_follower__st_5(Line_follower__st_5 x, char* buf) {
  switch (x) {
    case Line_follower__St_5_White:
      strcpy(buf, "St_5_White");
      break;
    case Line_follower__St_5_Black:
      strcpy(buf, "St_5_Black");
      break;
    default:
      break;
  };
  return buf;
}

Line_follower__st_4 Line_follower__st_4_of_string(char* s) {
  if ((strcmp(s, "St_4_Stop")==0)) {
    return Line_follower__St_4_Stop;
  };
  if ((strcmp(s, "St_4_Pid")==0)) {
    return Line_follower__St_4_Pid;
  };
  if ((strcmp(s, "St_4_Parking")==0)) {
    return Line_follower__St_4_Parking;
  };
  if ((strcmp(s, "St_4_Obstacle")==0)) {
    return Line_follower__St_4_Obstacle;
  };
  if ((strcmp(s, "St_4_Intersection")==0)) {
    return Line_follower__St_4_Intersection;
  };
  if ((strcmp(s, "St_4_Goright")==0)) {
    return Line_follower__St_4_Goright;
  };
  if ((strcmp(s, "St_4_Goleft")==0)) {
    return Line_follower__St_4_Goleft;
  };
  if ((strcmp(s, "St_4_Forward")==0)) {
    return Line_follower__St_4_Forward;
  };
}

char* string_of_Line_follower__st_4(Line_follower__st_4 x, char* buf) {
  switch (x) {
    case Line_follower__St_4_Stop:
      strcpy(buf, "St_4_Stop");
      break;
    case Line_follower__St_4_Pid:
      strcpy(buf, "St_4_Pid");
      break;
    case Line_follower__St_4_Parking:
      strcpy(buf, "St_4_Parking");
      break;
    case Line_follower__St_4_Obstacle:
      strcpy(buf, "St_4_Obstacle");
      break;
    case Line_follower__St_4_Intersection:
      strcpy(buf, "St_4_Intersection");
      break;
    case Line_follower__St_4_Goright:
      strcpy(buf, "St_4_Goright");
      break;
    case Line_follower__St_4_Goleft:
      strcpy(buf, "St_4_Goleft");
      break;
    case Line_follower__St_4_Forward:
      strcpy(buf, "St_4_Forward");
      break;
    default:
      break;
  };
  return buf;
}

Line_follower__st_3 Line_follower__st_3_of_string(char* s) {
  if ((strcmp(s, "St_3_RightTurn")==0)) {
    return Line_follower__St_3_RightTurn;
  };
  if ((strcmp(s, "St_3_LeftTurn")==0)) {
    return Line_follower__St_3_LeftTurn;
  };
  if ((strcmp(s, "St_3_Halt")==0)) {
    return Line_follower__St_3_Halt;
  };
  if ((strcmp(s, "St_3_Forward")==0)) {
    return Line_follower__St_3_Forward;
  };
  if ((strcmp(s, "St_3_Final")==0)) {
    return Line_follower__St_3_Final;
  };
  if ((strcmp(s, "St_3_Counter")==0)) {
    return Line_follower__St_3_Counter;
  };
}

char* string_of_Line_follower__st_3(Line_follower__st_3 x, char* buf) {
  switch (x) {
    case Line_follower__St_3_RightTurn:
      strcpy(buf, "St_3_RightTurn");
      break;
    case Line_follower__St_3_LeftTurn:
      strcpy(buf, "St_3_LeftTurn");
      break;
    case Line_follower__St_3_Halt:
      strcpy(buf, "St_3_Halt");
      break;
    case Line_follower__St_3_Forward:
      strcpy(buf, "St_3_Forward");
      break;
    case Line_follower__St_3_Final:
      strcpy(buf, "St_3_Final");
      break;
    case Line_follower__St_3_Counter:
      strcpy(buf, "St_3_Counter");
      break;
    default:
      break;
  };
  return buf;
}

Line_follower__st_2 Line_follower__st_2_of_string(char* s) {
  if ((strcmp(s, "St_2_Start")==0)) {
    return Line_follower__St_2_Start;
  };
  if ((strcmp(s, "St_2_Restart")==0)) {
    return Line_follower__St_2_Restart;
  };
  if ((strcmp(s, "St_2_Parkright")==0)) {
    return Line_follower__St_2_Parkright;
  };
  if ((strcmp(s, "St_2_Parkleft")==0)) {
    return Line_follower__St_2_Parkleft;
  };
  if ((strcmp(s, "St_2_Goright")==0)) {
    return Line_follower__St_2_Goright;
  };
  if ((strcmp(s, "St_2_Goleft")==0)) {
    return Line_follower__St_2_Goleft;
  };
  if ((strcmp(s, "St_2_Final")==0)) {
    return Line_follower__St_2_Final;
  };
  if ((strcmp(s, "St_2_Check")==0)) {
    return Line_follower__St_2_Check;
  };
}

char* string_of_Line_follower__st_2(Line_follower__st_2 x, char* buf) {
  switch (x) {
    case Line_follower__St_2_Start:
      strcpy(buf, "St_2_Start");
      break;
    case Line_follower__St_2_Restart:
      strcpy(buf, "St_2_Restart");
      break;
    case Line_follower__St_2_Parkright:
      strcpy(buf, "St_2_Parkright");
      break;
    case Line_follower__St_2_Parkleft:
      strcpy(buf, "St_2_Parkleft");
      break;
    case Line_follower__St_2_Goright:
      strcpy(buf, "St_2_Goright");
      break;
    case Line_follower__St_2_Goleft:
      strcpy(buf, "St_2_Goleft");
      break;
    case Line_follower__St_2_Final:
      strcpy(buf, "St_2_Final");
      break;
    case Line_follower__St_2_Check:
      strcpy(buf, "St_2_Check");
      break;
    default:
      break;
  };
  return buf;
}

Line_follower__st_1 Line_follower__st_1_of_string(char* s) {
  if ((strcmp(s, "St_1_Stop")==0)) {
    return Line_follower__St_1_Stop;
  };
  if ((strcmp(s, "St_1_Pid")==0)) {
    return Line_follower__St_1_Pid;
  };
  if ((strcmp(s, "St_1_Goright")==0)) {
    return Line_follower__St_1_Goright;
  };
  if ((strcmp(s, "St_1_Goleft")==0)) {
    return Line_follower__St_1_Goleft;
  };
  if ((strcmp(s, "St_1_Forward")==0)) {
    return Line_follower__St_1_Forward;
  };
}

char* string_of_Line_follower__st_1(Line_follower__st_1 x, char* buf) {
  switch (x) {
    case Line_follower__St_1_Stop:
      strcpy(buf, "St_1_Stop");
      break;
    case Line_follower__St_1_Pid:
      strcpy(buf, "St_1_Pid");
      break;
    case Line_follower__St_1_Goright:
      strcpy(buf, "St_1_Goright");
      break;
    case Line_follower__St_1_Goleft:
      strcpy(buf, "St_1_Goleft");
      break;
    case Line_follower__St_1_Forward:
      strcpy(buf, "St_1_Forward");
      break;
    default:
      break;
  };
  return buf;
}

Line_follower__st Line_follower__st_of_string(char* s) {
  if ((strcmp(s, "St_GoRight")==0)) {
    return Line_follower__St_GoRight;
  };
  if ((strcmp(s, "St_GoLeft")==0)) {
    return Line_follower__St_GoLeft;
  };
  if ((strcmp(s, "St_FrontDetected")==0)) {
    return Line_follower__St_FrontDetected;
  };
  if ((strcmp(s, "St_Exit")==0)) {
    return Line_follower__St_Exit;
  };
  if ((strcmp(s, "St_Done")==0)) {
    return Line_follower__St_Done;
  };
  if ((strcmp(s, "St_BackOneLine")==0)) {
    return Line_follower__St_BackOneLine;
  };
}

char* string_of_Line_follower__st(Line_follower__st x, char* buf) {
  switch (x) {
    case Line_follower__St_GoRight:
      strcpy(buf, "St_GoRight");
      break;
    case Line_follower__St_GoLeft:
      strcpy(buf, "St_GoLeft");
      break;
    case Line_follower__St_FrontDetected:
      strcpy(buf, "St_FrontDetected");
      break;
    case Line_follower__St_Exit:
      strcpy(buf, "St_Exit");
      break;
    case Line_follower__St_Done:
      strcpy(buf, "St_Done");
      break;
    case Line_follower__St_BackOneLine:
      strcpy(buf, "St_BackOneLine");
      break;
    default:
      break;
  };
  return buf;
}

