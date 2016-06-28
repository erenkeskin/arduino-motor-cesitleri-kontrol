/* Kütüphaneler */
#include <Servo.h>
Servo servoMotor;  /* Servo motor nesnesi yaratildi */

/* Global Değişkenler */
#define servoMotorPin     9        /* Servo motorumuzun bağlı olduğu PWM pini */
#define PotPin            A0       /* Potansiyometrenin bağlı olduğu Analog Pin'imiz */
int PotDeger;                      /* Potansiyometreden ölçülen değer değişkeni */


void setup(){
  
  servoMotor.attach(servoMotorPin); /* Servo motorun bağlı olduğu pini programa bildiriyoruz. */
  Serial.begin(9600);               /* Serial monitör Başlangıcı */
  
}
 
void loop(){
  
  PotDeger = analogRead(PotPin);                /* Potansiyometreden gelen değeri ölçüp, değişkene atayalım. */
  /* 
    Servo motorlar 0-180 açı aralığı taramaktadır. 
    Potansiyometreler ise 0-1023 değer aralığında değerler alır.
    Servo motoru potansiyometreden ölçülen değer kadar değiştirmemiz için;
    map() fonksiyonu ile 0-1023 arası değerleri 0-180 arasına atamamız gerekiyor.
    Bu atamayı yaptıktan sonra servo motorumuzu potansiyometre değerimiz kadar döndürebiliriz.
  */
  PotDeger = map(PotDeger, 0, 1023, 0, 179);    /* Atamamızı gerçekleştiriyoruz. */
  servoMotor.write(PotDeger);
  
}


