int flag;
int state = 1;
int buttonState = 0;
String message;


// kad sistem ne radi, odnosno treperi žuto
// svetlo, poziva se promenom stanja semafora

void yellowBlinking(){

// sve diode setujemo na LOW da ne bi
// svetlele dok žuto svetlo treperi

  digitalWrite(13, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  digitalWrite(9, LOW);
  
// dok god je stanje jednako 0, žuto svetlo
// treperi i signalizira da nešto nije u redu

  while(state == 0){
  
// pin 12 predstavlja žutu LED diodu i
// parametrima HIGH i LOW definisemo, da li svetli
// ili je ugašena, odnosno simuliramo treperenje

  digitalWrite(12, HIGH);
  delay(1000); // čeka 1 sekund
  digitalWrite(12, LOW);
  delay(1000); // čeka 1 sekund
  change();
  }
}



// inicijalno stanje pri pokretanju simulacije

void initState(){
 
//Zeleno svetlo za vozila, crveno za pešake,
// odnosno opet definišemo pomoću HIGH i LOW,
// koja dioda svetli a koje su ugašene.

  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  
// u ovom slučaju kada je zeleno za vozila (kod gore)
// definišemo da je crveno za pešake (kod dole)

  digitalWrite(10, HIGH);
  digitalWrite(9, LOW);
  delay(10000); // čeka 10 sekundi
}


// promena stanja semafora, i ukoliko je "Off" žuto treperi

void change(){
  if(Serial.available()>0){
   message = Serial.readString();
   Serial.print(message);
  if (message == "On "){
  
    state = 1;
    loop();
	
  }
  if (message == "Off"){
  
    state = 0;
    yellowBlinking();
    
  }
  }
}



void setup()
{
  pinMode(2, INPUT);
  
  pinMode(13, OUTPUT);
  
  pinMode(12, OUTPUT);
  
  pinMode(11, OUTPUT);
  
  pinMode(10, OUTPUT);
  
  pinMode(9, OUTPUT);
  
  pinMode(3, INPUT);
  
  Serial.begin(9600); 
}



void loop()
{
  change();
  flag = 0;
    
// Zeleno svetlo za vozila, crveno svetlo za pešake
// takođe korišćenjem HIGH i LOW

  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(9, LOW);
  
  delay(10000); // čeka 10 sekundi
  
  change();
  
bool btnFlag = false;  
  
  while(flag == 0){
	buttonState = digitalRead(2);
    
	
	change();
    
    if(buttonState==HIGH){
      btnFlag=true;
    }
		
    if(buttonState==LOW &&  btnFlag==true){
		btnFlag = false;  
		//Zuto svetlo za vozila, crveno svetlo za pešake
		
		digitalWrite(13, LOW);
		digitalWrite(12, HIGH);
		digitalWrite(11, LOW);
		digitalWrite(10, HIGH);
		digitalWrite(9, LOW);
		
		delay(3000); // čeka 3 sekunde
		
  
  
  
    // pa se izvrši promena
      change();
      
		//Crveno svetlo za vozila, crveno svetlo za pešake
		
		digitalWrite(13, HIGH);
		digitalWrite(12, LOW);
		digitalWrite(11, LOW);
		digitalWrite(10, HIGH);
		digitalWrite(9, LOW);
		
		delay(2000); // čeka 2 sekunde
     

	 // opet se izvrši promena 
      change();
      
		//Crveno svetlo za vozila, zeleno svetlo za pešake
		
		digitalWrite(13, HIGH);
		digitalWrite(12, LOW);
		digitalWrite(11, LOW);
		digitalWrite(10, LOW);
		digitalWrite(9, HIGH);
		
		delay(10000); // čeka 10 sekundi
      
	  
	  
      change();
      
		//Crveno svetlo za vozila, crveno svetlo za pešake
		
		digitalWrite(13, HIGH);
		digitalWrite(12, LOW);
		digitalWrite(11, LOW);
		digitalWrite(10, HIGH);
		digitalWrite(9, LOW);
		
		delay(1000); // čeka 1 sekundu
      
      change();
      
		//Zuto svetlo za vozila, crveno svetlo za pešake
		
		digitalWrite(13, LOW);
		digitalWrite(12, HIGH);
		digitalWrite(11, LOW);
		digitalWrite(10, HIGH);
		digitalWrite(9, LOW);
		
		delay(3000); // čeka 3 sekunde
      
	  
	  
      change();
      		
		flag = 1;
		
		}
  }
}