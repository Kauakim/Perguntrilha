//Codigo final
//Palavras não bastam, tem que se envolver...

//Carrega as bibliotecas
#include <LiquidCrystal.h>
//Inicializa o display LCD
LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);



//Variáveis Timer
int minuto,segundo;
//Pontuação
int erro,acerto,pontuacao;

//Alternativas e status das alternativas
const int LETRAa=(22),LETRAb=(27),LETRAc=(33),LETRAd=(31);
int statusA,statusB,statusC,statusD;

//Dificuldade
const int PullDown1=(A15),PullDown2=(A14);
int SPD1,SPD2;
//Botão de Start
const int Start=(37);
int StatS;

//Sensores
const int S1=(40),S2=(41),S3=(42),S4=(43),S5=(44),S6=(45),S7=(46),S8=(47);
int RS1,RS2,RS3,RS4,RS5,RS6,RS7,RS8;

//LEDs de erro e acerto
const int LEDVERDE=(53),LEDVERMELHO=(51);
const int LED1=(36),LED2=(34),LED3=(52);

// Contato com o labirinto e Pista
const int contato=(49);
int Statcont,totCont;
//const int pista=(33);

// Lista para randomização
int lista[8] = {0,0,0,0,0,0,0,0};



void setup()
{
  //Define o número de colunas e linhas do LCD.
  lcd_1.begin(16, 2);
  
  //Define os pinos de entrada e saída.
  pinMode(S1,INPUT);                        
  pinMode(S2,INPUT);
  pinMode(S3,INPUT);
  pinMode(S4,INPUT);
  pinMode(S5,INPUT);
  pinMode(S6,INPUT);
  pinMode(S7,INPUT);
  pinMode(S8,INPUT);
  pinMode(contato,INPUT);
  pinMode(LEDVERDE,OUTPUT);
  pinMode(LEDVERMELHO,OUTPUT);
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
  pinMode(LETRAa,INPUT_PULLUP);
  pinMode(LETRAb,INPUT_PULLUP);
  pinMode(LETRAc,INPUT_PULLUP);
  pinMode(LETRAd,INPUT_PULLUP);
  pinMode(Start,INPUT_PULLUP);
  //pinMode(pista,OUTPUT);
  
  //Define o monitor serial.
  Serial.begin(9600);
  
  //Semente do randomizador de números.
  randomSeed(analogRead(A0));
  
  //Valores inicias
  erro=0;
  acerto=0;
  totCont=0;
  segundo=0;
  minuto=3;
  pontuacao=16500;
}



