#define solPwm 11
#define sagPwm 9
#define solIleri 13
#define solGeri 12
#define sagIleri 8
#define sagGeri 10

int sag_sensor_echo = A0;// sağ sensör
int sag_sensor_trigger = A1;// sağ sensör
int sol_sensor_echo = A5;// sol sensör
int sol_sensor_trigger = A4;// sol sensör
int on_sensor_echo = A3; // Ön sensör
int on_sensor_trigger = A2; // Ön sensör

int solhiz=50;
int saghiz=50;
int ilerihiz=70;
int tamdonus_hiz=70;



void setup() 
{
  Serial.begin(9600);
  pinMode(on_sensor_trigger, OUTPUT);
  pinMode(on_sensor_echo, INPUT);
  pinMode(sol_sensor_trigger, OUTPUT);
  pinMode(sol_sensor_echo, INPUT);
  pinMode(sag_sensor_trigger, OUTPUT);
  pinMode(sag_sensor_echo, INPUT);
  pinMode(solPwm, OUTPUT);
  pinMode(sagPwm, OUTPUT);
  pinMode(solIleri, OUTPUT);
  pinMode(solGeri, OUTPUT);
  pinMode(sagIleri, OUTPUT);
  pinMode(sagGeri, OUTPUT);
  delay(3000);

}

void loop() 
{
 long on_sensor_zaman, sol_sensor_zaman, sag_sensor_zaman;
 long sag_mesafe, sol_mesafe, on_mesafe;
 digitalWrite(on_sensor_trigger, LOW);
 delayMicroseconds(2);
 digitalWrite(on_sensor_trigger, HIGH);
 delayMicroseconds(5);
 digitalWrite(on_sensor_trigger, LOW);
 on_sensor_zaman = pulseIn(on_sensor_echo, HIGH);
 on_mesafe = on_sensor_zaman/29/2;
 digitalWrite(sol_sensor_trigger, LOW);
 delayMicroseconds(2);
 digitalWrite(sol_sensor_trigger, HIGH);
 delayMicroseconds(5);
 digitalWrite(sol_sensor_trigger, LOW);
 sol_sensor_zaman = pulseIn(sol_sensor_echo, HIGH);
 sol_mesafe = sol_sensor_zaman/29/2;
 digitalWrite(sag_sensor_trigger, LOW);
 delayMicroseconds(2);
 digitalWrite(sag_sensor_trigger, HIGH);
 delayMicroseconds(5);
 digitalWrite(sag_sensor_trigger, LOW);
 sag_sensor_zaman = pulseIn(sag_sensor_echo, HIGH);
 sag_mesafe = sag_sensor_zaman/29/2;
   Serial.print(sol_mesafe);
   Serial.print("    ");
   Serial.print(on_mesafe);
   Serial.print("    ");
   Serial.println(sag_mesafe);
   analogWrite(solPwm,0);
   analogWrite(sagPwm,0);
   digitalWrite(sagIleri,LOW);
   digitalWrite(sagGeri,LOW);
   digitalWrite(solIleri,LOW);
   digitalWrite(solGeri,LOW);


if(on_mesafe>14)
  { 
      if(sag_mesafe>4 && sag_mesafe<13)
  {
   analogWrite(solPwm,70);
   analogWrite(sagPwm,70);
   digitalWrite(sagIleri,HIGH);
   digitalWrite(sagGeri,LOW);
   digitalWrite(solIleri,HIGH);
   digitalWrite(solGeri,LOW); 
  }
  if(sol_mesafe>=13)
  {
   analogWrite(solPwm,70);
   analogWrite(sagPwm,70);
   digitalWrite(sagIleri,HIGH);
   digitalWrite(sagGeri,LOW);
   digitalWrite(solIleri,LOW);
   digitalWrite(solGeri,HIGH);
  }
  if(sol_mesafe<4)
  {
   analogWrite(solPwm,70);
   analogWrite(sagPwm,70);
   digitalWrite(sagIleri,LOW);
   digitalWrite(sagGeri,HIGH);
   digitalWrite(solIleri,HIGH);
   digitalWrite(solGeri,LOW);
  }
  if(sag_mesafe>=13)
  {
   analogWrite(solPwm,70);
   analogWrite(sagPwm,70);
   digitalWrite(sagIleri,LOW);
   digitalWrite(sagGeri,HIGH);
   digitalWrite(solIleri,HIGH);
   digitalWrite(solGeri,LOW);
  }
  if(sag_mesafe<4)
  {
   analogWrite(solPwm,70);
   analogWrite(sagPwm,70);
   digitalWrite(sagIleri,HIGH);
   digitalWrite(sagGeri,LOW);
   digitalWrite(solIleri,LOW);
   digitalWrite(solGeri,HIGH);
  }
  }
else if(sol_mesafe <=20  && on_mesafe <13) {  TurnRight();}
else if(sag_mesafe <=20  && on_mesafe <13) {  TurnLeft();}
if(sol_mesafe<=20 && on_mesafe>=13){GoGo();}
if(sag_mesafe<=20 && on_mesafe>=13){GoGo();}


//
// 
// 
//if(sag_mesafe<=13 && on_mesafe<=14 && sol_mesafe<=13){TurnRight();}
if(sol_mesafe>20 && sag_mesafe>20 && on_mesafe<13) {TurnRight();}
if(sol_mesafe>20 && sag_mesafe>20 && on_mesafe>14) {GoGo();}
//if(sol_mesafe >20 && sag_mesafe>20 && on_mesafe <=8) { TurnRight(); }
//if(sag_mesafe <=20 && sol_mesafe>20 && on_mesafe <=8) { TurnLeft(); }
if(sag_mesafe<=20 && sol_mesafe<=20 && on_mesafe<13) { TurnAround(); }
   }



void dur(int durma_zamani)
{
   digitalWrite(sagIleri,LOW);
   digitalWrite(sagGeri,LOW);
   digitalWrite(solIleri,LOW);
   digitalWrite(solGeri,LOW);
   delay(durma_zamani);
}
void GoGo()
{
   analogWrite(sagPwm,70);
   analogWrite(solPwm,70);
   digitalWrite(sagIleri,HIGH);
   digitalWrite(sagGeri,LOW);
   digitalWrite(solIleri,HIGH);
   digitalWrite(solGeri,LOW);
}

void TurnRight()
{
   analogWrite(sagPwm,100);
   analogWrite(solPwm,100);
   digitalWrite(sagIleri,LOW);
   digitalWrite(sagGeri,HIGH);
   digitalWrite(solIleri,HIGH);
   digitalWrite(solGeri,LOW);  
   delay(100);
   
}

void TurnLeft()
{
   analogWrite(sagPwm,100);
   analogWrite(solPwm,100);
   digitalWrite(sagIleri,HIGH);
   digitalWrite(sagGeri,LOW);
   digitalWrite(solIleri,LOW);
   digitalWrite(solGeri,HIGH);
   delay(200);
}
void TurnAround()
{
   analogWrite(sagPwm,100);
   analogWrite(solPwm,100);
   digitalWrite(sagIleri,LOW);
   digitalWrite(sagGeri,HIGH);
   digitalWrite(solIleri,HIGH);
   digitalWrite(solGeri,LOW);  
   delay(200);
   
}

