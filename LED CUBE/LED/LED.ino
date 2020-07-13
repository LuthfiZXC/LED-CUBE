  #define POT A7
  
  
  int layer[4]={13, A0, A1, A2}; //initializing and declaring led layers
  int column[16]={A5,A4,A3,1, 0,2,3,4, 8,7,6,5, 12,11,10,9}; //initializing and declaring led rows
 
void setup()
{
  pinMode(POT, INPUT);
  
  for(int i = 0; i<16; i++)   
  {
    pinMode(column[i], OUTPUT);  //setting rows to ouput
  }
  
  for(int i = 0; i<4; i++)
  {
    pinMode(layer[i], OUTPUT);  //setting layers to output
  }
  
  randomSeed(analogRead(10));  //seeding random for random pattern
}

void loop()
{
  turnEverythingOff();
  flickerOn();
  turnEverythingOn();
  tunda();
  turnOnAndOffAllByLayerUpAndDownNotTimed();
  layerstompUpAndDown();
  spiralInAndOut();
  turnOnAndOffAllByColumnSideways();
  tunda();
  aroundEdgeDown();
  turnEverythingOff();
  //randomflicker();
  randomRain();
  diagonalRectangle();
  goThroughAllLedsOneAtATime();
  propeller();
  spiralInAndOut();
  flickerOff();
  turnEverythingOff();
  delay(2000);
}

void tunda(){
  int tnda = map(analogRead(POT), 0, 1013, 1000, 50);
  delay(tnda);
}


//turn all off
void turnEverythingOff()
 {
   for(int i = 0; i<16; i++)
   {
     digitalWrite(column[i], 0);
   }
   for(int i = 0; i<4; i++)
   {
     digitalWrite(layer[i], 0);
   }
 }
 
