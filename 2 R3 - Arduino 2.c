int buttonState = 0;
int state = 1;
int sState;



void setup(){

// definicija pinova, da li su input ili output

  pinMode(2, INPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  
  Serial.begin(9600);
  
  attachInterrupt(digitalPinToInterrupt(2), change, FALLING);
}



void loop(){  

// stanja simulacije, radi ili ne radi

  if(state == 1){
  
    working();
	
  }
  
  if(state == 0){
  
    NWorking();
	
  }
}



// ako radi zeleno treperi na svaki sekund
void working(){

  state = 1;
  sState = 0;
  
  digitalWrite(13, HIGH);
  delay(1000); // čeka 1 sekundu
  
  digitalWrite(13, LOW);
  delay(1000); // čeka 1 sekundu
}


// ako ne radi crveno treperi na svaki sekund
void NWorking(){

  state = 0;
  sState = 1;
  
  digitalWrite(12, HIGH);
  delay(1000); // čeka 1 sekundu
  
  digitalWrite(12, LOW);
  delay(1000); // čeka 1 sekundu
}



void change(){
  state = sState;
  
  if (state == 1){
  
    Serial.write("On ",3);
    delay(1000); // čeka 1 sekundu
	
  }
  if (state == 0){
  
    Serial.write("Off",3);
    delay(1000); // čeka 1 sekundu
	
  }
}