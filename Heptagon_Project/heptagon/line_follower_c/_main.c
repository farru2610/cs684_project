/* --- Generated the 9/4/2025 at 2:28 --- */
/* --- heptagon compiler, version 1.05.00 (compiled sun. mar. 9 17:3:22 CET 2025) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s main -hepts line_follower.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "_main.h"

Line_follower__main_mem mem;
int main(int argc, char** argv) {
  int step_c;
  int step_max;
  int sen0;
  int sen1;
  int sen2;
  int sen3;
  int sen4;
  int ir_front_left;
  int ir_front_right;
  int obs_left;
  int obs_right;
  int sec;
  Line_follower__main_out _res;
  step_c = 0;
  step_max = 0;
  if ((argc==2)) {
    step_max = atoi(argv[1]);
  };
  Line_follower__main_reset(&mem);
  while ((!(step_max)||(step_c<step_max))) {
    step_c = (step_c+1);
    
    if ((scanf("%d", &sen0)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%d", &sen1)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%d", &sen2)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%d", &sen3)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%d", &sen4)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%d", &ir_front_left)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%d", &ir_front_right)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%d", &obs_left)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%d", &obs_right)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%d", &sec)==EOF)) {
      return 0;
    };;
    Line_follower__main_step(sen0, sen1, sen2, sen3, sen4, ir_front_left,
                             ir_front_right, obs_left, obs_right, sec, &_res,
                             &mem);
    printf("%d\n", _res.v_l);
    printf("%d\n", _res.v_r);
    printf("%d\n", _res.dir);
    fflush(stdout);
  };
  return 0;
}

