int motorPin1 = 8;
int motorPin2 = 9;
int motorPin3 = 10;
int motorPin4 = 11;
int motor1Pin1 = 4;
int motor1Pin2 = 5;
int motor1Pin3 = 6;
int motor1Pin4 = 7;
int delayTime = 5;
int prevx = 0;
int prevy = 0;
int newx = 0;
int newy = 0;
float n1 = 0;
float n2 = 0;
float prevn1 = 0;
float prevn2 = 0;
int L = 295;

void setup() {
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor1Pin3, OUTPUT);
  pinMode(motor1Pin4, OUTPUT);
}



void forward1(int time){
  for(int x=0;x<time/20;x++){
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  delay(delayTime);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  delay(delayTime);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
  delay(delayTime);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  delay(delayTime);
  }
}
void forward2(int time){
  for(int x=0;x<time/20;x++){
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor1Pin3, LOW);
  digitalWrite(motor1Pin4, LOW);
  delay(delayTime);
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor1Pin3, LOW);
  digitalWrite(motor1Pin4, LOW);
  delay(delayTime);
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor1Pin3, HIGH);
  digitalWrite(motor1Pin4, LOW);
  delay(delayTime);
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor1Pin3, LOW);
  digitalWrite(motor1Pin4, HIGH);
  delay(delayTime);
  }
}
  void backward1(int time){
  for(int x=0;x<time/20;x++){
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  delay(delayTime);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  delay(delayTime);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
  delay(delayTime);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  delay(delayTime);
  }
  }
  void backward2(int time){
  for(int x=0;x<time/20;x++){
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor1Pin3, LOW);
  digitalWrite(motor1Pin4, LOW);
  delay(delayTime);
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor1Pin3, LOW);
  digitalWrite(motor1Pin4, HIGH);
  delay(delayTime);
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor1Pin3, HIGH);
  digitalWrite(motor1Pin4, LOW);
  delay(delayTime);
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor1Pin3, LOW);
  digitalWrite(motor1Pin4, LOW);
  delay(delayTime);
  }
  }
  void loop() {
    if(Serial.available()){ // only send data back if data has been sent
String inByte = Serial.readString(); // read the incoming data
Serial.println(inByte); // send the data back in a new line so that it is not all one long line
int commaIndex = inByte.indexOf(',');
//  Search for the next comma just after the first
int secondCommaIndex = inByte.indexOf(',', commaIndex+1);
String firstValue = inByte.substring(0, commaIndex);
String secondValue = inByte.substring(commaIndex+1, secondCommaIndex);
String thirdValue = inByte.substring(secondCommaIndex);
newx=firstValue.toInt();
newy=secondValue.toInt();

sqrt(sq(prevx)+sq(prevy))=prevn1;
sqrt(sq(prevx)+sq(L-prevy))=prevn2;
sqrt(sq(newx)+sq(newy))=n1;
sqrt(sq(newx)+sq(L-newy))=n2;

if ((n1-prevn1)>1){
  forward((n1-prevn1)*20);
}
else{
  backward((prevn1-n1)*20);
}
if ((n2-prevn2)>1){
  forward((n2-prevn2)*20);
}
else{
  backward((prevn2-n2)*20);
}
newx=prevx;
newy=prevy;

}
  
  }


