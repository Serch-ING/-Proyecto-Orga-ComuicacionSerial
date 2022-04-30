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
  Serial.begin(9600);
  Serial.println("Conexión Establecida");
}



void loop() {
  int JugadorActual;
  
  int DR2 = digitalRead(2);
  int DR3 = digitalRead(3);
  int DR4 = digitalRead(4);
  int DR5 = digitalRead(5);
  int DR6 = digitalRead(6);
  int DR7 = digitalRead(7);
  
  
  int DR9 = digitalRead(9);
  int DR10 = digitalRead(10);
  int DR11 = digitalRead(11);
  int DR12 = digitalRead(12);
  int DR13 = digitalRead(13);

  
  if( DR9 == 0){
    int fila_j2;
    if(DR13 == 0 && DR12 == 1){
      fila_j2 = 3;
    }else if(DR13 == 1 && DR12 == 0){
       fila_j2 = 2;
    }else if(DR13 == 1 && DR12 == 1){
        fila_j2 = 1;
    }else{
      fila_j2 = 1000;
     }

    int columna_j2;
    if(DR11 == 0 && DR10 == 1){
      columna_j2 = 3;
    }else if(DR11 == 1 && DR10 == 0){
       columna_j2 = 2;
    }else if(DR11 == 1 && DR10 == 1){
        columna_j2 = 1;
    }else{
      columna_j2 = 1000;
     }
    String cadenaJ2 = String(fila_j2) +String(",")  + String(columna_j2) ;

    Serial.println (cadenaJ2);
    
  }else if(DR7 == 1){
      int fila_j1;
      if(DR2 == 0 && DR3 == 1){
        fila_j1 = 1;
      }else if(DR2 == 1 && DR3 == 0){
         fila_j1 = 2;
      }else if(DR2 == 1 && DR3 == 1){
          fila_j1 = 3;
      }else{
        fila_j1 = 1000;
       }

       
    int columna_j1;
    if(DR6 == 0 && DR5 == 0 && DR4 == 1){
      columna_j1 = 3;
    }else if(DR6 == 0 && DR5 == 1 && DR4 == 0){
       columna_j1 = 2;
    }else if(DR6 == 1 && DR5 == 0 && DR4 == 0){
        columna_j1 = 1;
    }else{
      columna_j1 = 1000;
     }

     String cadenaJ1 = String(fila_j1) +String(",")  + String(columna_j1) ;
      
     Serial.println(cadenaJ1);
     
    }


  delay(700);
  
  
}
