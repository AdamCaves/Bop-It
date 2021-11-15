//Matching button LED task game!
bool check_wrong_whip(int cal1) {
  int cal2 = 0;
  int count = 10;
  int delta = 35;
  for (int i = 0; i < count; i ++) 
      {
        mpu.update();
        cal2 += mpu.getAngleZ();
        //Serial.print(mpu.getAngleZ());
      }
      
      //calculating current postion 
      cal2 = cal2/count;

      if (abs(cal1-cal2) > delta) {
        return true;
      } else {
        return false;
      }
} 
 
