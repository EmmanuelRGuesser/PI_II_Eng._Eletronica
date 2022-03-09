/*  Instituto Federal de Educação, Ciência e Tecnologia de Santa Catarina-Campus Florianópolis
 *  Unidade Curricular: Projeto Integrador II
 *  
 *  Alunno: Emmanuel Reitz Guesser
 * 
 *  Semestre 2021.2
 * 
 * Codigo para automacao residencial
*/

//------------------ BIBLIOTECAS --------------------

//Sistema de Ventilacao

#include <DHT.h>

// Display LCD

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Portao
#include <Servo.h> 
Servo SRV;

//------------------ DEFINIR PINOS ------------------

// Buzzer

#define buzzer 2

// Sistema GAS 

#define GAS 34
#define ENERGIA 23

//Sistema Iluminacao

#define Botao_LED 22
#define LED 30

//Sistema de Ventilacao

#define DHT11PIN 38
#define RESFRIAR 28
#define AQUECER 26
#define DHTTYPE  DHT11
DHT dht(DHT11PIN, DHTTYPE);

//Sistema de  Segurança

#define PIR 36
#define botao_seg 37

// Sistema Visita

#define trigger 9
#define eco 8
#define botao_vis 39

// Portao 

#define botao_portao 24
#define SERVOPIN 7 

void setup() {

  //------------- Inicia Comunicacao ---------

  //DHT11
  
  dht.begin();

  // Inicia display

  lcd.init();
  lcd.setBacklight(HIGH);

  //------------- ENTRADAS E SAIDAS ---------------

  // Buzzer
  
  pinMode (buzzer, OUTPUT);
  
  // Sistema de GAS

  pinMode (GAS, INPUT);  
  pinMode (ENERGIA, OUTPUT); 

  // Sistema Iluminacao

  pinMode(Botao_LED, INPUT_PULLUP);
  pinMode(LED, OUTPUT);

  //Sistema de  Ventilacao

  pinMode (RESFRIAR, OUTPUT);
  pinMode (AQUECER, OUTPUT);

  // Sistema de Seguranca

  pinMode (PIR, INPUT);
  pinMode (botao_seg, INPUT_PULLUP);

  // Sistema Visita

  pinMode(trigger, OUTPUT);
  pinMode(eco, INPUT);
  pinMode(botao_vis, INPUT_PULLUP);

  //Portao

  pinMode(botao_portao,INPUT);
  SRV.attach(SERVOPIN);
   
}

void loop() {
  
  Buzzer();
  Sistema_GAS();
  Sistema_Iluminacao();
  Sistema_Ventilacao();
  Sistema_Seguranca();
  DisplayLCD();
  Sistema_Visita();
  Sistema_portao();

}

//---------------- DIFINIR VARIAVEIS ------------------

// Buzzer

const unsigned long periodo_buzzer = 500;
unsigned long tempo_tarefa_buzzer = 0;
int estado_alarme = LOW;
bool ligar_alarme = false;
unsigned short int freq_buzzer;

// Sistema GAS

bool MQ2;
const unsigned long periodo_tarefa_MQ2 = 1000; 
unsigned long tempo_tarefa_MQ2 = 0; 

// Sistema Iluminacao

int LDR = 0;
bool BotaoRetencao();

// Sistema Ventilacao

const unsigned long periodo_tarefa_DHT = 1000;
unsigned long tempo_tarefa_DHT = millis();
float t, h;

// Sistema de Segurança

bool alarme_seg, sist_seg = false, botao_alarme;

//Display LCD

const unsigned long periodo_LCD = 1000;
unsigned long tempo_tarefa_LCD = 0;

// Sistema Visita

int aciona_visita = false;
long tempo_acionado_visita = 3000;
const unsigned long periodo_tarefa_SD = 100;
unsigned long ultimo_tempo_visita = 0;
unsigned long tempo_tarefa_SD = 0;
long duracao;
float dist;

//Portao

int pos = 0;
const unsigned long periodo_tarefa_servo = 1000;
unsigned long tempo_tarefa_servo = 0;

//--------------------------- FUNCOES ----------------------------

// Buzzer

