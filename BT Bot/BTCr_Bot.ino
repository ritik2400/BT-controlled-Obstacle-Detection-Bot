//Bot
int RMS,LMS;
int rfwd=2,lfwd=4,rrev=3,lrev=5;
bool turnspd=HIGH,basespd=HIGH;
int safe=7;

//Ultrasonic 1
int trig1 = 7;
int echo1 = 6;
long duration1;
int distance1;
int PowerUS = 12;

//Ultrasonic 2
int trig2 = 8;
int echo2 = 9;
long duration2;
int distance2;

//HC-05
char inputByte='H';


void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(rfwd,OUTPUT);
  pinMode(rrev,OUTPUT);
  pinMode(lfwd,OUTPUT);
  pinMode(lrev,OUTPUT);
  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(trig2, OUTPUT);
  pinMode(echo2, INPUT);
  pinMode(PowerUS, OUTPUT);
  digitalWrite(PowerUS, HIGH);
}

void loop()//This function continuously checks if there is any command from mobile app, and calls the function with the default, or received command.
{
  Serial.println("Start");
  while (Serial.available() > 0) 
  {
    inputByte = Serial.read();
  }
  Serial.print("inputByte= ");
  Serial.println(inputByte);
  Drive(inputByte);
  Serial.println();
}
