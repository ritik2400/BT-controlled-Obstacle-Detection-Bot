//This function drives the bot locomotion signal, and also checks 
//if there are any obstacles in the safe distance of the bot, and then executes appropriate command.
void Drive(char cmd)
{
  if(Check_Obs())
  {
    Serial.println("Halt due to Obstacle");
    halt();
    return ;
  }
//  Serial.println(inputByte);
  if(cmd=='R')
  {
    right();
    Serial.println("Right");
  }
  else if(cmd=='L')
  {
    left();
    Serial.println("Left");
  }
  else if(cmd=='F')
  {
    fwd();
    Serial.println("Fwd");
  }
  else if(cmd=='B')
  {
    back();
    Serial.println("Back");
  }
  else
  {
    halt();
    Serial.println("Halt");
  }
}

bool Check_Obs()//This function returns True if there is a obstacle in safe distance using Ultrasonic Sensors, and False if there are none.
{
  digitalWrite(trig1, LOW);
  delay(2);
  digitalWrite(trig1, HIGH);
  delay(10);
  digitalWrite(trig1, LOW);
  delay(2);
  duration1 = pulseIn(echo1, HIGH);
  distance1 = (duration1*0.0343)/2;


  digitalWrite(trig2, LOW);
  delay(2);
  digitalWrite(trig2, HIGH);
  delay(10);
  digitalWrite(trig2, LOW);
  delay(2);
  duration2 = pulseIn(echo2, HIGH);
  distance2 = (duration2*0.0343)/2;

  Serial.print("Duration1 = ");
  Serial.print(duration1);
  Serial.print("    ");
  Serial.print("Duration2 = ");
  Serial.println(duration2);
  
  Serial.print("Distance1 = ");
  Serial.print(distance1);
  Serial.print("    ");
  Serial.print("Distance2 = ");
  Serial.println(distance2);

  if(distance1<safe || distance2<safe)
  {
    return true;
  }
  else
  {
    return false;
  }
}