void Buzzer() {

unsigned long tempo_atual_buzzer = millis ();

  //Aciona o buzzer a cada 500 ms
  if (tempo_atual_buzzer - tempo_tarefa_buzzer > periodo_buzzer) {

    tempo_tarefa_buzzer = tempo_atual_buzzer;

    if (MQ2 == 0 || alarme_seg == true || aciona_visita == true) {

      if (estado_alarme == HIGH) {
        estado_alarme = LOW;
        tone(buzzer, freq_buzzer);
      }else {
        estado_alarme = HIGH;
        noTone(buzzer);
        digitalWrite(buzzer, HIGH);
      }
    }else {
      noTone(buzzer);
      digitalWrite(buzzer, HIGH);
      
    }
  }
}

// Sistema GAS

void Sistema_GAS() {
  
  unsigned long tempo_atual_MQ2 = millis (); 

  //Leitura caso tenha passado 1000 ms
  if (tempo_atual_MQ2 - tempo_tarefa_MQ2 > periodo_tarefa_MQ2) {

    tempo_tarefa_MQ2 = tempo_atual_MQ2;
  
    // Faz a leitura do sensor
    MQ2 = digitalRead(GAS);
    }
  
  //Caso detectado a presenca de gas ativa o buzzer e desliga a energia da casa
  if(MQ2 == 0){
    
    freq_buzzer = 3000;
    digitalWrite(ENERGIA, LOW);
    } else{
    
    digitalWrite(ENERGIA, HIGH);
    }
}

//Sistema Iluminacao

void Sistema_Iluminacao(){

  //Le o sensor LDR
  LDR = analogRead(A0);

  //Liga o led caso ligar pelo botao e iluminacao baixa
  if (BotaoRetencao()&& LDR < 500) {
    digitalWrite(LED, HIGH);
  }
  //Liga o led caso tiver gas ou alarme acionado
  else if (MQ2 == false || alarme_seg == true){
    digitalWrite(LED, HIGH);
   }
    
  else {
    digitalWrite(LED, LOW);
   }
   
}
// Funcao para eliminar o efeito bounce
bool BotaoRetencao() {
  #define tempoDebounce 50 

   bool estadoBotao;
   static bool estadoBotaoAnt; 
   static bool estadoRet = true;
   static unsigned long delayBotao = 0;

   if ( (millis() - delayBotao) > tempoDebounce ) {
      estadoBotao = digitalRead(Botao_LED);
      if ( estadoBotao && (estadoBotao != estadoBotaoAnt) ) {
         estadoRet = !estadoRet;
         delayBotao = millis();
      }
      estadoBotaoAnt = estadoBotao;
   }
  return estadoRet;
}

// Sistema de Ventilacao

void Sistema_Ventilacao() {
  unsigned long tempo_atual_DHT = millis ();

  //Realiza a leitura do sensor DHT a  cada 1000  ms
  if (tempo_atual_DHT - tempo_tarefa_DHT > periodo_tarefa_DHT) {
    
    h = dht.readHumidity();
    t = dht.readTemperature();    
  }   

  //Caso temperatura menor  que 22 graus liga o aquecedor
  if (t<22) {
    digitalWrite(AQUECER, HIGH);
  }
  //Caso temperatura maior que 22 graus liga o resfriador
  else if (t>22) {
    digitalWrite(RESFRIAR, HIGH);
  }else{
    digitalWrite(AQUECER, LOW);
  }
}

// Sistema de Segurança

void Sistema_Seguranca() {

  //Caso ativado o sistema de segurança, realiza a leitura do PIR
  if (BotaoRetencao2() == true){
      if (digitalRead(PIR) == HIGH) {
      alarme_seg = true;
      freq_buzzer = 5000;
   }else {
    alarme_seg = false;
   }
  }else{
    alarme_seg = false;
  }
}

//Funçao que elimina o efeito bounce do botao que ativa o sistema de segurança
bool BotaoRetencao2(){
  #define tempoDebounce 50 

  bool estadoBotao;
  static bool estadoBotaoAnt; 
  static bool estadoRet = true;
  static unsigned long delayBotao = 0;

  if ( (millis() - delayBotao) > tempoDebounce ) {
    estadoBotao = digitalRead(botao_seg);
    if ( estadoBotao && (estadoBotao != estadoBotaoAnt) ) {
      estadoRet = !estadoRet;
      delayBotao = millis();
    }
    estadoBotaoAnt = estadoBotao;
  }
  return estadoRet;
}

