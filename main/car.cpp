#include "car.h"

void Car::init() {
   // Initialize IO pins
   pinMode(IO_FORWARD, OUTPUT);
   pinMode(IO_BACKWARD, OUTPUT);
   pinMode(IO_LEFT, OUTPUT);
   pinMode(IO_RIGHT, OUTPUT);
}

void Car::move_forward() {
   // Move car forward
   digitalWrite(IO_BACKWARD, LOW);
   digitalWrite(IO_FORWARD, HIGH);
}

void Car::move_backward() {
   // Move car backward
   digitalWrite(IO_FORWARD, LOW);
   digitalWrite(IO_BACKWARD, HIGH);
}

void Car::stop_motion() {
   // Stop the car
   digitalWrite(IO_FORWARD, LOW);
   digitalWrite(IO_BACKWARD, LOW);
}

void Car::turn_left() {
   // Turn car to the left
   digitalWrite(IO_RIGHT, LOW);
   digitalWrite(IO_LEFT, HIGH);
}

void Car::turn_right() {
   // Turn car to the right
   digitalWrite(IO_LEFT, LOW);
   digitalWrite(IO_RIGHT, HIGH);
}

void Car::stop_turn() {
   // Straighten the wheels
   digitalWrite(IO_LEFT, LOW);
   digitalWrite(IO_RIGHT, LOW);
}
