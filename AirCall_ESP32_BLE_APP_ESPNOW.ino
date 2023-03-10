/*
    Este Codigo fue realizado por el Ing. Alejandro Orduz y es propiedad de la empresa Soluciones Vertiales
    Despliega un servidor BLE con caracteristicas de lectura y escritura, el cual recibe valores mediante bluetooth y los utiliza para activar una salida digital.
    En tota tiene 
*/
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>
#include <esp_now.h>
#include <WiFi.h>

BLECharacteristic *pCharacteristic;
bool deviceConnected = false;
float txValue = 0;

// Structure example to receive data
// Must match the sender structure
typedef struct struct_message {
    String msj;
} struct_message;

// Create a struct_message called myData
struct_message myData;

//const int readPin = 32; // Use GPIO number. See ESP32 board pinouts
//const int suno = 15;
//const int sdos = 2;
//const int cerrar = 13;

const int pisouno =  15; 
const int pisodos = 2;
const int pisotres = 4;
const int pisocuatro = 16;
const int pisocinco = 17;
const int pisoseis = 5;
const int pisosiete = 18;
const int pisoocho = 19;
const int pisonueve = 21;
const int pisodiez = 22;
const int pisoonce = 23;
const int pisodoce = 32;
const int pisotrece = 33;
const int pisocatorce = 25;
const int pisoquince = 26;
const int pisodieciseis = 27;
const int pisodiecisiete = 14;
const int pisodieciocho = 13; 

const int led = 12;

/* Si el edificio tiene sotanos 
const int suno = 15;
const int sdos = 2;
const int mezanine = 4;
const int pisouno =  16; 
const int pisodos = 17;
const int pisotres = 5;
const int pisocuatro = 18;
const int pisocinco = 19;
const int pisoseis = 21;
const int pisosiete = 22;
const int pisoocho = 23;
const int pisonueve = 32;
const int pisodiez = 33;
const int pisoonce = 25;
const int pisodoce = 26;
const int pisotrece = 27;
const int pisocatorce = 14;
const int pisoquince = 13;
*/


//std::string rxValue; // Could also make this a global var to access it in loop()

// See the following for generating UUIDs:
// https://www.uuidgenerator.net/

#define SERVICE_UUID           "ffe0" // UART service UUID a5f81d42-f76e-11ea-adc1-0242ac120002
#define CHARACTERISTIC_UUID_RX "ffe1"
#define CHARACTERISTIC_UUID_TX "ffe2"

class MyServerCallbacks: public BLEServerCallbacks {
    void onConnect(BLEServer* pServer) {
      deviceConnected = true;
    };

    void onDisconnect(BLEServer* pServer) {
      deviceConnected = false;
    }
};
 
