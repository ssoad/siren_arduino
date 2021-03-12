int a=0; //switch pin
int speaker=13; // speakerer Pin
void setup() {
  Serial.begin(9600);
for(int i=3;i<=13;i++)
{
  pinMode(i,OUTPUT);
}
pinMode(2,INPUT);
}

void loop() {
  a  = digitalRead(2);
  Serial.println(a);
  if(a == HIGH){
   siren();
   a = LOW;
  }
}



void siren() {
  // Whoop up
  for(int hz = 440; hz < 1000; hz+=25){
    tone(speaker, hz, 50);
    delay(5);
    for(int i=3;i<=7;i++)
    {
    digitalWrite(i,HIGH);
     digitalWrite(i+5,LOW);
    }
  }
  // Whoop down
  for(int hz = 1000; hz > 440; hz-=25){
    tone(speaker, hz, 50);
    delay(5);
    for(int i=3;i<=7;i++)
    {
      digitalWrite(i,HIGH);
      digitalWrite(i+5,HIGH);
    }
    
  }
  for(int i=3;i<=7;i++)
    {
    digitalWrite(i,LOW);
     digitalWrite(i+5,LOW);
    }
  }
  