//turn all on
void turnEverythingOn()
{
  for(int i = 0; i<16; i++)
  {
    digitalWrite(column[i], 1);
  }
  //turning on layers
  for(int i = 0; i<4; i++)
  {
    digitalWrite(layer[i], 1);
  }
}
//turn columns off
void turnColumnsOff()
{
  for(int i = 0; i<16; i++)
  {
    digitalWrite(column[i], 0);
  }
}
//flicker on
void flickerOn()
{
  int i = 150;
  while(i != 0)
  {
    turnEverythingOn();
    delay(i);
    turnEverythingOff();
    delay(i);
    i-= 5;
  }
}
//turn everything on and off by layer up and down NOT TIMED
void turnOnAndOffAllByLayerUpAndDownNotTimed()
{
  int x = 75;
  for(int i = 5; i != 0; i--)
  {
    turnEverythingOn();
    for(int i = 4; i!=0; i--)
    {
      digitalWrite(layer[i-1], 0);
      tunda();
    }
    for(int i = 0; i<4; i++)
    {
      digitalWrite(layer[i], 1);
      tunda();
    }
      for(int i = 0; i<4; i++)
    {
      digitalWrite(layer[i], 0);
      tunda();
    }
    for(int i = 4; i!=0; i--)
    {
      digitalWrite(layer[i-1], 1);
      tunda();
    }
  }
}
//turn everything on and off by column sideways
void turnOnAndOffAllByColumnSideways()
{
  int x = 75;
  turnEverythingOff();
  //turn on layers
  for(int i = 0; i<4; i++)
  {
    digitalWrite(layer[i], 1);
  }
  for(int y = 0; y<3; y++)
  {
    //turn on 0-3
    for(int i = 0; i<4; i++)
    {
      digitalWrite(column[i], 1);
      tunda();
    }
    //turn on 4-7
    for(int i = 4; i<8; i++)
    {
      digitalWrite(column[i], 1);
      tunda();
    }
    //turn on 8-11
    for(int i = 8; i<12; i++)
    {
      digitalWrite(column[i], 1);
      tunda();
    }
    //turn on 12-15
    for(int i = 12; i<16; i++)
    {
      digitalWrite(column[i], 1);
      tunda();
    }
    //turn off 0-3
    for(int i = 0; i<4; i++)
    {
      digitalWrite(column[i], 0);
      tunda();
    }
    //turn off 4-7
    for(int i = 4; i<8; i++)
    {
      digitalWrite(column[i], 0);
      tunda();
    }
    //turn off 8-11
    for(int i = 8; i<12; i++)
    {
      digitalWrite(column[i], 0);
      tunda();
    }
    //turn off 12-15
    for(int i = 12; i<16; i++)
    {
      digitalWrite(column[i], 0);
      tunda();
    }
    //turn on 12-15
    for(int i = 12; i<16; i++)
    {
      digitalWrite(column[i], 1);
      tunda();
    }
    //turn on 8-11
    for(int i = 8; i<12; i++)
    {
      digitalWrite(column[i], 1);
      tunda();
    }
    //turn on 4-7
    for(int i = 4; i<8; i++)
    {
      digitalWrite(column[i], 1);
      tunda();
    }
    //turn on 0-3
    for(int i = 0; i<4; i++)
    {
      digitalWrite(column[i], 1);
      tunda();
    }
    //turn off 12-15
    for(int i = 12; i<16; i++)
    {
      digitalWrite(column[i], 0);
      tunda();
    }
    //turn off 8-11
    for(int i = 8; i<12; i++)
    {
      digitalWrite(column[i], 0);
      tunda();
    }
    //turn off 4-7
    for(int i = 4; i<8; i++)
    {
      digitalWrite(column[i], 0);
      tunda();
    }
    //turn off 0-3
    for(int i = 0; i<4; i++)
    {
      digitalWrite(column[i], 0);
      tunda();
    }
  }
}
//up and down single layer stomp
void layerstompUpAndDown()
{
  int x = 75;
  for(int i = 0; i<4; i++)
  {
    digitalWrite(layer[i], 0);
  }
  for(int y = 0; y<5; y++)
  {
    for(int count = 0; count<1; count++)
    { 
      for(int i = 0; i<4; i++)
      {
        digitalWrite(layer[i], 1);
        tunda();
        digitalWrite(layer[i], 0);
      }
      for(int i = 4; i !=0; i--)
      {
        digitalWrite(layer[i-1], 1);
        tunda();
        digitalWrite(layer[i-1], 0);
      }
    }
    for(int i = 0; i<4; i++)
    {
      digitalWrite(layer[i], 1);
      tunda();
    }
    for(int i = 4; i!=0; i--)
    {
      digitalWrite(layer[i-1], 0);
      tunda();
    }
  }
}
//flicker off
void flickerOff()
{
  turnEverythingOn();
  for(int i = 0; i!= 150; i+=5)
  {
    turnEverythingOff();
    delay(i+50);
    turnEverythingOn();
    delay(i);
  }
}
//around edge of the cube down
void aroundEdgeDown()
{
  for(int x = 200; x != 0; x -=50)
  {
    turnEverythingOff();
    for(int i = 4; i != 0; i--)
    {
      digitalWrite(layer[i-1], 1);
      digitalWrite(column[5], 1);
      digitalWrite(column[6], 1);
      digitalWrite(column[9], 1);
      digitalWrite(column[10], 1);
      
      digitalWrite(column[0], 1);
      tunda();
      digitalWrite(column[0], 0);
      digitalWrite(column[4], 1);
      tunda();
      digitalWrite(column[4], 0);
      digitalWrite(column[8], 1);
      tunda();
      digitalWrite(column[8], 0);
      digitalWrite(column[12], 1);
      tunda();
      digitalWrite(column[12], 0);
      digitalWrite(column[13], 1);
      tunda();
      digitalWrite(column[13], 0);
      digitalWrite(column[14], 1);
      tunda();
      digitalWrite(column[14], 0);
      digitalWrite(column[15], 1);
      tunda();
      digitalWrite(column[15], 0);
      digitalWrite(column[11], 1);
      tunda();
      digitalWrite(column[11], 0);
      digitalWrite(column[7], 1);
      tunda();
      digitalWrite(column[7], 0);
      digitalWrite(column[3], 1);
      tunda();
      digitalWrite(column[3], 0);
      digitalWrite(column[2], 1);
      tunda();
      digitalWrite(column[2], 0);
      digitalWrite(column[1], 1);
      tunda();
      digitalWrite(column[1], 0);
    }
  }
}
//random flicker
void randomflicker()
{
  turnEverythingOff();
  int x = 10;
  for(int i = 0; i !=750; i+=2)
  {
  int randomLayer = random(0,4);
  int randomColumn = random(0,16);
  
  digitalWrite(layer[randomLayer], 1);
  digitalWrite(column[randomColumn], 1);
  tunda();
  digitalWrite(layer[randomLayer], 0);
  digitalWrite(column[randomColumn], 0);
  tunda(); 
  }
}
//random rain
void randomRain()
{
  turnEverythingOff();
  int x = 100;
  for(int i = 0; i!=60; i+=2)
  {
    int randomColumn = random(0,16);
    digitalWrite(column[randomColumn], 1);
    digitalWrite(layer[0], 1);
    delay(x+50);
    digitalWrite(layer[0], 0);
    digitalWrite(layer[1], 1);
    tunda();
    digitalWrite(layer[1], 0);
    digitalWrite(layer[2], 1);
    tunda();
    digitalWrite(layer[2], 0);
    digitalWrite(layer[3], 1);
    delay(x+50);
    digitalWrite(layer[3], 0);
    digitalWrite(column[randomColumn], 0);
  }
}
//diagonal rectangle
void diagonalRectangle()
{
  int x = 350;
  turnEverythingOff();
  for(int count = 0; count<5; count++)
  {
    //top left
    for(int i = 0; i<8; i++)
    {
      digitalWrite(column[i], 0);
    }
    digitalWrite(layer[3], 1);
    digitalWrite(layer[2], 1);
    tunda();
    turnEverythingOff();
    //middle middle
    for(int i = 4; i<12; i++)
    {
      digitalWrite(column[i], 1);
    }
    digitalWrite(layer[1], 1);
    digitalWrite(layer[2], 1);
    tunda();
    turnEverythingOff();
    //bottom right
    for(int i = 8; i<16; i++)
    {
      digitalWrite(column[i], 1);
    }
    digitalWrite(layer[0], 1);
    digitalWrite(layer[1], 1);
    tunda();
    turnEverythingOff();
    //bottom middle
    for(int i = 4; i<12; i++)
    {
      digitalWrite(column[i], 1);
    }
    digitalWrite(layer[0], 1);
    digitalWrite(layer[1], 1);
    tunda();
    turnEverythingOff();
    //bottom left
    for(int i = 0; i<8; i++)
    {
      digitalWrite(column[i], 1);
    }
    digitalWrite(layer[0], 1);
    digitalWrite(layer[1], 1);
    tunda();
    turnEverythingOff();
    //middle middle
    for(int i = 4; i<12; i++)
    {
      digitalWrite(column[i], 1);
    }
    digitalWrite(layer[1], 1);
    digitalWrite(layer[2], 1);
    tunda();
    turnEverythingOff();
    //top right
    for(int i = 8; i<16; i++)
    {
      digitalWrite(column[i], 1);
    }
    digitalWrite(layer[2], 1);
    digitalWrite(layer[3], 1);
    tunda();
    turnEverythingOff();
    //top middle
    for(int i = 4; i<12; i++)
    {
      digitalWrite(column[i], 1);
    }
    digitalWrite(layer[2], 1);
    digitalWrite(layer[3], 1);
    tunda();
    turnEverythingOff();
  }
  //top left
  for(int i = 0; i<8; i++)
  {
    digitalWrite(column[i], 1);
  }
  digitalWrite(layer[3], 1);
  digitalWrite(layer[2], 1);
  tunda();
  turnEverythingOff();
}
//propeller
void propeller()
{
  turnEverythingOff();
  int x = 90;
  for(int y = 4; y>0; y--)
  {
    for(int i = 0; i<6; i++)
    {
      //turn on layer
      digitalWrite(layer[y-1], 1);
      //a1
      turnColumnsOff();
      digitalWrite(column[0], 1);
      digitalWrite(column[5], 1);
      digitalWrite(column[10], 1);
      digitalWrite(column[15], 1);
      tunda();
      //b1
      turnColumnsOff();
      digitalWrite(column[4], 1);
      digitalWrite(column[5], 1);
      digitalWrite(column[10], 1);
      digitalWrite(column[11], 1);
      tunda();
      //c1
      turnColumnsOff();
      digitalWrite(column[6], 1);
      digitalWrite(column[7], 1);
      digitalWrite(column[8], 1);
      digitalWrite(column[9], 1);
      tunda();
      //d1
      turnColumnsOff();
      digitalWrite(column[3], 1);
      digitalWrite(column[6], 1);
      digitalWrite(column[9], 1);
      digitalWrite(column[12], 1);
      tunda();
      //d2
      turnColumnsOff();
      digitalWrite(column[2], 1);
      digitalWrite(column[6], 1);
      digitalWrite(column[9], 1);
      digitalWrite(column[13], 1);
      tunda();
      //d3
      turnColumnsOff();
      digitalWrite(column[1], 1);
      digitalWrite(column[5], 1);
      digitalWrite(column[10], 1);
      digitalWrite(column[14], 1);
      tunda();
    }
  }
  //d4
  turnColumnsOff();
  digitalWrite(column[0], 1);
  digitalWrite(column[5], 1);
  digitalWrite(column[10], 1);
  digitalWrite(column[15], 1);
  tunda();
}
//spiral in and out
void spiralInAndOut()
{
  turnEverythingOn();
  int x = 60;
  for(int i = 0; i<6; i++)
  {
    //spiral in clockwise
    digitalWrite(column[0], 0);
    tunda();
    digitalWrite(column[1], 0);
    tunda();
    digitalWrite(column[2], 0);
    tunda();
    digitalWrite(column[3], 0);
    tunda();
    digitalWrite(column[7], 0);
    tunda();
    digitalWrite(column[11], 0);
    tunda();
    digitalWrite(column[15], 0);
    tunda();
    digitalWrite(column[14], 0);
    tunda();
    digitalWrite(column[13], 0);
    tunda();
    digitalWrite(column[12], 0);
    tunda();
    digitalWrite(column[8], 0);
    tunda();
    digitalWrite(column[4], 0);
    tunda();
    digitalWrite(column[5], 0);
    tunda();
    digitalWrite(column[6], 0);
    tunda();
    digitalWrite(column[10], 0);
    tunda();
    digitalWrite(column[9], 0);
    tunda();
//spiral out counter clockwise
    digitalWrite(column[9], 1);
    tunda();
    digitalWrite(column[10], 1);
    tunda();
    digitalWrite(column[6], 1);
    tunda();
    digitalWrite(column[5], 1);
    tunda();
    digitalWrite(column[4], 1);
    tunda();
    digitalWrite(column[8], 1);
    tunda();
    digitalWrite(column[12], 1);
    tunda();
    digitalWrite(column[13], 1);
    tunda();
    digitalWrite(column[14], 1);
    tunda();
    digitalWrite(column[15], 1);
    tunda();
    digitalWrite(column[11], 1);
    tunda();
    digitalWrite(column[7], 1);
    tunda();
    digitalWrite(column[3], 1);
    tunda();
    digitalWrite(column[2], 1);
    tunda();
    digitalWrite(column[1], 1);
    tunda();
    digitalWrite(column[0], 1);
    tunda();
//spiral in counter clock wise
    digitalWrite(column[0], 0);
    tunda();
    digitalWrite(column[4], 0);
    tunda();
    digitalWrite(column[8], 0);
    tunda();
    digitalWrite(column[12], 0);
    tunda();
    digitalWrite(column[13], 0);
    tunda();
    digitalWrite(column[14], 0);
    tunda();
    digitalWrite(column[15], 0);
    tunda();
    digitalWrite(column[11], 0);
    tunda();
    digitalWrite(column[7], 0);
    tunda();
    digitalWrite(column[3], 0);
    tunda();
    digitalWrite(column[2], 0);
    tunda();
    digitalWrite(column[1], 0);
    tunda();
    digitalWrite(column[5], 0);
    tunda();
    digitalWrite(column[9], 0);
    tunda();
    digitalWrite(column[10], 0);
    tunda();
    digitalWrite(column[6], 0);
    tunda();
//spiral out clock wise
    digitalWrite(column[6], 1);
    tunda();
    digitalWrite(column[10], 1);
    tunda();
    digitalWrite(column[9], 1);
    tunda();
    digitalWrite(column[5], 1);
    tunda();
    digitalWrite(column[1], 1);
    tunda();
    digitalWrite(column[2], 1);
    tunda();
    digitalWrite(column[3], 1);
    tunda();
    digitalWrite(column[7], 1);
    tunda();
    digitalWrite(column[11], 1);
    tunda();
    digitalWrite(column[15], 1);
    tunda();
    digitalWrite(column[14], 1);
    tunda();
    digitalWrite(column[13], 1);
    tunda();
    digitalWrite(column[12], 1);
    tunda();
    digitalWrite(column[8], 1);
    tunda();
    digitalWrite(column[4], 1);
    tunda();
    digitalWrite(column[0], 1);
    tunda();
  }
}
//go through all leds one at a time
void goThroughAllLedsOneAtATime()
{
  int x = 15;
  turnEverythingOff();
  for(int y = 0; y<5; y++)
  {
    //0-3
    for(int count = 4; count != 0; count--)
    {
      digitalWrite(layer[count-1], 1);
      for(int i = 0; i<4; i++)
      {
        digitalWrite(column[i], 1);
        tunda();
        digitalWrite(column[i], 0);
        tunda();
      }
    digitalWrite(layer[count-1], 0);
    }
    //4-7
    for(int count = 0; count < 4; count++)
    {
      digitalWrite(layer[count], 1);
      for(int i = 4; i<8; i++)
      {
        digitalWrite(column[i], 1);
        tunda();
        digitalWrite(column[i], 0);
        tunda();
      }
    digitalWrite(layer[count], 0);
    }
    //8-11
    for(int count = 4; count != 0; count--)
    {
      digitalWrite(layer[count-1], 1);
      for(int i = 8; i<12; i++)
      {
        digitalWrite(column[i], 1);
        tunda();
        digitalWrite(column[i], 0);
        tunda();
      }
    digitalWrite(layer[count-1], 0);
    }
    //12-15
    for(int count = 0; count < 4; count++)
    {
      digitalWrite(layer[count], 1);
      for(int i = 12; i<16; i++)
      {
        digitalWrite(column[i], 1);
        tunda();
        digitalWrite(column[i], 0);
        tunda();
      }
    digitalWrite(layer[count], 0);
    }
  }
}
