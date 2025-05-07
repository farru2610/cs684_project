/* --- Generated the 9/4/2025 at 2:28 --- */
/* --- heptagon compiler, version 1.05.00 (compiled sun. mar. 9 17:3:22 CET 2025) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s main -hepts line_follower.ept --- */

#ifndef LINE_FOLLOWER_H
#define LINE_FOLLOWER_H

#include "line_follower_types.h"
typedef struct Line_follower__pid_mem {
  long v_4;
  long v_3;
  long v_1;
  long v;
} Line_follower__pid_mem;

typedef struct Line_follower__pid_out {
  long v_l;
  long v_r;
} Line_follower__pid_out;

void Line_follower__pid_reset(Line_follower__pid_mem* self);

void Line_follower__pid_step(long sen0, long sen1, long sen2, long sen3,
                             long sen4, Line_follower__pid_out* _out,
                             Line_follower__pid_mem* self);

typedef struct Line_follower__pidBlack_mem {
  long v_20;
  long v_19;
  long v_17;
  long v;
} Line_follower__pidBlack_mem;

typedef struct Line_follower__pidBlack_out {
  long v_l;
  long v_r;
} Line_follower__pidBlack_out;

void Line_follower__pidBlack_reset(Line_follower__pidBlack_mem* self);

void Line_follower__pidBlack_step(long sen0, long sen1, long sen2, long sen3,
                                  long sen4,
                                  Line_follower__pidBlack_out* _out,
                                  Line_follower__pidBlack_mem* self);

typedef struct Line_follower__obstacle_avoid_mem {
  Line_follower__st ck;
  long pnr;
} Line_follower__obstacle_avoid_mem;

typedef struct Line_follower__obstacle_avoid_out {
  long v_l;
  long v_r;
  long dir;
} Line_follower__obstacle_avoid_out;

void Line_follower__obstacle_avoid_reset(Line_follower__obstacle_avoid_mem* self);

void Line_follower__obstacle_avoid_step(long obs_left, long ir_front_left,
                                        long sen[5],
                                        Line_follower__obstacle_avoid_out* _out,
                                        Line_follower__obstacle_avoid_mem* self);

typedef struct Line_follower__main_mem {
  Line_follower__st_5 ck;
  Line_follower__st_4 v_270;
  Line_follower__st_3 v_459;
  long v_461;
  long v_470;
  long v_468;
  long v_464;
  long v_479;
  long v_477;
  long v_473;
  long v_487;
  long v_485;
  long v_481;
  long v_496;
  long v_494;
  long v_490;
  long v_505;
  long v_503;
  long v_499;
  long v_525;
  long v_523;
  long v_519;
  Line_follower__st_2 v_533;
  long v_535;
  long v_542;
  long v_540;
  long v_537;
  long v_549;
  Line_follower__st_1 v_605;
  long v_611;
  long pnr_4;
  long bound_right_1;
  long bound_left_1;
  long count_1;
  Line_follower__pidBlack_mem pidBlack;
  Line_follower__obstacle_avoid_mem obstacle_avoid;
  Line_follower__pidBlack_mem pidBlack_1;
  Line_follower__pid_mem pid;
} Line_follower__main_mem;

typedef struct Line_follower__main_out {
  long v_l;
  long v_r;
  long dir;
} Line_follower__main_out;

void Line_follower__main_reset(Line_follower__main_mem* self);

void Line_follower__main_step(long sen0, long sen1, long sen2, long sen3,
                              long sen4, long ir_front_left,
                              long ir_front_right, long obs_left,
                              long obs_right, long sec,
                              Line_follower__main_out* _out,
                              Line_follower__main_mem* self);

#endif // LINE_FOLLOWER_H
