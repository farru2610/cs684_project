/* --- Generated the 9/4/2025 at 2:28 --- */
/* --- heptagon compiler, version 1.05.00 (compiled sun. mar. 9 17:3:22 CET 2025) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s main -hepts line_follower.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "line_follower.h"

void Line_follower__pid_reset(Line_follower__pid_mem* self) {
  self->v_3 = true;
  self->v = true;
}

void Line_follower__pid_step(int sen0, int sen1, int sen2, int sen3,
                             int sen4, Line_follower__pid_out* _out,
                             Line_follower__pid_mem* self) {
  
  int v_16;
  int v_15;
  int v_14;
  int v_13;
  int v_12;
  int v_11;
  int v_10;
  int v_9;
  int v_8;
  int v_7;
  int v_6;
  int v_5;
  int v_2;
  int error;
  int i;
  int p;
  int d;
  int temp;
  int out;
  if (self->v_3) {
    v_5 = 0;
  } else {
    v_5 = self->v_4;
  };
  error = (sen1-sen3);
  d = (error-v_5);
  v_9 = (d*Line_follower__kd);
  v_2 = (self->v_1+error);
  if (self->v) {
    i = 0;
  } else {
    i = v_2;
  };
  v_7 = (i/Line_follower__ki);
  p = error;
  v_6 = (p/Line_follower__kp);
  v_8 = (v_6+v_7);
  temp = (v_8+v_9);
  v_11 = (temp>0);
  if (v_11) {
    v_12 = 10;
  } else {
    v_12 = 0;
  };
  v_10 = (temp<0);
  if (v_10) {
    out = -10;
  } else {
    out = v_12;
  };
  v_16 = (40+out);
  v_15 = (out==0);
  if (v_15) {
    _out->v_r = 60;
  } else {
    _out->v_r = v_16;
  };
  v_14 = (40-out);
  v_13 = (out==0);
  if (v_13) {
    _out->v_l = 60;
  } else {
    _out->v_l = v_14;
  };
  self->v_4 = error;
  self->v_3 = false;
  self->v_1 = i;
  self->v = false;;
}

void Line_follower__pidBlack_reset(Line_follower__pidBlack_mem* self) {
  self->v_19 = true;
  self->v = true;
}

void Line_follower__pidBlack_step(int sen0, int sen1, int sen2, int sen3,
                                  int sen4,
                                  Line_follower__pidBlack_out* _out,
                                  Line_follower__pidBlack_mem* self) {
  
  int v_34;
  int v_33;
  int v_32;
  int v_31;
  int v_30;
  int v_29;
  int v_28;
  int v_27;
  int v_26;
  int v_25;
  int v_24;
  int v_23;
  int v_22;
  int v_21;
  int v_18;
  int error;
  int i;
  int p;
  int d;
  int temp;
  int out;
  if (self->v_19) {
    v_21 = 0;
  } else {
    v_21 = self->v_20;
  };
  error = (sen1-sen3);
  d = (error-v_21);
  v_25 = (d*Line_follower__kdB);
  v_18 = (self->v_17+error);
  if (self->v) {
    i = 0;
  } else {
    i = v_18;
  };
  v_23 = (i/Line_follower__kiB);
  p = error;
  v_22 = (p/Line_follower__kpB);
  v_24 = (v_22+v_23);
  v_26 = (v_24+v_25);
  v_27 = (v_26*10);
  temp = (v_27/20);
  v_29 = (temp>0);
  if (v_29) {
    v_30 = 10;
  } else {
    v_30 = 0;
  };
  v_28 = (temp<0);
  if (v_28) {
    out = -10;
  } else {
    out = v_30;
  };
  v_34 = (40+out);
  v_33 = (out==0);
  if (v_33) {
    _out->v_r = 60;
  } else {
    _out->v_r = v_34;
  };
  v_32 = (40-out);
  v_31 = (out==0);
  if (v_31) {
    _out->v_l = 60;
  } else {
    _out->v_l = v_32;
  };
  self->v_20 = error;
  self->v_19 = false;
  self->v_17 = i;
  self->v = false;;
}

void Line_follower__obstacle_avoid_reset(Line_follower__obstacle_avoid_mem* self) {
  self->pnr = false;
  self->ck = Line_follower__St_FrontDetected;
}

void Line_follower__obstacle_avoid_step(int obs_left, int ir_front_left,
                                        int sen[5],
                                        Line_follower__obstacle_avoid_out* _out,
                                        Line_follower__obstacle_avoid_mem* self) {
  
  int v_38;
  int v_37;
  int v_36;
  int v_35;
  int v;
  int r_St_Exit;
  Line_follower__st s_St_Exit;
  int r_St_BackOneLine;
  Line_follower__st s_St_BackOneLine;
  int r_St_Done;
  Line_follower__st s_St_Done;
  int r_St_GoLeft;
  Line_follower__st s_St_GoLeft;
  int r_St_GoRight;
  Line_follower__st s_St_GoRight;
  int r_St_FrontDetected;
  Line_follower__st s_St_FrontDetected;
  int v_52;
  int v_51;
  int v_50;
  int v_49;
  int v_48;
  int v_47;
  int v_46;
  int v_45;
  int v_44;
  int v_43;
  int v_42;
  int v_41;
  int v_40;
  int v_39;
  int v_70;
  Line_follower__st v_69;
  int v_68;
  int v_67;
  int v_66;
  int v_65;
  int v_64;
  int v_63;
  int v_62;
  int v_61;
  int v_60;
  int v_59;
  int v_58;
  int v_57;
  int v_56;
  int v_55;
  int v_54;
  int v_53;
  int v_89;
  Line_follower__st v_88;
  int v_87;
  int v_86;
  int v_85;
  int v_84;
  int v_83;
  int v_82;
  int v_81;
  int v_80;
  int v_79;
  int v_78;
  int v_77;
  int v_76;
  int v_75;
  int v_74;
  int v_73;
  int v_72;
  int v_71;
  int nr_St_Exit;
  Line_follower__st ns_St_Exit;
  int dir_St_Exit;
  int v_r_St_Exit;
  int v_l_St_Exit;
  int nr_St_BackOneLine;
  Line_follower__st ns_St_BackOneLine;
  int dir_St_BackOneLine;
  int v_r_St_BackOneLine;
  int v_l_St_BackOneLine;
  int nr_St_Done;
  Line_follower__st ns_St_Done;
  int dir_St_Done;
  int v_r_St_Done;
  int v_l_St_Done;
  int nr_St_GoLeft;
  Line_follower__st ns_St_GoLeft;
  int dir_St_GoLeft;
  int v_r_St_GoLeft;
  int v_l_St_GoLeft;
  int nr_St_GoRight;
  Line_follower__st ns_St_GoRight;
  int dir_St_GoRight;
  int v_r_St_GoRight;
  int v_l_St_GoRight;
  int nr_St_FrontDetected;
  Line_follower__st ns_St_FrontDetected;
  int dir_St_FrontDetected;
  int v_r_St_FrontDetected;
  int v_l_St_FrontDetected;
  Line_follower__st ck_1;
  Line_follower__st s;
  Line_follower__st ns;
  int r;
  int nr;
  switch (self->ck) {
    case Line_follower__St_FrontDetected:
      r_St_FrontDetected = self->pnr;
      s_St_FrontDetected = Line_follower__St_FrontDetected;
      s = s_St_FrontDetected;
      r = r_St_FrontDetected;
      break;
    case Line_follower__St_GoRight:
      r_St_GoRight = self->pnr;
      s_St_GoRight = Line_follower__St_GoRight;
      s = s_St_GoRight;
      r = r_St_GoRight;
      break;
    case Line_follower__St_GoLeft:
      r_St_GoLeft = self->pnr;
      s_St_GoLeft = Line_follower__St_GoLeft;
      s = s_St_GoLeft;
      r = r_St_GoLeft;
      break;
    case Line_follower__St_Done:
      r_St_Done = self->pnr;
      s_St_Done = Line_follower__St_Done;
      s = s_St_Done;
      r = r_St_Done;
      break;
    case Line_follower__St_BackOneLine:
      v_36 = sen[3];
      v_37 = (v_36<500);
      v = sen[4];
      v_35 = (v<500);
      v_38 = (v_35||v_37);
      if (v_38) {
        r_St_BackOneLine = true;
        s_St_BackOneLine = Line_follower__St_Exit;
      } else {
        r_St_BackOneLine = self->pnr;
        s_St_BackOneLine = Line_follower__St_BackOneLine;
      };
      s = s_St_BackOneLine;
      r = r_St_BackOneLine;
      break;
    case Line_follower__St_Exit:
      r_St_Exit = self->pnr;
      s_St_Exit = Line_follower__St_Exit;
      s = s_St_Exit;
      r = r_St_Exit;
      break;
    default:
      break;
  };
  ck_1 = s;
  switch (ck_1) {
    case Line_follower__St_FrontDetected:
      dir_St_FrontDetected = 45;
      v_r_St_FrontDetected = 30;
      v_l_St_FrontDetected = 30;
      if (obs_left) {
        nr_St_FrontDetected = true;
        ns_St_FrontDetected = Line_follower__St_GoRight;
      } else {
        nr_St_FrontDetected = false;
        ns_St_FrontDetected = Line_follower__St_FrontDetected;
      };
      _out->v_l = v_l_St_FrontDetected;
      _out->v_r = v_r_St_FrontDetected;
      _out->dir = dir_St_FrontDetected;
      ns = ns_St_FrontDetected;
      nr = nr_St_FrontDetected;
      break;
    case Line_follower__St_GoRight:
      dir_St_GoRight = 1;
      v_r_St_GoRight = 50;
      v_l_St_GoRight = 20;
      v_85 = sen[0];
      v_86 = (v_85<500);
      v_82 = sen[4];
      v_83 = (v_82<500);
      v_79 = sen[3];
      v_80 = (v_79<500);
      v_76 = sen[2];
      v_77 = (v_76<500);
      v_74 = sen[1];
      v_75 = (v_74<500);
      v_78 = (v_75||v_77);
      v_81 = (v_78||v_80);
      v_84 = (v_81||v_83);
      v_87 = (v_84||v_86);
      if (v_87) {
        v_89 = true;
        v_88 = Line_follower__St_Done;
      } else {
        v_89 = false;
        v_88 = Line_follower__St_GoRight;
      };
      v_72 = (ir_front_left==0);
      v_71 = !(obs_left);
      v_73 = (v_71&&v_72);
      if (v_73) {
        nr_St_GoRight = true;
        ns_St_GoRight = Line_follower__St_GoLeft;
      } else {
        nr_St_GoRight = v_89;
        ns_St_GoRight = v_88;
      };
      _out->v_l = v_l_St_GoRight;
      _out->v_r = v_r_St_GoRight;
      _out->dir = dir_St_GoRight;
      ns = ns_St_GoRight;
      nr = nr_St_GoRight;
      break;
    case Line_follower__St_GoLeft:
      dir_St_GoLeft = 1;
      v_r_St_GoLeft = 20;
      v_l_St_GoLeft = 40;
      v_66 = sen[0];
      v_67 = (v_66<500);
      v_63 = sen[4];
      v_64 = (v_63<500);
      v_60 = sen[3];
      v_61 = (v_60<500);
      v_57 = sen[2];
      v_58 = (v_57<500);
      v_55 = sen[1];
      v_56 = (v_55<500);
      v_59 = (v_56||v_58);
      v_62 = (v_59||v_61);
      v_65 = (v_62||v_64);
      v_68 = (v_65||v_67);
      if (v_68) {
        v_70 = true;
        v_69 = Line_follower__St_Done;
      } else {
        v_70 = false;
        v_69 = Line_follower__St_GoLeft;
      };
      v_53 = (ir_front_left==1);
      v_54 = (obs_left||v_53);
      if (v_54) {
        nr_St_GoLeft = true;
        ns_St_GoLeft = Line_follower__St_GoRight;
      } else {
        nr_St_GoLeft = v_70;
        ns_St_GoLeft = v_69;
      };
      _out->v_l = v_l_St_GoLeft;
      _out->v_r = v_r_St_GoLeft;
      _out->dir = dir_St_GoLeft;
      ns = ns_St_GoLeft;
      nr = nr_St_GoLeft;
      break;
    case Line_follower__St_Done:
      dir_St_Done = 100;
      v_r_St_Done = 55;
      v_l_St_Done = 30;
      v_50 = sen[2];
      v_51 = (v_50>500);
      v_47 = sen[1];
      v_48 = (v_47>500);
      v_44 = sen[0];
      v_45 = (v_44>500);
      v_41 = sen[3];
      v_39 = sen[4];
      v_42 = (v_41>500);
      v_40 = (v_39>500);
      v_43 = (v_40&&v_42);
      v_46 = (v_43&&v_45);
      v_49 = (v_46&&v_48);
      v_52 = (v_49&&v_51);
      if (v_52) {
        nr_St_Done = true;
        ns_St_Done = Line_follower__St_BackOneLine;
      } else {
        nr_St_Done = false;
        ns_St_Done = Line_follower__St_Done;
      };
      _out->v_l = v_l_St_Done;
      _out->v_r = v_r_St_Done;
      _out->dir = dir_St_Done;
      ns = ns_St_Done;
      nr = nr_St_Done;
      break;
    case Line_follower__St_BackOneLine:
      dir_St_BackOneLine = 4;
      v_r_St_BackOneLine = 50;
      v_l_St_BackOneLine = 50;
      nr_St_BackOneLine = false;
      ns_St_BackOneLine = Line_follower__St_BackOneLine;
      _out->v_l = v_l_St_BackOneLine;
      _out->v_r = v_r_St_BackOneLine;
      _out->dir = dir_St_BackOneLine;
      ns = ns_St_BackOneLine;
      nr = nr_St_BackOneLine;
      break;
    case Line_follower__St_Exit:
      dir_St_Exit = 9;
      v_r_St_Exit = 0;
      v_l_St_Exit = 0;
      nr_St_Exit = false;
      ns_St_Exit = Line_follower__St_Exit;
      _out->v_l = v_l_St_Exit;
      _out->v_r = v_r_St_Exit;
      _out->dir = dir_St_Exit;
      ns = ns_St_Exit;
      nr = nr_St_Exit;
      break;
    default:
      break;
  };
  self->pnr = nr;
  self->ck = ns;;
}

void Line_follower__main_reset(Line_follower__main_mem* self) {
  Line_follower__pid_reset(&self->pid);
  Line_follower__pidBlack_reset(&self->pidBlack_1);
  Line_follower__obstacle_avoid_reset(&self->obstacle_avoid);
  Line_follower__pidBlack_reset(&self->pidBlack);
  self->bound_right_1 = 0;
  self->bound_left_1 = 0;
  self->count_1 = 0;
  self->pnr_4 = false;
  self->ck = Line_follower__St_5_White;
  self->v_611 = false;
  self->v_605 = Line_follower__St_1_Forward;
  self->v_549 = false;
  self->v_270 = Line_follower__St_4_Forward;
  self->v_537 = true;
  self->v_535 = false;
  self->v_533 = Line_follower__St_2_Start;
  self->v_461 = false;
  self->v_459 = Line_follower__St_3_Counter;
  self->v_519 = true;
  self->v_499 = true;
  self->v_490 = true;
  self->v_481 = true;
  self->v_473 = true;
  self->v_464 = true;
}

void Line_follower__main_step(int sen0, int sen1, int sen2, int sen3,
                              int sen4, int ir_front_left,
                              int ir_front_right, int obs_left,
                              int obs_right, int sec,
                              Line_follower__main_out* _out,
                              Line_follower__main_mem* self) {
  Line_follower__obstacle_avoid_out Line_follower__obstacle_avoid_out_st;
  Line_follower__pid_out Line_follower__pid_out_st;
  Line_follower__pidBlack_out Line_follower__pidBlack_out_st;
  
  int v_97;
  int v_96;
  int v_95;
  int v_94;
  int v_93;
  int v_92;
  int v_91;
  int v_90;
  int v;
  int r_4_St_5_Black;
  Line_follower__st_5 s_4_St_5_Black;
  int r_4_St_5_White;
  Line_follower__st_5 s_4_St_5_White;
  int v_100;
  int v_99;
  int v_98;
  int v_139;
  Line_follower__st_4 v_138;
  int v_137;
  Line_follower__st_4 v_136;
  int v_135;
  Line_follower__st_4 v_134;
  int v_133;
  int v_132;
  int v_131;
  int v_130;
  int v_129;
  int v_128;
  int v_127;
  int v_126;
  int v_125;
  int v_124;
  int v_123;
  int v_122;
  int v_121;
  int v_120;
  int v_119;
  int v_118;
  int v_117;
  int v_116;
  int v_115;
  int v_114;
  int v_113;
  int v_112;
  int v_111;
  int v_110;
  int v_109;
  int v_108;
  int v_107;
  int v_106;
  int v_105;
  int v_104;
  int v_103;
  int v_102;
  int v_101;
  int v_181;
  Line_follower__st_4 v_180;
  int v_179;
  Line_follower__st_4 v_178;
  int v_177;
  Line_follower__st_4 v_176;
  int v_175;
  int v_174;
  int v_173;
  int v_172;
  int v_171;
  int v_170;
  int v_169;
  int v_168;
  int v_167;
  int v_166;
  int v_165;
  int v_164;
  int v_163;
  int v_162;
  int v_161;
  int v_160;
  int v_159;
  int v_158;
  int v_157;
  int v_156;
  int v_155;
  int v_154;
  int v_153;
  int v_152;
  int v_151;
  int v_150;
  int v_149;
  int v_148;
  int v_147;
  int v_146;
  int v_145;
  int v_144;
  int v_143;
  int v_142;
  int v_141;
  int v_140;
  int v_223;
  Line_follower__st_4 v_222;
  int v_221;
  Line_follower__st_4 v_220;
  int v_219;
  Line_follower__st_4 v_218;
  int v_217;
  int v_216;
  int v_215;
  int v_214;
  int v_213;
  int v_212;
  int v_211;
  int v_210;
  int v_209;
  int v_208;
  int v_207;
  int v_206;
  int v_205;
  int v_204;
  int v_203;
  int v_202;
  int v_201;
  int v_200;
  int v_199;
  int v_198;
  int v_197;
  int v_196;
  int v_195;
  int v_194;
  int v_193;
  int v_192;
  int v_191;
  int v_190;
  int v_189;
  int v_188;
  int v_187;
  int v_186;
  int v_185;
  int v_184;
  int v_183;
  int v_182;
  int v_269;
  Line_follower__st_4 v_268;
  int v_267;
  Line_follower__st_4 v_266;
  int v_265;
  Line_follower__st_4 v_264;
  int v_263;
  Line_follower__st_4 v_262;
  int v_261;
  int v_260;
  int v_259;
  int v_258;
  int v_257;
  int v_256;
  int v_255;
  int v_254;
  int v_253;
  int v_252;
  int v_251;
  int v_250;
  int v_249;
  int v_248;
  int v_247;
  int v_246;
  int v_245;
  int v_244;
  int v_243;
  int v_242;
  int v_241;
  int v_240;
  int v_239;
  int v_238;
  int v_237;
  int v_236;
  int v_235;
  int v_234;
  int v_233;
  int v_232;
  int v_231;
  int v_230;
  int v_229;
  int v_228;
  int v_227;
  int v_226;
  int v_225;
  int v_224;
  int r_3_St_4_Intersection;
  Line_follower__st_4 s_3_St_4_Intersection;
  int r_3_St_4_Obstacle;
  Line_follower__st_4 s_3_St_4_Obstacle;
  int r_3_St_4_Parking;
  Line_follower__st_4 s_3_St_4_Parking;
  int r_3_St_4_Stop;
  Line_follower__st_4 s_3_St_4_Stop;
  int r_3_St_4_Pid;
  Line_follower__st_4 s_3_St_4_Pid;
  int r_3_St_4_Goleft;
  Line_follower__st_4 s_3_St_4_Goleft;
  int r_3_St_4_Goright;
  Line_follower__st_4 s_3_St_4_Goright;
  int r_3_St_4_Forward;
  Line_follower__st_4 s_3_St_4_Forward;
  Line_follower__st_4 ck_5;
  int v_276;
  int v_275;
  int v_281;
  int v_280;
  int v_279;
  int v_278;
  int v_277;
  int v_457;
  Line_follower__st_3 v_456;
  int v_455;
  Line_follower__st_3 v_454;
  int v_453;
  int v_452;
  int v_451;
  int v_450;
  int v_449;
  int v_448;
  int v_447;
  int v_446;
  int v_445;
  int v_444;
  int v_443;
  int v_442;
  int v_441;
  int v_440;
  int v_439;
  int v_438;
  int v_437;
  int v_436;
  int v_435;
  int v_434;
  int v_433;
  int v_432;
  int v_431;
  int v_430;
  int v_429;
  int v_428;
  int v_427;
  int v_426;
  int v_425;
  int v_424;
  int v_423;
  int v_422;
  int v_421;
  int v_420;
  int v_419;
  int v_418;
  int v_417;
  int v_416;
  int v_415;
  int v_414;
  int v_413;
  int v_412;
  int v_411;
  int v_410;
  int v_409;
  int v_408;
  int v_407;
  int v_406;
  int v_405;
  int v_404;
  int v_403;
  int v_402;
  int v_401;
  int v_400;
  int v_399;
  int v_398;
  int v_397;
  int v_396;
  int v_395;
  int v_394;
  int v_393;
  int v_392;
  int v_391;
  int v_390;
  int v_389;
  int v_388;
  int v_387;
  int v_386;
  int v_385;
  int v_384;
  int v_383;
  int v_382;
  int v_381;
  int v_380;
  int v_379;
  int v_378;
  int v_377;
  int v_376;
  int v_375;
  int v_374;
  int v_373;
  int v_372;
  int v_371;
  int v_370;
  int v_369;
  int v_368;
  int v_367;
  int v_366;
  int v_365;
  int v_364;
  int v_363;
  int v_362;
  int v_361;
  int v_360;
  int v_359;
  int v_358;
  int v_357;
  int v_356;
  int v_355;
  int v_354;
  int v_353;
  int v_352;
  int v_351;
  int v_350;
  int v_349;
  int v_348;
  int v_347;
  int v_346;
  int v_345;
  int v_344;
  int v_343;
  int v_342;
  int v_341;
  int v_340;
  int v_339;
  int v_338;
  int v_337;
  int v_336;
  int v_335;
  int v_334;
  int v_333;
  int v_332;
  int v_331;
  int v_330;
  int v_329;
  int v_328;
  int v_327;
  int v_326;
  int v_325;
  int v_324;
  int v_323;
  int v_322;
  int v_321;
  int v_320;
  int v_319;
  int v_318;
  int v_317;
  int v_316;
  int v_315;
  int v_314;
  int v_313;
  int v_312;
  int v_311;
  int v_310;
  int v_309;
  int v_308;
  int v_307;
  int v_306;
  int v_305;
  int v_304;
  int v_303;
  int v_302;
  int v_301;
  int v_300;
  int v_299;
  int v_298;
  int v_297;
  int v_296;
  int v_295;
  int v_294;
  int v_293;
  int v_292;
  int v_291;
  int v_290;
  int v_289;
  int v_288;
  int v_287;
  int v_286;
  int v_285;
  int v_284;
  int v_283;
  int v_282;
  int v_458;
  int nr_2_St_3_Final;
  Line_follower__st_3 ns_2_St_3_Final;
  int count_St_5_Black_St_4_Intersection_St_3_Final;
  int dir_St_5_Black_St_4_Intersection_St_3_Final;
  int v_r_St_5_Black_St_4_Intersection_St_3_Final;
  int v_l_St_5_Black_St_4_Intersection_St_3_Final;
  int nr_2_St_3_Halt;
  Line_follower__st_3 ns_2_St_3_Halt;
  int count_St_5_Black_St_4_Intersection_St_3_Halt;
  int dir_St_5_Black_St_4_Intersection_St_3_Halt;
  int v_r_St_5_Black_St_4_Intersection_St_3_Halt;
  int v_l_St_5_Black_St_4_Intersection_St_3_Halt;
  int nr_2_St_3_LeftTurn;
  Line_follower__st_3 ns_2_St_3_LeftTurn;
  int count_St_5_Black_St_4_Intersection_St_3_LeftTurn;
  int dir_St_5_Black_St_4_Intersection_St_3_LeftTurn;
  int v_r_St_5_Black_St_4_Intersection_St_3_LeftTurn;
  int v_l_St_5_Black_St_4_Intersection_St_3_LeftTurn;
  int nr_2_St_3_RightTurn;
  Line_follower__st_3 ns_2_St_3_RightTurn;
  int count_St_5_Black_St_4_Intersection_St_3_RightTurn;
  int dir_St_5_Black_St_4_Intersection_St_3_RightTurn;
  int v_r_St_5_Black_St_4_Intersection_St_3_RightTurn;
  int v_l_St_5_Black_St_4_Intersection_St_3_RightTurn;
  int nr_2_St_3_Forward;
  Line_follower__st_3 ns_2_St_3_Forward;
  int count_St_5_Black_St_4_Intersection_St_3_Forward;
  int dir_St_5_Black_St_4_Intersection_St_3_Forward;
  int v_r_St_5_Black_St_4_Intersection_St_3_Forward;
  int v_l_St_5_Black_St_4_Intersection_St_3_Forward;
  int nr_2_St_3_Counter;
  Line_follower__st_3 ns_2_St_3_Counter;
  int count_St_5_Black_St_4_Intersection_St_3_Counter;
  int dir_St_5_Black_St_4_Intersection_St_3_Counter;
  int v_r_St_5_Black_St_4_Intersection_St_3_Counter;
  int v_l_St_5_Black_St_4_Intersection_St_3_Counter;
  Line_follower__st_3 ck_8;
  int v_460;
  int v_274;
  Line_follower__st_4 v_273;
  int v_272;
  int v_271;
  Line_follower__st_3 ns_2;
  int r_2;
  int nr_2;
  int pnr_2;
  int v_462;
  int r_5;
  int v_471;
  int v_469;
  int v_467;
  int v_466;
  int v_465;
  int v_463;
  int time_6;
  int v_480;
  int v_478;
  int v_476;
  int v_475;
  int v_474;
  int v_472;
  int time_5;
  int v_488;
  int v_486;
  int v_484;
  int v_483;
  int v_482;
  int time_4;
  int v_497;
  int v_495;
  int v_493;
  int v_492;
  int v_491;
  int v_489;
  int time_3;
  int v_506;
  int v_504;
  int v_502;
  int v_501;
  int v_500;
  int v_498;
  int time_2;
  int v_512;
  Line_follower__st_2 v_511;
  int v_510;
  Line_follower__st_2 v_509;
  int v_508;
  int v_507;
  int v_531;
  int v_530;
  int v_529;
  int v_528;
  int v_527;
  int v_526;
  int v_524;
  int v_522;
  int v_521;
  int v_520;
  int v_518;
  int v_517;
  int v_516;
  int v_515;
  int v_514;
  int v_513;
  int r_6;
  int time_1;
  int v_532;
  int nr_1_St_2_Final;
  Line_follower__st_2 ns_1_St_2_Final;
  int bound_right_St_5_Black_St_4_Parking_St_2_Final;
  int bound_left_St_5_Black_St_4_Parking_St_2_Final;
  int dir_St_5_Black_St_4_Parking_St_2_Final;
  int v_r_St_5_Black_St_4_Parking_St_2_Final;
  int v_l_St_5_Black_St_4_Parking_St_2_Final;
  int nr_1_St_2_Parkleft;
  Line_follower__st_2 ns_1_St_2_Parkleft;
  int bound_right_St_5_Black_St_4_Parking_St_2_Parkleft;
  int bound_left_St_5_Black_St_4_Parking_St_2_Parkleft;
  int dir_St_5_Black_St_4_Parking_St_2_Parkleft;
  int v_r_St_5_Black_St_4_Parking_St_2_Parkleft;
  int v_l_St_5_Black_St_4_Parking_St_2_Parkleft;
  int nr_1_St_2_Parkright;
  Line_follower__st_2 ns_1_St_2_Parkright;
  int bound_right_St_5_Black_St_4_Parking_St_2_Parkright;
  int bound_left_St_5_Black_St_4_Parking_St_2_Parkright;
  int dir_St_5_Black_St_4_Parking_St_2_Parkright;
  int v_r_St_5_Black_St_4_Parking_St_2_Parkright;
  int v_l_St_5_Black_St_4_Parking_St_2_Parkright;
  int nr_1_St_2_Restart;
  Line_follower__st_2 ns_1_St_2_Restart;
  int bound_right_St_5_Black_St_4_Parking_St_2_Restart;
  int bound_left_St_5_Black_St_4_Parking_St_2_Restart;
  int dir_St_5_Black_St_4_Parking_St_2_Restart;
  int v_r_St_5_Black_St_4_Parking_St_2_Restart;
  int v_l_St_5_Black_St_4_Parking_St_2_Restart;
  int nr_1_St_2_Goright;
  Line_follower__st_2 ns_1_St_2_Goright;
  int bound_right_St_5_Black_St_4_Parking_St_2_Goright;
  int bound_left_St_5_Black_St_4_Parking_St_2_Goright;
  int dir_St_5_Black_St_4_Parking_St_2_Goright;
  int v_r_St_5_Black_St_4_Parking_St_2_Goright;
  int v_l_St_5_Black_St_4_Parking_St_2_Goright;
  int nr_1_St_2_Goleft;
  Line_follower__st_2 ns_1_St_2_Goleft;
  int bound_right_St_5_Black_St_4_Parking_St_2_Goleft;
  int bound_left_St_5_Black_St_4_Parking_St_2_Goleft;
  int dir_St_5_Black_St_4_Parking_St_2_Goleft;
  int v_r_St_5_Black_St_4_Parking_St_2_Goleft;
  int v_l_St_5_Black_St_4_Parking_St_2_Goleft;
  int nr_1_St_2_Check;
  Line_follower__st_2 ns_1_St_2_Check;
  int bound_right_St_5_Black_St_4_Parking_St_2_Check;
  int bound_left_St_5_Black_St_4_Parking_St_2_Check;
  int dir_St_5_Black_St_4_Parking_St_2_Check;
  int v_r_St_5_Black_St_4_Parking_St_2_Check;
  int v_l_St_5_Black_St_4_Parking_St_2_Check;
  int nr_1_St_2_Start;
  Line_follower__st_2 ns_1_St_2_Start;
  int bound_right_St_5_Black_St_4_Parking_St_2_Start;
  int bound_left_St_5_Black_St_4_Parking_St_2_Start;
  int dir_St_5_Black_St_4_Parking_St_2_Start;
  int v_r_St_5_Black_St_4_Parking_St_2_Start;
  int v_l_St_5_Black_St_4_Parking_St_2_Start;
  Line_follower__st_2 ck_7;
  int v_534;
  Line_follower__st_2 ns_1;
  int r_1;
  int nr_1;
  int pnr_1;
  int v_543;
  int v_541;
  int v_539;
  int v_538;
  int v_536;
  int time;
  int v_548;
  int v_547;
  int v_546;
  int v_545;
  int v_544;
  int r_7;
  int nr_3_St_4_Intersection;
  Line_follower__st_4 ns_3_St_4_Intersection;
  int bound_right_St_5_Black_St_4_Intersection;
  int bound_left_St_5_Black_St_4_Intersection;
  int count_St_5_Black_St_4_Intersection;
  int dir_St_5_Black_St_4_Intersection;
  int v_r_St_5_Black_St_4_Intersection;
  int v_l_St_5_Black_St_4_Intersection;
  int nr_3_St_4_Obstacle;
  Line_follower__st_4 ns_3_St_4_Obstacle;
  int bound_right_St_5_Black_St_4_Obstacle;
  int bound_left_St_5_Black_St_4_Obstacle;
  int count_St_5_Black_St_4_Obstacle;
  int dir_St_5_Black_St_4_Obstacle;
  int v_r_St_5_Black_St_4_Obstacle;
  int v_l_St_5_Black_St_4_Obstacle;
  int nr_3_St_4_Parking;
  Line_follower__st_4 ns_3_St_4_Parking;
  int bound_right_St_5_Black_St_4_Parking;
  int bound_left_St_5_Black_St_4_Parking;
  int count_St_5_Black_St_4_Parking;
  int dir_St_5_Black_St_4_Parking;
  int v_r_St_5_Black_St_4_Parking;
  int v_l_St_5_Black_St_4_Parking;
  int nr_3_St_4_Stop;
  Line_follower__st_4 ns_3_St_4_Stop;
  int bound_right_St_5_Black_St_4_Stop;
  int bound_left_St_5_Black_St_4_Stop;
  int count_St_5_Black_St_4_Stop;
  int dir_St_5_Black_St_4_Stop;
  int v_r_St_5_Black_St_4_Stop;
  int v_l_St_5_Black_St_4_Stop;
  int nr_3_St_4_Pid;
  Line_follower__st_4 ns_3_St_4_Pid;
  int bound_right_St_5_Black_St_4_Pid;
  int bound_left_St_5_Black_St_4_Pid;
  int count_St_5_Black_St_4_Pid;
  int dir_St_5_Black_St_4_Pid;
  int v_r_St_5_Black_St_4_Pid;
  int v_l_St_5_Black_St_4_Pid;
  int nr_3_St_4_Goleft;
  Line_follower__st_4 ns_3_St_4_Goleft;
  int bound_right_St_5_Black_St_4_Goleft;
  int bound_left_St_5_Black_St_4_Goleft;
  int count_St_5_Black_St_4_Goleft;
  int dir_St_5_Black_St_4_Goleft;
  int v_r_St_5_Black_St_4_Goleft;
  int v_l_St_5_Black_St_4_Goleft;
  int nr_3_St_4_Goright;
  Line_follower__st_4 ns_3_St_4_Goright;
  int bound_right_St_5_Black_St_4_Goright;
  int bound_left_St_5_Black_St_4_Goright;
  int count_St_5_Black_St_4_Goright;
  int dir_St_5_Black_St_4_Goright;
  int v_r_St_5_Black_St_4_Goright;
  int v_l_St_5_Black_St_4_Goright;
  int nr_3_St_4_Forward;
  Line_follower__st_4 ns_3_St_4_Forward;
  int bound_right_St_5_Black_St_4_Forward;
  int bound_left_St_5_Black_St_4_Forward;
  int count_St_5_Black_St_4_Forward;
  int dir_St_5_Black_St_4_Forward;
  int v_r_St_5_Black_St_4_Forward;
  int v_l_St_5_Black_St_4_Forward;
  Line_follower__st_4 ck_6;
  Line_follower__st_4 s_3;
  Line_follower__st_4 ns_3;
  int r_3;
  int nr_3;
  int pnr_3;
  int v_567;
  Line_follower__st_1 v_566;
  int v_565;
  Line_follower__st_1 v_564;
  int v_563;
  int v_562;
  int v_561;
  int v_560;
  int v_559;
  int v_558;
  int v_557;
  int v_556;
  int v_555;
  int v_573;
  Line_follower__st_1 v_572;
  int v_571;
  int v_570;
  int v_569;
  int v_568;
  int v_582;
  Line_follower__st_1 v_581;
  int v_580;
  int v_579;
  int v_578;
  int v_577;
  int v_576;
  int v_575;
  int v_574;
  int v_591;
  Line_follower__st_1 v_590;
  int v_589;
  int v_588;
  int v_587;
  int v_586;
  int v_585;
  int v_584;
  int v_583;
  int v_604;
  Line_follower__st_1 v_603;
  int v_602;
  Line_follower__st_1 v_601;
  int v_600;
  int v_599;
  int v_598;
  int v_597;
  int v_596;
  int v_595;
  int v_594;
  int v_593;
  int v_592;
  int r_St_1_Stop;
  Line_follower__st_1 s_St_1_Stop;
  int r_St_1_Pid;
  Line_follower__st_1 s_St_1_Pid;
  int r_St_1_Goleft;
  Line_follower__st_1 s_St_1_Goleft;
  int r_St_1_Goright;
  Line_follower__st_1 s_St_1_Goright;
  int r_St_1_Forward;
  Line_follower__st_1 s_St_1_Forward;
  Line_follower__st_1 ck_3;
  int v_610;
  int v_609;
  int v_608;
  int v_607;
  int v_606;
  int r_8;
  int nr_St_1_Stop;
  Line_follower__st_1 ns_St_1_Stop;
  int dir_St_5_White_St_1_Stop;
  int v_r_St_5_White_St_1_Stop;
  int v_l_St_5_White_St_1_Stop;
  int nr_St_1_Pid;
  Line_follower__st_1 ns_St_1_Pid;
  int dir_St_5_White_St_1_Pid;
  int v_r_St_5_White_St_1_Pid;
  int v_l_St_5_White_St_1_Pid;
  int nr_St_1_Goleft;
  Line_follower__st_1 ns_St_1_Goleft;
  int dir_St_5_White_St_1_Goleft;
  int v_r_St_5_White_St_1_Goleft;
  int v_l_St_5_White_St_1_Goleft;
  int nr_St_1_Goright;
  Line_follower__st_1 ns_St_1_Goright;
  int dir_St_5_White_St_1_Goright;
  int v_r_St_5_White_St_1_Goright;
  int v_l_St_5_White_St_1_Goright;
  int nr_St_1_Forward;
  Line_follower__st_1 ns_St_1_Forward;
  int dir_St_5_White_St_1_Forward;
  int v_r_St_5_White_St_1_Forward;
  int v_l_St_5_White_St_1_Forward;
  Line_follower__st_1 ck_4;
  int v_554;
  int v_553;
  int v_552;
  int v_551;
  int v_550;
  Line_follower__st_1 s;
  Line_follower__st_1 ns;
  int r;
  int nr;
  int pnr;
  int nr_4_St_5_Black;
  Line_follower__st_5 ns_4_St_5_Black;
  int bound_right_St_5_Black;
  int bound_left_St_5_Black;
  int count_St_5_Black;
  int sen_St_5_Black[5];
  int dir_St_5_Black;
  int v_r_St_5_Black;
  int v_l_St_5_Black;
  int nr_4_St_5_White;
  Line_follower__st_5 ns_4_St_5_White;
  int bound_right_St_5_White;
  int bound_left_St_5_White;
  int count_St_5_White;
  int sen_St_5_White[5];
  int dir_St_5_White;
  int v_r_St_5_White;
  int v_l_St_5_White;
  Line_follower__st_5 ck_2;
  Line_follower__st_5 s_4;
  Line_follower__st_5 ns_4;
  int r_4;
  int nr_4;
  int sen[5];
  int count;
  int bound_left;
  int bound_right;
  switch (self->ck) {
    case Line_follower__St_5_White:
      v_95 = (sen3<500);
      v_93 = (sen2<500);
      v_92 = (sen1<500);
      v_94 = (v_92||v_93);
      v_96 = (v_94||v_95);
      v_90 = (sen4>500);
      v = (sen0>500);
      v_91 = (v&&v_90);
      v_97 = (v_91&&v_96);
      if (v_97) {
        r_4_St_5_White = true;
        s_4_St_5_White = Line_follower__St_5_Black;
      } else {
        r_4_St_5_White = self->pnr_4;
        s_4_St_5_White = Line_follower__St_5_White;
      };
      s_4 = s_4_St_5_White;
      r_4 = r_4_St_5_White;
      break;
    case Line_follower__St_5_Black:
      r_4_St_5_Black = self->pnr_4;
      s_4_St_5_Black = Line_follower__St_5_Black;
      s_4 = s_4_St_5_Black;
      r_4 = r_4_St_5_Black;
      break;
    default:
      break;
  };
  ck_2 = s_4;
  switch (ck_2) {
    case Line_follower__St_5_White:
      bound_right_St_5_White = self->bound_right_1;
      bound_left_St_5_White = self->bound_left_1;
      count_St_5_White = self->count_1;
      if (r_4) {
        pnr = false;
        ck_3 = Line_follower__St_1_Forward;
      } else {
        pnr = self->v_611;
        ck_3 = self->v_605;
      };
      v_554 = (1023-sen4);
      v_553 = (1023-sen3);
      v_552 = (1023-sen2);
      v_551 = (1023-sen1);
      v_550 = (1023-sen0);
      nr_4_St_5_White = false;
      ns_4_St_5_White = Line_follower__St_5_White;
      ns_4 = ns_4_St_5_White;
      nr_4 = nr_4_St_5_White;
      sen_St_5_White[0] = v_550;
      sen_St_5_White[1] = v_551;
      sen_St_5_White[2] = v_552;
      sen_St_5_White[3] = v_553;
      sen_St_5_White[4] = v_554;
      {
        int _6;
        for (_6 = 0; _6 < 5; ++_6) {
          sen[_6] = sen_St_5_White[_6];
        }
      };
      switch (ck_3) {
        case Line_follower__St_1_Forward:
          v_599 = sen[4];
          v_600 = (v_599<500);
          if (v_600) {
            v_602 = true;
            v_601 = Line_follower__St_1_Goright;
          } else {
            v_602 = pnr;
            v_601 = Line_follower__St_1_Forward;
          };
          v_597 = sen[0];
          v_598 = (v_597<500);
          if (v_598) {
            v_604 = true;
            v_603 = Line_follower__St_1_Goleft;
          } else {
            v_604 = v_602;
            v_603 = v_601;
          };
          v_594 = sen[3];
          v_595 = (v_594<500);
          v_592 = sen[1];
          v_593 = (v_592<500);
          v_596 = (v_593||v_595);
          if (v_596) {
            r_St_1_Forward = true;
            s_St_1_Forward = Line_follower__St_1_Pid;
          } else {
            r_St_1_Forward = v_604;
            s_St_1_Forward = v_603;
          };
          s = s_St_1_Forward;
          r = r_St_1_Forward;
          break;
        case Line_follower__St_1_Goright:
          v_588 = sen[0];
          v_589 = (v_588<500);
          if (v_589) {
            v_591 = true;
            v_590 = Line_follower__St_1_Goleft;
          } else {
            v_591 = pnr;
            v_590 = Line_follower__St_1_Goright;
          };
          v_585 = sen[3];
          v_586 = (v_585<500);
          v_583 = sen[1];
          v_584 = (v_583<500);
          v_587 = (v_584||v_586);
          if (v_587) {
            r_St_1_Goright = true;
            s_St_1_Goright = Line_follower__St_1_Pid;
          } else {
            r_St_1_Goright = v_591;
            s_St_1_Goright = v_590;
          };
          s = s_St_1_Goright;
          r = r_St_1_Goright;
          break;
        case Line_follower__St_1_Goleft:
          v_579 = sen[4];
          v_580 = (v_579<500);
          if (v_580) {
            v_582 = true;
            v_581 = Line_follower__St_1_Goright;
          } else {
            v_582 = pnr;
            v_581 = Line_follower__St_1_Goleft;
          };
          v_576 = sen[3];
          v_577 = (v_576<500);
          v_574 = sen[1];
          v_575 = (v_574<500);
          v_578 = (v_575||v_577);
          if (v_578) {
            r_St_1_Goleft = true;
            s_St_1_Goleft = Line_follower__St_1_Pid;
          } else {
            r_St_1_Goleft = v_582;
            s_St_1_Goleft = v_581;
          };
          s = s_St_1_Goleft;
          r = r_St_1_Goleft;
          break;
        case Line_follower__St_1_Pid:
          v_570 = sen[4];
          v_571 = (v_570<500);
          if (v_571) {
            v_573 = true;
            v_572 = Line_follower__St_1_Goright;
          } else {
            v_573 = pnr;
            v_572 = Line_follower__St_1_Pid;
          };
          v_568 = sen[0];
          v_569 = (v_568<500);
          if (v_569) {
            r_St_1_Pid = true;
            s_St_1_Pid = Line_follower__St_1_Goleft;
          } else {
            r_St_1_Pid = v_573;
            s_St_1_Pid = v_572;
          };
          s = s_St_1_Pid;
          r = r_St_1_Pid;
          break;
        case Line_follower__St_1_Stop:
          v_562 = sen[4];
          v_563 = (v_562<500);
          if (v_563) {
            v_565 = true;
            v_564 = Line_follower__St_1_Goright;
          } else {
            v_565 = pnr;
            v_564 = Line_follower__St_1_Stop;
          };
          v_560 = sen[0];
          v_561 = (v_560<500);
          if (v_561) {
            v_567 = true;
            v_566 = Line_follower__St_1_Goleft;
          } else {
            v_567 = v_565;
            v_566 = v_564;
          };
          v_557 = sen[3];
          v_558 = (v_557<500);
          v_555 = sen[1];
          v_556 = (v_555<500);
          v_559 = (v_556||v_558);
          if (v_559) {
            r_St_1_Stop = true;
            s_St_1_Stop = Line_follower__St_1_Pid;
          } else {
            r_St_1_Stop = v_567;
            s_St_1_Stop = v_566;
          };
          s = s_St_1_Stop;
          r = r_St_1_Stop;
          break;
        default:
          break;
      };
      ck_4 = s;
      switch (ck_4) {
        case Line_follower__St_1_Forward:
          v_r_St_5_White_St_1_Forward = 80;
          v_l_St_5_White_St_1_Forward = 80;
          dir_St_5_White_St_1_Forward = 1;
          nr_St_1_Forward = false;
          ns_St_1_Forward = Line_follower__St_1_Forward;
          v_l_St_5_White = v_l_St_5_White_St_1_Forward;
          v_r_St_5_White = v_r_St_5_White_St_1_Forward;
          dir_St_5_White = dir_St_5_White_St_1_Forward;
          ns = ns_St_1_Forward;
          nr = nr_St_1_Forward;
          break;
        case Line_follower__St_1_Goright:
          v_r_St_5_White_St_1_Goright = 80;
          v_l_St_5_White_St_1_Goright = 80;
          dir_St_5_White_St_1_Goright = 4;
          nr_St_1_Goright = false;
          ns_St_1_Goright = Line_follower__St_1_Goright;
          v_l_St_5_White = v_l_St_5_White_St_1_Goright;
          v_r_St_5_White = v_r_St_5_White_St_1_Goright;
          dir_St_5_White = dir_St_5_White_St_1_Goright;
          ns = ns_St_1_Goright;
          nr = nr_St_1_Goright;
          break;
        case Line_follower__St_1_Goleft:
          v_r_St_5_White_St_1_Goleft = 80;
          v_l_St_5_White_St_1_Goleft = 80;
          dir_St_5_White_St_1_Goleft = 3;
          nr_St_1_Goleft = false;
          ns_St_1_Goleft = Line_follower__St_1_Goleft;
          v_l_St_5_White = v_l_St_5_White_St_1_Goleft;
          v_r_St_5_White = v_r_St_5_White_St_1_Goleft;
          dir_St_5_White = dir_St_5_White_St_1_Goleft;
          ns = ns_St_1_Goleft;
          nr = nr_St_1_Goleft;
          break;
        case Line_follower__St_1_Pid:
          v_610 = sen[4];
          v_609 = sen[3];
          v_608 = sen[2];
          v_607 = sen[1];
          v_606 = sen[0];
          dir_St_5_White_St_1_Pid = 2;
          nr_St_1_Pid = false;
          ns_St_1_Pid = Line_follower__St_1_Pid;
          r_8 = (r_4||r);
          if (r_8) {
            Line_follower__pid_reset(&self->pid);
          };
          Line_follower__pid_step(v_606, v_607, v_608, v_609, v_610,
                                  &Line_follower__pid_out_st, &self->pid);
          v_l_St_5_White_St_1_Pid = Line_follower__pid_out_st.v_l;
          v_r_St_5_White_St_1_Pid = Line_follower__pid_out_st.v_r;
          v_l_St_5_White = v_l_St_5_White_St_1_Pid;
          v_r_St_5_White = v_r_St_5_White_St_1_Pid;
          dir_St_5_White = dir_St_5_White_St_1_Pid;
          ns = ns_St_1_Pid;
          nr = nr_St_1_Pid;
          break;
        case Line_follower__St_1_Stop:
          v_r_St_5_White_St_1_Stop = 0;
          v_l_St_5_White_St_1_Stop = 0;
          dir_St_5_White_St_1_Stop = 0;
          nr_St_1_Stop = false;
          ns_St_1_Stop = Line_follower__St_1_Stop;
          v_l_St_5_White = v_l_St_5_White_St_1_Stop;
          v_r_St_5_White = v_r_St_5_White_St_1_Stop;
          dir_St_5_White = dir_St_5_White_St_1_Stop;
          ns = ns_St_1_Stop;
          nr = nr_St_1_Stop;
          break;
        default:
          break;
      };
      _out->v_l = v_l_St_5_White;
      _out->v_r = v_r_St_5_White;
      _out->dir = dir_St_5_White;
      count = count_St_5_White;
      bound_left = bound_left_St_5_White;
      bound_right = bound_right_St_5_White;
      break;
    case Line_follower__St_5_Black:
      if (r_4) {
        pnr_3 = false;
        ck_5 = Line_follower__St_4_Forward;
      } else {
        pnr_3 = self->v_549;
        ck_5 = self->v_270;
      };
      nr_4_St_5_Black = false;
      ns_4_St_5_Black = Line_follower__St_5_Black;
      ns_4 = ns_4_St_5_Black;
      nr_4 = nr_4_St_5_Black;
      switch (ck_5) {
        case Line_follower__St_4_Forward:
          v_225 = (ir_front_right==1);
          v_224 = (ir_front_left==1);
          v_226 = (v_224||v_225);
          break;
        case Line_follower__St_4_Goright:
          v_183 = (ir_front_right==1);
          v_182 = (ir_front_left==1);
          v_184 = (v_182&&v_183);
          break;
        case Line_follower__St_4_Goleft:
          v_141 = (ir_front_right==1);
          v_140 = (ir_front_left==1);
          v_142 = (v_140||v_141);
          break;
        case Line_follower__St_4_Pid:
          v_102 = (ir_front_right==1);
          v_101 = (ir_front_left==1);
          v_103 = (v_101||v_102);
          break;
        case Line_follower__St_4_Stop:
          v_99 = (ir_front_right==1);
          v_98 = (ir_front_left==1);
          v_100 = (v_98||v_99);
          if (v_100) {
            r_3_St_4_Stop = true;
            s_3_St_4_Stop = Line_follower__St_4_Obstacle;
          } else {
            r_3_St_4_Stop = pnr_3;
            s_3_St_4_Stop = Line_follower__St_4_Stop;
          };
          break;
        case Line_follower__St_4_Parking:
          r_3_St_4_Parking = pnr_3;
          s_3_St_4_Parking = Line_follower__St_4_Parking;
          break;
        case Line_follower__St_4_Obstacle:
          r_3_St_4_Obstacle = pnr_3;
          s_3_St_4_Obstacle = Line_follower__St_4_Obstacle;
          break;
        case Line_follower__St_4_Intersection:
          r_3_St_4_Intersection = pnr_3;
          s_3_St_4_Intersection = Line_follower__St_4_Intersection;
          break;
        default:
          break;
      };
      sen_St_5_Black[0] = sen0;
      sen_St_5_Black[1] = sen1;
      sen_St_5_Black[2] = sen2;
      sen_St_5_Black[3] = sen3;
      sen_St_5_Black[4] = sen4;
      {
        int _7;
        for (_7 = 0; _7 < 5; ++_7) {
          sen[_7] = sen_St_5_Black[_7];
        }
      };
      switch (ck_5) {
        case Line_follower__St_4_Forward:
          v_260 = sen[4];
          v_261 = (v_260<500);
          if (v_261) {
            v_263 = true;
            v_262 = Line_follower__St_4_Goright;
          } else {
            v_263 = pnr_3;
            v_262 = Line_follower__St_4_Forward;
          };
          v_258 = sen[0];
          v_259 = (v_258<500);
          if (v_259) {
            v_265 = true;
            v_264 = Line_follower__St_4_Goleft;
          } else {
            v_265 = v_263;
            v_264 = v_262;
          };
          v_255 = sen[3];
          v_256 = (v_255<500);
          v_253 = sen[1];
          v_254 = (v_253<500);
          v_257 = (v_254||v_256);
          if (v_257) {
            v_267 = true;
            v_266 = Line_follower__St_4_Pid;
          } else {
            v_267 = v_265;
            v_266 = v_264;
          };
          v_249 = sen[3];
          v_250 = (v_249<500);
          v_246 = sen[2];
          v_247 = (v_246<500);
          v_244 = sen[4];
          v_245 = (v_244<500);
          v_248 = (v_245&&v_247);
          v_251 = (v_248&&v_250);
          v_240 = sen[0];
          v_241 = (v_240<500);
          v_237 = sen[2];
          v_238 = (v_237<500);
          v_235 = sen[1];
          v_236 = (v_235<500);
          v_239 = (v_236&&v_238);
          v_242 = (v_239&&v_241);
          v_232 = sen[3];
          v_233 = (v_232<500);
          v_229 = sen[2];
          v_230 = (v_229<500);
          v_227 = sen[1];
          v_228 = (v_227<500);
          v_231 = (v_228&&v_230);
          v_234 = (v_231&&v_233);
          v_243 = (v_234||v_242);
          v_252 = (v_243||v_251);
          if (v_252) {
            v_269 = true;
          } else {
            v_269 = v_267;
          };
          if (v_226) {
            r_3_St_4_Forward = true;
          } else {
            r_3_St_4_Forward = v_269;
          };
          if (v_252) {
            v_268 = Line_follower__St_4_Intersection;
          } else {
            v_268 = v_266;
          };
          if (v_226) {
            s_3_St_4_Forward = Line_follower__St_4_Obstacle;
          } else {
            s_3_St_4_Forward = v_268;
          };
          s_3 = s_3_St_4_Forward;
          r_3 = r_3_St_4_Forward;
          break;
        case Line_follower__St_4_Goright:
          v_216 = sen[0];
          v_217 = (v_216<500);
          if (v_217) {
            v_219 = true;
            v_218 = Line_follower__St_4_Goleft;
          } else {
            v_219 = pnr_3;
            v_218 = Line_follower__St_4_Goright;
          };
          v_213 = sen[3];
          v_214 = (v_213<500);
          v_211 = sen[1];
          v_212 = (v_211<500);
          v_215 = (v_212||v_214);
          if (v_215) {
            v_221 = true;
            v_220 = Line_follower__St_4_Pid;
          } else {
            v_221 = v_219;
            v_220 = v_218;
          };
          v_207 = sen[3];
          v_208 = (v_207<500);
          v_204 = sen[2];
          v_205 = (v_204<500);
          v_202 = sen[4];
          v_203 = (v_202<500);
          v_206 = (v_203&&v_205);
          v_209 = (v_206&&v_208);
          v_198 = sen[0];
          v_199 = (v_198<500);
          v_195 = sen[2];
          v_196 = (v_195<500);
          v_193 = sen[1];
          v_194 = (v_193<500);
          v_197 = (v_194&&v_196);
          v_200 = (v_197&&v_199);
          v_190 = sen[3];
          v_191 = (v_190<500);
          v_187 = sen[2];
          v_188 = (v_187<500);
          v_185 = sen[1];
          v_186 = (v_185<500);
          v_189 = (v_186&&v_188);
          v_192 = (v_189&&v_191);
          v_201 = (v_192||v_200);
          v_210 = (v_201||v_209);
          if (v_210) {
            v_223 = true;
          } else {
            v_223 = v_221;
          };
          if (v_184) {
            r_3_St_4_Goright = true;
          } else {
            r_3_St_4_Goright = v_223;
          };
          if (v_210) {
            v_222 = Line_follower__St_4_Intersection;
          } else {
            v_222 = v_220;
          };
          if (v_184) {
            s_3_St_4_Goright = Line_follower__St_4_Obstacle;
          } else {
            s_3_St_4_Goright = v_222;
          };
          s_3 = s_3_St_4_Goright;
          r_3 = r_3_St_4_Goright;
          break;
        case Line_follower__St_4_Goleft:
          v_174 = sen[4];
          v_175 = (v_174<500);
          if (v_175) {
            v_177 = true;
            v_176 = Line_follower__St_4_Goright;
          } else {
            v_177 = pnr_3;
            v_176 = Line_follower__St_4_Goleft;
          };
          v_171 = sen[3];
          v_172 = (v_171<500);
          v_169 = sen[1];
          v_170 = (v_169<500);
          v_173 = (v_170||v_172);
          if (v_173) {
            v_179 = true;
            v_178 = Line_follower__St_4_Pid;
          } else {
            v_179 = v_177;
            v_178 = v_176;
          };
          v_165 = sen[3];
          v_166 = (v_165<500);
          v_162 = sen[2];
          v_163 = (v_162<500);
          v_160 = sen[4];
          v_161 = (v_160<500);
          v_164 = (v_161&&v_163);
          v_167 = (v_164&&v_166);
          v_156 = sen[0];
          v_157 = (v_156<500);
          v_153 = sen[2];
          v_154 = (v_153<500);
          v_151 = sen[1];
          v_152 = (v_151<500);
          v_155 = (v_152&&v_154);
          v_158 = (v_155&&v_157);
          v_148 = sen[3];
          v_149 = (v_148<500);
          v_145 = sen[2];
          v_146 = (v_145<500);
          v_143 = sen[1];
          v_144 = (v_143<500);
          v_147 = (v_144&&v_146);
          v_150 = (v_147&&v_149);
          v_159 = (v_150||v_158);
          v_168 = (v_159||v_167);
          if (v_168) {
            v_181 = true;
          } else {
            v_181 = v_179;
          };
          if (v_142) {
            r_3_St_4_Goleft = true;
          } else {
            r_3_St_4_Goleft = v_181;
          };
          if (v_168) {
            v_180 = Line_follower__St_4_Intersection;
          } else {
            v_180 = v_178;
          };
          if (v_142) {
            s_3_St_4_Goleft = Line_follower__St_4_Obstacle;
          } else {
            s_3_St_4_Goleft = v_180;
          };
          s_3 = s_3_St_4_Goleft;
          r_3 = r_3_St_4_Goleft;
          break;
        case Line_follower__St_4_Pid:
          v_132 = sen[4];
          v_133 = (v_132<500);
          if (v_133) {
            v_135 = true;
            v_134 = Line_follower__St_4_Goright;
          } else {
            v_135 = pnr_3;
            v_134 = Line_follower__St_4_Pid;
          };
          v_130 = sen[0];
          v_131 = (v_130<500);
          if (v_131) {
            v_137 = true;
            v_136 = Line_follower__St_4_Goleft;
          } else {
            v_137 = v_135;
            v_136 = v_134;
          };
          v_126 = sen[3];
          v_127 = (v_126<500);
          v_123 = sen[2];
          v_124 = (v_123<500);
          v_121 = sen[4];
          v_122 = (v_121<500);
          v_125 = (v_122&&v_124);
          v_128 = (v_125&&v_127);
          v_117 = sen[0];
          v_118 = (v_117<500);
          v_114 = sen[2];
          v_115 = (v_114<500);
          v_112 = sen[1];
          v_113 = (v_112<500);
          v_116 = (v_113&&v_115);
          v_119 = (v_116&&v_118);
          v_109 = sen[3];
          v_110 = (v_109<500);
          v_106 = sen[2];
          v_107 = (v_106<500);
          v_104 = sen[1];
          v_105 = (v_104<500);
          v_108 = (v_105&&v_107);
          v_111 = (v_108&&v_110);
          v_120 = (v_111||v_119);
          v_129 = (v_120||v_128);
          if (v_129) {
            v_139 = true;
          } else {
            v_139 = v_137;
          };
          if (v_103) {
            r_3_St_4_Pid = true;
          } else {
            r_3_St_4_Pid = v_139;
          };
          if (v_129) {
            v_138 = Line_follower__St_4_Intersection;
          } else {
            v_138 = v_136;
          };
          if (v_103) {
            s_3_St_4_Pid = Line_follower__St_4_Obstacle;
          } else {
            s_3_St_4_Pid = v_138;
          };
          s_3 = s_3_St_4_Pid;
          r_3 = r_3_St_4_Pid;
          break;
        case Line_follower__St_4_Intersection:
          s_3 = s_3_St_4_Intersection;
          r_3 = r_3_St_4_Intersection;
          break;
        case Line_follower__St_4_Obstacle:
          s_3 = s_3_St_4_Obstacle;
          r_3 = r_3_St_4_Obstacle;
          break;
        case Line_follower__St_4_Parking:
          s_3 = s_3_St_4_Parking;
          r_3 = r_3_St_4_Parking;
          break;
        case Line_follower__St_4_Stop:
          s_3 = s_3_St_4_Stop;
          r_3 = r_3_St_4_Stop;
          break;
        default:
          break;
      };
      ck_6 = s_3;
      switch (ck_6) {
        case Line_follower__St_4_Forward:
          bound_right_St_5_Black_St_4_Forward = self->bound_right_1;
          bound_left_St_5_Black_St_4_Forward = self->bound_left_1;
          count_St_5_Black_St_4_Forward = self->count_1;
          v_r_St_5_Black_St_4_Forward = 80;
          v_l_St_5_Black_St_4_Forward = 80;
          dir_St_5_Black_St_4_Forward = 1;
          nr_3_St_4_Forward = false;
          ns_3_St_4_Forward = Line_follower__St_4_Forward;
          v_l_St_5_Black = v_l_St_5_Black_St_4_Forward;
          v_r_St_5_Black = v_r_St_5_Black_St_4_Forward;
          dir_St_5_Black = dir_St_5_Black_St_4_Forward;
          count_St_5_Black = count_St_5_Black_St_4_Forward;
          bound_left_St_5_Black = bound_left_St_5_Black_St_4_Forward;
          bound_right_St_5_Black = bound_right_St_5_Black_St_4_Forward;
          break;
        case Line_follower__St_4_Goright:
          bound_right_St_5_Black_St_4_Goright = self->bound_right_1;
          bound_left_St_5_Black_St_4_Goright = self->bound_left_1;
          count_St_5_Black_St_4_Goright = self->count_1;
          v_r_St_5_Black_St_4_Goright = 80;
          v_l_St_5_Black_St_4_Goright = 80;
          dir_St_5_Black_St_4_Goright = 4;
          nr_3_St_4_Goright = false;
          ns_3_St_4_Goright = Line_follower__St_4_Goright;
          v_l_St_5_Black = v_l_St_5_Black_St_4_Goright;
          v_r_St_5_Black = v_r_St_5_Black_St_4_Goright;
          dir_St_5_Black = dir_St_5_Black_St_4_Goright;
          count_St_5_Black = count_St_5_Black_St_4_Goright;
          bound_left_St_5_Black = bound_left_St_5_Black_St_4_Goright;
          bound_right_St_5_Black = bound_right_St_5_Black_St_4_Goright;
          break;
        case Line_follower__St_4_Goleft:
          bound_right_St_5_Black_St_4_Goleft = self->bound_right_1;
          bound_left_St_5_Black_St_4_Goleft = self->bound_left_1;
          count_St_5_Black_St_4_Goleft = self->count_1;
          v_r_St_5_Black_St_4_Goleft = 80;
          v_l_St_5_Black_St_4_Goleft = 80;
          dir_St_5_Black_St_4_Goleft = 3;
          nr_3_St_4_Goleft = false;
          ns_3_St_4_Goleft = Line_follower__St_4_Goleft;
          v_l_St_5_Black = v_l_St_5_Black_St_4_Goleft;
          v_r_St_5_Black = v_r_St_5_Black_St_4_Goleft;
          dir_St_5_Black = dir_St_5_Black_St_4_Goleft;
          count_St_5_Black = count_St_5_Black_St_4_Goleft;
          bound_left_St_5_Black = bound_left_St_5_Black_St_4_Goleft;
          bound_right_St_5_Black = bound_right_St_5_Black_St_4_Goleft;
          break;
        case Line_follower__St_4_Pid:
          bound_right_St_5_Black_St_4_Pid = self->bound_right_1;
          bound_left_St_5_Black_St_4_Pid = self->bound_left_1;
          count_St_5_Black_St_4_Pid = self->count_1;
          v_548 = sen[4];
          v_547 = sen[3];
          v_546 = sen[2];
          v_545 = sen[1];
          v_544 = sen[0];
          dir_St_5_Black_St_4_Pid = 2;
          nr_3_St_4_Pid = false;
          ns_3_St_4_Pid = Line_follower__St_4_Pid;
          r_7 = (r_4||r_3);
          if (r_7) {
            Line_follower__pidBlack_reset(&self->pidBlack_1);
          };
          Line_follower__pidBlack_step(v_544, v_545, v_546, v_547, v_548,
                                       &Line_follower__pidBlack_out_st,
                                       &self->pidBlack_1);
          v_l_St_5_Black_St_4_Pid = Line_follower__pidBlack_out_st.v_l;
          v_r_St_5_Black_St_4_Pid = Line_follower__pidBlack_out_st.v_r;
          v_l_St_5_Black = v_l_St_5_Black_St_4_Pid;
          v_r_St_5_Black = v_r_St_5_Black_St_4_Pid;
          dir_St_5_Black = dir_St_5_Black_St_4_Pid;
          count_St_5_Black = count_St_5_Black_St_4_Pid;
          bound_left_St_5_Black = bound_left_St_5_Black_St_4_Pid;
          bound_right_St_5_Black = bound_right_St_5_Black_St_4_Pid;
          break;
        case Line_follower__St_4_Stop:
          bound_right_St_5_Black_St_4_Stop = self->bound_right_1;
          bound_left_St_5_Black_St_4_Stop = self->bound_left_1;
          count_St_5_Black_St_4_Stop = self->count_1;
          v_r_St_5_Black_St_4_Stop = 0;
          v_l_St_5_Black_St_4_Stop = 0;
          dir_St_5_Black_St_4_Stop = 0;
          v_541 = (self->v_540-1);
          if (sec) {
            v_543 = v_541;
          } else {
            v_543 = self->v_542;
          };
          v_538 = (r_4||r_3);
          if (self->v_537) {
            v_539 = true;
          } else {
            v_539 = v_538;
          };
          if (v_539) {
            time = 2;
          } else {
            time = v_543;
          };
          v_536 = (time==0);
          if (v_536) {
            nr_3_St_4_Stop = true;
            ns_3_St_4_Stop = Line_follower__St_4_Parking;
          } else {
            nr_3_St_4_Stop = false;
            ns_3_St_4_Stop = Line_follower__St_4_Stop;
          };
          v_l_St_5_Black = v_l_St_5_Black_St_4_Stop;
          v_r_St_5_Black = v_r_St_5_Black_St_4_Stop;
          dir_St_5_Black = dir_St_5_Black_St_4_Stop;
          count_St_5_Black = count_St_5_Black_St_4_Stop;
          bound_left_St_5_Black = bound_left_St_5_Black_St_4_Stop;
          bound_right_St_5_Black = bound_right_St_5_Black_St_4_Stop;
          break;
        case Line_follower__St_4_Parking:
          count_St_5_Black_St_4_Parking = self->count_1;
          v_534 = (r_4||r_3);
          if (v_534) {
            pnr_1 = false;
          } else {
            pnr_1 = self->v_535;
          };
          r_1 = pnr_1;
          v_532 = (r_4||r_3);
          if (v_532) {
            ck_7 = Line_follower__St_2_Start;
          } else {
            ck_7 = self->v_533;
          };
          nr_3_St_4_Parking = false;
          ns_3_St_4_Parking = Line_follower__St_4_Parking;
          switch (ck_7) {
            case Line_follower__St_2_Start:
              v_531 = sen[4];
              v_530 = sen[3];
              v_529 = sen[2];
              v_528 = sen[1];
              v_527 = sen[0];
              v_524 = (self->v_523-1);
              if (sec) {
                v_526 = v_524;
              } else {
                v_526 = self->v_525;
              };
              v_520 = (r_4||r_3);
              v_521 = (v_520||r_1);
              if (self->v_519) {
                v_522 = true;
              } else {
                v_522 = v_521;
              };
              if (v_522) {
                time_1 = 4;
              } else {
                time_1 = v_526;
              };
              v_517 = (obs_right==true);
              if (v_517) {
                v_518 = 1;
              } else {
                v_518 = 0;
              };
              bound_right_St_5_Black_St_4_Parking_St_2_Start = (self->bound_right_1+v_518);
              v_515 = (obs_left==true);
              if (v_515) {
                v_516 = 1;
              } else {
                v_516 = 0;
              };
              bound_left_St_5_Black_St_4_Parking_St_2_Start = (self->bound_left_1+v_516);
              dir_St_5_Black_St_4_Parking_St_2_Start = 2;
              v_514 = (time_1==0);
              if (v_514) {
                nr_1_St_2_Start = true;
                ns_1_St_2_Start = Line_follower__St_2_Check;
              } else {
                nr_1_St_2_Start = false;
                ns_1_St_2_Start = Line_follower__St_2_Start;
              };
              v_513 = (r_4||r_3);
              r_6 = (v_513||r_1);
              if (r_6) {
                Line_follower__pidBlack_reset(&self->pidBlack);
              };
              Line_follower__pidBlack_step(v_527, v_528, v_529, v_530, v_531,
                                           &Line_follower__pidBlack_out_st,
                                           &self->pidBlack);
              v_l_St_5_Black_St_4_Parking_St_2_Start = Line_follower__pidBlack_out_st.v_l;
              v_r_St_5_Black_St_4_Parking_St_2_Start = Line_follower__pidBlack_out_st.v_r;
              v_l_St_5_Black_St_4_Parking = v_l_St_5_Black_St_4_Parking_St_2_Start;
              v_r_St_5_Black_St_4_Parking = v_r_St_5_Black_St_4_Parking_St_2_Start;
              dir_St_5_Black_St_4_Parking = dir_St_5_Black_St_4_Parking_St_2_Start;
              bound_left_St_5_Black_St_4_Parking = bound_left_St_5_Black_St_4_Parking_St_2_Start;
              bound_right_St_5_Black_St_4_Parking = bound_right_St_5_Black_St_4_Parking_St_2_Start;
              break;
            case Line_follower__St_2_Check:
              bound_right_St_5_Black_St_4_Parking_St_2_Check = self->bound_right_1;
              bound_left_St_5_Black_St_4_Parking_St_2_Check = self->bound_left_1;
              dir_St_5_Black_St_4_Parking_St_2_Check = 0;
              v_r_St_5_Black_St_4_Parking_St_2_Check = 0;
              v_l_St_5_Black_St_4_Parking_St_2_Check = 0;
              if (true) {
                v_510 = true;
              } else {
                v_510 = false;
              };
              if (true) {
                v_509 = Line_follower__St_2_Restart;
              } else {
                v_509 = Line_follower__St_2_Check;
              };
              v_l_St_5_Black_St_4_Parking = v_l_St_5_Black_St_4_Parking_St_2_Check;
              v_r_St_5_Black_St_4_Parking = v_r_St_5_Black_St_4_Parking_St_2_Check;
              dir_St_5_Black_St_4_Parking = dir_St_5_Black_St_4_Parking_St_2_Check;
              bound_left_St_5_Black_St_4_Parking = bound_left_St_5_Black_St_4_Parking_St_2_Check;
              bound_right_St_5_Black_St_4_Parking = bound_right_St_5_Black_St_4_Parking_St_2_Check;
              break;
            case Line_follower__St_2_Goleft:
              bound_right_St_5_Black_St_4_Parking_St_2_Goleft = self->bound_right_1;
              bound_left_St_5_Black_St_4_Parking_St_2_Goleft = self->bound_left_1;
              v_504 = (self->v_503-1);
              if (sec) {
                v_506 = v_504;
              } else {
                v_506 = self->v_505;
              };
              v_500 = (r_4||r_3);
              v_501 = (v_500||r_1);
              if (self->v_499) {
                v_502 = true;
              } else {
                v_502 = v_501;
              };
              if (v_502) {
                time_2 = 2;
              } else {
                time_2 = v_506;
              };
              dir_St_5_Black_St_4_Parking_St_2_Goleft = 0;
              v_r_St_5_Black_St_4_Parking_St_2_Goleft = 0;
              v_l_St_5_Black_St_4_Parking_St_2_Goleft = 0;
              v_498 = (time_2==0);
              if (v_498) {
                nr_1_St_2_Goleft = true;
                ns_1_St_2_Goleft = Line_follower__St_2_Parkleft;
              } else {
                nr_1_St_2_Goleft = false;
                ns_1_St_2_Goleft = Line_follower__St_2_Goleft;
              };
              v_l_St_5_Black_St_4_Parking = v_l_St_5_Black_St_4_Parking_St_2_Goleft;
              v_r_St_5_Black_St_4_Parking = v_r_St_5_Black_St_4_Parking_St_2_Goleft;
              dir_St_5_Black_St_4_Parking = dir_St_5_Black_St_4_Parking_St_2_Goleft;
              bound_left_St_5_Black_St_4_Parking = bound_left_St_5_Black_St_4_Parking_St_2_Goleft;
              bound_right_St_5_Black_St_4_Parking = bound_right_St_5_Black_St_4_Parking_St_2_Goleft;
              break;
            case Line_follower__St_2_Goright:
              bound_right_St_5_Black_St_4_Parking_St_2_Goright = self->bound_right_1;
              bound_left_St_5_Black_St_4_Parking_St_2_Goright = self->bound_left_1;
              v_495 = (self->v_494-1);
              if (sec) {
                v_497 = v_495;
              } else {
                v_497 = self->v_496;
              };
              v_491 = (r_4||r_3);
              v_492 = (v_491||r_1);
              if (self->v_490) {
                v_493 = true;
              } else {
                v_493 = v_492;
              };
              if (v_493) {
                time_3 = 2;
              } else {
                time_3 = v_497;
              };
              dir_St_5_Black_St_4_Parking_St_2_Goright = 0;
              v_r_St_5_Black_St_4_Parking_St_2_Goright = 0;
              v_l_St_5_Black_St_4_Parking_St_2_Goright = 0;
              v_489 = (time_3==0);
              if (v_489) {
                nr_1_St_2_Goright = true;
                ns_1_St_2_Goright = Line_follower__St_2_Parkright;
              } else {
                nr_1_St_2_Goright = false;
                ns_1_St_2_Goright = Line_follower__St_2_Goright;
              };
              v_l_St_5_Black_St_4_Parking = v_l_St_5_Black_St_4_Parking_St_2_Goright;
              v_r_St_5_Black_St_4_Parking = v_r_St_5_Black_St_4_Parking_St_2_Goright;
              dir_St_5_Black_St_4_Parking = dir_St_5_Black_St_4_Parking_St_2_Goright;
              bound_left_St_5_Black_St_4_Parking = bound_left_St_5_Black_St_4_Parking_St_2_Goright;
              bound_right_St_5_Black_St_4_Parking = bound_right_St_5_Black_St_4_Parking_St_2_Goright;
              break;
            case Line_follower__St_2_Restart:
              dir_St_5_Black_St_4_Parking_St_2_Restart = 0;
              v_r_St_5_Black_St_4_Parking_St_2_Restart = 0;
              v_l_St_5_Black_St_4_Parking_St_2_Restart = 0;
              bound_right_St_5_Black_St_4_Parking_St_2_Restart = 0;
              bound_left_St_5_Black_St_4_Parking_St_2_Restart = 0;
              v_486 = (self->v_485-1);
              if (sec) {
                v_488 = v_486;
              } else {
                v_488 = self->v_487;
              };
              v_482 = (r_4||r_3);
              v_483 = (v_482||r_1);
              if (self->v_481) {
                v_484 = true;
              } else {
                v_484 = v_483;
              };
              if (v_484) {
                time_4 = 2;
              } else {
                time_4 = v_488;
              };
              if (true) {
                nr_1_St_2_Restart = true;
              } else {
                nr_1_St_2_Restart = false;
              };
              if (true) {
                ns_1_St_2_Restart = Line_follower__St_2_Start;
              } else {
                ns_1_St_2_Restart = Line_follower__St_2_Restart;
              };
              v_l_St_5_Black_St_4_Parking = v_l_St_5_Black_St_4_Parking_St_2_Restart;
              v_r_St_5_Black_St_4_Parking = v_r_St_5_Black_St_4_Parking_St_2_Restart;
              dir_St_5_Black_St_4_Parking = dir_St_5_Black_St_4_Parking_St_2_Restart;
              bound_left_St_5_Black_St_4_Parking = bound_left_St_5_Black_St_4_Parking_St_2_Restart;
              bound_right_St_5_Black_St_4_Parking = bound_right_St_5_Black_St_4_Parking_St_2_Restart;
              break;
            case Line_follower__St_2_Parkright:
              bound_right_St_5_Black_St_4_Parking_St_2_Parkright = self->bound_right_1;
              bound_left_St_5_Black_St_4_Parking_St_2_Parkright = self->bound_left_1;
              v_478 = (self->v_477-1);
              if (sec) {
                v_480 = v_478;
              } else {
                v_480 = self->v_479;
              };
              v_474 = (r_4||r_3);
              v_475 = (v_474||r_1);
              if (self->v_473) {
                v_476 = true;
              } else {
                v_476 = v_475;
              };
              if (v_476) {
                time_5 = 2;
              } else {
                time_5 = v_480;
              };
              dir_St_5_Black_St_4_Parking_St_2_Parkright = 5;
              v_r_St_5_Black_St_4_Parking_St_2_Parkright = 63;
              v_l_St_5_Black_St_4_Parking_St_2_Parkright = 40;
              v_472 = (time_5<=0);
              if (v_472) {
                nr_1_St_2_Parkright = true;
                ns_1_St_2_Parkright = Line_follower__St_2_Final;
              } else {
                nr_1_St_2_Parkright = false;
                ns_1_St_2_Parkright = Line_follower__St_2_Parkright;
              };
              v_l_St_5_Black_St_4_Parking = v_l_St_5_Black_St_4_Parking_St_2_Parkright;
              v_r_St_5_Black_St_4_Parking = v_r_St_5_Black_St_4_Parking_St_2_Parkright;
              dir_St_5_Black_St_4_Parking = dir_St_5_Black_St_4_Parking_St_2_Parkright;
              bound_left_St_5_Black_St_4_Parking = bound_left_St_5_Black_St_4_Parking_St_2_Parkright;
              bound_right_St_5_Black_St_4_Parking = bound_right_St_5_Black_St_4_Parking_St_2_Parkright;
              break;
            case Line_follower__St_2_Parkleft:
              bound_right_St_5_Black_St_4_Parking_St_2_Parkleft = self->bound_right_1;
              bound_left_St_5_Black_St_4_Parking_St_2_Parkleft = self->bound_left_1;
              v_469 = (self->v_468-1);
              if (sec) {
                v_471 = v_469;
              } else {
                v_471 = self->v_470;
              };
              v_465 = (r_4||r_3);
              v_466 = (v_465||r_1);
              if (self->v_464) {
                v_467 = true;
              } else {
                v_467 = v_466;
              };
              if (v_467) {
                time_6 = 2;
              } else {
                time_6 = v_471;
              };
              dir_St_5_Black_St_4_Parking_St_2_Parkleft = 6;
              v_r_St_5_Black_St_4_Parking_St_2_Parkleft = 40;
              v_l_St_5_Black_St_4_Parking_St_2_Parkleft = 63;
              v_463 = (time_6<=0);
              if (v_463) {
                nr_1_St_2_Parkleft = true;
                ns_1_St_2_Parkleft = Line_follower__St_2_Final;
              } else {
                nr_1_St_2_Parkleft = false;
                ns_1_St_2_Parkleft = Line_follower__St_2_Parkleft;
              };
              v_l_St_5_Black_St_4_Parking = v_l_St_5_Black_St_4_Parking_St_2_Parkleft;
              v_r_St_5_Black_St_4_Parking = v_r_St_5_Black_St_4_Parking_St_2_Parkleft;
              dir_St_5_Black_St_4_Parking = dir_St_5_Black_St_4_Parking_St_2_Parkleft;
              bound_left_St_5_Black_St_4_Parking = bound_left_St_5_Black_St_4_Parking_St_2_Parkleft;
              bound_right_St_5_Black_St_4_Parking = bound_right_St_5_Black_St_4_Parking_St_2_Parkleft;
              break;
            case Line_follower__St_2_Final:
              bound_right_St_5_Black_St_4_Parking_St_2_Final = self->bound_right_1;
              bound_left_St_5_Black_St_4_Parking_St_2_Final = self->bound_left_1;
              dir_St_5_Black_St_4_Parking_St_2_Final = 9;
              v_r_St_5_Black_St_4_Parking_St_2_Final = 0;
              v_l_St_5_Black_St_4_Parking_St_2_Final = 0;
              nr_1_St_2_Final = false;
              ns_1_St_2_Final = Line_follower__St_2_Final;
              v_l_St_5_Black_St_4_Parking = v_l_St_5_Black_St_4_Parking_St_2_Final;
              v_r_St_5_Black_St_4_Parking = v_r_St_5_Black_St_4_Parking_St_2_Final;
              dir_St_5_Black_St_4_Parking = dir_St_5_Black_St_4_Parking_St_2_Final;
              bound_left_St_5_Black_St_4_Parking = bound_left_St_5_Black_St_4_Parking_St_2_Final;
              bound_right_St_5_Black_St_4_Parking = bound_right_St_5_Black_St_4_Parking_St_2_Final;
              break;
            default:
              break;
          };
          v_l_St_5_Black = v_l_St_5_Black_St_4_Parking;
          v_r_St_5_Black = v_r_St_5_Black_St_4_Parking;
          dir_St_5_Black = dir_St_5_Black_St_4_Parking;
          count_St_5_Black = count_St_5_Black_St_4_Parking;
          bound_left_St_5_Black = bound_left_St_5_Black_St_4_Parking;
          bound_right_St_5_Black = bound_right_St_5_Black_St_4_Parking;
          break;
        case Line_follower__St_4_Obstacle:
          bound_right_St_5_Black_St_4_Obstacle = self->bound_right_1;
          bound_left_St_5_Black_St_4_Obstacle = self->bound_left_1;
          count_St_5_Black_St_4_Obstacle = self->count_1;
          r_5 = (r_4||r_3);
          if (r_5) {
            Line_follower__obstacle_avoid_reset(&self->obstacle_avoid);
          };
          Line_follower__obstacle_avoid_step(obs_left, ir_front_left, sen,
                                             &Line_follower__obstacle_avoid_out_st,
                                             &self->obstacle_avoid);
          v_l_St_5_Black_St_4_Obstacle = Line_follower__obstacle_avoid_out_st.v_l;
          v_r_St_5_Black_St_4_Obstacle = Line_follower__obstacle_avoid_out_st.v_r;
          dir_St_5_Black_St_4_Obstacle = Line_follower__obstacle_avoid_out_st.dir;
          v_l_St_5_Black = v_l_St_5_Black_St_4_Obstacle;
          v_r_St_5_Black = v_r_St_5_Black_St_4_Obstacle;
          dir_St_5_Black = dir_St_5_Black_St_4_Obstacle;
          count_St_5_Black = count_St_5_Black_St_4_Obstacle;
          bound_left_St_5_Black = bound_left_St_5_Black_St_4_Obstacle;
          bound_right_St_5_Black = bound_right_St_5_Black_St_4_Obstacle;
          break;
        case Line_follower__St_4_Intersection:
          bound_right_St_5_Black_St_4_Intersection = self->bound_right_1;
          bound_left_St_5_Black_St_4_Intersection = self->bound_left_1;
          v_460 = (r_4||r_3);
          if (v_460) {
            pnr_2 = false;
          } else {
            pnr_2 = self->v_461;
          };
          r_2 = pnr_2;
          v_458 = (r_4||r_3);
          if (v_458) {
            ck_8 = Line_follower__St_3_Counter;
          } else {
            ck_8 = self->v_459;
          };
          switch (ck_8) {
            case Line_follower__St_3_Counter:
              count_St_5_Black_St_4_Intersection_St_3_Counter = (self->count_1+1);
              v_r_St_5_Black_St_4_Intersection_St_3_Counter = 40;
              v_l_St_5_Black_St_4_Intersection_St_3_Counter = 40;
              dir_St_5_Black_St_4_Intersection_St_3_Counter = 2;
              if (true) {
                nr_2_St_3_Counter = true;
              } else {
                nr_2_St_3_Counter = false;
              };
              if (true) {
                ns_2_St_3_Counter = Line_follower__St_3_Forward;
              } else {
                ns_2_St_3_Counter = Line_follower__St_3_Counter;
              };
              v_l_St_5_Black_St_4_Intersection = v_l_St_5_Black_St_4_Intersection_St_3_Counter;
              v_r_St_5_Black_St_4_Intersection = v_r_St_5_Black_St_4_Intersection_St_3_Counter;
              dir_St_5_Black_St_4_Intersection = dir_St_5_Black_St_4_Intersection_St_3_Counter;
              count_St_5_Black_St_4_Intersection = count_St_5_Black_St_4_Intersection_St_3_Counter;
              break;
            case Line_follower__St_3_Forward:
              count_St_5_Black_St_4_Intersection_St_3_Forward = self->count_1;
              v_r_St_5_Black_St_4_Intersection_St_3_Forward = 40;
              v_l_St_5_Black_St_4_Intersection_St_3_Forward = 40;
              dir_St_5_Black_St_4_Intersection_St_3_Forward = 1;
              v_448 = sen[3];
              v_449 = (v_448>=500);
              v_445 = sen[2];
              v_446 = (v_445>=500);
              v_442 = sen[1];
              v_443 = (v_442>=500);
              v_439 = sen[0];
              v_440 = (v_439>=500);
              v_437 = sen[4];
              v_438 = (v_437<=500);
              v_441 = (v_438&&v_440);
              v_444 = (v_441&&v_443);
              v_447 = (v_444&&v_446);
              v_450 = (v_447&&v_449);
              v_433 = sen[4];
              v_434 = (v_433>=500);
              v_430 = sen[2];
              v_431 = (v_430>=500);
              v_427 = sen[1];
              v_428 = (v_427>=500);
              v_424 = sen[0];
              v_425 = (v_424>=500);
              v_422 = sen[3];
              v_423 = (v_422<=500);
              v_426 = (v_423&&v_425);
              v_429 = (v_426&&v_428);
              v_432 = (v_429&&v_431);
              v_435 = (v_432&&v_434);
              v_418 = sen[4];
              v_419 = (v_418>=500);
              v_415 = sen[3];
              v_416 = (v_415>=500);
              v_412 = sen[1];
              v_413 = (v_412>=500);
              v_409 = sen[0];
              v_410 = (v_409>=500);
              v_407 = sen[2];
              v_408 = (v_407<=500);
              v_411 = (v_408&&v_410);
              v_414 = (v_411&&v_413);
              v_417 = (v_414&&v_416);
              v_420 = (v_417&&v_419);
              v_403 = sen[4];
              v_404 = (v_403>=500);
              v_400 = sen[3];
              v_401 = (v_400>=500);
              v_397 = sen[2];
              v_398 = (v_397>=500);
              v_394 = sen[0];
              v_395 = (v_394>=500);
              v_392 = sen[1];
              v_393 = (v_392<=500);
              v_396 = (v_393&&v_395);
              v_399 = (v_396&&v_398);
              v_402 = (v_399&&v_401);
              v_405 = (v_402&&v_404);
              v_389 = sen[4];
              v_390 = (v_389>=500);
              v_386 = sen[3];
              v_387 = (v_386>=500);
              v_383 = sen[2];
              v_384 = (v_383>=500);
              v_380 = sen[1];
              v_381 = (v_380>=500);
              v_378 = sen[0];
              v_379 = (v_378<=500);
              v_382 = (v_379&&v_381);
              v_385 = (v_382&&v_384);
              v_388 = (v_385&&v_387);
              v_391 = (v_388&&v_390);
              v_406 = (v_391||v_405);
              v_421 = (v_406||v_420);
              v_436 = (v_421||v_435);
              v_451 = (v_436||v_450);
              v_370 = sen[3];
              v_371 = (v_370>=500);
              v_367 = sen[2];
              v_368 = (v_367>=500);
              v_364 = sen[1];
              v_365 = (v_364>=500);
              v_361 = sen[0];
              v_362 = (v_361>=500);
              v_359 = sen[4];
              v_360 = (v_359<=500);
              v_363 = (v_360&&v_362);
              v_366 = (v_363&&v_365);
              v_369 = (v_366&&v_368);
              v_372 = (v_369&&v_371);
              v_355 = sen[4];
              v_356 = (v_355>=500);
              v_352 = sen[2];
              v_353 = (v_352>=500);
              v_349 = sen[1];
              v_350 = (v_349>=500);
              v_346 = sen[0];
              v_347 = (v_346>=500);
              v_344 = sen[3];
              v_345 = (v_344<=500);
              v_348 = (v_345&&v_347);
              v_351 = (v_348&&v_350);
              v_354 = (v_351&&v_353);
              v_357 = (v_354&&v_356);
              v_340 = sen[4];
              v_341 = (v_340>=500);
              v_337 = sen[3];
              v_338 = (v_337>=500);
              v_334 = sen[1];
              v_335 = (v_334>=500);
              v_331 = sen[0];
              v_332 = (v_331>=500);
              v_329 = sen[2];
              v_330 = (v_329<=500);
              v_333 = (v_330&&v_332);
              v_336 = (v_333&&v_335);
              v_339 = (v_336&&v_338);
              v_342 = (v_339&&v_341);
              v_325 = sen[4];
              v_326 = (v_325>=500);
              v_322 = sen[3];
              v_323 = (v_322>=500);
              v_319 = sen[2];
              v_320 = (v_319>=500);
              v_316 = sen[0];
              v_317 = (v_316>=500);
              v_314 = sen[1];
              v_315 = (v_314<=500);
              v_318 = (v_315&&v_317);
              v_321 = (v_318&&v_320);
              v_324 = (v_321&&v_323);
              v_327 = (v_324&&v_326);
              v_311 = sen[4];
              v_312 = (v_311>=500);
              v_308 = sen[3];
              v_309 = (v_308>=500);
              v_305 = sen[2];
              v_306 = (v_305>=500);
              v_302 = sen[1];
              v_303 = (v_302>=500);
              v_300 = sen[0];
              v_301 = (v_300<=500);
              v_304 = (v_301&&v_303);
              v_307 = (v_304&&v_306);
              v_310 = (v_307&&v_309);
              v_313 = (v_310&&v_312);
              v_328 = (v_313||v_327);
              v_343 = (v_328||v_342);
              v_358 = (v_343||v_357);
              v_373 = (v_358||v_372);
              v_293 = sen[4];
              v_294 = (v_293>=500);
              v_290 = sen[3];
              v_291 = (v_290>=500);
              v_287 = sen[2];
              v_288 = (v_287>=500);
              v_284 = sen[1];
              v_285 = (v_284>=500);
              v_282 = sen[0];
              v_283 = (v_282>=500);
              v_286 = (v_283&&v_285);
              v_289 = (v_286&&v_288);
              v_292 = (v_289&&v_291);
              v_295 = (v_292&&v_294);
              v_l_St_5_Black_St_4_Intersection = v_l_St_5_Black_St_4_Intersection_St_3_Forward;
              v_r_St_5_Black_St_4_Intersection = v_r_St_5_Black_St_4_Intersection_St_3_Forward;
              dir_St_5_Black_St_4_Intersection = dir_St_5_Black_St_4_Intersection_St_3_Forward;
              count_St_5_Black_St_4_Intersection = count_St_5_Black_St_4_Intersection_St_3_Forward;
              break;
            case Line_follower__St_3_RightTurn:
              count_St_5_Black_St_4_Intersection_St_3_RightTurn = self->count_1;
              v_r_St_5_Black_St_4_Intersection_St_3_RightTurn = 40;
              v_l_St_5_Black_St_4_Intersection_St_3_RightTurn = 40;
              dir_St_5_Black_St_4_Intersection_St_3_RightTurn = 4;
              v_279 = sen[3];
              v_280 = (v_279<500);
              v_277 = sen[4];
              v_278 = (v_277<500);
              v_281 = (v_278||v_280);
              if (v_281) {
                nr_2_St_3_RightTurn = true;
                ns_2_St_3_RightTurn = Line_follower__St_3_Final;
              } else {
                nr_2_St_3_RightTurn = false;
                ns_2_St_3_RightTurn = Line_follower__St_3_RightTurn;
              };
              v_l_St_5_Black_St_4_Intersection = v_l_St_5_Black_St_4_Intersection_St_3_RightTurn;
              v_r_St_5_Black_St_4_Intersection = v_r_St_5_Black_St_4_Intersection_St_3_RightTurn;
              dir_St_5_Black_St_4_Intersection = dir_St_5_Black_St_4_Intersection_St_3_RightTurn;
              count_St_5_Black_St_4_Intersection = count_St_5_Black_St_4_Intersection_St_3_RightTurn;
              break;
            case Line_follower__St_3_LeftTurn:
              v_275 = sen[0];
              count_St_5_Black_St_4_Intersection_St_3_LeftTurn = self->count_1;
              v_r_St_5_Black_St_4_Intersection_St_3_LeftTurn = 60;
              v_l_St_5_Black_St_4_Intersection_St_3_LeftTurn = 60;
              dir_St_5_Black_St_4_Intersection_St_3_LeftTurn = 3;
              v_276 = (v_275<500);
              if (v_276) {
                nr_2_St_3_LeftTurn = true;
                ns_2_St_3_LeftTurn = Line_follower__St_3_Final;
              } else {
                nr_2_St_3_LeftTurn = false;
                ns_2_St_3_LeftTurn = Line_follower__St_3_LeftTurn;
              };
              v_l_St_5_Black_St_4_Intersection = v_l_St_5_Black_St_4_Intersection_St_3_LeftTurn;
              v_r_St_5_Black_St_4_Intersection = v_r_St_5_Black_St_4_Intersection_St_3_LeftTurn;
              dir_St_5_Black_St_4_Intersection = dir_St_5_Black_St_4_Intersection_St_3_LeftTurn;
              count_St_5_Black_St_4_Intersection = count_St_5_Black_St_4_Intersection_St_3_LeftTurn;
              break;
            case Line_follower__St_3_Halt:
              count_St_5_Black_St_4_Intersection_St_3_Halt = self->count_1;
              v_r_St_5_Black_St_4_Intersection_St_3_Halt = 0;
              v_l_St_5_Black_St_4_Intersection_St_3_Halt = 0;
              dir_St_5_Black_St_4_Intersection_St_3_Halt = 0;
              nr_2_St_3_Halt = false;
              ns_2_St_3_Halt = Line_follower__St_3_Halt;
              v_l_St_5_Black_St_4_Intersection = v_l_St_5_Black_St_4_Intersection_St_3_Halt;
              v_r_St_5_Black_St_4_Intersection = v_r_St_5_Black_St_4_Intersection_St_3_Halt;
              dir_St_5_Black_St_4_Intersection = dir_St_5_Black_St_4_Intersection_St_3_Halt;
              count_St_5_Black_St_4_Intersection = count_St_5_Black_St_4_Intersection_St_3_Halt;
              break;
            case Line_follower__St_3_Final:
              count_St_5_Black_St_4_Intersection_St_3_Final = self->count_1;
              v_r_St_5_Black_St_4_Intersection_St_3_Final = 0;
              v_l_St_5_Black_St_4_Intersection_St_3_Final = 0;
              dir_St_5_Black_St_4_Intersection_St_3_Final = 90;
              nr_2_St_3_Final = false;
              ns_2_St_3_Final = Line_follower__St_3_Final;
              v_l_St_5_Black_St_4_Intersection = v_l_St_5_Black_St_4_Intersection_St_3_Final;
              v_r_St_5_Black_St_4_Intersection = v_r_St_5_Black_St_4_Intersection_St_3_Final;
              dir_St_5_Black_St_4_Intersection = dir_St_5_Black_St_4_Intersection_St_3_Final;
              count_St_5_Black_St_4_Intersection = count_St_5_Black_St_4_Intersection_St_3_Final;
              break;
            default:
              break;
          };
          v_l_St_5_Black = v_l_St_5_Black_St_4_Intersection;
          v_r_St_5_Black = v_r_St_5_Black_St_4_Intersection;
          dir_St_5_Black = dir_St_5_Black_St_4_Intersection;
          count_St_5_Black = count_St_5_Black_St_4_Intersection;
          bound_left_St_5_Black = bound_left_St_5_Black_St_4_Intersection;
          bound_right_St_5_Black = bound_right_St_5_Black_St_4_Intersection;
          break;
        default:
          break;
      };
      _out->v_l = v_l_St_5_Black;
      _out->v_r = v_r_St_5_Black;
      _out->dir = dir_St_5_Black;
      count = count_St_5_Black;
      bound_left = bound_left_St_5_Black;
      bound_right = bound_right_St_5_Black;
      switch (ck_6) {
        case Line_follower__St_4_Parking:
          switch (ck_7) {
            case Line_follower__St_2_Check:
              v_508 = (bound_right==0);
              if (v_508) {
                v_512 = true;
                v_511 = Line_follower__St_2_Goright;
              } else {
                v_512 = v_510;
                v_511 = v_509;
              };
              v_507 = (bound_left==0);
              if (v_507) {
                nr_1_St_2_Check = true;
                ns_1_St_2_Check = Line_follower__St_2_Goleft;
              } else {
                nr_1_St_2_Check = v_512;
                ns_1_St_2_Check = v_511;
              };
              ns_1 = ns_1_St_2_Check;
              nr_1 = nr_1_St_2_Check;
              break;
            case Line_follower__St_2_Final:
              ns_1 = ns_1_St_2_Final;
              nr_1 = nr_1_St_2_Final;
              break;
            case Line_follower__St_2_Parkleft:
              ns_1 = ns_1_St_2_Parkleft;
              nr_1 = nr_1_St_2_Parkleft;
              break;
            case Line_follower__St_2_Parkright:
              ns_1 = ns_1_St_2_Parkright;
              nr_1 = nr_1_St_2_Parkright;
              break;
            case Line_follower__St_2_Restart:
              ns_1 = ns_1_St_2_Restart;
              nr_1 = nr_1_St_2_Restart;
              break;
            case Line_follower__St_2_Goright:
              ns_1 = ns_1_St_2_Goright;
              nr_1 = nr_1_St_2_Goright;
              break;
            case Line_follower__St_2_Goleft:
              ns_1 = ns_1_St_2_Goleft;
              nr_1 = nr_1_St_2_Goleft;
              break;
            case Line_follower__St_2_Start:
              ns_1 = ns_1_St_2_Start;
              nr_1 = nr_1_St_2_Start;
              break;
            default:
              break;
          };
          ns_3 = ns_3_St_4_Parking;
          nr_3 = nr_3_St_4_Parking;
          break;
        case Line_follower__St_4_Obstacle:
          v_462 = (_out->dir==9);
          if (v_462) {
            nr_3_St_4_Obstacle = true;
            ns_3_St_4_Obstacle = Line_follower__St_4_Pid;
          } else {
            nr_3_St_4_Obstacle = false;
            ns_3_St_4_Obstacle = Line_follower__St_4_Obstacle;
          };
          ns_3 = ns_3_St_4_Obstacle;
          nr_3 = nr_3_St_4_Obstacle;
          break;
        case Line_follower__St_4_Intersection:
          v_272 = (_out->dir==0);
          if (v_272) {
            v_274 = true;
            v_273 = Line_follower__St_4_Stop;
          } else {
            v_274 = false;
            v_273 = Line_follower__St_4_Intersection;
          };
          v_271 = (_out->dir==90);
          if (v_271) {
            nr_3_St_4_Intersection = true;
            ns_3_St_4_Intersection = Line_follower__St_4_Forward;
          } else {
            nr_3_St_4_Intersection = v_274;
            ns_3_St_4_Intersection = v_273;
          };
          ns_3 = ns_3_St_4_Intersection;
          nr_3 = nr_3_St_4_Intersection;
          switch (ck_8) {
            case Line_follower__St_3_Forward:
              v_452 = (count==5);
              v_453 = (v_451&&v_452);
              if (v_453) {
                v_455 = true;
                v_454 = Line_follower__St_3_Halt;
              } else {
                v_455 = false;
                v_454 = Line_follower__St_3_Forward;
              };
              v_375 = (count==4);
              v_374 = (count==3);
              v_376 = (v_374||v_375);
              v_377 = (v_373&&v_376);
              if (v_377) {
                v_457 = true;
                v_456 = Line_follower__St_3_LeftTurn;
              } else {
                v_457 = v_455;
                v_456 = v_454;
              };
              v_297 = (count==2);
              v_296 = (count==1);
              v_298 = (v_296||v_297);
              v_299 = (v_295&&v_298);
              if (v_299) {
                nr_2_St_3_Forward = true;
                ns_2_St_3_Forward = Line_follower__St_3_RightTurn;
              } else {
                nr_2_St_3_Forward = v_457;
                ns_2_St_3_Forward = v_456;
              };
              ns_2 = ns_2_St_3_Forward;
              nr_2 = nr_2_St_3_Forward;
              break;
            case Line_follower__St_3_Final:
              ns_2 = ns_2_St_3_Final;
              nr_2 = nr_2_St_3_Final;
              break;
            case Line_follower__St_3_Halt:
              ns_2 = ns_2_St_3_Halt;
              nr_2 = nr_2_St_3_Halt;
              break;
            case Line_follower__St_3_LeftTurn:
              ns_2 = ns_2_St_3_LeftTurn;
              nr_2 = nr_2_St_3_LeftTurn;
              break;
            case Line_follower__St_3_RightTurn:
              ns_2 = ns_2_St_3_RightTurn;
              nr_2 = nr_2_St_3_RightTurn;
              break;
            case Line_follower__St_3_Counter:
              ns_2 = ns_2_St_3_Counter;
              nr_2 = nr_2_St_3_Counter;
              break;
            default:
              break;
          };
          break;
        case Line_follower__St_4_Stop:
          ns_3 = ns_3_St_4_Stop;
          nr_3 = nr_3_St_4_Stop;
          break;
        case Line_follower__St_4_Pid:
          ns_3 = ns_3_St_4_Pid;
          nr_3 = nr_3_St_4_Pid;
          break;
        case Line_follower__St_4_Goleft:
          ns_3 = ns_3_St_4_Goleft;
          nr_3 = nr_3_St_4_Goleft;
          break;
        case Line_follower__St_4_Goright:
          ns_3 = ns_3_St_4_Goright;
          nr_3 = nr_3_St_4_Goright;
          break;
        case Line_follower__St_4_Forward:
          ns_3 = ns_3_St_4_Forward;
          nr_3 = nr_3_St_4_Forward;
          break;
        default:
          break;
      };
      break;
    default:
      break;
  };
  self->bound_right_1 = bound_right;
  self->bound_left_1 = bound_left;
  self->count_1 = count;
  self->pnr_4 = nr_4;
  self->ck = ns_4;
  switch (ck_2) {
    case Line_follower__St_5_White:
      self->v_611 = nr;
      self->v_605 = ns;
      break;
    case Line_follower__St_5_Black:
      self->v_549 = nr_3;
      self->v_270 = ns_3;
      switch (ck_6) {
        case Line_follower__St_4_Stop:
          self->v_542 = time;
          self->v_540 = time;
          self->v_537 = false;
          break;
        case Line_follower__St_4_Parking:
          self->v_535 = nr_1;
          self->v_533 = ns_1;
          switch (ck_7) {
            case Line_follower__St_2_Start:
              self->v_525 = time_1;
              self->v_523 = time_1;
              self->v_519 = false;
              break;
            case Line_follower__St_2_Goleft:
              self->v_505 = time_2;
              self->v_503 = time_2;
              self->v_499 = false;
              break;
            case Line_follower__St_2_Goright:
              self->v_496 = time_3;
              self->v_494 = time_3;
              self->v_490 = false;
              break;
            case Line_follower__St_2_Restart:
              self->v_487 = time_4;
              self->v_485 = time_4;
              self->v_481 = false;
              break;
            case Line_follower__St_2_Parkright:
              self->v_479 = time_5;
              self->v_477 = time_5;
              self->v_473 = false;
              break;
            case Line_follower__St_2_Parkleft:
              self->v_470 = time_6;
              self->v_468 = time_6;
              self->v_464 = false;
              break;
            default:
              break;
          };
          break;
        case Line_follower__St_4_Intersection:
          self->v_461 = nr_2;
          self->v_459 = ns_2;
          break;
        default:
          break;
      };
      break;
    default:
      break;
  };;
}

