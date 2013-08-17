/*
Wed Jul 31 23:19:56 CEST 2013, Lloyd DIZON
Xbee client - sends data to server

Router/End device
atid    - 2001
atsh/sl - 13A200/40A63C57
atdh/dl - 13A200/408B1877

*/

#define aref_voltage 3.3 // we tie 3.3V to ARef and measure it with a multimeter!

//TMP36 Pin Variables
int tempPin = 0; //the analog pin the TMP36's Vout (sense) pin is connected to

//the resolution is 10 mV / degree centigrade with a
//500 mV offset to allow for negative temperatures
int tempReading; // the analog reading from the sensor

// constants won't change. They're used here to 
// set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);      
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT); 

  // Open serial communications and wait for port to open:
  Serial.begin(9600);  

  // If you want to set the aref to something other than 5v
  analogReference(EXTERNAL);
}

void loop(){
    tempReading = analogRead(tempPin);
//    Serial.print("Temp reading = ");
//    Serial.print(tempReading); // the raw analog reading

    // converting that reading to voltage, which is based off the reference voltage
    float voltage = tempReading * aref_voltage;
    voltage /= 1024.0;

    // print out the voltage
//    Serial.print(" - ");
//    Serial.print(voltage); Serial.println(" volts");

    // now print out the temperature
    float temperatureC = (voltage - 0.5) * 100 ; //converting from 10 mv per degree wit 500 mV offset

    //to degrees ((volatge - 500mV) times 100)
    Serial.print(temperatureC); //Serial.println(" degrees C");

    // now convert to Fahrenheight
//    float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
//    Serial.print(temperatureF); Serial.println(" degrees F");
    delay(5000);
}

