// NEED TO USE VERSION 2.8.0 of IRReciever. Higher versions don't work

#define USE_NO_SEND_PWM

#include "IRremote.h"
#include "EG_IR_Projector.h"

const int receiver = 11;
const int sender = 9;

IRrecv irrecv(receiver);
decode_results results;

IRsend irsend(sender);

void printHex(uint32_t number)
{
    Serial.print("0x");
    Serial.print(number < 16 ? "0" : "");
    Serial.print(number, HEX);
    Serial.print(" ");
}

void translateIR()
{

    // decode type = 9 (NEC I think)
    switch (results.value)
    {
    case PROJECTOR_IR_POWER:
        Serial.println("POWER");
        break;
    case PROJECTOR_IR_MUTE:
        Serial.println("MUTE");
        break;
    case PROJECTOR_IR_SKIP_LEFT:
        Serial.println("SKIP LEFT");
        break;
    case PROJECTOR_IR_SKIP_RIGHT:
        Serial.println("SKIP RIGHT");
        break;
    case PROJECTOR_IR_FWD:
        Serial.println("FWD");
        break;
    case PROJECTOR_IR_RWD:
        Serial.println("RWD");
        break;
    case PROJECTOR_IR_PLAY_PAUSE:
        Serial.println("PLAY / PAUSE");
        break;
    case PROJECTOR_IR_VOL_DOWN:
        Serial.println("VOL DOWN");
        break;
    case PROJECTOR_IR_VOL_UP:
        Serial.println("VOL UP");
        break;
    case PROJECTOR_IR_FLIP:
        Serial.println("FLIP");
        break;
    case PROJECTOR_IR_SOURCE:
        Serial.println("SOURCE");
        break;
    case PROJECTOR_IR_ZOOM:
        Serial.println("ZOOM");
        break;
    case PROJECTOR_IR_MENU:
        Serial.println("MENU");
        break;
    case PROJECTOR_IR_EXIT:
        Serial.println("EXIT");
        break;
    case PROJECTOR_IR_DPAD_UP:
        Serial.println("DPAD UP");
        break;
    case PROJECTOR_IR_DPAD_DOWN:
        Serial.println("DPAD DOWN");
        break;
    case PROJECTOR_IR_DPAD_LEFT:
        Serial.println("DPAD LEFT");
        break;
    case PROJECTOR_IR_DPAD_RIGHT:
        Serial.println("DPAD RIGHT");
        break;
    case PROJECTOR_IR_DPAD_OK:
        Serial.println("DPAD OK");
        break;
    case PROJECTOR_IR_NUM_1:
        Serial.println("NUM 1");
        break;
    case PROJECTOR_IR_NUM_2:
        Serial.println("NUM 2");
        break;
    case PROJECTOR_IR_NUM_3:
        Serial.println("NUM 3");
        break;
    case PROJECTOR_IR_NUM_4:
        Serial.println("NUM 4");
        break;
    case PROJECTOR_IR_NUM_5:
        Serial.println("NUM 5");
        break;
    case PROJECTOR_IR_NUM_6:
        Serial.println("NUM 6");
        break;
    case PROJECTOR_IR_NUM_7:
        Serial.println("NUM 7");
        break;
    case PROJECTOR_IR_NUM_8:
        Serial.println("NUM 8");
        break;
    case PROJECTOR_IR_NUM_9:
        Serial.println("NUM 9");
        break;
    case PROJECTOR_IR_NUM_0:
        Serial.println("NUM 0");
        break;
    case PROJECTOR_IR_RECALL:
        Serial.println("RECALL");
        break;
    case PROJECTOR_IR_FAV_BACKSPACE:
        Serial.println("FAV / BACKSPACE");
        break;
    case PROJECTOR_IR_REPEAT_COMMAND:
        Serial.println("REPEAT");
        break;

    default:
        Serial.print("Other Button: ");
        printHex(results.value);
        Serial.println();
    }
}

void setup()
{
    Serial.begin(115200);
    Serial.println("IR Receiver Button Decode");
    irrecv.enableIRIn(); // Start the receiver

    irsend.enableIROut(PROJECTOR_SETTINGS_KHZ);

    irsend.sendNEC(PROJECTOR_IR_POWER, PROJECTOR_SETTINGS_NUM_BITS);
}

void loop()
{

    // have we received an IR signal?
    if (irrecv.decode(&results))
    {
        translateIR();
        irrecv.resume();
    }
}