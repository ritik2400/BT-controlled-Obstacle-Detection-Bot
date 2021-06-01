//This tab contains the direction functions for the Bot.
void fwd()
{
  digitalWrite(rfwd,basespd);
  digitalWrite(lfwd,basespd);
  digitalWrite(rrev,0);
  digitalWrite(lrev,0);    
}
void back()
{
  digitalWrite(rfwd,0);
  digitalWrite(lfwd,0);
  digitalWrite(rrev,basespd);
  digitalWrite(lrev,basespd);    
}
void left()
{
  digitalWrite(rfwd,turnspd);
  digitalWrite(lfwd,0);
  digitalWrite(rrev,0);
  digitalWrite(lrev,turnspd);    
}
void right()
{
  digitalWrite(rfwd,0);
  digitalWrite(lfwd,turnspd);
  digitalWrite(rrev,turnspd);
  digitalWrite(lrev,0);    
}
void halt()
{
  digitalWrite(rfwd,0);
  digitalWrite(lfwd,0);
  digitalWrite(rrev,0);
  digitalWrite(lrev,0);    
}
