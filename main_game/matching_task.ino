//Matching button LED task game!
bool matching_task() {
  //Display task
  lcd.setCursor(3, 0);
  lcd.print(matchString);
  
  bool matching_success = true;
  int pinArray[] = {RED, YELLOW, BLUE};
  
  //randomize the pin array
  const size_t n = sizeof(pinArray) / sizeof(pinArray[0]);
  for (size_t i = 0; i < n - 1; i++) {
    size_t j = random(0, n - i);

    int t = pinArray[i];
    pinArray[i] = pinArray[j];
    pinArray[j] = t;
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
  pinMode(BLUE, INPUT);
  
  while(digitalRead(pinArray[0]) == LOW) {
    if (digitalRead(pinArray[1] == HIGH) || digitalRead(pinArray[2]) == HIGH) {
      matching_success = false;
      break;
    }
  }
  while(digitalRead(pinArray[1]) == LOW) {
    if (digitalRead(pinArray[0] == HIGH) || digitalRead(pinArray[1]) == HIGH) {
      matching_success = false;
      break;
    }
  }
  while(digitalRead(pinArray[2]) == LOW) {
    if (digitalRead(pinArray[0] == HIGH) || digitalRead(pinArray[1]) == HIGH) {
      matching_success = false;
      break;
    }
  }
  return matching_success;
  delay(200);
} 
 
