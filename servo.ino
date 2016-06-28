/* Kütüphaneler */
#include <Servo.h>
Servo servoMotor;  /* Servo motor nesnesi yaratildi */

/* Global Değişkenler */
#define servoMotorPin     3;        /* Servo motorumuzun bağlı olduğu PWM pini */
int i = 0;

/* Fonksiyon Prototipleri */
void tarama(int aci, int gecikme);  /* Açı 0-180 derece arasında olmalıdır. Gecikme milisaniye cinsinden girilmelidir */

void setup(){
  servoMotor.attach(servoMotorPin); /* Servo motorun bağlı olduğu pini programa bildiriyoruz. */
  Serial.begin(9600);               /* Serial monitör Başlangıcı */
}
 
void loop(){
  
  tarama(180, 5);
  
}

/* Servo Motor ile Açı Tarama Fonksiyonu */
void tarama(int aci, int gecikme){
  for(i = 0; i < aci; i++){                            
      servoMotor.write(i);  
      delay(gecikme);    
  }
  for(i = aci; i > 0; i--){                          
      servoMotor.write(i);      
      delay(gecikme);  
  }
  Serial.println("Tarama Bitti.");    /* Serial monitörde taramanın tamamlandığını gösterelim. */
}

