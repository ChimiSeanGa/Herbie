#include "controller.h"

// Constructor for Controller class
Controller::Controller(Car *car, state* state_list, int num_states) {
   this->car = car;
   this->state_list = state_list;
   this->num_states = num_states;
}

// Performs the next available action in the state list
void Controller::next_action() {
   // If there are no more actions, stop the car and exit the program
   if (cur_state >= num_states) {
      make_action(Action::stop);
      exit(EXIT_SUCCESS);
   }

   // Retrieve the data for the current state
   state *st = &state_list[cur_state];

   // Perform the current action
   make_action(st->action);

   // Check if current state is finished
   if (st->loop == 0)
      cur_state++;
   else
      st->loop--;
}

void Controller::make_action(int action_id) {
   switch(action_id) {
      case Action::stop:
         car->stop_motion();
         car->stop_turn();
         break;
      case Action::forward:
         car->stop_turn();
         car->move_forward();
         break;
      case Action::f_left:
         car->move_forward();
         car->turn_left();
         break;
      case Action::f_right:
         car->move_forward();
         car->turn_right();
         break;
      case Action::backward:
         car->stop_turn();
         car->move_backward();
         break;
      case Action::b_left:
         car->move_backward();
         car->turn_left();
         break;
      case Action::b_right:
         car->move_backward();
         car->turn_right();
         break;
      case Action::left:
         car->stop_motion();
         car->turn_left();
         break;
      case Action::right:
         car->stop_motion();
         car->turn_right();
         break;
   }
}
