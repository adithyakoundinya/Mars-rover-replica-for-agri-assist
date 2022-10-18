/*This code is to test the movement of wheels in the forward and backward direction*/
int in1 = 2;
int in2 = 3;
int enable1 = 5;  // pin with ~ symbol

int channel_2 = 6;  // pin with ~ symbol

int in3 = 7;
int in4 = 8;
int enable2 = 9;  // pin with ~ symbol

/*int in5 = 10;
  int in6 = 11;
  int enable3 = 12;  // pin with ~ symbol

  int in7 = 13;
  int in8 = 14;
  int enable4 = 15;  // pin with ~ symbol4

  int in9 = 16;
  int in10 = 17;
  int enable5 = 18;  // pin with ~ symbol

  int in11 = 19;
  int in12 = 20;
  int enable6 = 21;  // pin with ~ symbol
*/


void setup()
{
  pinMode(channel_2, INPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enable1, OUTPUT);

  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enable2, OUTPUT);

  /* pinMode(in5, OUTPUT);
    pinMode(in6, OUTPUT);
    pinMode(enable3, OUTPUT);

    pinMode(in7, OUTPUT);
    pinMode(in8, OUTPUT);
    pinMode(enable4, OUTPUT);

    pinMode(in9, OUTPUT);
    pinMode(in10, OUTPUT);
    pinMode(enable5, OUTPUT);

    pinMode(in11, OUTPUT);
    pinMode(in12, OUTPUT);
    pinMode(enable6, OUTPUT);
    Serial.begin(9600);
  */
}

void loop() {

  int pwm = 0;
  int value = pulseIn(channel_2, HIGH, 25000);

  if (value == 0)
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    analogWrite(enable1, 0);

    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    analogWrite(enable2, 0);
    /*
          digitalWrite(in5, LOW);
          digitalWrite(in6, LOW);
          analogWrite(enable3, 0);

          digitalWrite(in7, LOW);
          digitalWrite(in8, LOW);
          analogWrite(enable4, 0);

          digitalWrite(in9, LOW);
          digitalWrite(in10, LOW);
          analogWrite(enable5, 0);

          digitalWrite(in11, LOW);
          digitalWrite(in12, LOW);
          analogWrite(enable6, 0);
    */
  }

  else if (value > 1530)
  {
    pwm = map(value, 1530, 2000, 0, 255);

    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(enable1, pwm);

    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enable2, pwm);
    /*
          digitalWrite(in5, LOW);
          digitalWrite(in6, HIGH);
          analogWrite(enable3, pwm);

          digitalWrite(in7, LOW);
          digitalWrite(in8, HIGH);
          analogWrite(enable4, pwm);

          digitalWrite(in9, LOW);
          digitalWrite(in10, HIGH);
          analogWrite(enable5, pwm);

          digitalWrite(in11, LOW);
          digitalWrite(in12, HIGH);
          analogWrite(enable6, pwm);
    */
  }

  else if (value < 1460)
  {
    pwm = map(value, 1460, 1000, 0, 255);

    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(enable1, pwm);

    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enable2, pwm);
    /*
         digitalWrite(in5, HIGH);
         digitalWrite(in6, LOW);
         analogWrite(enable3, pwm);

         digitalWrite(in7, HIGH);
         digitalWrite(in8, LOW);
         analogWrite(enable4, pwm);

         digitalWrite(in9, HIGH);
         digitalWrite(in10, LOW);
         analogWrite(enable5, pwm);

         digitalWrite(in11, HIGH);
         digitalWrite(in12, LOW);
         analogWrite(enable6, pwm);
    */

  }

  else
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    analogWrite(enable1, 0);

    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    analogWrite(enable2, 0);
    /*
          digitalWrite(in5, LOW);
          digitalWrite(in6, LOW);
          analogWrite(enable3, 0);

          digitalWrite(in7, LOW);
          digitalWrite(in8, LOW);
          analogWrite(enable4, 0);

          digitalWrite(in9, LOW);
          digitalWrite(in10, LOW);
          analogWrite(enable5, 0);

          digitalWrite(in11, LOW);
          digitalWrite(in12, LOW);
          analogWrite(enable6, 0);
    */

  }

  delay(10);
}
