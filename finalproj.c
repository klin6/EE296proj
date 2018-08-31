int dist_pin = 0;

//save distance reading
int current_dist = 0;
int sensor_dist= 0;

//alarm = 1 if set off or 0 is no alarm is needed
//int alarm = 0;

void setup() {
 Serial.begin(9600);

}

void loop() {
 //read in the sensor distance
 sensor_dist = analogRead(dist_pin);
 
 //convert into cm
 current_dist=28250/(sensor_dist - 229.5);

 //check to see if there is an accurate reading
 //if there is a weird reading i.e negative/ large reading read again
 while(current_dist < 0 || current_dist> 500){
   sensor_dist = analogRead(dist_pin);
   //convert into cm
   current_dist=28250/(sensor_dist - 229.5);
 }
  
 //for debug, print the values on the monitor
 //Serial.print(current_dist);
 //Serial.println("cm");

   //check to see if the attacker is about 4 feet away
   //if yes then set alarm off
  if(current_dist < 130){
   //set alarm off
   Serial.write("alarm");
  }
  
/* 
 //if the alarm was triggered set off then turn alarm to 0
 if(alarm = 1){
  Serial.write("alarm");
  alarm = 0;
 }
*/

 //delay by half a second
 delay(500);
}