String marcar_piso(String piso){
   if (piso == "1") {
        Serial.println("Piso 1!");
        digitalWrite(pisouno, HIGH);
        digitalWrite(led, HIGH);
        delay(500);
        digitalWrite(pisouno, LOW); 
        digitalWrite(led, LOW);
        }
//        else if (rxValue.find("0") != -1) {
//        Serial.println("Cerrando puertas");
//        digitalWrite(cerrar, HIGH);
//        delay(500);
//        digitalWrite(cerrar, LOW); 
//        }
        else if (piso == "2") {
        Serial.println("Piso 2!");
        digitalWrite(pisodos, HIGH);
        digitalWrite(led, HIGH);
        delay(500);
        digitalWrite(pisodos, LOW); 
        digitalWrite(led, LOW);
        }
        else if (piso == "3") {
        Serial.println("Piso 3!");
        digitalWrite(pisotres, HIGH);
        digitalWrite(led, HIGH);
        delay(500);
        digitalWrite(pisotres, LOW);
        digitalWrite(led, LOW);
        }
        else if (piso == "4") {
        Serial.println("Piso 4!");
        digitalWrite(pisocuatro, HIGH);
        digitalWrite(led, HIGH);
        delay(500);
        digitalWrite(pisocuatro, LOW); 
        digitalWrite(led, LOW);
        }
        else if (piso == "5") {
        Serial.println("Piso 5!");
        digitalWrite(pisocinco, HIGH);
        digitalWrite(led, HIGH);
        delay(500);
        digitalWrite(pisocinco, LOW);
        digitalWrite(led, LOW); 
        }
        else if (piso == "6") {
        Serial.println("Piso 6!");
        digitalWrite(pisoseis, HIGH);
        digitalWrite(led, HIGH);
        delay(500);
        digitalWrite(pisoseis, LOW);
        digitalWrite(led, LOW);
        }
        else if (piso == "7") {
        Serial.println("Piso 7!");
        digitalWrite(pisosiete, HIGH);
        digitalWrite(led, HIGH);
        delay(500);
        digitalWrite(pisosiete, LOW); 
        digitalWrite(led, LOW);
        }
        else if (piso == "8") {
        Serial.println("Piso 8!");
        digitalWrite(pisoocho, HIGH);
        digitalWrite(led, HIGH);
        delay(500);
        digitalWrite(pisoocho, LOW); 
        digitalWrite(led, LOW);
        }
        else if (piso == "9") {
        Serial.println("Piso 9!");
        digitalWrite(pisonueve, HIGH);
        digitalWrite(led, HIGH);
        delay(500);
        digitalWrite(pisonueve, LOW);
        digitalWrite(led, LOW);
        }
        else if (piso == "A") {
        Serial.println("Piso 10!");
        digitalWrite(pisodiez, HIGH);
        digitalWrite(led, HIGH);
        delay(500);
        digitalWrite(pisodiez, LOW);
        digitalWrite(led, LOW); 
        }
        else if (piso == "B") {
        Serial.println("Piso 11!");
        digitalWrite(pisoonce, HIGH);
        digitalWrite(led, HIGH);
        delay(500);
        digitalWrite(pisoonce, LOW);
        digitalWrite(led, LOW); 
        }
        else if (piso == "C") {
        Serial.println("Piso 12!");
        digitalWrite(pisodoce, HIGH);
        digitalWrite(led, HIGH);
        delay(500);
        digitalWrite(pisodoce, LOW);
        digitalWrite(led, LOW);
        }
        else if (piso == "D") {
        Serial.println("Piso 13!");
        digitalWrite(pisotrece, HIGH);
        digitalWrite(led, HIGH);
        delay(500);
        digitalWrite(pisotrece, LOW);
        digitalWrite(led, LOW); 
        }
          else if (piso == "E") {
        Serial.println("Piso 14!");
        digitalWrite(pisocatorce, HIGH);
        digitalWrite(led, HIGH);
        delay(1500);
        digitalWrite(pisocatorce, LOW); 
        digitalWrite(led, LOW);
        }
        else if (piso == "F") {
        Serial.println("Piso 15!");
        digitalWrite(pisoquince, HIGH);
        digitalWrite(led, HIGH);
        delay(500);
        digitalWrite(pisoquince, LOW); 
        digitalWrite(led, LOW);
        }
        else if (piso == "G") {
        Serial.println("Piso 16!");
        digitalWrite(pisodieciseis, HIGH);
        digitalWrite(led, HIGH);
        delay(500);
        digitalWrite(pisodieciseis, LOW); 
        digitalWrite(led, LOW);
        }
        else if (piso == "H") {
        Serial.println("Piso 17!");
        digitalWrite(pisodiecisiete, HIGH);
        digitalWrite(led, HIGH);
        delay(500);
        digitalWrite(pisodiecisiete, LOW);
        digitalWrite(led, LOW); 
        }
        else if (piso == "I") {
        Serial.println("Piso 18!");
        digitalWrite(pisodieciocho, HIGH);
        digitalWrite(led, HIGH);
        delay(500);
        digitalWrite(pisodieciocho, LOW); 
        digitalWrite(led, LOW);
        }  
}

class MyCallbacks: public BLECharacteristicCallbacks {
    void onWrite(BLECharacteristic *pCharacteristic) {
      std::string rxValue = pCharacteristic->getValue();

      if (rxValue.length() > 0) {
        Serial.println("*********");
        Serial.print("Received Value: ");

        for (int i = 0; i < rxValue.length(); i++) {
          Serial.print(rxValue[i]);
        }
        Serial.println("---rxValues--");
        Serial.println(rxValue.length());
        Serial.println(rxValue[0]);
        Serial.println(rxValue[1]);
        Serial.println("--------------");
        String piso_esp = String(rxValue[0]);
        marcar_piso(piso_esp);
        Serial.println(piso_esp);
       Serial.println("*********");
      }
    }
};

// callback function that will be executed when data is received
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&myData, incomingData, sizeof(myData));
  Serial.print("Bytes received: ");
  Serial.println(len);
  Serial.print("Mensaje: ");
  Serial.println(myData.msj);
  marcar_piso(myData.msj);
}