void loop()
{
  //Valor das variáveis
  //Alternativas
  int statusA = digitalRead(LETRAa);
  int statusB = digitalRead(LETRAb);
  int statusC = digitalRead(LETRAc);
  int statusD = digitalRead(LETRAd);
  
  //Sensores 
  int RS1=digitalRead(S1),RS2=digitalRead(S2),RS3=digitalRead(S3),RS4=digitalRead(S4);
  int RS5=digitalRead(S5),RS6=digitalRead(S6),RS7=digitalRead(S7),RS8=digitalRead(S8);
  
  //Contato
  int Statcont=digitalRead(contato);
  
  //Dificuldade e Start
  int SPD1=analogRead(PullDown1),SPD2=analogRead(PullDown2);
  int StatS=digitalRead(Start);
  
  //Randomizador da pergunta.
  //int PerA1=random(1,6),PerA2=random(16,21), PerB1=random(26,31), PerB2=random(36,41);
  //int PerC1=random(6,11), PerC2=random(21,26), PerD1=random(11,16), PerD2=random(31,36);
  
  
  
  //Exibição no monitor serial.
  //Serial.println(statusA);
  //Serial.println(statusB);
  //Serial.println(statusC);
  //Serial.println(statusD);
  //Serial.println(StatS);
  //Serial.println(Statcont);
  //Serial.println(SPD1);
  //Serial.println(SPD2);
  Serial.println("RS1");
  Serial.println(RS1);
  Serial.println("RS2");
  Serial.println(RS2);
  Serial.println("RS3");
  Serial.println(RS3);
  Serial.println("RS4");
  Serial.println(RS4);
  Serial.println("RS5");
  Serial.println(RS5);
  Serial.println("RS6");
  Serial.println(RS6);
  Serial.println("RS7");
  Serial.println(RS7);
  Serial.println("RS8");
  Serial.println(RS8);
  //delay(1500);
  
  
  
     //Dificuldade das perguntas
     if(StatS==0 && SPD1<=500 && SPD2<=500)
     {
      //DIFICULDADE 1
      lcd_1.clear();
      lcd_1.setCursor(2, 0);
      lcd_1.print("Dificuldade 1");
      delay(1500);
      
      segundo=segundo-2;
      pontuacao=pontuacao-70;
     }
     else if(StatS==0 && SPD1<=500 && SPD2>=500)
     {
      //DIFICULDADE 2
      lcd_1.clear();
      lcd_1.setCursor(2, 0);
      lcd_1.print("Dificuldade 2");
      delay(1500);
      
      segundo=segundo-2;
      pontuacao=pontuacao-70;
     }
     else if(StatS==0 && SPD1>=500 && SPD2<=500)
     {
      //DIFICULDADE 3
      lcd_1.clear();
      lcd_1.setCursor(2, 0);
      lcd_1.print("Dificuldade 3");
      delay(1500);
      
      segundo=segundo-2;
      pontuacao=pontuacao-70;
     }
     else if(StatS==0 && SPD1>=500 && SPD2>=500)
     {
      //DIFICULDADE 4
      lcd_1.clear();
      lcd_1.setCursor(2, 0);
      lcd_1.print("Dificuldade 4");
      delay(1500);
      
      segundo=segundo-2;
      pontuacao=pontuacao-70;
     }
     
     
     
     //Fim do tempo
     if(minuto<=0 && segundo<=0)
     {
      lcd_1.clear();
      lcd_1.setCursor(4, 0);
      lcd_1.print("Seu tempo");
      lcd_1.setCursor(5, 1);
      lcd_1.print("acabou");
      delay(2500);
      
      //Pontuação
      lcd_1.clear();
      lcd_1.setCursor(2,0);
      lcd_1.print(pontuacao);
      lcd_1.setCursor(7,0);
      lcd_1.print(" pontos!");
      //Acertos
      lcd_1.setCursor(0,1);
      lcd_1.print("A: ");
      lcd_1.setCursor(2,1);
      lcd_1.print(acerto);
      //Erros
      lcd_1.setCursor(6,1);
      lcd_1.print("E: ");
      lcd_1.setCursor(8,1);
      lcd_1.print(erro);
      //Contatos
      lcd_1.setCursor(11,1);
      lcd_1.print("C:");
      lcd_1.setCursor(13,1);
      lcd_1.print(totCont);
      delay(50000);
     }
     else if(segundo==0)
     {
      pontuacao=pontuacao-35;
      minuto=minuto-1;
      segundo=59;
      delay(1000);
     }
     //Condicao para verificar se segundos são negativos
     if(segundo<0 && RS1==0 && RS2==0 && RS3==0 && RS4==0 && RS5==0 && RS6==0 && RS7==0 && RS8==0 && Statcont==0 )
     {
      //Convertendo segundos para positivo
      minuto=minuto-1;
      segundo=60-(segundo*-1);
     }
  
  
  
  //PERGUNTA 1
  if(RS1==1)
  {
    //Randomizando o primeiro sensor
    //PerA1
    if(lista[0] == 0 )
    {
      lista[0] = random(1,6);
    }
    
    //Pergunta já randomizada
    lcd_1.clear();
    lcd_1.setCursor(3, 0);
    lcd_1.print("Pergunta:");
    lcd_1.setCursor(12, 0);
    lcd_1.print(lista[0]);
    delay(1500);
     
    if(statusB==0 || statusC==0 || statusD==0)
    {
     lcd_1.clear();
     lcd_1.setCursor(3, 0);
     lcd_1.print("Voce errou!");
     digitalWrite(LEDVERMELHO,HIGH);
     
     erro=erro+1;
     pontuacao=pontuacao-570;
     segundo=segundo-2;
     
     delay(2000);
     digitalWrite(LEDVERMELHO,LOW);

    lcd_1.clear();
    lcd_1.setCursor(0, 0);
    lcd_1.print("A resposta certa");
    lcd_1.setCursor(1, 1);
    lcd_1.print("era a letra A");
    delay(1500);
    segundo=segundo-2;
    pontuacao=pontuacao-70;
    
    }    
    else if(statusA==0)
    {
     lcd_1.clear();
     lcd_1.setCursor(2, 0);
     lcd_1.print("Voce acertou!");
     digitalWrite(LEDVERDE,HIGH);
     
     acerto=acerto+1;
     pontuacao=pontuacao+680;
     segundo=segundo-2;
     
     delay(2000);
     digitalWrite(LEDVERDE,LOW);
    }
    
    //Timer
    lcd_1.clear();
    lcd_1.setCursor(5, 0);
    lcd_1.print(minuto);
    lcd_1.setCursor(6,0);
    lcd_1.print(":");
    if(segundo<10)
    {
     lcd_1.setCursor(7, 0);
     lcd_1.print("0");
     lcd_1.setCursor(8, 0);
     lcd_1.print(segundo);
    }
    else
    {
     lcd_1.setCursor(7, 0);
     lcd_1.print(segundo);
    }
    lcd_1.setCursor(9,0);
    lcd_1.print(":00");
    delay(1000);
    
    segundo=segundo-3;
    pontuacao=pontuacao-105;
   }
   
  //PERGUNTA 2
  else if(RS2==1)
  {
   //Randomizando o segundo sensor
   //PerC1
    if(lista[1] == 0 )
    {
      lista[1] = random(6,11);
    }
    
    //Pergunta já randomizada
    lcd_1.clear();
    lcd_1.setCursor(3, 0);
    lcd_1.print("Pergunta:");
    lcd_1.setCursor(12, 0);
    lcd_1.print(lista[1]);
    delay(1500);
    
    if(statusA==0 || statusB==0 || statusD==0)
    {
     lcd_1.clear();
     lcd_1.setCursor(3, 0);
     lcd_1.print("Voce errou!");
     digitalWrite(LEDVERMELHO,HIGH);
     
     erro=erro+1;
     pontuacao=pontuacao-570;
     segundo=segundo-2;
     
     delay(2000);
     digitalWrite(LEDVERMELHO,LOW);
     
    lcd_1.clear();
    lcd_1.setCursor(0, 0);
    lcd_1.print("A resposta certa");
    lcd_1.setCursor(1, 1);
    lcd_1.print("era a letra C");
    delay(1500);
    segundo=segundo-2;
    pontuacao=pontuacao-70;
    
    }    
    else if(statusC==0)
    {
     lcd_1.clear();
     lcd_1.setCursor(2, 0);
     lcd_1.print("Voce acertou!");
     digitalWrite(LEDVERDE,HIGH);
     
     acerto=acerto+1;
     pontuacao=pontuacao+680;
     segundo=segundo-2;
     
     delay(2000);
     digitalWrite(LEDVERDE,LOW);
    }
    
    //Timer
    lcd_1.clear();
    lcd_1.setCursor(5, 0);
    lcd_1.print(minuto);
    lcd_1.setCursor(6,0);
    lcd_1.print(":");
    if(segundo<10)
    {
     lcd_1.setCursor(7, 0);
     lcd_1.print("0");
     lcd_1.setCursor(8, 0);
     lcd_1.print(segundo);
    }
    else
    {
     lcd_1.setCursor(7, 0);
     lcd_1.print(segundo);
    }
    lcd_1.setCursor(9,0);
    lcd_1.print(":00");
    delay(1000);
   
    segundo=segundo-3;
    pontuacao=pontuacao-105;
  }
  
  //PERGUNTA 3
  else if(RS3==1)
  {
    //Randomizando o terceiro sensor
    //PerD1
    if(lista[2] == 0 )
    {
      lista[2] = random(11,16);
    }
    
    //Pergunta já randomizada
    lcd_1.clear();
    lcd_1.setCursor(3, 0);
    lcd_1.print("Pergunta:");
    lcd_1.setCursor(12, 0);
    lcd_1.print(lista[2]);
    delay(1500);
    
    if(statusA==0 || statusB==0 || statusC==0)
    {
     lcd_1.clear();
     lcd_1.setCursor(3, 0);
     lcd_1.print("Voce errou!");
     digitalWrite(LEDVERMELHO,HIGH);
     
     erro=erro+1;
     pontuacao=pontuacao-570;
     segundo=segundo-2;
     
     delay(2000);
     digitalWrite(LEDVERMELHO,LOW);
 
    lcd_1.clear();
    lcd_1.setCursor(0, 0);
    lcd_1.print("A resposta certa");
    lcd_1.setCursor(1, 1);
    lcd_1.print("era a letra D");
    delay(1500);
    segundo=segundo-2;
    pontuacao=pontuacao-70;
    
    }    
    else if(statusD==0)
    {
     lcd_1.clear();
     lcd_1.setCursor(2, 0);
     lcd_1.print("Voce acertou!");
     digitalWrite(LEDVERDE,HIGH);
     
     acerto=acerto+1;
     pontuacao=pontuacao+680;
     segundo=segundo-2;
     
     delay(2000);
     digitalWrite(LEDVERDE,LOW);
    }
    
    //Timer
    lcd_1.clear();
    lcd_1.setCursor(5, 0);
    lcd_1.print(minuto);
    lcd_1.setCursor(6,0);
    lcd_1.print(":");
    if(segundo<10)
    {
     lcd_1.setCursor(7, 0);
     lcd_1.print("0");
     lcd_1.setCursor(8, 0);
     lcd_1.print(segundo);
    }
    else
    {
     lcd_1.setCursor(7, 0);
     lcd_1.print(segundo);
    }
    lcd_1.setCursor(9,0);
    lcd_1.print(":00");
    delay(1000);
   
    segundo=segundo-3;
    pontuacao=pontuacao-105;
  }
  
  //PERGUNTA 4
  else if(RS4==1)
  {
    //Randomizando o quarto sensor
    //PerA2
    if(lista[3] == 0 )
    {
      lista[3] = random(16,21);
    }
    
    //Pergunta já randomizada
    lcd_1.clear();
    lcd_1.setCursor(3, 0);
    lcd_1.print("Pergunta:");
    lcd_1.setCursor(12, 0);
    lcd_1.print(lista[3]);
    delay(1500);
    
    if(statusB==0 || statusC==0 || statusD==0)
    {
     lcd_1.clear();
     lcd_1.setCursor(3, 0);
     lcd_1.print("Voce errou!");
     digitalWrite(LEDVERMELHO,HIGH);
     
     erro=erro+1;
     pontuacao=pontuacao-570;
     segundo=segundo-2;
     
     delay(2000);
     digitalWrite(LEDVERMELHO,LOW);
     
    lcd_1.clear();
    lcd_1.setCursor(0, 0);
    lcd_1.print("A resposta certa");
    lcd_1.setCursor(1, 1);
    lcd_1.print("era a letra A");
    delay(1500);
    segundo=segundo-2;
    pontuacao=pontuacao-70;
    
    }    
    else if(statusA==0)
    {
     lcd_1.clear();
     lcd_1.setCursor(2, 0);
     lcd_1.print("Voce acertou!");
     digitalWrite(LEDVERDE,HIGH);
     
     acerto=acerto+1;
     pontuacao=pontuacao+680;
     segundo=segundo-2;
     
     delay(2000);
     digitalWrite(LEDVERDE,LOW);
    }
    
    //Timer
    lcd_1.clear();
    lcd_1.setCursor(5, 0);
    lcd_1.print(minuto);
    lcd_1.setCursor(6,0);
    lcd_1.print(":");
    if(segundo<10)
    {
     lcd_1.setCursor(7, 0);
     lcd_1.print("0");
     lcd_1.setCursor(8, 0);
     lcd_1.print(segundo);
    }
    else
    {
     lcd_1.setCursor(7, 0);
     lcd_1.print(segundo);
    }
    lcd_1.setCursor(9,0);
    lcd_1.print(":00");
    delay(1000);
   
    segundo=segundo-3;
    pontuacao=pontuacao-105;
  }

  //PERGUNTA 5
  else if(RS5==1)
  {
    //Randomizando o quinto sensor
    //PerC2
    if(lista[4] == 0 )
    {
      lista[4] = random(21,26);
    }
    
    //Pergunta já randomizada
    lcd_1.clear();
    lcd_1.setCursor(3, 0);
    lcd_1.print("Pergunta:");
    lcd_1.setCursor(12, 0);
    lcd_1.print(lista[4]);
    delay(1500);
    
    if(statusA==0 || statusB==0 || statusD==0)
    {
     lcd_1.clear();
     lcd_1.setCursor(3, 0);
     lcd_1.print("Voce errou!");
     digitalWrite(LEDVERMELHO,HIGH);
     
     erro=erro+1;
     pontuacao=pontuacao-570;
     segundo=segundo-2;
     
     delay(2000);
     digitalWrite(LEDVERMELHO,LOW);

    lcd_1.clear();
    lcd_1.setCursor(0, 0);
    lcd_1.print("A resposta certa");
    lcd_1.setCursor(1, 1);
    lcd_1.print("era a letra C");
    delay(1500);
    segundo=segundo-2;
    pontuacao=pontuacao-70;
    }    
    else if(statusC==0)
    {
     lcd_1.clear();
     lcd_1.setCursor(2, 0);
     lcd_1.print("Voce acertou!");
     digitalWrite(LEDVERDE,HIGH);
     
     acerto=acerto+1;
     pontuacao=pontuacao+680;
     segundo=segundo-2;
     
     delay(2000);
     digitalWrite(LEDVERDE,LOW);
    }
    
    //Timer
    lcd_1.clear();
    lcd_1.setCursor(5, 0);
    lcd_1.print(minuto);
    lcd_1.setCursor(6,0);
    lcd_1.print(":");
    if(segundo<10)
    {
     lcd_1.setCursor(7, 0);
     lcd_1.print("0");
     lcd_1.setCursor(8, 0);
     lcd_1.print(segundo);
    }
    else
    {
     lcd_1.setCursor(7, 0);
     lcd_1.print(segundo);
    }
    lcd_1.setCursor(9,0);
    lcd_1.print(":00");
    delay(1000);
   
    segundo=segundo-3;
    pontuacao=pontuacao-105;
  }

  //PERGUNTA 6
  else if(RS6==1)
  {
    //Randomizando o sexto sensor
    //PerB1
    if(lista[5] == 0 )
    {
      lista[5] = random(26,31);
    }
    
    //Pergunta já randomizada
    lcd_1.clear();
    lcd_1.setCursor(3, 0);
    lcd_1.print("Pergunta:");
    lcd_1.setCursor(12, 0);
    lcd_1.print(lista[5]);
    delay(1500);
    
    if(statusA==0 || statusC==0 || statusD==0)
    {
     lcd_1.clear();
     lcd_1.setCursor(3, 0);
     lcd_1.print("Voce errou!");
     digitalWrite(LEDVERMELHO,HIGH);
     
     erro=erro+1;
     pontuacao=pontuacao-570;
     segundo=segundo-2;
     
     delay(2000);
     digitalWrite(LEDVERMELHO,LOW);

    lcd_1.clear();
    lcd_1.setCursor(0, 0);
    lcd_1.print("A resposta certa");
    lcd_1.setCursor(1, 1);
    lcd_1.print("era a letra B");
    delay(1500);
    segundo=segundo-2;
    pontuacao=pontuacao-70;
    
    }    
    else if(statusB==0)
    {
     lcd_1.clear();
     lcd_1.setCursor(2, 0);
     lcd_1.print("Voce acertou!");
     digitalWrite(LEDVERDE,HIGH);
     
     acerto=acerto+1;
     pontuacao=pontuacao+680;
     segundo=segundo-2;
     
     delay(2000);
     digitalWrite(LEDVERDE,LOW);
    }
    
    //Timer
    lcd_1.clear();
    lcd_1.setCursor(5, 0);
    lcd_1.print(minuto);
    lcd_1.setCursor(6,0);
    lcd_1.print(":");
    if(segundo<10)
    {
     lcd_1.setCursor(7, 0);
     lcd_1.print("0");
     lcd_1.setCursor(8, 0);
     lcd_1.print(segundo);
    }
    else
    {
     lcd_1.setCursor(7, 0);
     lcd_1.print(segundo);
    }
    lcd_1.setCursor(9,0);
    lcd_1.print(":00");
    delay(1000);
   
    segundo=segundo-3;
    pontuacao=pontuacao-105;
  }

  //PERGUNTA 7
  else if(RS7==1)
  {
    //Randomizando o sétimo sensor
    //PerD2
    if(lista[6] == 0 )
    {
      lista[6] = random(31,36);
    }
    
    //Pergunta já randomizada
    lcd_1.clear();
    lcd_1.setCursor(3, 0);
    lcd_1.print("Pergunta:");
    lcd_1.setCursor(12, 0);
    lcd_1.print(lista[6]);
    delay(1500);
    
    if(statusA==0 || statusB==0 || statusC==0)
    {
     lcd_1.clear();
     lcd_1.setCursor(3, 0);
     lcd_1.print("Voce errou!");
     digitalWrite(LEDVERMELHO,HIGH);
     
     erro=erro+1;
     pontuacao=pontuacao-570;
     segundo=segundo-2;
     
     delay(2000);
     digitalWrite(LEDVERMELHO,LOW);

    lcd_1.clear();
    lcd_1.setCursor(0, 0);
    lcd_1.print("A resposta certa");
    lcd_1.setCursor(1, 1);
    lcd_1.print("era a letra D");
    delay(1500);
    segundo=segundo-2;
    pontuacao=pontuacao-70;
    
    }    
    else if(statusD==0)
    {
     lcd_1.clear();
     lcd_1.setCursor(2, 0);
     lcd_1.print("Voce acertou!");
     digitalWrite(LEDVERDE,HIGH);
     
     acerto=acerto+1;
     pontuacao=pontuacao+680;
     segundo=segundo-2;
     
     delay(2000);
     digitalWrite(LEDVERDE,LOW);
    }
    
    //Timer
    lcd_1.clear();
    lcd_1.setCursor(5, 0);
    lcd_1.print(minuto);
    lcd_1.setCursor(6,0);
    lcd_1.print(":");
    if(segundo<10)
    {
     lcd_1.setCursor(7, 0);
     lcd_1.print("0");
     lcd_1.setCursor(8, 0);
     lcd_1.print(segundo);
    }
    else
    {
     lcd_1.setCursor(7, 0);
     lcd_1.print(segundo);
    }
    lcd_1.setCursor(9,0);
    lcd_1.print(":00");
    delay(1000);
   
    segundo=segundo-3;
    pontuacao=pontuacao-105;
  }
  
  //PERGUNTA 8
  else if(RS8==1)
  { 
   //Randomizando o oitavo sensor
   //PerB2
    if(lista[7] == 0 )
    {
      lista[7] = random(36,41);
    }
    
   //Pergunta já randomizada
   lcd_1.clear();
   lcd_1.setCursor(3, 0);
   lcd_1.print("Pergunta:");
   lcd_1.setCursor(12, 0);
   lcd_1.print(lista[7]);
   delay(1500);
   
   segundo=segundo-2;
   pontuacao=pontuacao-30;
   
   if(statusA==0 || statusC==0 || statusD==0)
   {
    lcd_1.clear();
    lcd_1.setCursor(3, 0);
    lcd_1.print("Voce errou!");
    digitalWrite(LEDVERMELHO,HIGH);
    
    erro=erro+1;
    pontuacao=pontuacao-570;
    segundo=segundo-2;

    delay(2000);
    digitalWrite(LEDVERMELHO,LOW);

    lcd_1.clear();
    lcd_1.setCursor(0, 0);
    lcd_1.print("A resposta certa");
    lcd_1.setCursor(1, 1);
    lcd_1.print("era a letra B");
    delay(1500);
    segundo=segundo-2;
    pontuacao=pontuacao-70;
    
    lcd_1.clear();
    lcd_1.setCursor(2, 0);
    lcd_1.print("Ultimo sensor");
    lcd_1.setCursor(3, 1);
    lcd_1.print("Respondido");
    delay(2000);
    
    //Pontuação
    lcd_1.clear();
    lcd_1.setCursor(2,0);
    lcd_1.print(pontuacao);
    lcd_1.setCursor(8,0);
    lcd_1.print(" pontos!");
    //Acertos
    lcd_1.setCursor(0,1);
    lcd_1.print("A:");
    lcd_1.setCursor(2,1);
    lcd_1.print(acerto);
    //Erros
    lcd_1.setCursor(6,1);
    lcd_1.print("E:");
    lcd_1.setCursor(8,1);
    lcd_1.print(erro);
    //Contatos
    lcd_1.setCursor(11,1);
    lcd_1.print("C:");
    lcd_1.setCursor(13,1);
    lcd_1.print(totCont);
    delay(50000);
   }    
   else if(statusB==0 )
   {
    lcd_1.clear();
    lcd_1.setCursor(2, 0);
    lcd_1.print("Voce acertou!");
    digitalWrite(LEDVERDE,HIGH);
    
     acerto=acerto+1;
     pontuacao=pontuacao+680;
     segundo=segundo-2;
    
    delay(2000);
    digitalWrite(LEDVERDE,LOW);
     
    lcd_1.clear();
    lcd_1.setCursor(2, 0);
    lcd_1.print("Ultimo sensor");
    lcd_1.setCursor(3, 1);
    lcd_1.print("Respondido");
    delay(2000);
    
    //Pontuação
    lcd_1.clear();
    lcd_1.setCursor(2,0);
    lcd_1.print(pontuacao);
    lcd_1.setCursor(8,0);
    lcd_1.print(" pontos!");
    //Acertos
    lcd_1.setCursor(0,1);
    lcd_1.print("A: ");
    lcd_1.setCursor(2,1);
    lcd_1.print(acerto);
    //Erros
    lcd_1.setCursor(6,1);
    lcd_1.print("E: ");
    lcd_1.setCursor(8,1);
    lcd_1.print(erro);
    //Contatos
    lcd_1.setCursor(11,1);
    lcd_1.print("C:");
    lcd_1.setCursor(13,1);
    lcd_1.print(totCont);
    delay(50000);
    }

    //Timer
    lcd_1.clear();
    lcd_1.setCursor(5, 0);
    lcd_1.print(minuto);
    lcd_1.setCursor(6,0);
    lcd_1.print(":");
    if(segundo<10)
    {
     lcd_1.setCursor(7, 0);
     lcd_1.print("0");
     lcd_1.setCursor(8, 0);
     lcd_1.print(segundo);
    }
    else
    {
     lcd_1.setCursor(7, 0);
     lcd_1.print(segundo);
    }
    lcd_1.setCursor(9,0);
    lcd_1.print(":00");
    delay(1000);
   
    segundo=segundo-3;
    pontuacao=pontuacao-105;
   }
   
  //Contato com o labirinto
  else if(Statcont==1)
  {
    lcd_1.clear();
    lcd_1.setCursor(2, 0);
    lcd_1.print("Voce errou o");
    lcd_1.setCursor(4, 1);
    lcd_1.print("caminho!");
    
    //digitalWrite(LED1,HIGH);
    //digitalWrite(LED2,HIGH);
    //digitalWrite(LED3,HIGH);
    digitalWrite(LEDVERMELHO,HIGH);
    //digitalWrite(pista,HIGH);
    delay(1500);
    //digitalWrite(pista,LOW);
    //digitalWrite(LED1,LOW);
    //digitalWrite(LED2,LOW);
    //digitalWrite(LED3,LOW);
    digitalWrite(LEDVERMELHO,LOW);
    
    totCont=totCont+1;
    segundo=segundo-2;
    pontuacao=pontuacao-1070; 
  } 
    
  //SENSORES DESLIGADOS E CONTATO DESLIGADO
  else 
  {
   //Timer
   lcd_1.clear();
   lcd_1.setCursor(5, 0);
   lcd_1.print(minuto);
   lcd_1.setCursor(6,0);
   lcd_1.print(":");
   if(segundo<10)
   {
    lcd_1.setCursor(7, 0);
    lcd_1.print("0");
    lcd_1.setCursor(8, 0);
    lcd_1.print(segundo);
   }
   else
   {
   lcd_1.setCursor(7, 0);
   lcd_1.print(segundo);
   }
   lcd_1.setCursor(9,0);
   lcd_1.print(":00");
   delay(1000);
   segundo=segundo-1;
   pontuacao=pontuacao-35;
  }
}
