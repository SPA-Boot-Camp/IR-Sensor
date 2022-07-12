#include <IRremote.h>

const int RECV_PIN=A0;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  irrecv.blink13(true);
}

void loop() {
 

 if (IrReceiver.decode()) 
  {
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    
    irrecv.resume(); // Receive the next value
 delay(100);
 }
}
