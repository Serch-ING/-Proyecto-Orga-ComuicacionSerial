void setup() {
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(5,INPUT);
  pinMode(6,INPUT);
  pinMode(7,INPUT);

  pinMode(9,INPUT);
  pinMode(10,INPUT);
  pinMode(11,INPUT);
  pinMode(12,INPUT);
  pinMode(13,INPUT);

}

void loop() {
  if(digitalRead(9) == 1){
    Serial.println ("Jugador 2");
  }else{
     Serial.println ("Jugador 1");
  }

  Serial.println ("Jugador xxx");
  
}
