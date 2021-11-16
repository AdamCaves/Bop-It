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
  lcd.setCursor(3, 0);
  lcd.print("TASK FAILED");
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
  lcd.setCursor(3, 0);
  lcd.print("OUT OF TIME");
  SCORE = 0;
  return 0;
}
