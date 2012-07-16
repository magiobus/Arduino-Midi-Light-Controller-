
//USEs 5 LEDS 
//this works with velocity now 
//led1 = C3 , led2 = D3 , led3 = E3, led4 = F3, led5 = G3
const int boardled = 6; 
const int led1 = 16;
const int led2 = 15;
const int led3 = 14;
const int led4 = 13;
const int led5 = 12;


void setup() {
  Serial.begin(57600);
  Serial.println("MIDI Input Test");

  pinMode(boardled,OUTPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT); 
  pinMode(led5,OUTPUT);
}



void loop() {
  int type, note, velocity, channel, d1, d2;
  if (usbMIDI.read()) {      // Is there a MIDI message incoming ?
    digitalWrite(boardled,HIGH);
    byte type = usbMIDI.getType();
    switch (type) {
    case NoteOn:
      note = usbMIDI.getData1();
      velocity = usbMIDI.getData2();
      channel = usbMIDI.getChannel();
      if (velocity > 0) {

        //leds ON code
        if (note == 60) {
          analogWrite(led1,velocity);

        }

        if (note == 62) {
          analogWrite(led2,velocity);
        }

        if (note == 64) {
          analogWrite(led3,velocity);
        }

        if (note == 65) {
          digitalWrite(led4,HIGH);
        }

        if (note == 67) {
          digitalWrite(led5,HIGH);
        }
        Serial.println(String("Note On:  ch=") + channel + ", note=" + note + ", velocity=" + velocity);
      } 
      else {
        Serial.println(String("Note Off: ch=") + channel + ", note=" + note);
      }
      break;
    case NoteOff:
      note = usbMIDI.getData1();
      velocity = usbMIDI.getData2();
      channel = usbMIDI.getChannel();

      //leds ON code
      if (note == 60) {
        digitalWrite(led1,LOW);
      }

      if (note == 62) {
        digitalWrite(led2,LOW);
      }

      if (note == 64) {
        digitalWrite(led3,LOW);
      }

      if (note == 65) {
        digitalWrite(led4,LOW);
      }

      if (note == 67) {
        digitalWrite(led5,LOW);
      }        






      Serial.println(String("Note Off: ch=") + channel + ", note=" + note + ", velocity=" + velocity);
      break;
    default:
      d1 = usbMIDI.getData1();
      d2 = usbMIDI.getData2();
      Serial.println(String("Message, type=") + type + ", data = " + d1 + " " + d2);
    }



  }
}

