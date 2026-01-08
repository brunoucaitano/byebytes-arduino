/**
 * ByeBytes - Automação de Forno Solar Sustentável
 * Projeto inovador para monitoramento de luz e tempo de cozimento.
 * Desenvolvido para plataforma Arduino.
 */

// Definição dos pinos para LEDs e Botões
const int ledLuz = 2;       // Indica presença de radiação solar suficiente
const int ledStatus = 3;    // Indica seleção de timer (pisca conforme o tempo escolhido)
const int ledProcesso = 4;  // Indica que o forno está em operação
const int btnTimer = 5;     // Seleciona entre 5, 15 ou 30 minutos
const int btnStart = 6;     // Inicia o processo de contagem
const int ldrPin = A0;      // Sensor de luminosidade (LDR)

// Configurações de Timer (ms)
unsigned long t5min = 300000; 
unsigned long t15min = 900000; 
unsigned long t30min = 1800000; 
unsigned long tempoSelecionado;
int selecao = 0;

void setup() {
  pinMode(ledLuz, OUTPUT);
  pinMode(ledStatus, OUTPUT);
  pinMode(ledProcesso, OUTPUT);
  pinMode(btnTimer, INPUT_PULLUP); // Uso de resistor interno do Arduino
  pinMode(btnStart, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // Lógica de monitoramento solar
  int valorLDR = analogRead(ldrPin);
  digitalWrite(ledLuz, (valorLDR > 500) ? HIGH : LOW);

  // Seleção de Tempo via Botão 1
  if (digitalRead(btnTimer) == LOW) {
    delay(300); // Debounce de software
    selecao++;
    if (selecao > 3) selecao = 1;
    
    // Feedback visual da seleção
    for (int i = 0; i < selecao; i++) {
      digitalWrite(ledStatus, HIGH); delay(200);
      digitalWrite(ledStatus, LOW); delay(200);
    }
  }

  // Atribuição do tempo
  if (selecao == 1) tempoSelecionado = t5min;
  else if (selecao == 2) tempoSelecionado = t15min;
  else if (selecao == 3) tempoSelecionado = t30min;

  // Início do Ciclo de Cozimento via Botão 2
  if (digitalRead(btnStart) == LOW && selecao > 0) {
    delay(300);
    unsigned long inicio = millis();
    while (millis() - inicio < tempoSelecionado) {
      // LEDs piscando indicam processo ativo
      digitalWrite(ledProcesso, HIGH); delay(200);
      digitalWrite(ledProcesso, LOW); delay(200);
    }
  }
}
