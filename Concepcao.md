# Concepção do Projeto

Acesso rápido:
  - [Introdução](./README.md)
  - [Design/Projeto](./Design.md)
  - [Implementação](./Implementacao.md)
  - [Operação](./Operacao.md)

Este projeto de domótica tem como objetivo proporcionar uma casa com mais praticidade, facilidade no controle dos recursos, ter mais conforto  e segurança, para realizar isto temos os objetivos abaixo à seguir:

- Modo seguro: durante a noite ou quando for acionado manualmente, quando o sensor de presença detectar uma movimentação fora de casa será acionado o buzzer, a iluminação da casa acenderá (caso for noite);

- Controle de luminosidade: a fim de economizar energia, em dias ensolarados a iluminação da casa diminuirá;

- Controle de temperatura: para proporcionar uma casa com a temperatura mais agradável, quando a temperatura passar de de 28 Graus ou for abaixo de 18 Graus, o sistema de climatização será acionado para casa ficar em 24 Graus;

- Controle do portão: o sistema quando identificar que tem visita, acionará a companhia e vai solicitar ao usuário que abra o portão caso queira;

- Sistema de irrigação do jardim: para se ter o jardim sempre verde, quando o nível de água do reservatório estiver acima de 20% e a umidade estiver baixa, será acionada a irrigação de plantas do jardim ou manualmente;

- Sensor de gás: quando o sensor detectar um nível superior de gás dentro da casa, a janela será aberta para se ter uma ventilação, e os interruptores do sistema de iluminação será desabilitado, para evitar uma faísca;

- Controle do usuário: a interação manual será feita através de uma interface no computador;

- A matriz de leds juntamente com o buzzer alertaram o usuário, caso um dos sistemas descritos acima sejam acionados;

- As informações dos sensores e dos sistemas da casa serão mostradas no display de LCD;

Para a conclusão dos objetivos serão necessários: 

 - Placa MEGA 2560 R3
 - Micro Servo SG92R 9g TowerPro
 - Módulo Sensor de Umidade/Nível Água Chuva
 - Módulo Relé 5 V e um Canal
 - Módulo Matriz de LED 8×8 com MAX7219
 - Sensor Fotoresistor LDR de 5mm 
 - Sensor de Umidade e Temperatura DHT11
 - Sensor de presença e movimento PIR
 - Sensor de gás MQ-2 inflamável e fumaça
 - Sensor ultrasônico HC-SR04
 - Buzzer passivo
 - Led branco
 - Botão Push-button
 - resistores
 - Display LCD 16×2 I2C Backlight Azul
