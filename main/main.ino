#include "car.h"
#include "controller.h"

Car car;
state state_list[] = {
   {Action::forward, 20},
   {Action::f_left, 10},
   {Action::f_right, 10},
   {Action::b_right, 30},
   {Action::b_left, 10}
};
Controller controller(&car, state_list, sizeof(state_list)/sizeof(state));

void setup() {
   car.init();
}

void loop() {
   controller.next_action();
   delay(100);
}
