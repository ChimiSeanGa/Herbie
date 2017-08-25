#include "car.h"
#include "controller.h"

// Initialize a car object
Car car;

/* Create a list of states for the car.
   Each number denotes the number of loops to repeat the same action.
   Each loop is 100ms, so performing an action 10 times would result in the
   action being performed for 2000ms, or 2s.
*/
state state_list[] = {
   {Action::forward, 20},
   {Action::f_left, 10},
   {Action::f_right, 10},
   {Action::b_right, 30},
   {Action::b_left, 10}
};

// Initialize the car controller.
Controller controller(&car, state_list, sizeof(state_list)/sizeof(state));

// Initialize the IO ports of the car
void setup() {
   car.init();
}

// Perform an action every 100ms
void loop() {
   controller.next_action();
   delay(100);
}
