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
  digitalWrite(SUCCESS_LIGHT, LOW);
  SCORE ++;
  if (SCORE >= 5) {
    for (int i = 0; i < 4; i ++) {
    int dur = 1000/winDurations[i];
    tone(SPEAKER, win_tone[i], dur);
    int pause = dur*1.30;
    delay(pause);
    noTone(SPEAKER);
    }
    Serial.print("YOU WIN!");
    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("YOU WIN!");
    lcd.setCursor(1, 1);
    lcd.print("FINAL SCORE: ");
    lcd.setCursor(14,1);
    lcd.print(SCORE);
    resetTimer();
    SCORE = 0;
    return 0;
  }
  return 1;
}
