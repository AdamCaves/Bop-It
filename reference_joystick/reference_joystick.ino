int VRx = A0;
int VRy = A1;

int xPosition = 0;
int yPosition = 0;
int mapX = 0;
int mapY = 0;

void setup() {
  Serial.begin(9600); 
  
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  
}

void loop() {
  xPosition = analogRead(VRx);
  yPosition = analogRead(VRy);
  
  mapX = map(xPosition, 0, 1023, 50, -50);
  mapY = map(yPosition, 0, 1023, 50, -50);
  
//  Serial.print("X: ");
//  Serial.print(mapX);
  Serial.print(" | Y: ");
  Serial.print(mapY);
 

  delay(100);
  
}
