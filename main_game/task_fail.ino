//Output when task is NOT completed successfully!
void task_fail() {
  resetTimer();
  digitalWrite(FAIL_LIGHT, HIGH);
  for (int i = 0; i < 2; i ++) {
    int dur = 1000/noteDurations[i];
    tone(SPEAKER, fail_tone[i], dur);
    int pause = dur*1.30;
    delay(pause);
    noTone(SPEAKER);
  }
  digitalWrite(FAIL_LIGHT, LOW);
  Serial.print("Input fail");
}

void timer_fail()
{
  // Put same things in but diplay "out of time" on LCD so user knows why they lost
  resetTimer();
  Serial.print("Timer fail");
}
