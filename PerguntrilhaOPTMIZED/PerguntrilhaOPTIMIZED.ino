// This code is a refined version developed nearly three years after the original, showcasing significant growth in programming skills.
// Inspired by principles from books like "Clean Code" by Robert C. Martin, this iteration reflects a deeper understanding of best practices gained since my initial foray into programming.

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);



const int letterA = (22), letterB = (27), letterC = (33), letterD = (31);
int correctButton, wrongButton1, wrongButton2, wrongButton3;

const int difficultSwitch1 = (A15), difficultSwitch2 = (A14);
const int startButton = (37);

const int reedSwitch1 = (40), reedSwitch2 = (41), reedSwitch3 = (42), reedSwitch4 = (43), reedSwitch5 = (44), reedSwitch6 = (45), reedSwitch7 = (46), reedSwitch8 = (47);

//LEDs de erro e acerto
const int rightLed = (53), wrongLed = (51);

int listOfQuestions[8] = {0, 0, 0, 0, 0, 0, 0, 0};

const int hoop = (49);

int minutes = 3, seconds = 0;
int errors = 0, rights = 0, points = 16500;
int sumOfHoopContactsWithMaze = 0;
int pointsLostPerSecond = 35;
int pointsLostPerWrongAnswer = 500;
int pointsGainedPerRightAnswer = 670;
int pointsLostPerHoopContact = 1000;



void randomizeQuestions(int list[]) {
  list[0] = random(1, 6);
  list[1] = random(6, 11);
  list[2] = random(11, 16);
  list[3] = random(16, 21);
  list[4] = random(21, 26);
  list[5] = random(26, 31);
  list[6] = random(31, 36);
  list[7] = random(36, 41);
}



void setup()
{
  lcd.begin(16, 2);  //16 Rows x 2 Collums

  pinMode(reedSwitch1, INPUT);
  pinMode(reedSwitch2, INPUT);
  pinMode(reedSwitch3, INPUT);
  pinMode(reedSwitch4, INPUT);
  pinMode(reedSwitch5, INPUT);
  pinMode(reedSwitch6, INPUT);
  pinMode(reedSwitch7, INPUT);
  pinMode(reedSwitch8, INPUT);
  pinMode(hoop, INPUT);
  pinMode(letterA, INPUT_PULLUP);
  pinMode(letterB, INPUT_PULLUP);
  pinMode(letterC, INPUT_PULLUP);
  pinMode(letterD, INPUT_PULLUP);
  pinMode(startButton, INPUT_PULLUP);
  pinMode(rightLed, OUTPUT);
  pinMode(wrongLed, OUTPUT);

  Serial.begin(9600);

  //Ensure that the random seed will always be different from the previous games
  randomSeed(analogRead(A0));

  randomizeQuestions(listOfQuestions);
}



void setDifficult() {
  int switchStateValue = 500;
  char difficult[16];

  if (digitalRead(startButton) == 0) {
    if (analogRead(difficultSwitch1) <= 500 && analogRead(difficultSwitch2) <= 500)
    {
      strcpy(difficult, "Dificuladade 1");
    }
    else if (analogRead(difficultSwitch1) <= 500 && analogRead(difficultSwitch2) > 500)
    {
      strcpy(difficult, "Dificuladade 2");
    }
    else if (analogRead(difficultSwitch1) > 500 && analogRead(difficultSwitch2) <= 500)
    {
      strcpy(difficult, "Dificuladade 3");
    }
    else if (analogRead(difficultSwitch1) > 500 && analogRead(difficultSwitch2) > 500)
    {
      strcpy(difficult, "Dificuladade 4");
    }
  }

  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print(difficult);
  delay(2000);

  seconds -= 2;
  points -= 2 * pointsLostPerSecond;
}


void timer() {
  if (minutes <= 0 && seconds <= 0)
  {
    lcd.clear();
    lcd.setCursor(4, 0);
    lcd.print("Seu tempo");
    lcd.setCursor(5, 1);
    lcd.print("acabou");
    delay(2500);

    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print(points);
    lcd.setCursor(7, 0);
    lcd.print(" pontos!");
    lcd.setCursor(0, 1);
    lcd.print("A: ");
    lcd.setCursor(2, 1);
    lcd.print(rights);
    lcd.setCursor(6, 1);
    lcd.print("E: ");
    lcd.setCursor(8, 1);
    lcd.print(errors);
    lcd.setCursor(11, 1);
    lcd.print("C:");
    lcd.setCursor(13, 1);
    lcd.print(sumOfHoopContactsWithMaze);
    delay(300000);
  }
  else if (seconds == 0)
  {
    points = points - pointsLostPerSecond;
    minutes = minutes - 1;
    seconds = 59;
    delay(1000);
  }
  else if (seconds < 0)
  {
    seconds = 60 + seconds;
    minutes = minutes - 1;
  }
}


