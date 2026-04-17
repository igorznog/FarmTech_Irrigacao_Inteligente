// IMPORTAR BIBLÍOTECA
#include <DHT.h>

// CONFIGURAÇÃO DO SENSOR DHT22
#define DHTTYPE DHT22
int pinoDHT = 4;   

// PINOS DOS BOTÕES (NPK)
int botaoN = 12;
int botaoP = 14;
int botaoK = 27;

// PINO DO RELÉ (BOMBA D'ÁGUA)
int rele = 23;

// SENSOR LDR (SIMULANDO pH)
int sensorLDR = 34;

// OBJETO DO SENSOR DHT
DHT dht(pinoDHT, DHTTYPE);

// CULTURA ESCOLHIDA: TOMATE
// Necessidades típicas:
// - Umidade ideal: 50% a 80%
// - pH ideal: 6.0 a 6.8
// - LDR entre 1500 e 2500 = pH ideal

void setup() {
  Serial.begin(115200);

  // BOTÕES COMO ENTRADA COM PULLUP
  pinMode(botaoN, INPUT_PULLUP);
  pinMode(botaoP, INPUT_PULLUP);
  pinMode(botaoK, INPUT_PULLUP);

  // RELÉ COMO SAÍDA
  pinMode(rele, OUTPUT);

  // INICIA SENSOR DHT
  dht.begin();
}

void loop() {

  // LEITURA DOS SENSORES
  float umidade = dht.readHumidity();
  int valorLDR = analogRead(sensorLDR);

  int estadoN = digitalRead(botaoN);
  int estadoP = digitalRead(botaoP);
  int estadoK = digitalRead(botaoK);

  // TRATAMENTO DE ERRO DO DHT22
  if (isnan(umidade)) {
    Serial.println("Erro ao ler umidade!");
    delay(1000);
    return;
  }

  // EXIBIÇÃO DOS VALORES
  Serial.println("-- MONITORAMENTO AGRÍCOLA --");

  Serial.print("Umidade (%): ");
  Serial.println(umidade);

  Serial.print("Valor do LDR (simulando pH): ");
  Serial.println(valorLDR);

  Serial.println("NPK:");
  Serial.println(estadoN == LOW ? "N: Ativo" : "N: Desativado");
  Serial.println(estadoP == LOW ? "P: Ativo" : "P: Desativado");
  Serial.println(estadoK == LOW ? "K: Ativo" : "K: Desativado");

  // LÓGICA DE NPK (botão pressionado = nutriente presente)
  bool npk_ok = (estadoN == LOW && estadoP == LOW && estadoK == LOW);

  // LÓGICA DE pH IDEAL (USANDO VALOR DO LDR)
  bool ph_ok = (valorLDR >= 1500 && valorLDR <= 2500);

  // LÓGICA DE IRRIGAÇÃO
 if (umidade < 50 && ph_ok) {
  digitalWrite(rele, HIGH);
  Serial.println("Irrigação: LIGADA");
} else {
  digitalWrite(rele, LOW);
  Serial.println("Irrigação: DESLIGADA");
}

  Serial.println("----------------------------------");
  Serial.println();

  delay(1000);
}
