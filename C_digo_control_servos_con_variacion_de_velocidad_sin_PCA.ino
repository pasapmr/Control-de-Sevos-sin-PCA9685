#include <ESP32Servo.h>
#include <BluetoothSerial.h>

BluetoothSerial SerialBT;
Servo servo1; // Servo de la base
Servo servo2; // Servo del brazo
Servo servo3; // Servo de la muñeca
Servo servo4; // Servo del antebrazo
Servo servo5; // Servo de giro de muñeca
Servo servo6; // Servo de la garra
Servo servo7; // Servo de la garra

int pinservo1 = 19;
int pinservo2 = 18;
int pinservo3 = 13;
int pinservo4 = 33;
int pinservo5 = 14;
int pinservo6 = 15;
int pinservo7 = 16;
int vel; // Variable para la velocidad de movimiento de los servos

int s1Act, s2Act, s3Act, s4Act, s5Act, s6Act, s7Act;        // Posición actual de los servos
int s1Ant, s2Ant, s3Ant, s4Ant, s5Ant, s6Ant, s7Ant;       // Posición anterior de los servos
int s1[50], s2[50], s3[50], s4[50], s5[50], s6[50], s7[50]; // Matrices para almacenar las posiciones de cada servo

String bt, btS1, btS2, btS3, btS4, btS5, btS6, btS7, v;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_BT_Servo"); // Nombre del dispositivo Bluetooth
  servo1.attach(pinservo1);
  servo2.attach(pinservo2);
  servo3.attach(pinservo3);
  servo4.attach(pinservo4);
  servo5.attach(pinservo5);
  servo6.attach(pinservo6);
  servo7.attach(pinservo7);
  delay(2000);

  s1Ant = 90;  // Inicialización de la base en posición central
  servo1.write(s1Ant);

  // Inicialización de los servos del brazo y la muñeca en posición central
  s2Ant = 90;
  servo2.write(s2Ant);
  
  s3Ant = 90;
  servo3.write(s3Ant);
  
  // Inicialización del servo del antebrazo en posición central
  s4Ant = 90;
  servo4.write(s4Ant);
  
  // Inicialización del servo de giro de muñeca en posición central
  s5Ant = 90;
  servo5.write(s5Ant);
  
  // Inicialización de los servos de la garra en posición central
  s6Ant = 90;
  servo6.write(s6Ant);
  
  s7Ant = 90;
  servo7.write(s7Ant);
}

void loop() {
  if (SerialBT.available() > 0) {
    bt = SerialBT.readString();               // Leer cadena Bluetooth
    if (bt.startsWith("vel")) {
      v = bt.substring(3, bt.length());
      vel = v.toInt();                        // Convertir velocidad a entero
    }

    // Control del servo 1 - Base
    if (bt.startsWith("s1")) {
      btS1 = bt.substring(2, bt.length());
      s1Act = btS1.toInt();
      // Movimiento del servo con un barrido
      if (s1Ant > s1Act) {
        for (int j = s1Ant; j >= s1Act; j--) {
          servo1.write(j);
          delay(vel);
        }
      } else {
        for (int j = s1Ant; j <= s1Act; j++) {
          servo1.write(j);
          delay(vel);
        }
      }
      s1Ant = s1Act; // Actualizar posición anterior
    }

    // Control del servo 2 - Brazo
    if (bt.startsWith("s2")) {
      btS2 = bt.substring(2, bt.length());
      s2Act = btS2.toInt();
      // Movimiento del servo con un barrido
      if (s2Ant > s2Act) {
        for (int j = s2Ant; j >= s2Act; j--) {
          servo2.write(j);
          delay(vel);
        }
      } else {
        for (int j = s2Ant; j <= s2Act; j++) {
          servo2.write(j);
          delay(vel);
        }
      }
      s2Ant = s2Act; // Actualizar posición anterior
    }

    // Control del servo 3 - Muñeca
    if (bt.startsWith("s3")) {
      btS3 = bt.substring(2, bt.length());
      s3Act = btS3.toInt();
      // Movimiento del servo con un barrido
      if (s3Ant > s3Act) {
        for (int j = s3Ant; j >= s3Act; j--) {
          servo3.write(j);
          delay(vel);
        }
      } else {
        for (int j = s3Ant; j <= s3Act; j++) {
          servo3.write(j);
          delay(vel);
        }
      }
      s3Ant = s3Act; // Actualizar posición anterior
    }

    // Control del servo 4 - Antebrazo
    if (bt.startsWith("s4")) {
      btS4 = bt.substring(2, bt.length());
      s4Act = btS4.toInt();
      // Movimiento del servo con un barrido
      if (s4Ant > s4Act) {
        for (int j = s4Ant; j >= s4Act; j--) {
          servo4.write(j);
          delay(vel);
        }
      } else {
        for (int j = s4Ant; j <= s4Act; j++) {
          servo4.write(j);
          delay(vel);
        }
      }
      s4Ant = s4Act; // Actualizar posición anterior
    }

    // Control del servo 5 - Giro de muñeca
    if (bt.startsWith("s5")) {
      btS5 = bt.substring(2, bt.length());
      s5Act = btS5.toInt();
      // Movimiento del servo con un barrido
      if (s5Ant > s5Act) {
        for (int j = s5Ant; j >= s5Act; j--) {
          servo5.write(j);
          delay(vel);
        }
      } else {
        for (int j = s5Ant; j <= s5Act; j++) {
          servo5.write(j);
          delay(vel);
        }
      }
      s5Ant = s5Act; // Actualizar posición anterior
    }

    // Control de los servos 6 y 7 - Garra
    if (bt.startsWith("s6")) {
      btS6 = bt.substring(2, bt.length());
      s6Act = btS6.toInt();
      // Movimiento de los servos con un barrido para ambos
      if (s6Ant > s6Act) {
        for (int j = s6Ant; j >= s6Act; j--) {
          servo6.write(j);
          servo7.write(j);
          delay(vel);
        }
      } else {
        for (int j = s6Ant; j <= s6Act; j++) {
          servo6.write(j);
          servo7.write(j);
          delay(vel);
        }
      }
      s6Ant = s6Act; // Actualizar posición anterior
      s7Ant = s6Act; // Ambos servos de la garra se mueven juntos
    }
  }
}
