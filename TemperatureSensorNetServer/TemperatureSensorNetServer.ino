/*
Wed Jul 31 23:19:56 CEST 2013, Lloyd DIZON
Xbee server - receives data, does something with it

Coordinator
atid    - 2001
atsh/sl - 13A200/408B1877
atdh/dl - 13A200/40A63C57


*/

#include <SPI.h>
#include <Ethernet.h>

// Enter a MAC address for your controller below.
// Newer Ethernet shields have a MAC address printed on a sticker on the shield
byte mac[] = {  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress server(10,0,1,4); // CrusherW



// Initialize the Ethernet client library
// with the IP address and port of the server 
// that you want to connect to (port 80 is default for HTTP):
EthernetClient client;


// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {

  
 // Open serial communications and wait for port to open:
  Serial.begin(9600);


  // start the Ethernet connection:
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    // no point in carrying on, so do nothing forevermore:
    for(;;)
      ;
  }
  // give the Ethernet shield a second to initialize:
  delay(1000);
  Serial.println("connecting...");


}

void loop() {

  if (Serial.available() > 0) {

    Serial.println(Serial.parseFloat());



  }

  delay(2000);
  
}
