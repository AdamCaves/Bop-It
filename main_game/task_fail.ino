//Output when task is NOT completed successfully!
bool task_fail() {
  digitalWrite(FAIL_LIGHT, HIGH);
  for (int i = 0; i < 2; i ++) {
    int dur = 1000/noteDurations[i];
    tone(SPEAKER, fail_tone[i], dur);
    int pause = dur*1.30;
    delay(pause);
    noTone(SPEAKER);
  }
  digitalWrite(FAIL_LIGHT, LOW);
  resetTimer();
  Serial.print("Input fail"); // These should be replaced with LCD commands
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("GAME OVER");
  lcd.setCursor(3, 1);
  lcd.print("SCORE: ");
  lcd.setCursor(11, 1);
  lcd.print(SCORE);
  SCORE = 0;
  return 0;
}

bool timer_fail()
{
  // Put same things in but diplay "out of time" on LCD so user knows why they lost
  digitalWrite(FAIL_LIGHT, HIGH);
  for (int i = 0; i < 2; i ++) {
    int dur = 1000/noteDurations[i];
    tone(SPEAKER, fail_tone[i], dur);
    int pause = dur*1.30;
    delay(pause);
    noTone(SPEAKER);
  }
  
  digitalWrite(FAIL_LIGHT, LOW);
  resetTimer();
  Serial.print("Timer fail"); // These should be replaced with LCD commands
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("OUT OF TIME");
  lcd.setCursor(3, 1);
  lcd.print("SCORE: ");
  lcd.setCursor(11, 1);
  lcd.print(SCORE);
  SCORE = 0;
  return 0;
}
