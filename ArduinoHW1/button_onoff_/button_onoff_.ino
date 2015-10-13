int oldButtonState = 0;
int newButtonState = 0;
int buttonPin = 2;
int ledPin = 13;
int debounceTime = 10;
bool ledState = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
  pinMode(buttonPin,INPUT);
  }

void loop() {
  Serial.println(digitalRead(8));
  oldButtonState = digitalRead(buttonPin);
  delay(debounceTime);
  newButtonState = digitalRead(buttonPin);

  if(oldButtonState != newButtonState){
    if(newButtonState == 1){
          //if we've gotten this far in our if statment
          //we've found the rising edge
      ledState = !ledState;
          //changing the ledState, if ledState is true, turn in to false,
          //if it is false, turn it to ture

      }
    }
  if(ledState == true){
    digitalWrite(ledPin,HIGH);
    }
    else{
      digitalWrite(ledPin,LOW);
    }
  // put your main code here, to run repeatedly:

}