void showQuestion(int questionOrdinalNumber, int rightAnswer) {
  if (rightAnswer == 'A') {
    correctButton = letterA;
    wrongButton1 = letterB;
    wrongButton2 = letterC;
    wrongButton3 = letterD;
  }
  else if (rightAnswer == 'B') {
    correctButton = letterB;
    wrongButton1 = letterA;
    wrongButton2 = letterC;
    wrongButton3 = letterD;
  }
  else if (rightAnswer == 'C') {
    correctButton = letterC;
    wrongButton1 = letterA;
    wrongButton2 = letterB;
    wrongButton3 = letterD;
  }
  else if (rightAnswer == 'D') {
    correctButton = letterD;
    wrongButton1 = letterA;
    wrongButton2 = letterB;
    wrongButton3 = letterC;
  }

  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("Pergunta:");
  lcd.setCursor(12, 0);
  lcd.print(listOfQuestions[questionOrdinalNumber]);
  delay(1000);

  if (digitalRead(wrongButton1) == 0 || digitalRead(wrongButton2) == 0 || digitalRead(wrongButton3) == 0)
  {
    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("Voce errou!");
    digitalWrite(wrongLed, HIGH);

    errors = errors + 1;
    points = points - pointsLostPerWrongAnswer - 2 * pointsLostPerSecond;
    seconds = seconds - 2;

    delay(2000);
    digitalWrite(wrongLed, LOW);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("A resposta certa");
    lcd.setCursor(1, 1);
    lcd.print("era a letra");
    lcd.setCursor(14, 1);
    lcd.print(rightAnswer);
    delay(1500);

    seconds = seconds - 2;
    points = points - 2 * pointsLostPerSecond;
  }
  else if (digitalRead(correctButton) == 0)
  {
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("Voce acertou!");
    digitalWrite(rightLed, HIGH);

    rights = rights + 1;
    points = points + pointsGainedPerRightAnswer;
    seconds = seconds - 2;

    delay(2000);
    digitalWrite(rightLed, LOW);
  }

  lcd.clear();
  lcd.setCursor(5, 0);
  lcd.print(minutes);
  lcd.setCursor(6, 0);
  lcd.print(":");

  if (seconds < 10)
  {
    lcd.setCursor(7, 0);
    lcd.print("0");
    lcd.setCursor(8, 0);
    lcd.print(seconds);
  }
  else
  {
    lcd.setCursor(7, 0);
    lcd.print(seconds);
  }

  lcd.setCursor(9, 0);
  lcd.print(":00");
  delay(1000);

  seconds = seconds - 2;
  points = points - 2 * pointsLostPerSecond;
}

void loop()
{
  setDifficult();
  timer();

  if (digitalRead(reedSwitch1) == 1)
  {
    showQuestion(0, 'A');
  }
  else if (digitalRead(reedSwitch2) == 1)
  {
    showQuestion(1, 'C');
  }
  else if (digitalRead(reedSwitch3) == 1)
  {
    showQuestion(2, 'D');
  }
  else if (digitalRead(reedSwitch4) == 1)
  {
    showQuestion(3, 'A');
  }
  else if (digitalRead(reedSwitch5) == 1)
  {
    showQuestion(4, 'C');
  }
  else if (digitalRead(reedSwitch6) == 1)
  {
    showQuestion(5, 'B');
  }
  else if (digitalRead(reedSwitch7) == 1)
  {
    showQuestion(6, 'D');
  }
  else if (digitalRead(reedSwitch8) == 1)
  {
    showQuestion(7, 'B');

    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("Ultimo sensor");
    lcd.setCursor(3, 1);
    lcd.print("Respondido");
    delay(2000);

    //Pontuação
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print(points);
    lcd.setCursor(8, 0);
    lcd.print(" pontos!");
    //Acertos
    lcd.setCursor(0, 1);
    lcd.print("A:");
    lcd.setCursor(2, 1);
    lcd.print(rights);
    //Erros
    lcd.setCursor(6, 1);
    lcd.print("E:");
    lcd.setCursor(8, 1);
    lcd.print(errors);
    //Contatos
    lcd.setCursor(11, 1);
    lcd.print("C:");
    lcd.setCursor(13, 1);
    lcd.print(sumOfHoopContactsWithMaze);
    delay(300000);
  }
  else if (digitalRead(hoop) == 1)
  {
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("Voce errou o");
    lcd.setCursor(4, 1);
    lcd.print("caminho!");

    digitalWrite(wrongLed, HIGH);
    delay(2000);
    digitalWrite(wrongLed, LOW);

    sumOfHoopContactsWithMaze = sumOfHoopContactsWithMaze + 1;
    seconds = seconds - 2;
    points = points - pointsLostPerHoopContact - 2 * pointsLostPerSecond;
  }
  else
  {
    lcd.clear();
    lcd.setCursor(5, 0);
    lcd.print(minutes);
    lcd.setCursor(6, 0);
    lcd.print(":");

    if (seconds < 10)
    {
      lcd.setCursor(7, 0);
      lcd.print("0");
      lcd.setCursor(8, 0);
      lcd.print(seconds);
    }
    else
    {
      lcd.setCursor(7, 0);
      lcd.print(seconds);
    }

    lcd.setCursor(9, 0);
    lcd.print(":00");
    delay(1000);

    seconds = seconds - 1;
    points = points - pointsLostPerSecond;
  }
}
