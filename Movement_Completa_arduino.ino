int motorA_Vel = 10; // Controle de velocidade do motor A (Esquerdo) portas PWM
int motorB_Vel = 11; // Controle de velocidade do motor B (Direito) portas PWM
int motorA_Dir = 12; // Controle de direção do motor A (Esquerdo)
int motorB_Dir = 13; // Controle de direção do motor B (Direito)
int velocidade = 183; // Variável para controle de velocidade de rotação dos motores, sendo 0 o valor de velocidade mínimo e 255 o valor de velocidade máxima.

void setup() {
  // Configura os motores como saída
  pinMode(motorA_Vel, OUTPUT);
  pinMode(motorA_Dir, OUTPUT);
  pinMode(motorB_Vel, OUTPUT);
  pinMode(motorB_Dir, OUTPUT);
}

void loop() {
  MoverFrente();       //  mover o robô para frente
  delay(5000);         // 5 segundos

  MoverDireita();      //  mover o robô para a direita
  delay(5000);         // Aguarda 5 segundos

  MoverEsquerda();     //  mover o robô para a esquerda
  delay(5000);         // Aguarda 5 segundos

  MoverTras();         //  mover o robô para trás
  delay(5000);         // Aguarda 5 segundos
}

void MoverFrente() {
  digitalWrite(motorA_Dir, HIGH);  // Mot A HIGH = HORÁRIO
  digitalWrite(motorB_Dir, HIGH);  // Mot B HIGH = HORÁRIO
  analogWrite(motorA_Vel, velocidade);  // Velocidade do motor esquerdo
  analogWrite(motorB_Vel, velocidade);  // Velocidade do motor direito
}

void MoverDireita() {
  digitalWrite(motorA_Dir, HIGH);  // Mot A HIGH = HORÁRIO
  digitalWrite(motorB_Dir, LOW);   // Mot B LOW = ANTI-HORÁRIO
  analogWrite(motorA_Vel, velocidade);  // Velocidade do motor esquerdo
  analogWrite(motorB_Vel, velocidade);  // Velocidade do motor direito
}

void MoverEsquerda() {
  digitalWrite(motorA_Dir, LOW);   // Mot A LOW = ANTI-HORÁRIO
  digitalWrite(motorB_Dir, HIGH);  // Mot B HIGH = HORÁRIO
  analogWrite(motorA_Vel, velocidade);  // Velocidade do motor esquerdo
  analogWrite(motorB_Vel, velocidade);  // Velocidade do motor direito
}

void MoverTras() {
  digitalWrite(motorA_Dir, LOW);   // Mot A LOW = ANTI-HORÁRIO
  digitalWrite(motorB_Dir, LOW);   // Mot B LOW = ANTI-HORÁRIO
  analogWrite(motorA_Vel, velocidade);  // Velocidade do motor esquerdo
  analogWrite(motorB_Vel, velocidade);  // Velocidade do motor direito
}
