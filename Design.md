# Design do Projeto

Acesso rápido:
  - [Introdução](./README.md)
  - [Concepção](./Concepcao.md)
  - [Implementação](./Implementacao.md)
  - [Operação](./Operacao.md)

A fim de completar os objetivos da concepção de projeto, se faz necessário definir os materiais necessários para a sua realização, assim como a ligação entre eles na maquete eletrônica e a disposição dentro da casa na planta baixa.

## Manquete eletrônica

A imagem abaixo, mostra uma representação de como será feita a ligação dos componetes eletrônicos presentes neste projeto.

![circuito_projetoPI](https://github.com/EmmanuelRGuesser/PI_II_Eng._Eletronica/blob/main/imagens/Diagrama%20Eletronico.png)

## Planta baixa

A imagem abaixo, mostra a representação da planta baixa,ou seja, como os componentes eletrônicos ficaram distribuidos pela casa.

![palnta baixa](https://github.com/EmmanuelRGuesser/PI_II_Eng._Eletronica/blob/main/imagens/planta.png)

## Componentes

Quantidade  | Tecnologias                                   
:---------: | ------                                        
1           |Placa Arduino MEGA 2560 R3 + Fonte + Cabo USB       
1           |Micro Servo SG92R 9g TowerPro                       
1           |Módulo Relé 5 V e um Canal                             
1           |Sensor Fotoresistor LDR de 5mm                 
1           |Sensor de Umidade e Temperatura DHT11         
1           |Sensor de presença e movimento PIR            
1           |Sensor de gás MQ-2        
1           |Sensor ultrasônico HC-SR04                     
1           |Buzzer passivo                                                            
5*          |Led Amarelo
1*          |Led Vermelho
1*          |Led Azul
4*          |Botão Push-button
2           |Resistor 220
5           |Resistor 10k Ω
1           |Display LCD 16×2 I2C Backlight Azul

OBS:* Já tenho

#### Utilização dos componentes:

- Micro Servo SG92R 9g TowerPro, será utilizado para controlar a abertura do portão da casa;

- Módulo Relé 5 V e um Canal, será utilizado para a iluminação da casa;

- Sensor Fotoresistor LDR de 5mm, utilizado como sensor de luminosidade, para controlar a iluminação da casa;

- Sensor DHT11, será utilizado como sensor de umidade e temperatura da casa;

- Sensor de presença e movimento PIR, utilizado para detectar a presença de pessoas na área de fora da residência;

- Sensor de gás MQ-2 inflamável e fumaça, será utilizado como sensor caso tenha um incêndio ou vasamento de gás;

- Sensor ultrasônico HC-SR04, usado como sensor de visitantes fora da casa;

- Buzzer passivo, será utilizado para dar avisos sonoros;
                          
- Leds amarelos, utilizado para a iluminação da casa;

- Leds vermelho e azul, serão utilizados para indicar o aquecimento e refriamento da casa;

- Botões push-button, serão utilizados como interuptor para ativar e desativar os sistemas utilizados;

- Display LCD 16×2 I2C Backlight Azul, utilizado para dar informações sobre a casa e os sistemas tecnológicos nela empregados;

- Serão utilizados cabos para as devidas conexões necessárias.
