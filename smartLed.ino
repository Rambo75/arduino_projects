#define btnPin_G 3
#define btnPin_R 2
#define btnPin_Y 12
#define ledPin_L 10
#define potzPin A0

bool IsBtnGPressed = false;
bool IsBtnYPressed = false;
bool IsBtnRPressed = false;
int interval = 5000;
unsigned long timeStart;
void setup() {
  pinMode(btnPin_G, INPUT_PULLUP);
  pinMode(btnPin_R, INPUT_PULLUP);
  pinMode(btnPin_Y, INPUT_PULLUP);
  pinMode(ledPin_L, OUTPUT);
  digitalWrite(ledPin_L, LOW);
  Serial.begin(9600);
  
}
void loop() {
  int potzVal=analogRead(potzPin);
  if(potzVal > 50 ){
    if(digitalRead(btnPin_G)==LOW){
     IsBtnGPressed = true;
     IsBtnYPressed = false;
     IsBtnRPressed = false;
     timeStart = millis();
  }
  
  if(digitalRead(btnPin_Y)==LOW){
    IsBtnYPressed = true;
    IsBtnGPressed = false;
    IsBtnRPressed = false;
    timeStart = millis(); 
  }
  if(digitalRead(btnPin_R)==LOW){
    IsBtnRPressed = true;
    IsBtnGPressed = false;
    IsBtnYPressed =false;
  
  }
  if(IsBtnGPressed){
    digitalWrite(ledPin_L, HIGH);
  }
  if(millis()-timeStart >= interval){
    digitalWrite(ledPin_L, LOW);
  }
  if(IsBtnYPressed){
    analogWrite(ledPin_L, 64);
  }
  if(millis()-timeStart >= interval){
    digitalWrite(ledPin_L, LOW);
  }
  if(IsBtnRPressed){
    IsBtnGPressed = false;
    IsBtnYPressed = false;
  digitalWrite(ledPin_L, LOW);
  
  }
  }
   Serial.println(potzVal);
}
