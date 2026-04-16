# 🌱 FarmTech Solutions - Sistema de Irrigação Inteligente

## 📌 Descrição do Projeto

Este projeto tem como objetivo desenvolver um sistema de irrigação inteligente utilizando conceitos de IoT (Internet das Coisas) e sensoriamento.

A solução proposta busca otimizar o uso da água em ambientes agrícolas, garantindo eficiência hídrica e melhorando a produtividade, simulando o funcionamento de uma fazenda inteligente.

---

## 🧠 Funcionamento do Sistema

O sistema realiza a coleta de dados de diferentes sensores e, com base nessas informações, toma decisões automáticas sobre a irrigação.

### 🔹 Sensores utilizados:

- **Umidade (DHT22)** → Mede a umidade do ambiente  
  - Biblioteca necessária: **DHT sensor library (Adafruit)**  
  - Biblioteca auxiliar: **Adafruit Unified Sensor**

- **NPK (Switches)** → Simulam a presença de nutrientes no solo:
  - N (Nitrogênio)  
  - P (Fósforo)  
  - K (Potássio)  

- **LDR (Simulação de pH)** → Representa variações do solo  

---

## ⚙️ Lógica de Funcionamento

A irrigação é controlada principalmente pela umidade do ambiente:

- Se **umidade < 50%** → Irrigação **LIGADA**  
- Se **umidade ≥ 50%** → Irrigação **DESLIGADA**  

Os sensores NPK atuam como suporte à decisão, indicando a presença de nutrientes e simulando um cenário real de cultivo ativo.

---

## 🔌 Componentes Utilizados

- ESP32  
- Sensor DHT22  
- Sensor LDR  
- 3 Switches (NPK)  
- Módulo Relé  
- Protoboard e Jumpers  

---

## 🛠️ Ferramentas Necessárias

Para rodar este projeto, é necessário:

- Simulador Wokwi  
- Arduino IDE (para execução local, opcional)  
- Navegador (Google Chrome, Edge, etc.)  
- Biblioteca **DHT sensor library (Adafruit)**  
- Biblioteca **Adafruit Unified Sensor**

---

## 🖼️ Circuito no Wokwi

O circuito foi desenvolvido e simulado utilizando a plataforma Wokwi, permitindo a integração de sensores e testes em tempo real sem necessidade de hardware físico.

(INSIRA AQUI PRINT DO CIRCUITO)

---

## 💻 Código do Projeto

O código principal foi desenvolvido em C/C++ utilizando a plataforma ESP32.

Arquivo:
- `sketch.ino`

---

## 🎥 Demonstração em Vídeo

🔗 (INSIRA AQUI O LINK DO VÍDEO NO YOUTUBE)

O vídeo demonstra:

- Funcionamento dos sensores  
- Alteração dos valores em tempo real  
- Resposta do sistema de irrigação  
- Ativação do relé  

---

## 🚀 Conclusão

O projeto demonstra como a integração entre IoT e sensores pode contribuir para a automação agrícola, promovendo sustentabilidade e eficiência no uso de recursos naturais.

---

## 👨‍💻 Integrantes

(INSIRA OS NOMES DO GRUPO)
