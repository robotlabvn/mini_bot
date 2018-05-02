
/* -----------------------------------------------------------------------------
 * Example .ino file for arduino communication with ROS for the
 * L298N motor controller board
 * Command signals expected to be between -255 and +255 with motors stopping at 0
 *----------------------------------------------------------------------------*/

#include <ros.h>
#include <geometry_msgs/Twist.h>

//#define ENA 5
//#define ENB 11
//#define IN1 6
//#define IN2 7
//#define IN3 8
//#define IN4 9

#define PWM_R 10
#define DIR_R 12
#define PWM_L 11
#define DIR_L 13

float L = 0.18; //distance between wheels

ros::NodeHandle  nh;

void cmdVelCB( const geometry_msgs::Twist& twist)
{
  int gain_L = 700;
  int gain_R = 700;
  float left_wheel_data = gain_L*(twist.linear.x - twist.angular.z*L);
  float right_wheel_data = gain_R*(twist.linear.x + twist.angular.z*L);
  
  if (left_wheel_data >= 0)
  {
    analogWrite(PWM_L, abs(left_wheel_data));
    digitalWrite(DIR_L, HIGH);
    
  }
  else
  {
    analogWrite(PWM_L, abs(left_wheel_data));
    digitalWrite(DIR_L, LOW);
  }
  if (right_wheel_data >= 0)
  {
    analogWrite(PWM_R, abs(right_wheel_data));
    digitalWrite(DIR_R, HIGH);
    
   
  }
  else
  {
    analogWrite(PWM_R, abs(right_wheel_data));
    digitalWrite(DIR_R, LOW);
  }
}

ros::Subscriber<geometry_msgs::Twist> subCmdVel("/cmd_vel", cmdVelCB);
  
void setup()
{
pinMode(DIR_R, OUTPUT);
pinMode(DIR_L, OUTPUT);
    
  nh.initNode();
  nh.subscribe(subCmdVel);
    
 }
  
 void loop()
 {
  nh.spinOnce();
 }
