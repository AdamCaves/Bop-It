//Joystick task game!
bool whip_task() {
  //Display task
  lcd.setCursor(3, 0);
  lcd.print(whipString);

  int count = 10;
  int cal = 0;
  for (int i = 0; i < count; i ++) {
    mpu.update();
    cal += mpu.getAngleZ();
    Serial.print(mpu.getAngleZ());
  }
  cal = cal/count;
  Serial.print("AVERAGE");
  Serial.print(cal);
  return 1;
} 
