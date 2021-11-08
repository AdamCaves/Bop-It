//Matching button LED task game!
bool matching_task() {
  //Display task
  lcd.setCursor(3, 0);
  lcd.print(matchString);

  int pinArray[3] = {RED, YELLOW, BLUE};

  int pSel = random(0,6);
  switch (pSel)
  {
    case 0:
      pinArray[0] = RED;
      pinArray[1] = YELLOW;
      pinArray[2] = BLUE;
    break;
    case 1:
      pinArray[0] = RED;
      pinArray[1] = BLUE;
      pinArray[2] = YELLOW;
    break;
    case 2:
      pinArray[0] = BLUE;
      pinArray[1] = YELLOW;
      pinArray[2] = RED;
    break;
    case 3:
      pinArray[0] = BLUE;
      pinArray[1] = RED;
      pinArray[2] = YELLOW;
    break;
    case 4:
      pinArray[0] = YELLOW;
      pinArray[1] = RED;
      pinArray[2] = BLUE;
    break;
    case 5:
      pinArray[0] = YELLOW;
      pinArray[1] = BLUE;
      pinArray[2] = RED;
    break;
  }

  pinMode(BLUE, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  
  // generate task
  digitalWrite(pinArray[0], HIGH);
  delay(del1);
  digitalWrite(pinArray[0], LOW);
  delay(del2);
  digitalWrite(pinArray[1], HIGH);
  delay(del1);
  digitalWrite(pinArray[1], LOW);
  delay(del2);
  digitalWrite(pinArray[2], HIGH);
  delay(del1);
  digitalWrite(pinArray[2], LOW);

  
  //look for input
  pinMode(BLUE, INPUT);
  pinMode(RED, INPUT);
  pinMode(YELLOW, INPUT);
  delay(del1);

  startTimer(); // start the timer

  Serial.print("\n");
  Serial.print(pinArray[0]);
  Serial.print(pinArray[1]);
  Serial.print(pinArray[2]);
  
    // Check for first button press
    while(!digitalRead(pinArray[0])) {
      if (digitalRead(pinArray[1]) || digitalRead(pinArray[2])) {
  //      Serial.print(digitalRead(pinArray[0]));
  //      Serial.print(digitalRead(pinArray[1]));
  //      Serial.print(digitalRead(pinArray[2]));
        Serial.print("\nExit 1");
        return false;
      }
    }
    // Wait for release
    while(digitalRead(pinArray[0])){}
  
   // Test debounce
    delay(50);
  
    // Check for second button press
    while(!digitalRead(pinArray[1])) {
      if (digitalRead(pinArray[0]) || digitalRead(pinArray[2])) {
        Serial.print("\nExit 2");
        return false;
      }
    }
  
    // Wait for release
    while(digitalRead(pinArray[1])){}
  
    // Test debounce
    delay(50);
    // Check for third button press
    while(!digitalRead(pinArray[2])) {
      if (digitalRead(pinArray[0]) || digitalRead(pinArray[1])) {
        Serial.print("\nExit 3");
        return false;
      }
    }
  
    // Stop timer count here
    stopTimer();
  
  // Wait for release
  while(digitalRead(pinArray[2])){}

  // Test debounce
  delay(50);

  Serial.print("\nEnd");
  
  return true;
  delay(250);
} 
 
