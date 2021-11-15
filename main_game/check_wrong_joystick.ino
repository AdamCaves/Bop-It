//Matching button LED task game!
bool check_wrong_joystick() {

  if (abs(map(analogRead(joyY), 0, 1023, maxbound, -maxbound)) > abs(thresh) || abs(map(analogRead(joyX), 0, 1023, maxbound, -maxbound)) > abs(thresh)) {
    return true;
  } else {
    return false;
  }
} 
 
