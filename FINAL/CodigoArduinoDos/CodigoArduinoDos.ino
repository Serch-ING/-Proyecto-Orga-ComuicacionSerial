
int valor_dato = 0;

void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  Serial.begin(9600);
  Serial.println("Conexión Establecida");
}

void loop(){
  
  while(Serial.available())
  {
    valor_dato = Serial.read();
  }
  
  if (valor_dato == '1')
  {
    digitalWrite (3, HIGH);
    digitalWrite (2, LOW);
  }
  else if (valor_dato == '0')
  {
    digitalWrite (2, HIGH);
     digitalWrite (3, LOW);
  }else{
   digitalWrite (2, LOW);
     digitalWrite (3, LOW);
   }
}
