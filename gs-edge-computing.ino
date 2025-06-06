#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo servoComporta;

// Pinos
const int sensorNivelAgua = A0;
const int sensorChuva = A1;
const int ledVerde = 2;
const int ledAmarelo = 3;
const int ledVermelho = 4;
const int buzzer = 5;
const int servoPin = 6;
const int botaoEmergencia = 7;
const int botaoReset = 8;

// Estados de controle
bool emergenciaAtivada = false;
bool ultimoEstadoBotaoEmergencia = false;
bool ultimoEstadoBotaoReset = false;

void setup() {
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(botaoEmergencia, INPUT);
  pinMode(botaoReset, INPUT);

  servoComporta.attach(servoPin);
  servoComporta.write(0); // comporta aberta

  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
}

void loop() {
  int nivelAgua = analogRead(sensorNivelAgua);
  int chuva = analogRead(sensorChuva);

  // Leitura dos botões
  bool estadoAtualEmergencia = digitalRead(botaoEmergencia);
  bool estadoAtualReset = digitalRead(botaoReset);

  // Detecção de toque (borda de subida)
  if (estadoAtualEmergencia == HIGH && !ultimoEstadoBotaoEmergencia) {
    emergenciaAtivada = true;
  }
  if (estadoAtualReset == HIGH && !ultimoEstadoBotaoReset) {
    emergenciaAtivada = false;
  }

  // Atualiza estado dos botões
  ultimoEstadoBotaoEmergencia = estadoAtualEmergencia;
  ultimoEstadoBotaoReset = estadoAtualReset;

  // Lógica de decisão
  String status = "";
  bool modoPerigo = emergenciaAtivada || nivelAgua >= 600 || chuva >= 600;

  if (modoPerigo) {
    status = "PERIGO";
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, HIGH);
    servoComporta.write(90); // fecha comporta

    // Alarme rápido e intenso
    for (int i = 0; i < 6; i++) {
      digitalWrite(buzzer, HIGH);
      delay(1000);  // mais tempo ligado
      digitalWrite(buzzer, LOW);
      delay(200);   // menos tempo desligado
    }
  }
  else if (nivelAgua >= 300 || chuva >= 300) {
    status = "ALERTA";
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVermelho, LOW);
    digitalWrite(buzzer, LOW);
    servoComporta.write(45); // meio termo
  }
  else {
    status = "NORMAL";
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, LOW);
    digitalWrite(buzzer, LOW);
    servoComporta.write(0); // comporta aberta
  }

  // Tela 1: exibição dos valores e status
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Agua:");
  lcd.print(nivelAgua);
  lcd.print(" Ch:");
  lcd.print(chuva);
  lcd.setCursor(0, 1);
  lcd.print("Status:");
  lcd.print(status);
  delay(2000);

  // Tela 2: barra de progresso do nível da água
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Nivel Agua:");

  int blocos = map(nivelAgua, 0, 1023, 0, 10);
  lcd.setCursor(0, 1);
  for (int i = 0; i < blocos; i++) {
    lcd.print("#");
  }
  for (int i = blocos; i < 10; i++) {
    lcd.print(".");
  }

  delay(2000);
}