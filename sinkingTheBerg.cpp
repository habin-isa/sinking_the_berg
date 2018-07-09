
const int LINEARPIN_BUTTON = 6;        //Linear Actuator on Digital Pin 6
const int LINEARPIN_KNOB = 9;          //Linear Actuator on Digital Pin 9
const int LINEARPIN_SLIDER = 10;       //Linear Actuator on Digital Pin 10
const int LINEARPIN_JOYSTICK = 11;     //Linear Actuator on Digital Pin 11

const int KNOB_PIN = 0;
const int JOYSTICK_PIN = 1;
const int SLIDER_PIN = 2;


const int BUTTON1_PIN = 2;     //Button 1 on Digital Pin 2
const int BUTTON2_PIN = 4;     //Button 2 on Digital Pin 4
const int BUTTON3_PIN = 7;     //Button 3 on Digital Pin 7


const int DEADBAND_LOW = 482;
const int DEADBAND_HIGH = 542;


const int LINEAR_MIN = 1050;
const int LINEAR_MAX = 2000;


int button1State = 0;
int button2State = 0;
int button3State = 0;


void setup()
{

  linearKnob.attach(LINEARPIN_KNOB);
  linearSlider.attach(LINEARPIN_SLIDER);
  linearButton.attach(LINEARPIN_BUTTON);
  linearJoystick.attach(LINEARPIN_JOYSTICK);




  linearKnob.writeMicroseconds(linearValue_Knob);
  linearSlider.writeMicroseconds(linearValue_Slider);
  linearButton.writeMicroseconds(linearValue_Button);
  linearJoystick.writeMicroseconds(linearValue_Joystick);
}

void loop()
{


  button1State = digitalRead(BUTTON1_PIN);
  if (button1State == HIGH) {
    linearValue_Button = 1300;
  }

  button2State = digitalRead(BUTTON2_PIN);
  if (button2State == HIGH) {
    linearValue_Button = 1500;
  }

  button3State = digitalRead(BUTTON3_PIN);
  if (button3State == HIGH) {
    linearValue_Button = 1700;
  }


  knobValue = analogRead(KNOB_PIN);
  sliderValue = analogRead(SLIDER_PIN);

  linearValue_Knob = map(knobValue, 0, 1023, LINEAR_MAX, LINEAR_MIN);
  linearValue_Slider = map(sliderValue, 0, 1023, LINEAR_MAX, LINEAR_MIN);


  joystickValue = analogRead(JOYSTICK_PIN);


   if(joystickValue > DEADBAND_HIGH || joystickValue < DEADBAND_LOW)
   {
     valueMapped = map(joystickValue, 0, 1023, speed, -speed);
     linearValue_Joystick = linearValue_Joystick + valueMapped;

     linearValue_Joystick = constrain(linearValue_Joystick, LINEAR_MIN, LINEAR_MAX);  //
   }


  linearKnob.writeMicroseconds(linearValue_Knob);
  linearSlider.writeMicroseconds(linearValue_Slider);
  linearButton.writeMicroseconds(linearValue_Button);
  linearJoystick.writeMicroseconds(linearValue_Joystick);
  delay(10);
}
