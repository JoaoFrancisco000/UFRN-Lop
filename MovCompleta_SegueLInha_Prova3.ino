 const int pinSensorD = A0;// Sensores
 const int pinSensorE = A1;

 const int pinMotorA1B = 6;// Motores
 const int pinMotorA1A = 5;
 const int pinMotorB1B = 10;
 const int pinMotorB1A = 9;

int velocidade = 255; // Define Velocidade

void setup() {
// Sensores
 pinMode(pinSensorD, INPUT); //Sensor Direito
 pinMode(pinSensorE, INPUT);// Sensor Esquerdo Entrada de Dados

 pinMode(pinMotorA1B, OUTPUT);// Motor Esquerdo
 pinMode(pinMotorA1A, OUTPUT);
 pinMode(pinMotorB1B, OUTPUT); // Motor Direito
 pinMode(pinMotorB1A, OUTPUT);

}

void loop() {

  int estadoD = !digitalRead(pinSensorD); //  Leitura do Sensor Direito
  int estadoE = !digitalRead(pinSensorE); // Leitura do Sensor Esquerdo
    
  if(estadoD && estadoE){ // Seguir
    analogWrite(pinMotorA1B,0); // Define a velocidade
    analogWrite(pinMotorB1B,0);// Modelo físico anda para frente com velocidade zero
    digitalWrite(pinMotorA1A, HIGH);// e motores ligados
    digitalWrite(pinMotorB1A, HIGH);
  } 
  if(!estadoD && !estadoE){ // Parar
    digitalWrite(pinMotorA1B,LOW); // Todos os módulos desligados
    digitalWrite(pinMotorA1A,LOW);
    digitalWrite(pinMotorB1B,LOW);
    digitalWrite(pinMotorB1A,LOW);
  }
  if(!estadoD && estadoE){ // Virar para a Direita
    analogWrite(pinMotorA1B,0);// Andar pra frente
    digitalWrite(pinMotorA1A, HIGH);
    analogWrite(pinMotorB1B, velocidade);// girar no próprio eixo
    digitalWrite(pinMotorB1A, LOW); // Movimento contrário ao motor que vira
    
  }

  if(estadoD && !estadoE){ // Virar para a Esquerda
    analogWrite(pinMotorB1B,0);// Andar pra frente
    digitalWrite(pinMotorB1A, HIGH);
    analogWrite(pinMotorA1B,velocidade);// girar no próprio eixo
    digitalWrite(pinMotorA1A, LOW); // Movimento contrário ao motor que vira
    
  }
  delay(50);// Curvas mais lentas
  //Parar
     digitalWrite(pinMotorA1B,LOW);// função de parada
   digitalWrite(pinMotorA1A,LOW);
   digitalWrite(pinMotorB1B,LOW);
   digitalWrite(pinMotorB1A,LOW);
   delay(500);// Pausa nas funções para maior controle e estabilidade do robô
     
}
