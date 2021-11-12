bool choose_task() {
  // put your main code here, to run repeatedly:
  int cTask = random(0,2);
  bool r = 0;
  switch (cTask)
  {
    case 0:
        r = joystick_task();
    break;
    case 1:
        r = matching_task();
    break;
    case 2:
        r = whip_task();
    break;
  }

  return r;
}
