//update kondisi
void update (){
  if (back == LOW){
  delay(200);
  if(kondisi==0){
    //pas
  }
  else{
    kondisi -=1;
    
  }
}
if (next == LOW){
  delay(200);
    if (kondisi==3){
      //pass
    }
    else{
      kondisi +=1;
      
    }
}
}

//baca sensor kekeruhan
void baca_kekeruhan(){
  nilai = (kalibrasi-analogRead(sensor_kekeruhan))*1.1;
  lcd.setCursor(0,1);
//lcd.print(kondisi);
//lcd.print("                   ");
lcd.print("Turbidity="+String(nilai)+" NTU");

delay(300);
   //Serial.println("Turbidity="+String(nilai)+" NTU");
}

// buka tutup kran
//buka kran atas
 void buka_kran_atas(){
  for (pos_atas = 0; pos_atas <= 60; pos_atas += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo_atas.write(pos_atas);              // tell servo to go to position in variable 'pos'
    delay(15);
    lcd.print("Top Valve is on ");
  }
 }

//tutup kran atas
 void tutup_kran_atas(){
  for (pos_atas = 60; pos_atas >= 0; pos_atas -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo_atas.write(pos_atas);              // tell servo to go to position in variable 'pos'
    delay(15);
    lcd.print("Top valve is off");
     }
 }
// buka kran bawah
 void buka_kran_bawah(){
  for (pos_bawah = 0; pos_bawah <= 60; pos_bawah += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo_bawah.write(pos_atas);              // tell servo to go to position in variable 'pos'
    delay(15);
    lcd.print("Bott valve's on ");
  }
 }

//tutup kran bawah
 void tutup_kran_bawah(){
  for (pos_bawah = 60; pos_bawah >= 0; pos_bawah -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo_bawah.write(pos_bawah);              // tell servo to go to position in variable 'pos'
    delay(15);
    lcd.print("Bott valve's off");
     }
 }

//proses elektrolisis
void elektrolisis(){
  digitalWrite(relay.HIGH);
  //milis
  lcd.print("Electrolisis's on");
}
 
void jarak_atas(){
  pinMode(pingPin1, OUTPUT);
  digitalWrite(pingPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin1, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin1, LOW);
  pinMode(pingPin1, INPUT);
  delayMicroseconds(50);
  jarakRaw = 0;
  for (indexPing = 0; indexPing <= 200; indexPing++)
  {
    if (digitalRead(pingPin1)) jarakRaw++;
    delayMicroseconds(57);
  }
  jarak1 = ((1 - alpha) * jarak) + (alpha * jarakRaw);
}

void jarak_bawah()
{
  pinMode(pingPin2, OUTPUT);
  digitalWrite(pingPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin2, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin2, LOW);
  pinMode(pingPin2, INPUT);
  delayMicroseconds(50);
  jarakRaw = 0;
  for (indexPing = 0; indexPing <= 200; indexPing++)
  {
    if (digitalRead(pingPin2)) jarakRaw++;
    delayMicroseconds(57);
  }
  jarak2 = ((1 - alpha) * jarak) + (alpha * jarakRaw);
}


//update buat lcd
void cek (){
  if (back == LOW){
  delay(200);
  if(kondisi==0){
    //pas
  }
  else{
    kondisi -=1;
    
  }
}
if (next == LOW){
  delay(200);
    if (kondisi==3){
      //pass
    }
    else{
      kondisi +=1;
      
    }
}
}
