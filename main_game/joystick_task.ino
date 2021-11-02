//Joystick task game!
bool joystick_task() {
  bool joystick_success = true;
  int xMap, yMap, xValue, yValue;
  String flickArray[] = {"up", "down", "left", "right"};
  int thresh = 25;
  int maxbound = 50;
  //randomize the flick call
  int joyid = random(0, 4);
  if (flickArray[joyid] == "up") {
    while (map(analogRead(joyY), 0, 1023, -maxbound, maxbound) < thresh) {
      if (map(analogRead(joyY), 0, 1023, -50, 50) < -thresh || map(analogRead(joyX), 0, 1023, -50, 50) < -thresh || map(analogRead(joyX), 0, 1023, -50, 50) > thresh) {
        joystick_success = false;
        break;
      }
    }
  } else if (flickArray[joyid] == "down") {
    while (map(analogRead(joyY), 0, 1023, -maxbound, maxbound) < -thresh) {
      if (map(analogRead(joyY), 0, 1023, -50, 50) > thresh || map(analogRead(joyX), 0, 1023, -50, 50) < -thresh || map(analogRead(joyX), 0, 1023, -50, 50) > thresh) {
        joystick_success = false;
        break;
      }
    }
  } else if (flickArray[joyid] == "left") {
    while (map(analogRead(joyX), 0, 1023, -maxbound, maxbound) < -thresh) {
      if (map(analogRead(joyX), 0, 1023, -50, 50) > thresh || map(analogRead(joyY), 0, 1023, -50, 50) < -thresh || map(analogRead(joyY), 0, 1023, -50, 50) > thresh) {
        joystick_success = false;
        break;
      }
    }
  } else {
    while (map(analogRead(joyX), 0, 1023, -maxbound, maxbound) > thresh) {
      if (map(analogRead(joyX), 0, 1023, -50, 50) < -thresh || map(analogRead(joyY), 0, 1023, -50, 50) < -thresh || map(analogRead(joyY), 0, 1023, -50, 50) > thresh) {
        joystick_success = false;
        break;
      }
    }
  }
  return joystick_success;
  delay(200);
} 

//sample code for joystick
// xValue = analogRead(joyX);
//  yValue = analogRead(joyY);
//  xMap = map(xValue, 0,1023, 0, 7);
//  yMap = map(yValue,0,1023,7,0);
