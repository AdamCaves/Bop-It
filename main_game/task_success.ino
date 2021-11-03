//Output when task is successfully completed!
void task_success() {
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
}
