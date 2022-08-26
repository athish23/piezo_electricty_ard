int threshold=1;  //Threshold level to be set so that arduino can check if power should be taken from battery or capacitor
int battery=7;      //arduino pin number of battery connected relay
int capacitor=6;    //arduino pin number of battery connected capacitor

void setup() {
  // put your setup code here, to run once:
  pinMode(7,OUTPUT);     //initialisation of output pin #7
  pinMode(6,OUTPUT);     //initialisation of output pin #6
  Serial.begin(9600);    //Usage of serial monitor
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(battery,HIGH);    //Initially battery is on
  digitalWrite(capacitor,LOW);   //Initially capacitor is off
   delay(2000);                  //Wait for 2 seconds
   int volt=analogRead(A0);      //Reading the voltage from voltage sensor
  double voltage=map(volt,0,1023,0,2500);  //Converting digital  to voltage × 100
  voltage=voltage/100;            //voltage in original form
   if(voltage>threshold)          //Condition checking for transfer of relay switch
  { digitalWrite(capacitor,HIGH); //Using power from capacitor 
    delay(100);                   //delay of 100ms
    digitalWrite(battery,LOW);    //switching off supply from battery
    }
  
  delay(1000);                    // wait for 1 second
  
  Serial.print("Voltage across Capacitor:"); //Prints voltage  across capacitors
  Serial.print(voltage);
  Serial.print("\n"); 
  

}
