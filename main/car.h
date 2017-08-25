#ifndef CAR_H
#define CAR_H

#include <Arduino.h>

// IO pin values
#define IO_FORWARD   4
#define IO_BACKWARD  5
#define IO_LEFT      6
#define IO_RIGHT     7

class Car {
public:
   // Initialize IO ports and variables
   void init();

   // Forward and backward motion
   void move_forward();
   void move_backward();
   void stop_motion();

   // Horizontal motion
   void turn_left();
   void turn_right();
   void stop_turn();
};

#endif
