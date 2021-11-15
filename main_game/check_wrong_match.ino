//Matching button LED task game!
bool check_wrong_match() {
 
  pinMode(BLUE, INPUT);
  pinMode(RED, INPUT);
  pinMode(YELLOW, INPUT);

  if (digitalRead(BLUE) || digitalRead(RED) || digitalRead(YELLOW)) {
    return true;
  } else {
    return false;
  }
} 
 
