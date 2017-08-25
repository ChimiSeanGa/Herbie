#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "car.h"

// Action identifiers
enum Action {
   stop,
   forward,
   f_left,
   f_right,
   backward,
   b_left,
   b_right,
   left,
   right
};

// Data structure to hold state information
struct state {
   int action;
   int loop;
};

class Controller {

state *state_list;
int num_states = 0;
int cur_state = 0;
Car *car;

public:
   // Set car variable and load script
   Controller(Car *car, state* state_list, int num_states);

   // Get next action
   void next_action();

private:
   // Translate action identifier to function
   void make_action(int action_id);
};

#endif