void setup() {
  
  Serial.begin(115200);

  //pinMode(ponce, OUTPUT);
  // Init LED and turn off
/*  pinMode(suno, OUTPUT);
 digitalWrite(suno, LOW);
  pinMode(sdos, OUTPUT);
  digitalWrite(sdos, LOW);
  */
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
    Serial.print("ESP Board MAC Address:  ");
  Serial.println(WiFi.macAddress());
  pinMode(pisouno, OUTPUT);
  digitalWrite(pisouno, LOW);
  pinMode(pisodos, OUTPUT);
  digitalWrite(pisodos, LOW);
  pinMode(pisotres, OUTPUT);
  digitalWrite(pisotres, LOW);
  pinMode(pisocuatro, OUTPUT);
  digitalWrite(pisocuatro, LOW);
  pinMode(pisocinco, OUTPUT);
  digitalWrite(pisocinco, LOW);
  pinMode(pisoseis, OUTPUT);
  digitalWrite(pisoseis, LOW);
  pinMode(pisosiete, OUTPUT);
  digitalWrite(pisosiete, LOW);
  pinMode(pisoocho, OUTPUT);
  digitalWrite(pisoocho, LOW);
  pinMode(pisonueve, OUTPUT);
  digitalWrite(pisonueve, LOW);
  pinMode(pisodiez, OUTPUT);
  digitalWrite(pisodiez, LOW);
  pinMode(pisoonce, OUTPUT);
  digitalWrite(pisoonce, LOW);
  pinMode(pisodoce, OUTPUT);
  digitalWrite(pisodoce, LOW);
   pinMode(pisotrece, OUTPUT);
  digitalWrite(pisotrece, LOW);
  pinMode(pisocatorce, OUTPUT);
  digitalWrite(pisocatorce, LOW);
     pinMode(pisoquince, OUTPUT);
  digitalWrite(pisoquince, LOW);
  pinMode(pisodieciseis, OUTPUT);
  digitalWrite(pisodieciseis, LOW);
    pinMode(pisodiecisiete, OUTPUT);
  digitalWrite(pisodiecisiete, LOW);
  pinMode(pisodieciocho, OUTPUT);
  digitalWrite(pisodieciocho, LOW);



  // Create the BLE Device
  BLEDevice::init("AIRCALL SV"); // Give it a name

  // Create the BLE Server
  BLEServer *pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());

  // Create the BLE Service
  BLEService *pService = pServer->createService(SERVICE_UUID);

  // Create a BLE Characteristic
  pCharacteristic = pService->createCharacteristic(
                      CHARACTERISTIC_UUID_TX,
                      BLECharacteristic::PROPERTY_NOTIFY
                    );
                      
  pCharacteristic->addDescriptor(new BLE2902());

  BLECharacteristic *pCharacteristic = pService->createCharacteristic(
                                         CHARACTERISTIC_UUID_RX,
                                         BLECharacteristic::PROPERTY_WRITE
                                       );

  pCharacteristic->setCallbacks(new MyCallbacks());

  // Start the service
  pService->start();

  // Start advertising
  pServer->getAdvertising()->start();
  Serial.println("Waiting a client connection to notify...");
 
    // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  
  // Once ESPNow is successfully Init, we will register for recv CB to
  // get recv packer info
  esp_now_register_recv_cb(OnDataRecv);
}

void loop() {
  if (deviceConnected) {
    // Fabricate some arbitrary junk for now...
    txValue = 5; // This could be an actual sensor reading!

    // Let's convert the value to a char array:
    char txString[8]; // make sure this is big enuffz
    dtostrf(txValue, 1, 2, txString); // float_val, min_width, digits_after_decimal, char_buffer
    
//    pCharacteristic->setValue(&txValue, 1); // To send the integer value
//    pCharacteristic->setValue("Hello!"); // Sending a test message
    pCharacteristic->setValue(txString);
    
    pCharacteristic->notify(); // Send the value to the app!
    //Serial.print("*** Sent Value: ");
    //Serial.print(txString);
    //Serial.println(" ***");

    // You can add the rxValue checks down here instead
    // if you set "rxValue" as a global var at the top!
    // Note you will have to delete "std::string" declaration
    // of "rxValue" in the callback function.
//    if (rxValue.find("A") != -1) { 
//      Serial.println("Turning ON!");
//      digitalWrite(LED, HIGH);
//    }
//    else if (rxValue.find("B") != -1) {
//      Serial.println("Turning OFF!");
//      digitalWrite(LED, LOW);
//    }
  }
  delay(500);
}
