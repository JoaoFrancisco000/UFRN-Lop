int motor_Vel = 10; // Pino para controle da velocidade do motor
int motor_Dir = 12; // Pino para controle da direção do motor
int velocidade = 183; // Variável para controle de velocidade (0 a 255)

void setup() { 
  // Configura os pinos do motor como saída
  pinMode(motor_Vel, OUTPUT);
  pinMode(motor_Dir, OUTPUT);
}

void loop() { 
  MotorSentidoAntiHorario(); // Chama a função para rotação no sentido anti-horário
  delay(5000); // Aguarda 5 segundos
  MotorParar(); // Chama a função para parar o motor
  delay(5000); // Aguarda 5 segundos
}

void MotorSentidoAntiHorario() { 
  digitalWrite(motor_Dir, LOW); // Direção do motor = ANTI-HORÁRIO
  analogWrite(motor_Vel, velocidade); // Define a velocidade do motor
}

void MotorParar() { 
  analogWrite(motor_Vel, 0); // Define a velocidade do motor para 0 (parar)
}