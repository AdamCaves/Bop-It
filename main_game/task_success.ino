//Output when task is successfully completed!
bool task_success() {
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("NICE!");
  digitalWrite(SUCCESS_LIGHT, HIGH);
  for (int i = 0; i < 2; i ++) {
    int dur = 1000/noteDurations[i];
    tone(SPEAKER, success_tone[i], dur);
    int pause = dur*1.30;
    delay(pause);
    noTone(SPEAKER);
  }
  delay(2000);
  digitalWrite(SUCCESS_LIGHT, LOW);
  SCORE ++;
  if (SCORE >= 5) {
    Serial.print("YOU WIN!");
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("6094954498");
    lcd.setCursor(1, 1);
    lcd.print("text4 suckysuck");
  }
  return 1;
}
