
    #include <IRremote.h>
     
    int RECV_PIN = 11; // the pin where you connect the output pin of TSOP4838
    int led1 = 13;
    int led2 = 8;
    int led3 = 9;
    int led4 = 10;
    int itsONled[] = {0,0,0,0,0};
    /* the initial state of LEDs is OFF (zero) 
    the first zero must remain zero but you can 
    change the others to 1's if you want a certain
    led to light when the board is powered */
    #define code1  8415 // code received from button A
    #define code2  41055 // code received from button B
    #define code3  24735 // code received from button C
    #define code4  4335 // code received from button D     
    IRrecv irrecv(RECV_PIN);
     
    decode_results results;
     
    void setup()
    {
      Serial.begin(9600);   // you can comment this line
      irrecv.enableIRIn();  // Start the receiver
      pinMode(led1, OUTPUT);
      pinMode(led2, OUTPUT);
      pinMode(led3, OUTPUT);
      pinMode(led4, OUTPUT);
    }
     
    void loop() {
      if (irrecv.decode(&results)) {
        unsigned int value = results.value;
        switch(value) {
           case code1:
             if(itsONled[1] == 1) {        // if first led is on then
                digitalWrite(led1, LOW);   // turn it off when button is pressed
                itsONled[1] = 0; 
                Serial.println("LED 1 OFF");  
             } else {                      // else if first led is off
                 digitalWrite(led1, HIGH); // turn it on when the button is pressed
                 itsONled[1] = 1;          // and set its state as on
                 Serial.println("LED 1 OFF");
             }
              break; 
           case code2:
             if(itsONled[2] == 1) {
                digitalWrite(led2, LOW);
                itsONled[2] = 0;
             } else {
                 digitalWrite(led2, HIGH);
                 itsONled[2] = 1;
             }
              break;
           case code3:
             if(itsONled[3] == 1) {
                digitalWrite(led3, LOW);
                itsONled[3] = 0;
             } else {
                 digitalWrite(led3, HIGH);
                 itsONled[3] = 1;
             }
              break;    
                case code4:
             if(itsONled[4] == 1) {
                digitalWrite(led4, LOW);
                itsONled[4] = 0;
             } else {
                 digitalWrite(led4, HIGH);
                 itsONled[4] = 1;
             }
              break;      
        }
        Serial.println(value); // you can comment this line
        irrecv.resume(); // Receive the next value
      }
    }
