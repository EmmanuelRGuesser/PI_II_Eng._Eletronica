# Design do Projeto

Acesso rápido:
  - [Introdução](./README.md)
  - [Concepção](./Concepcao.md)
  - [Implementação](./Implementacao.md)
  - [Operação](./Operacao.md)

A fim de completar os objetivos da concepção de projeto, se faz necessário definir os materiais necessários para a sua realização, assim como a ligação entre eles na maquete eletrônica e a disposição dentro da casa na planta baixa.

## Manquete eletrônica

A imagem abaixo, mostra uma representação de como será feita a ligação dos componetes eletrônicos presentes neste projeto.

![circuito_projetoPI](https://github.com/EmmanuelRGuesser/PI_II_Eng._Eletronica/blob/main/imagens/Maquete%20Eletr%C3%B4nica.png)

## Planta baixa

A imagem abaixo, mostra a representação da planta baixa,ou seja, como os componentes eletrônicos ficaram distribuidos pela casa.

![palnta baixa](https://github.com/EmmanuelRGuesser/PI_II_Eng._Eletronica/blob/main/imagens/Planta%20baixa.jpeg)

## Componentes

Quantidade  | Tecnologias                                   
:---------: | ------                                        
1           |Placa Arduino MEGA 2560 R3 + Fonte + Cabo USB       
1           |Micro Servo SG92R 9g TowerPro                  
1           |Módulo Sensor de Umidade/Nível Água Chuva      
1           |Módulo Relé 5 V e um Canal                     
1           |Módulo Matriz de LED 8×8 com MAX7219          
1           |Sensor Fotoresistor LDR de 5mm                 
1           |Sensor de Umidade e Temperatura DHT11         
1           |Sensor de presença e movimento PIR            
1           |Sensor de gás MQ-2 inflamável e fumaça         
1           |Sensor ultrasônico HC-SR04                     
1           |Buzzer passivo                                 
1*          |Cooler - Ventilador                            
1           |Led
1           |Resistor para led
2           |Resistor 10k Ω
1           |Botão Push-button
1           |Display LCD 16×2 I2C Backlight Azul

OBS:* Já tenho

#### Utilização dos componentes:

-Micro Servo SG92R 9g TowerPro, será utilizado para controlar a abertura do portão da casa;

-Módulo Sensor de Umidade/Nível Água Chuva, será utilizado para medir o nível do reservatório de água da casa;

-Módulo Relé 5 V e um Canal e Cooler, serão utilizados para a ventilação da casa;

-Módulo Matriz de LED 8×8 com MAX7219, será utilizados para avisos rápidos e emergências;

-Sensor Fotoresistor LDR de 5mm, utilizado como sensor de luminosidade, para controlar a intensidade da iluminação da casa;

-Sensor DHT11, será utilizado como sensor de umidade e temperatura da casa;

-Sensor de presença e movimento PIR, utilizado para detectar a presença de pessoas na área de fora da residência;

-Sensor de gás MQ-2 inflamável e fumaça, será utilizado como sensor casp tenha um incêndio ou vasamento de gás;

-Sensor ultrasônico HC-SR04, usado como sensor de visitantes fora da casa;

-Buzzer passivo, será utilizado para dar avisos sonoros;
                          
-Led, utilizado para a iluminação da casa;

-Botão Push-button, utilizado como interuptor de luz;

-Display LCD 16×2 I2C Backlight Azul, utilizado para dar informações sobre a casa e os sistemas tecnológicos nela empregados.
