#include "gait.h"
#include "leg.h"
//#include "tail.h"
#include "tgait.h" 

const float kp_walk = 0.03; // 0.02
const float kd_walk = 1.0;
const int walk_period = 2000; // 720;

/*
Explanation of parameters:

Duty Factor: Percentage of time the leg is in a standing position
(0 is always "fast", 1 is always "slow") (takes decimal values of 0-1)

Sweep: angle width of "slow phase" in degrees (takes integer values 0-360)

Down: center angle of the "slow phase" in degrees (takes integer values 0-360)

Phase: Determines the relative timing of the legs. Takes values from 0-1.
A phase of .5 will( have the leg at the opposite part of the cycle from a leg
with a phase of 0 ) (takes decimal values 0-1)
*/

//Leg 1 (Left Front) Parameters:
const float leg_dutyf = 0.42;
const float leg_sweep = 40.0;
const float leg_down = 20.0;
const float leg_phase1 = 0.50;
const float leg_phase2 = 0.0;

// -------------------------------------- //


/*
 struct tGait 
{
  //int id;
  bool first; //should always be set to true and will set be false during first run
  float kp;
  float kd;
  float period; //amount of time at each tail location in milliseconds
  int num_locs; // number of locations in the locations array
  float locations[10]; //these should be positions or angles and then converted to positions
  int curr_loc_ind; 
  int phase_inc; //if we should be incrementing up the locations or down the location array
  int count; 
};

 */
//TAIL GAITS
int horizontal = 512;
int vertical = 768;
//position 512 is horizontal (parallel to the ground) 
const tGait no_tail { 
  true,
  0, 0,
  1000, //needs to be one because we mod by period,
  1,
  {512, 0, 0, 0, 0, 0,0,0,0,0},
  0,
  1,
  0
};
const tGait standard_tail { 
  true,
  kp_walk, kd_walk,
  5000, //milliseconds
  4,
  {512, 540, 560, 580, 0, 0, 0, 0, 0, 0}, // these are angles,
  0,
  1,
  0
};

//----------------------------------------//
const Gait stand_gait {
    STAND,
    kp_walk, kd_walk,
    {leg_sweep, leg_sweep, leg_sweep, leg_sweep, leg_sweep, leg_sweep},
    {leg_down, leg_down, leg_down, leg_down, leg_down, leg_down},
    {1, 1, 1, 1, 1, 1},
    {walk_period, walk_period, walk_period, walk_period, walk_period, walk_period},
    {leg_dutyf, leg_dutyf, leg_dutyf, leg_dutyf, leg_dutyf, leg_dutyf},
    {leg_phase1, leg_phase1, leg_phase1, leg_phase1, leg_phase1, leg_phase1},
    no_tail
    
};

const Gait walk_gait {
    WALK,
    kp_walk, kd_walk,
    {leg_sweep, leg_sweep, leg_sweep, leg_sweep, leg_sweep, leg_sweep},
    {leg_down, leg_down, leg_down, leg_down, leg_down, leg_down},
    {1, 1, 1, 1, 1, 1},
    {walk_period, walk_period, walk_period, walk_period, walk_period, walk_period},
    {leg_dutyf, leg_dutyf, leg_dutyf, leg_dutyf, leg_dutyf, leg_dutyf},
    {leg_phase1, leg_phase2, leg_phase1, leg_phase2, leg_phase1, leg_phase2},
    standard_tail
};

const Gait reverse_gait {
    REVERSE,
    kp_walk, kd_walk,
    {leg_sweep, leg_sweep, leg_sweep, leg_sweep, leg_sweep, leg_sweep},
    {leg_down, leg_down, leg_down, leg_down, leg_down, leg_down},
    {-1, -1, -1, -1, -1, -1},
    {walk_period, walk_period, walk_period, walk_period, walk_period, walk_period},
    {leg_dutyf, leg_dutyf, leg_dutyf, leg_dutyf, leg_dutyf, leg_dutyf},
    {leg_phase1, leg_phase2, leg_phase1, leg_phase2, leg_phase1, leg_phase2},
    no_tail
};

const Gait left_gait {
    LEFT,
    kp_walk, kd_walk,
    {leg_sweep, leg_sweep, leg_sweep, leg_sweep, leg_sweep, leg_sweep},
    {leg_down, leg_down, leg_down, leg_down, leg_down, leg_down},
    {-1, -1, -1, 1, 1, 1},
    {walk_period, walk_period, walk_period, walk_period, walk_period, walk_period},
    {leg_dutyf, leg_dutyf, leg_dutyf, leg_dutyf, leg_dutyf, leg_dutyf},
    {leg_phase1, leg_phase2, leg_phase1, leg_phase2, leg_phase1, leg_phase2},
    no_tail
};

const Gait right_gait {
    RIGHT,
    kp_walk, kd_walk,
    {leg_sweep, leg_sweep, leg_sweep, leg_sweep, leg_sweep, leg_sweep},
    {leg_down, leg_down, leg_down, leg_down, leg_down, leg_down},
    {1, 1, 1, -1, -1, -1},
    {walk_period, walk_period, walk_period, walk_period, walk_period, walk_period},
    {leg_dutyf, leg_dutyf, leg_dutyf, leg_dutyf, leg_dutyf, leg_dutyf},
    {leg_phase1, leg_phase2, leg_phase1, leg_phase2, leg_phase1, leg_phase2},
    no_tail
};

const Gait gait_order[TOTAL_GAITS] = {stand_gait, walk_gait}; //, reverse_gait, left_gait, right_gait};
