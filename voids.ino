void getColorsFromLeftSensor() {
  // (?!) Nao faço a minima ideia de como isso funciona
  digitalWrite(l_s2, LOW);
  digitalWrite(l_s3, LOW);
  l_red = pulseIn(l_out, digitalRead(l_out) == HIGH ? LOW : HIGH);
  digitalWrite(l_s3, HIGH);
  l_blue = pulseIn(l_out, digitalRead(l_out) == HIGH ? LOW : HIGH);
  digitalWrite(l_s2, HIGH);
  l_green = pulseIn(l_out, digitalRead(l_out) == HIGH ? LOW : HIGH);
}

void getColorsFromRightSensor() {
  // (?!) Nao faço a minima ideia de como isso funciona
  digitalWrite(r_s2, LOW);
  digitalWrite(r_s3, LOW);
  r_red = pulseIn(r_out, digitalRead(r_out) == HIGH ? LOW : HIGH);
  digitalWrite(r_s3, HIGH);
  r_blue = pulseIn(r_out, digitalRead(r_out) == HIGH ? LOW : HIGH);
  digitalWrite(r_s2, HIGH);
  r_green = pulseIn(r_out, digitalRead(r_out) == HIGH ? LOW : HIGH);
}


void printColorsOfLeftSensor() {
  Serial.println(String(count) + String("- SENSOR ESQUERDO"));
  Serial.println(String("RED:   ") + String(l_red));
  Serial.println(String("GREEN: ") + String(l_green));
  Serial.println(String("BLUE:  ") + String(l_blue));

  if (l_blue > 15 && l_blue <= 30 && l_blue > 15 && l_green > 15 && l_red > 15) {
    Serial.println("preto");
    digitalWrite(motorPin1, LOW); // set Input 1 of the L293D low
    digitalWrite(motorPin2, LOW); // set Input 2 of the L293D high
    digitalWrite(motorPin4, HIGH); // set Input 1 of the L293D low
   digitalWrite(motorPin3, LOW);
   delay(50);
   digitalWrite(motorPin4, LOW); // set Input 1 of the L293D low
   digitalWrite(motorPin3, LOW);
  } else if (l_blue <= 15 && l_red <= 15 && l_green <= 15) {
    Serial.println("branco");
   digitalWrite(motorPin4, HIGH); // set Input 1 of the L293D low
   digitalWrite(motorPin3, LOW);
   delay(50);
   digitalWrite(motorPin4, LOW); // set Input 1 of the L293D low
   digitalWrite(motorPin3, LOW);
  } else if (l_blue > 30) {
    Serial.println("Verde");
  digitalWrite(motorPin4, LOW); // set Input 1 of the L293D low
   digitalWrite(motorPin3, LOW);
  }

  Serial.println("-----");
}

void printColorsOfRightSensor() {
  Serial.println(String(count) + String("- SENSOR DIREITO"));
  Serial.println(String("RED: ") + String(r_red));
  Serial.println(String("GREEN: ") + String(r_green));
  Serial.println(String("BLUE: ") + String(r_blue));

  if (r_green > 16 && r_green < 30) {
    Serial.println("preto");
  digitalWrite(motorPin4, LOW); // set Input 1 of the L293D low
   digitalWrite(motorPin3, LOW);
   digitalWrite(motorPin1, HIGH); // set Input 1 of the L293D low
   digitalWrite(motorPin2, LOW);
   delay(50);
   digitalWrite(motorPin1, LOW); // set Input 1 of the L293D low
   digitalWrite(motorPin2, LOW);
  } else if (r_green <= 16 && r_red <= 15 && r_blue <= 15) {
    Serial.println("branco");
  digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    delay(50);
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
  } else if (r_green > 30) {
    Serial.println("Verde");
  digitalWrite(motorPin1, LOW); // set Input 1 of the L293D low
    digitalWrite(motorPin2, LOW); // set Input 2 of the L293D high
  } 
  Serial.println("-----");

 }
 void BothColors() {
Serial.println(String(count) + String("- AMBOS SENSORES"));
  Serial.println(String("RED: ") + String(r_red && l_red));
  Serial.println(String("GREEN: ") + String(r_green && l_green));
  Serial.println(String("BLUE: ") + String(r_blue && l_blue));
  if (r_green > 30 && l_blue > 30) {
    Serial.println("180º");
  digitalWrite(motorPin1, LOW); // set Input 1 of the L293D low
    digitalWrite(motorPin2, HIGH); // set Input 2 of the L293D high
  } else if (r_green > 15 && r_green < 30 && l_blue > 15 && l_green > 15 && l_red > 15) {
    Serial.println("cruzamento");
    digitalWrite(motorPin1, HIGH); // set Input 1 of the L293D low
    digitalWrite(motorPin2, LOW); // set Input 2 of the L293D high
    digitalWrite(motorPin3, HIGH); // set Input 1 of the L293D low
    digitalWrite(motorPin4, LOW);
  }
Serial.println("-----");
 }