// Display LCD

void DisplayLCD() {

  unsigned long tempo_atual_LCD = millis ();

  //Atualiza o Display a cada 1000 ms
  if (tempo_atual_LCD - tempo_tarefa_LCD > periodo_LCD) {

    tempo_tarefa_LCD = tempo_atual_LCD;

    //Escreve umidade e temperatura
    lcd.setCursor(0, 0);
    lcd.print(F("U:"));
    lcd.setCursor(2, 0);
    lcd.print(h);
    lcd.setCursor(6, 0);
    lcd.print(F("% "));
    lcd.setCursor(8, 0);
    lcd.print(F("T: "));
    lcd.setCursor(10, 0);
    lcd.print(t);
    lcd.setCursor(14, 0);  
    lcd.write(223); // Caracter °
    lcd.print(F("C"));

    //Escreve informaçoes do sistema
    lcd.setCursor(0, 1);
  
    if (MQ2 == 0){
      lcd.print("Alerta de Gas!");
    }else if(alarme_seg == true){
      lcd.print("Invasao    ");
    }else if(aciona_visita == true){
      lcd.print("Visita !      "); 
    }else {
      lcd.print("Sistemas OK!   ");
    }

    //Escreve se o sistema de visita e alarme estão ativados
    lcd.setCursor(14,1);
    if(BotaoRetencao2() == true){
      lcd.print("S");
    }else{
      lcd.print(" ");
    }
    lcd.setCursor(15,1);
    if(BotaoRetencao3() == true){
      lcd.print("V");
    }else{
      lcd.print(" ");
    }     
  }
}

// Sistema de Visita

void Sistema_Visita(){
  unsigned long tempo_atual_visita = millis();
  unsigned long tempo_atual_SD = millis();

  //Realiza a leitura a cada 100 ms
  if (tempo_atual_SD - tempo_tarefa_SD > periodo_tarefa_SD){

    tempo_tarefa_SD = tempo_atual_SD;
    
    digitalWrite(trigger, LOW);
    delayMicroseconds(5);
    digitalWrite(trigger, HIGH);
    delayMicroseconds(10); 
    digitalWrite(trigger, LOW);

    // Inicia contagem de tempo e lê o pino de eco
    duracao = pulseIn(eco, HIGH);

    // Calcular a distância
    dist = duracao * 0.034 / 2;
  }

  // Caso tiver algo a menos de 5 cm  e visita ativada aciona a campainha 
  if(dist < 50 && BotaoRetencao3() == true){
    aciona_visita = true;
  }
  
  if (aciona_visita == true){
    if(tempo_atual_visita - ultimo_tempo_visita >= tempo_acionado_visita){
      freq_buzzer = 1000;
      ultimo_tempo_visita = tempo_atual_visita;
    }
  }
  if(dist > 50){
    ultimo_tempo_visita = tempo_atual_visita;
    aciona_visita = false;
  }
}

//Funçao que elimina o efeito bounce do botao que ativa o sistema de visita
bool BotaoRetencao3(){
  #define tempoDebounce 50 

   bool estadoBotao;
   static bool estadoBotaoAnt; 
   static bool estadoRet = true;
   static unsigned long delayBotao = 0;

   if ( (millis() - delayBotao) > tempoDebounce ) {
      estadoBotao = digitalRead(botao_vis);
      if ( estadoBotao && (estadoBotao != estadoBotaoAnt) ) {
         estadoRet = !estadoRet;
         delayBotao = millis();
      }
      estadoBotaoAnt = estadoBotao;
   }
  return estadoRet;
}

//Portao

void Sistema_portao(){
  unsigned long tempo_atual_servo = millis();

  if (digitalRead(botao_portao) == HIGH){

    if (tempo_atual_servo - tempo_tarefa_servo > periodo_tarefa_servo){

      tempo_tarefa_servo = tempo_atual_servo;
    
      for (pos = 0; pos <= 90; pos += 1) {
        // Troca de posição
        SRV.write(pos);
        // Aguarda 15 ms
        delay(15);
      }
    }
    for (pos = 90; pos >= 0; pos -= 1) {
      // Troca de posição
      SRV.write(pos);
      // Aguarda 15 ms
      delay(15);
    }      
  }
}
