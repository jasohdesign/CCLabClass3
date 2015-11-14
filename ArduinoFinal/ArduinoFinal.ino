#include <SoftwareSerial.h>
#include <MP3.h>

/** define mp3 class */
#define REDPIN 5
#define GREENPIN 6
#define BLUEPIN 3
#define FADESPEED 2     // make this higher to slow down

int fsrAnalogPin = 0; // FSR is connected to analog 0
int fsrReading;
MP3 mp3;
int sound;
void setup()
{
  Serial.begin(9600);
  /** begin function */
  mp3.begin(MP3_SOFTWARE_SERIAL);    // select software serial
  //  mp3.begin();                       // select hardware serial(or mp3.begin(MP3_HARDWARE_SERIAL);)

  /** set volum to the MAX */
  //  mp3.volume(10);

  /** set MP3 Shield CYCLE mode */
  mp3.set_mode(MP3::CYCLE);

  /** play music in sd, '0001' for first music */
  mp3.play_sd(0x0001);

  /** play music in USB-disk */
  //mp3.play_usb_disk(0x0001);

  /** play music in SPI FLASH */
  //mp3.play_spi_flash(0x0001);
  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);
}

void loop() {
  fsrReading = analogRead(fsrAnalogPin);
  //  Serial.println(fsrReading);
  sound = map(fsrReading, 0, 1023, 6, 31); //sound ranges from 0-31. Started from 6 so can initially faintly hear sound
  mp3.volume(sound);//when force sensor is pressed, sound gets louder
  Serial.println(fsrReading);
  int r, g, b;
  if (fsrReading < 900) {
    r = 0;
    g = 0;
    b = 0;
    analogWrite(REDPIN, r);
    analogWrite(GREENPIN, g);
    analogWrite(BLUEPIN, b);
  }
  else{
   b = 255;
   analogWrite(GREENPIN, g);
   delay(FADESPEED);
    }//when force sensor is pressed turn the led light to green
  
}
