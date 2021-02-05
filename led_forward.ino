int button =8;   //button pin
int userPress=0; //is button on or off
int leftMotorForward=11; //left wheel moves forwards
int leftMotorBackward=10; //left wheel moves backwards
int rightMotorForward=9;//right wheel moves forwards
int rightMotorBackward=12;//right wheel moves backwards
int leftSensor=5; //left sensor pin
int rightSensor=4; //right sensor pin
int blackCounter=0; //counter for number of black lines seen
int p=0; //counter for loop
int copy; //copies blackCounter for return
int counter3=2; //counter for destination 3
int copy3=2; //copy for destination 3
int counter=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(button, INPUT);
  pinMode(leftSensor, INPUT);
  pinMode(rightSensor, INPUT);
  pinMode(leftMotorForward, OUTPUT);
  pinMode(leftMotorBackward, OUTPUT);
  pinMode(rightMotorForward, OUTPUT);
  pinMode(rightMotorBackward, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0; i<=2; i++)
  {
    userPress= digitalRead(button); //counts the number of times the user pushes button
  if(userPress==LOW)
  {
    blackCounter=blackCounter*2; //increases blackCounter based on user input
    copy=blackCounter; //copies blackCounter
  }
  }
  if(userPress==LOW)    //starts after user presses button
  {
    while(userPress==LOW)
    {
      int a = analogRead(rightSensor);
      int b = analogRead(leftSensor);
      Serial.println(a);
      delay(1);
      Serial.println(b);
      delay(1);

      if(a<=900 && b>1000)
      {
        digitalWrite(leftMotorForward, HIGH);
        digitalWrite(rightMotorForward, LOW);
      }

      else if(a>900 && b<=1000 )
      {
        digitalWrite(rightMotorForward, HIGH);
        digitalWrite(leftMotorForward, LOW);
      }
      else if(b>1000 && a>900)
      {
        digitalWrite(leftMotorForward, HIGH);
        digitalWrite(rightMotorForward, HIGH);
      }
    }

   }
}

