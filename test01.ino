#include <Servo.h>
Servo myservo1, myservo2, myservo3, myservo4;
int ang1, ang2, ang3, ang4;
int val1, val2, val3, val4;
int vrPin1, vrPin2, vrPin3, vrPin4;

void init(){
    val1 = 90;
    val2 = 90;
    val3 = 90;
    val4 = 90;
}

void setup(){
    Serial.begin(9600);
    myservo1.write(val1);
    myservo2.write(val2);
    myservo3.write(val3);
    myservo4.write(val4);
}

void loop(){
    init();

    myservo1.attach(6);
    myservo2.attach(7);
    myservo3.attach(5);
    myservo4.attach(9);
    
    ang1=analogRead(vrPin1);                                                                                                                                                                     
    ang2=analogRead(vrPin2);
    ang3=analogRead(vrPin3);
    ang4=analogRead(vrPin4);

    delay(10);

    // part1
    if((ang1>600)&&(val1<165)) {
        val1=val1+2;
    }
    if((ang1<400)&&(val1>44)) {
        val1=val1-2;
    }
    myservo1.write(val1);
    Serial.print("M1:") ;
    Serial .print(val1 ) ;
    
    if (ang2>600) && (val2<165)) {
        val2=val2+2;
    }
    if ((ang2<400) && (val2>30)) { 
        val2=val2-2;
    }
    myservo2.write(val2);
    Serial.print("  M2:") ;
    Serial .print(val2 ) ;
    
    // part2
    if ((ang3>600)&&(val3<165)) {
        val3=val3-2;
    }
    if ((ang3<400)&&(val3>20)) {
        val3=val3+2;
    }
    myservo3.write(val3);
    Serial.print("  M3:") ;
    Serial .print(val3 ) ;

    // part3
    if ((ang4>600) && (val4<145)) {
        val4=val4+2;
    }
    if ((ang4<400) && (val4>75)) {
        val4=val4-2;
    }
    myservo4.write(val4);
    Serial.print("  M4:") ;
    Serial .println(val4 ) ;
    
    delay(200);
}
