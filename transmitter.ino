int button1 = 11;  //testADR
int button2 = 10;  //testADR
int button3 = 12;  //testADR


#define DEBUG

const int UNIT_LENGTH = 100;
const int DIT_LENGTH = UNIT_LENGTH * 1;
const int DAH_LENGTH = UNIT_LENGTH * 3;
const int ELEMENT_GAP = UNIT_LENGTH * 1;
const int SHORT_GAP = UNIT_LENGTH * 2;
const int MEDIUM_GAP = UNIT_LENGTH * 4;

const char* codeset[] = {
  /* ! */ "-.-.--",
  /* " */ ".-..-.",
  /* # */ NULL,
  /* $ */ "...-..-",
  /* % */ NULL,
  /* & */ ".-...",
  /* ' */ ".----.",
  /* ( */ "-.--.",
  /* ) */ "-.--.-",
  /* * */ NULL,
  /* + */ ".-.-.",
  /* , */ "--..--",
  /* - */ "-....-",
  /* . */ ".-.-.-",
  /* / */ "-..-.",
  /* 0 */ "-----",
  /* 1 */ ".----",
  /* 2 */ "..---",
  /* 3 */ "...--",
  /* 4 */ "....-",
  /* 5 */ ".....",
  /* 6 */ "-....",
  /* 7 */ "--...",
  /* 8 */ "---..",
  /* 9 */ "----.",
  /* : */ "---...",
  /* ; */ "-.-.-.",
  /* < */ NULL,
  /* = */ "-...-",
  /* > */ NULL,
  /* ? */ "..--..",
  /* @ */ ".--.-.",
  /* A */ ".-",
  /* B */ "-...",
  /* C */ "-.-.",
  /* D */ "-..",
  /* E */ ".",
  /* F */ "..-.",
  /* G */ "--.",
  /* H */ "....",
  /* I */ "..",
  /* J */ ".---",
  /* K */ "-.-",
  /* L */ ".-..",
  /* M */ "--",
  /* N */ "-.",
  /* O */ "---",
  /* P */ ".--.",
  /* Q */ "--.-",
  /* R */ ".-.",
  /* S */ "...",
  /* T */ "-",
  /* U */ "..-",
  /* V */ "...-",
  /* W */ ".--",
  /* X */ "-..-",
  /* Y */ "-.--",
  /* Z */ "--..",
  /* [ */ NULL,
  /* \ */ NULL,
  /* ] */ NULL,
  /* ^ */ NULL,
  /* _ */ "..--.-"
 };

const char* getCode(char c) {
  // To uppercase if needed
  if ('a' <= c && c <= 'z') {
    c = c - ('a' - 'A');
  }

  if ('!' <= c && c <= '_') {
    return codeset[c - '!'];
  }

  return NULL;
}

void dit()
{
#ifdef DEBUG
  Serial.print(".");
#endif
  digitalWrite(7, HIGH);
  delay(DIT_LENGTH);
  digitalWrite(7, LOW);
  delay(ELEMENT_GAP);
}

void dah()
{
#ifdef DEBUG
  Serial.print("-");
#endif
  digitalWrite(7, HIGH);
  delay(DAH_LENGTH);
  digitalWrite(7, LOW);
  delay(ELEMENT_GAP);
}

void letter()
{
#ifdef DEBUG
  Serial.print(" ");
#endif
  delay(SHORT_GAP);
}

void space()
{
#ifdef DEBUG
  Serial.println();
#endif
  delay(MEDIUM_GAP);
}



void play(const char * input) {
  int inputLength = strlen(input);

  for (int i = 0; i < inputLength; i++) {
    char c = input[i];

    if (c == ' ') {
      space();
    }
    else {
      const char* code = getCode(c);
      
      if (code == NULL) {
        continue;
      }

      int codeLength = strlen(code);
  
      for (int j = 0; j < codeLength; j++) {
        if (code[j] == '.') {
          dit();  
        }
        else if (code[j] == '-') {
          dah();
        }
      }
      
      letter();  
    }
  }
}

const char* text = "HELLO";
const char* text2 = "..TEST2.";
const char* text3 = "/MORSE CODE.";

void setup() {
  pinMode(7, OUTPUT);
  pinMode(button1, INPUT_PULLUP); //testADR
  pinMode(button2, INPUT_PULLUP); //testADR
  pinMode(button3, INPUT_PULLUP); //testADR
    
  Serial.begin(19200);
  
}


// the loop function runs over and over again forever
void loop() {
  if (digitalRead(button1) == LOW) {
  play(text);
}
if (digitalRead(button2) == LOW) {
  play(text);
  delay(200);
  play(text2);
}
if (digitalRead(button3) == LOW) {
  play(text);
  delay(200);
  play(text3);
}
 // play(text);
}
