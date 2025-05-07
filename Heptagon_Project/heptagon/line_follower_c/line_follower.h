/* --- Generated the 9/4/2025 at 2:28 --- */
/* --- heptagon compiler, version 1.05.00 (compiled sun. mar. 9 17:3:22 CET 2025) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s main -hepts line_follower.ept --- */

#ifndef LINE_FOLLOWER_H
#define LINE_FOLLOWER_H

#include "line_follower_types.h"
typedef struct Line_follower__pid_mem {
  int v_4;
  int v_3;
  int v_1;
  int v;
} Line_follower__pid_mem;

typedef struct Line_follower__pid_out {
  int v_l;
  int v_r;
} Line_follower__pid_out;

void Line_follower__pid_reset(Line_follower__pid_mem* self);

void Line_follower__pid_step(int sen0, int sen1, int sen2, int sen3,
                             int sen4, Line_follower__pid_out* _out,
                             Line_follower__pid_mem* self);

typedef struct Line_follower__pidBlack_mem {
  int v_20;
  int v_19;
  int v_17;
  int v;
} Line_follower__pidBlack_mem;

typedef struct Line_follower__pidBlack_out {
  int v_l;
  int v_r;
} Line_follower__pidBlack_out;

void Line_follower__pidBlack_reset(Line_follower__pidBlack_mem* self);

void Line_follower__pidBlack_step(int sen0, int sen1, int sen2, int sen3,
                                  int sen4,
                                  Line_follower__pidBlack_out* _out,
                                  Line_follower__pidBlack_mem* self);

typedef struct Line_follower__obstacle_avoid_mem {
  Line_follower__st ck;
  int pnr;
} Line_follower__obstacle_avoid_mem;

typedef struct Line_follower__obstacle_avoid_out {
  int v_l;
  int v_r;
  int dir;
} Line_follower__obstacle_avoid_out;

void Line_follower__obstacle_avoid_reset(Line_follower__obstacle_avoid_mem* self);

void Line_follower__obstacle_avoid_step(int obs_left, int ir_front_left,
                                        int sen[5],
                                        Line_follower__obstacle_avoid_out* _out,
                                        Line_follower__obstacle_avoid_mem* self);

typedef struct Line_follower__main_mem {
  Line_follower__st_5 ck;
  Line_follower__st_4 v_270;
  Line_follower__st_3 v_459;
  int v_461;
  int v_470;
  int v_468;
  int v_464;
  int v_479;
  int v_477;
  int v_473;
  int v_487;
  int v_485;
  int v_481;
  int v_496;
  int v_494;
  int v_490;
  int v_505;
  int v_503;
  int v_499;
  int v_525;
  int v_523;
  int v_519;
  Line_follower__st_2 v_533;
  int v_535;
  int v_542;
  int v_540;
  int v_537;
  int v_549;
  Line_follower__st_1 v_605;
  int v_611;
  int pnr_4;
  int bound_right_1;
  int bound_left_1;
  int count_1;
  Line_follower__pidBlack_mem pidBlack;
  Line_follower__obstacle_avoid_mem obstacle_avoid;
  Line_follower__pidBlack_mem pidBlack_1;
  Line_follower__pid_mem pid;
} Line_follower__main_mem;

typedef struct Line_follower__main_out {
  int v_l;
  int v_r;
  int dir;
} Line_follower__main_out;

void Line_follower__main_reset(Line_follower__main_mem* self);

void Line_follower__main_step(int sen0, int sen1, int sen2, int sen3,
                              int sen4, int ir_front_left,
                              int ir_front_right, int obs_left,
                              int obs_right, int sec,
                              Line_follower__main_out* _out,
                              Line_follower__main_mem* self);

#endif // LINE_FOLLOWER_H
