// C++ code
//
char data = 0; 
void setup()
{

  Serial.begin(9600); 
  // PINOS DO MOTOR A
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

  // PINOS DO MOTOR B
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop()
{

  /*COMEÇA A RECEBER VALORES DO BLUETOOTH*/
  if(Serial.available() > 0){
    /*LE O VALOR DO BLUETOOTH*/
   data = Serial.read();
   Serial.print(data);
   Serial.print("\n");
   
      if( data=='1' || data=='A'){
           frenteMotorA();
           frenteMotorB();
               
      }

      if( data=='2' || data=='D'){
           pararMotorA();
           frenteMotorB();
               
      }
      if( data=='3' || data=='E'){
           pararMotorB();
           frenteMotorA();
               
      }
      
      if( data=='4' || data=='R'){
           trasMotorA();
           trasMotorB();
               
      }
  
  
  
  
  }

}

void frenteMotorA()
{
  digitalWrite(10, HIGH); // Liga o MotorA no sentido de rotação desejado
  digitalWrite(9, LOW);   // Desliga o outro pino para evitar curto-circuito
}



void trasMotorA()
{
  digitalWrite(10, LOW);  // Inverte a direção do MotorA
  digitalWrite(9, HIGH);  // Desliga o outro pino para evitar curto-circuito
}

void frenteMotorB()
{
  digitalWrite(6, HIGH);  // Liga o MotorB no sentido de rotação desejado
  digitalWrite(5, LOW);   // Desliga o outro pino para evitar curto-circuito
}


void trasMotorB()
{
  digitalWrite(6, LOW);   // Inverte a direção do MotorB
  digitalWrite(5, HIGH);  // Desliga o outro pino para evitar curto-circuito
}

void pararMotorA(){
   digitalWrite(10, HIGH);  // ativa o pino digital 5
  digitalWrite(9, HIGH);  // ativa o pino digital 6
  
  }
void pararMotorB(){
   digitalWrite(6, HIGH);  // ativa o pino digital 5
  digitalWrite(5, HIGH);  // ativa o pino digital 6

  }
