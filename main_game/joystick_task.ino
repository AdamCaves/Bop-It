//Joystick task game!
bool joystick_task() {
  //Display task
  lcd.setCursor(3, 0);
  lcd.print(joystickString);
  
  bool joystick_success = true;
  int xMap, yMap, xValue, yValue;
  char *flickArray[] = {"up", "down", "left", "right"};
  int thresh = 25;
  int maxbound = 50;
  
  //randomize the flick call
  int joyid = random(0, 4);
  Serial.print("\n\n");
  Serial.print(flickArray[joyid]);
  Serial.print("\n\n");

  //start the timer
  startTimer();
  
  //check for inputs
  if (flickArray[joyid] == "up") {
    while (map(analogRead(joyY), 0, 1023, maxbound, -maxbound) < thresh) {
      //check for incorrect inputs
      if (map(analogRead(joyY), 0, 1023, 50, -50) < -thresh || map(analogRead(joyX), 0, 1023, 50, -50) < -thresh || map(analogRead(joyX), 0, 1023, 50, -50) > thresh) {
        return task_fail();
      }
      //check for timer
      if (timerFail)
      {
        return timer_fail();
      }
    }
    //check for inputs
  } else if (flickArray[joyid] == "down") {
    while (map(analogRead(joyY), 0, 1023, maxbound, -maxbound) > -thresh) {
      //check for incorrect inputs
      if (map(analogRead(joyY), 0, 1023, 50, -50) > thresh || map(analogRead(joyX), 0, 1023, 50, -50) < -thresh || map(analogRead(joyX), 0, 1023, 50, -50) > thresh) {
        return task_fail();
      }
      //check for timer
      if (timerFail)
      {
        return timer_fail();
      }
    }
    //check for inputs
  } else if (flickArray[joyid] == "left") {
    while (map(analogRead(joyX), 0, 1023, maxbound, -maxbound) > -thresh) {
      //check for incorrect inputs
      if (map(analogRead(joyX), 0, 1023, 50, -50) > thresh || map(analogRead(joyY), 0, 1023, 50, -50) < -thresh || map(analogRead(joyY), 0, 1023, 50, -50) > thresh) {
        return task_fail();
      }
      //check for timers
      if (timerFail)
      {
        return timer_fail();
      }
    }
    //check for inputs
  } else {
    while (map(analogRead(joyX), 0, 1023, maxbound, -maxbound) < thresh) {
      //check for incorrect inputs
      if (map(analogRead(joyX), 0, 1023, 50, -50) < -thresh || map(analogRead(joyY), 0, 1023, 50, -50) < -thresh || map(analogRead(joyY), 0, 1023, 50, -50) > thresh) {
        return task_fail();
      }
      //check for timer
      if (timerFail)
      {
        return timer_fail();
      }
    }
  }
  //stop the timer
  stopTimer();
  //call success function and return true boolean
  return task_success();
//  delay(200);
} 
