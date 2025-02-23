/* 
  Sketch generated by the Arduino IoT Cloud Thing "Untitled"
  https://create.arduino.cc/cloud/things/50669516-e489-4b71-98f8-0c148b672b45 

  Arduino IoT Cloud Variables description

  The following variables are automatically generated and updated when changes are made to the Thing

  float aC;
  float cH4;
  float cO;
  float h2S;
  float nH4;

  Variables which are marked as READ/WRITE in the Cloud Thing will also have functions
  which are called when their values are changed from the Dashboard.
  These functions are generated with the Thing and added at the end of this sketch.
*/

#include "thingProperties.h"

#include <MQ135.h>
// Include the required libraries


int R0 = 176;
int R2 = 1000;
float RS;
float PPM_acetone;
const int mq135Pin = A0;
MQ135 gasSensor = MQ135(mq135Pin);
const float ammoniaR0 = 150;




const int mq5Pin = A5;
int myled=10;
int buzzer=8;





void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
  
   pinMode(myled,OUTPUT);
    pinMode(buzzer,OUTPUT);
}

void loop() {
  ArduinoCloud.update();
  
  int sensorValue = analogRead(A0);
    
    int smqv=analogRead(A5);
    
    // read the input on analog pin 0:
    // convert to voltage:
    float volts = sensorValue * 5;
    volts = volts / 1023;
    // calculate RS
    RS = R2 * (1-volts);
    RS = RS/volts;
    // calculate acetone PPM
    PPM_acetone = 159.6 - 133.33*(RS/R0);
    // print out the acetone concentration:
    Serial.println("The amount of acetone (in PPM): ");
    Serial.println(PPM_acetone);
    aC=PPM_acetone;
    delay(500); // delay in between reads for stability

  int cosensorValue = analogRead(A0);
  Serial.println("The amount of CO2 (in PPM): ");
  Serial.println(cosensorValue);
  h2S=cosensorValue;
  delay(500);


   int rawValue = analogRead(mq135Pin);

  // Convert the raw analog value to ammonia concentration using the calibration factor
  float ppmAmmonia = gasSensor.getPPM();
  // You can also get other values like resistance, R0, etc., if needed.

  // Print the ammonia concentration to the serial monitor
  Serial.print("Ammonia Concentration (PPM): ");
  Serial.println(ppmAmmonia);
  nH4=ppmAmmonia;

  // Add a delay between readings
  delay(500); // Adjust the delay time as needed


  
  
  
  
  
    // Read the analog value from the MQ-5 sensor
  int RrawValue = analogRead(mq5Pin);

  // Convert raw value to gas concentrations (adjust these values based on your sensor)
  float ppmH2 = map(RrawValue, 0, 1023, 0, 1000); // Hydrogen (H2)
  float ppmLPG = map(RrawValue, 0, 1023, 0, 5000); // LPG
  float ppmCH4 = map(RrawValue, 0, 1023, 0, 5000); // Methane (CH4)
  float ppmCO = map(RrawValue, 0, 1023, 0, 1000); // Carbon Monoxide (CO)
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  // Print gas concentrations to the serial monitor
  Serial.print("Hydrogen (H2) Concentration (PPM): ");
  Serial.println(ppmH2);
  Serial.print("LPG Concentration (PPM): ");
  Serial.println(ppmLPG);
  Serial.print("Methane (CH4) Concentration (PPM): ");
  Serial.println(ppmCH4);
  cH4=ppmCH4;
  Serial.print("Carbon Monoxide (CO) Concentration (PPM): ");
  Serial.println(ppmCO);
  cO=ppmCO;

  // Add a delay between readings
  delay(100); // Adjust the delay time as needed
  // Your code here 
  
 if(PPM_acetone<0)
  {
      
  digitalWrite(myled, HIGH);
   digitalWrite(buzzer, LOW);// turn the LED on (HIGH is the voltage level)
  
  
  }
   //else
   //{
  // wait for a second
 

   
  // digitalWrite(myled, LOW);
  //digitalWrite(buzzer, HIGH); 
 
  // }
                         // wait for a second
  
}







