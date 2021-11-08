void timerSetup()
{
//  // Configure Timer 1
  cli(); // Disable interrupts
  TCCR1A &= ~(0xFF); // Clear Timer 1 registers
  TCCR1B &= ~(0xFF);
  TCNT1 = 0; // Clear count
  TCCR1B = 0; // Ensure timer in stop mode
  OCR1AH = timeAllowed; // Initialize first time limit at ~4.18 seconds
  OCR1AL = 0;
  TIMSK1 |= (1 << OCIE1A); // Enable capture/compare interrupt 1
  TIFR1 &= ~(1 << OCF1A); // Clear IFG
  sei(); // Enable interrupts
}

void startTimer() // Starts timer
{
  timerFail = 0; // Ensure timer fail is not set
  TCNT1 = 0;// Ensure count is reset
  TCCR1B |= 0x5; // Put timer in start mdoe with 1024 prescale
  Serial.print("Start timer");
}

void stopTimer() // To be called after a task is successfully completed
{
  TCCR1B = 0; // Put timer in stop mode
  TCNT1 = 0; // Reset count
  decrementTime(); // Call function to decrement time
  TIFR1 &= ~(1 << OCF1A); // Clear IFG just in case
}

void decrementTime()
{
  timeAllowed = timeAllowed - 0x01; // Decrement time allowed
  OCR1AH = timeAllowed; // Update max time
}

void resetTimer() // To be called at the beginning of a new game - first thing that should be done
{
  timerFail = 0; // Reset timer fail
  TCCR1B = 0; // Put timer in stop mode
  TCNT1 = 0; // Reset count
  timeAllowed = 0xFF; // Reset allowed time to max
  OCR1AH = timeAllowed; // Update max time
  
}

ISR(TIMER1_COMPA_vect) // ISR for Timer 1
{
  if (OCF1A) // Ensure that correct IFG triggered
  {
    timerFail = 1; // Set the timer fail flag
    Serial.print("Timer IFG triggered");
    stopTimer(); // Stop the timer and clear the IFG
  }
}
