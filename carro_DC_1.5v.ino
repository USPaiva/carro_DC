#include <Ultrasonic.h>
#define LED 6
//sensor de distancia
#define echo 30
#define trig 31
//motor1 é direita
//motor2 é esquerda
#define motorPin1 2 // motor1 Input 1
#define motorPin2 3 // motor1 Input 2
#define motorPin3 8 // motor2 Input 1
#define motorPin4 7 // motor2 Input 2
// Pinos de conexao do sensor de cor TCS230 da direita
#define l_out 23
#define l_s1 22
#define l_s2 25
#define l_s0 24
#define l_s3 26
// Pinos de conexao do sensor de cor TCS230 da esquerda
#define r_s0 53
#define r_s1 52
#define r_s2 50
#define r_s3 51
#define r_out 48
// Valores adquiridos a cada loop
int l_red = 0;
int l_green = 0;
int l_blue = 0; 
int r_red = 0;
int r_green = 0; 
int r_blue = 0;
// Contagem
int count = 0;
//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(trig, echo);

void setup() {
  Serial.begin(9600);
  Serial.println("v1.5 meio testada");

  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4 , OUTPUT);
}
void ultrason(){
   //Le as informacoes do sensor, em cm e pol
  float cmMsec, inMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  inMsec = ultrasonic.convert(microsec, Ultrasonic::IN);
  //Exibe informacoes no serial monitor
  Serial.print("Distancia em cm: ");
  Serial.print(cmMsec);
  Serial.print(" - Distancia em polegadas: ");
  Serial.println(inMsec);
 if (cmMsec < 11) {
   Serial.println("obstaculo");
   digitalWrite(motorPin1, LOW); // set Input 1 of the L293D low
   digitalWrite(motorPin2, HIGH);
   digitalWrite(motorPin3, LOW); // set Input 1 of the L293D low
   digitalWrite(motorPin4, HIGH);
   Serial.println("-----");
 }
}
void loop() {
  count++;
 analogWrite(12, 460);
 analogWrite(11, 460); 
   ultrason();
   getColorsFromLeftSensor();
   getColorsFromRightSensor();
   BothColors();
  printColorsOfLeftSensor();
  printColorsOfRightSensor(); 
}

