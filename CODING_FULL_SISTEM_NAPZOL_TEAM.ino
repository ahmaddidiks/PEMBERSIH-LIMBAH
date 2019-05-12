//INI CODINGAN FULL SISTEM NAPZOL TEAM
/*
pin
2  relay
3  tombol1  
4  tombol2
5  sensor jarak 1
6  sensor jarak 2
7  servo 1
8  servo 2
9  servo 3  //INI NGGAK JADI ADA
A0 sensor kekeruhan
*/

//library
#include <Servo.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 16, 2); 
#include <Wire.h>  // Comes with Arduino IDE


//pendefinisian
const int sensor_kekeruhan =      A0;
const int  relay   =               2;
const int tombol1             = 4;
const int tombol2              =  3;
Servo servo_atas;
Servo servo_bawah;
//char proses[] = "Sistem Stars";

//Tipe data
//sensor kekeruhan
int kalibrasi = 738;
float baca;
float nilai;

//waktu
//unsigned time;
//int menit=time/6000;

//sensor jarak
int
pingPin1 = 5,
indexPing
;
float
alpha = 0.95,
jarakRaw,
jarak
;

int
pingPin2 = 6;
float
jarak1,jarak2
;

//servo
int pos_atas;
int pos_bawah;

//tombol
int kondisi;
int back;
int next;

//volume
int volume1,volume2;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
lcd.begin(16, 2);
pinMode(sensor_kekeruhan,INPUT);
pinMode (tombol1, INPUT_PULLUP);
pinMode (tombol2, INPUT_PULLUP);
pinMode (relay, OUTPUT);
servo_atas.attach(7);
servo_atas.write(90);
servo_bawah.attach(8);
servo_bawah.write(90);
digitalWrite(relay,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
jarak_atas();
jarak_bawah();

back= digitalRead(tombol1);
next= digitalRead(tombol2);

volume1 = 15*10*jarak1;
volume2 = 15*10*jarak2;

if (jarak1 > 3 & jarak2 > 3 & pos_atas == 0 & pos_bawah == 0 & relay==LOW){
    void buka_kran_atas();
    char proses[]="top valve is on";
}
if (jarak1 <= 3 & jarak2 > 3 & pos_atas == 60 & pos_bawah == 0 & relay==LOW){
    //matiin kran atas
     void tutup_kran_atas();
     char proses[]="turning off top valve";
  }


//proses kedua elektrolisis
if (jarak1 <= 3 & jarak2 > 3 & pos_atas == 0 & pos_bawah == 0){
   //proses elketrolisisi mulai relay on
   digitalWrite(relay, HIGH);
    //milis 1 jam
    char    proses[]="electrolisis process";
}

//proses kedua air mengalir ke kaca bawah dari kaca atas setelah di eletrolisis selama 10 menit. 
if (jarak1 <= 3 & jarak2 > 3 & pos_atas == 0 & pos_bawah == 0 & relay==LOW){
  void buka_kran_bawah();
  char proses[]="buttom valve is on";
}
if (jarak1 >= 9 & jarak2 <= 3 & pos_atas == 0 & pos_bawah == 60 & relay==LOW){
    void tutup_kran_bawah();
    char proses[]= "turning off top valve";
  }
  
cek();

//print LCD

if (kondisi == 1){
  lcd.print("kondisi 1");
  }

if (kondisi == 2){
  lcd.print("kondisi 2");
  }

else{
  lcd.print("kondisi 0");
  }
baca_kekeruhan();

Serial.print("jarakak1 =");Serial.print(jarak1);
Serial.print("jarakak2 =");Serial.print(jarak2);

}
