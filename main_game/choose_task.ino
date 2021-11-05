bool chooseTask() {
  // put your main code here, to run repeatedly:
  int cTask = rand(0,4);
  bool rVal = 0;
  switch (cTask)
  {
    case 1:
        r = joystick_task();
    break;
    case 2:
        r = matching_task();
    break;
    case 3:
        //r = tilt_task();
    break;
  }

  return r;
}
