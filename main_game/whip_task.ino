//Whip It task game!
bool whip_task() {
  //Display task
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print(whipString);
  lcd.setCursor(3, 1);
  lcd.print("SCORE: ");
  lcd.setCursor(11, 1);
  lcd.print(SCORE);
  int count = 10;
  int cal1 = 0;
  int cal2 = 0;
  int delta = 0;

  for (int i = 0; i < count; i ++) 
  {
    mpu.update();
    cal1 += mpu.getAngleZ();
    //Serial.print(mpu.getAngleZ());
  }
  cal1 = cal1/count;
  Serial.print("\n\nAVERAGE 1 : ");
  Serial.print(cal1);
  //return 1;

  //start the timer
  startTimer();

  while(delta<35)
  {
    Serial.print("/nI am here/n");
    
    //check wrong inputs
    if (check_wrong_match() || check_wrong_joystick()) {
      return task_fail();
    }
    
    //check for inputs
    for (int i = 0; i < count; i ++) 
    {
      mpu.update();
      cal2 += mpu.getAngleZ();
      //Serial.print(mpu.getAngleZ());
    }
    
    //calculating current postion 
    cal2 = cal2/count;
    Serial.print("\n\nAVERAGE 2 : ");
    Serial.print(cal2);
  //return 1;

    //comparing current position to start position
    delta = abs(cal1-cal2);

    Serial.print("\n\nDELTA : ");
    Serial.print(delta);
    Serial.print("\n\n");
    //return 1;

  //check for timer
    if (timerFail)
    {
      return timer_fail();
    }
  }

  
  // Stop timer count here
  stopTimer();

  return task_success();

} 
