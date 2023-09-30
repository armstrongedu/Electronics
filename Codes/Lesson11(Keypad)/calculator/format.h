#ifndef _STACKARRAY_H
#define _STACKARRAY_H

// include Arduino basic header.


// the definition of the stack class.
template<typename T>
class StackArray {
  public:
    // init the stack (constructor).
    StackArray ();

    // clear the stack (destructor).
    ~StackArray ();

    // push an item to the stack.
    void push (const T i);

    // pop an item from the stack.
    T pop ();

    // unshift an item to the stack.
    void unshift (const T i);

    // get an item from the stack.
    T peek () const;

    // check if the stack is empty.
    bool isEmpty () const;

    // get the number of items in the stack.
    int count () const;

    // check if the stack is full.
    bool isFull () const;

    // set the printer of the stack.
    void setPrinter (Print & p);

  private:
    // resize the size of the stack.
    void resize (const int s);

    // exit report method in case of error.
    void exit (const char * m) const;

    // led blinking method in case of error.
    void blink () const;

    // the initial size of the stack.
    static const int initialSize = 2;

    // the pin number of the on-board led.
    static const int ledPin = 13;

    Print * printer; // the printer of the stack.
    T * contents;    // the array of the stack.
    int size;        // the size of the stack.
    int top;         // the top index of the stack.
};

// init the stack (constructor).
template<typename T>
StackArray<T>::StackArray () {
  size = 0;       // set the size of stack to zero.
  top = 0;        // set the initial top index of the stack.
  printer = NULL; // set the printer of stack to point nowhere.

  // allocate enough memory for the array.
  contents = (T *) malloc (sizeof (T) * initialSize);

  // if there is a memory allocation error.
  if (contents == NULL)
    exit ("STACK: insufficient memory to initialize stack.");

  // set the initial size of the stack.
  size = initialSize;
}

// clear the stack (destructor).
template<typename T>
StackArray<T>::~StackArray () {
  free (contents); // deallocate the array of the stack.

  contents = NULL; // set stack's array pointer to nowhere.
  printer = NULL;  // set the printer of stack to point nowhere.
  size = 0;        // set the size of stack to zero.
  top = 0;         // set the initial top index of the stack.
}

// resize the size of the stack.
template<typename T>
void StackArray<T>::resize (const int s) {
  // defensive issue.
  if (s <= 0)
    exit ("STACK: error due to undesirable size for stack size.");

  // reallocate enough memory for the array.
  contents = (T *) realloc (contents, sizeof (T) * s);

  // if there is a memory allocation error.
  if (contents == NULL)
    exit ("STACK: insufficient memory to resize stack.");

  // set the new size of the stack.
  size = s;
}


template<typename T>
void StackArray<T>::push (const T i) {
  // check if the stack is full.
  if (isFull ())
    // double size of array.
    resize (size * 2);

  // store the item to the array.
  contents[top++] = i;
}

// pop an item from the stack.
template<typename T>
T StackArray<T>::pop () {
  // check if the stack is empty.
  if (isEmpty ())
    exit ("STACK: can't pop item from stack: stack is empty.");

  // fetch the top item from the array.
  T item = contents[--top];

  // shrink size of array if necessary.
  if (!isEmpty () && (top <= size / 4))
    resize (size / 2);

  // return the top item from the array.
  return item;
}

// unshift an item to the stack.
template<typename T>
void StackArray<T>::unshift (const T i) {
  // check if the stack is full.
  if (isFull ())
    // double size of array.
    resize (size * 2);

  // store the item to the array.
  for(int c = size-1 ; c > 0 ; c--){
    contents[c] = contents[c-1];
  }
  contents[0] = i;
  top++;
}

// get an item from the stack.
template<typename T>
T StackArray<T>::peek () const {
  // check if the stack is empty.
  if (isEmpty ())
    exit ("STACK: can't peek item from stack: stack is empty.");

  // get the top item from the array.
  return contents[top - 1];
}

// check if the stack is empty.
template<typename T>
bool StackArray<T>::isEmpty () const {
  return top == 0;
}

// check if the stack is full.
template<typename T>
bool StackArray<T>::isFull () const {
  return top == size;
}

// get the number of items in the stack.
template<typename T>
int StackArray<T>::count () const {
  return top;
}

// set the printer of the stack.
template<typename T>
void StackArray<T>::setPrinter (Print & p) {
  printer = &p;
}

// exit report method in case of error.
template<typename T>
void StackArray<T>::exit (const char * m) const {
  // print the message if there is a printer.
  if (printer)
    printer->println (m);

  // loop blinking until hardware reset.
  blink ();
}

// led blinking method in case of error.
template<typename T>
void StackArray<T>::blink () const {
  // set led pin as output.
  pinMode (ledPin, OUTPUT);

  // continue looping until hardware reset.
  while (true) {
    digitalWrite (ledPin, HIGH); // sets the LED on.
    delay (250);                 // pauses 1/4 of second.
    digitalWrite (ledPin, LOW);  // sets the LED off.
    delay (250);                 // pauses 1/4 of second.
  }

  // solution selected due to lack of exit() and assert().
}

#endif // _STACKARRAY_H
/*
based on three row resistors=2.7 Kilo-Ohm and two columns resistors=10 Kilo-Ohm and pull down resistor=10 Kilo-Ohm 
*/

char getKey(){
  int value=analogRead(A0);
  if(value>340&&value<370){
    return '1';
  }
  else if(value>500&&value<580){
    return '2';
  }
  else if(value>1020){
    return '3';
  } 
  else if(value>325&&value<340){
    return '4';
  } 
  else if(value>450&&value<500){
    return '5';
  }  
  else if(value>750&&value<900){
    return '6';
  } 
  else if(value>300&&value<325){
    return '7';
  } 
  else if(value>400&&value<450){
    return '8';
  }
  else if(value>650&&value<750){
    return '9';
  }
  else if(value>200&&value<300){
    return '*';
  }
  else if(value>370&&value<400){
    return '0';
  }
  else if(value>580&&value<650){
    return '#';
  }
  else{
    return '?';
  }
  
}
int states[3][3]={
                  {1,3,2},
                  {3,3,2},
                  {0,0,2}
                  };
bool precedence(char c1,char c2){
  int p1=0,p2=0;
  if(c1=='*'||c1=='/'){p1=1;}
  else{p1=0;}
  if(c2=='*'||c2=='/'){p2=1;}
  else{p2=0;}  
  return p1>=p2;
    
}
float calculate(float operand1,char operator_name,float operand2){
  
  if(operator_name=='+'){return operand1+operand2;}
  else if(operator_name=='-'){return operand1-operand2;}
  else if(operator_name=='*'){return operand1*operand2;}
  else { 
      return operand1/operand2; 
  }
}
String reduntant_minus(String s){
 StackArray <char> st;
 int n=s.length();
 st.push(s.charAt(n-1));
 for(int i=n-2;i>=0;i--){
  char c=s.charAt(i);
  if(c=='-'&&st.peek()=='+'||c=='+'&&st.peek()=='-'){
    st.pop();
    st.push('-');
  }
  else if(c=='-'&&st.peek()=='-'){
    st.pop();
    st.push('+');
  }
  else if(c=='+'&&st.peek()=='+'){}
  else{st.push(c);}
 }
 String ans="";
 while(!st.isEmpty()){
  ans+=st.pop();
 }
 if(ans.charAt(0)=='+'){ans=ans.substring(1);}

 return ans;
}

bool check_Format(String s){

 s=reduntant_minus(s);


  int n=s.length(),state=0;
  for(int i=0;i<n;i++){
    char c=s.charAt(i);
    if(c=='-'){
      state=states[state][0];
    }
    else if(c=='+'||c=='*'||c=='/'){
      state=states[state][1];
    }
    else{
      state=states[state][2];
    }
    if(state==3){return false;}
  }
  return state==2;
}
int get_next_space(int index,String s){
  int n=s.length();
  for(int i=index+1;i<n;i++){
    if(s.charAt(i)==' '){
    return i;
    }
  }
  return n;
}
float Evaluate(String s){
   s=reduntant_minus(s);
  int n=s.length(),index=0;
  String spaced="";
  spaced+=s.charAt(0);
  for(int i=1;i<n;i++){
    char c=s.charAt(i);
    if(c=='+'||c=='*'||c=='/'){
      spaced=spaced+=" ";
      spaced+=c;
      spaced+=" ";
    }
    else if(c=='-'){
      if(spaced.charAt(spaced.length()-1)==' '){
        spaced+='-';
      }
      else{
      spaced=spaced+=" ";
      spaced+=c;
      spaced+=" ";        
      }
    }
    else{
      spaced+=c;
    }
  }
  StackArray <float> numbers;
  StackArray <char> operators;
  n=spaced.length();
  int next_space=get_next_space(0,spaced),current=0;
  
  while(next_space<n){
    numbers.push(spaced.substring(current,next_space).toFloat());
    char operator_name=spaced.charAt(next_space+1);
    while(!operators.isEmpty()&&precedence(operators.peek(),operator_name)){
     char top=operators.pop();
     float x=numbers.pop();
     float y=numbers.pop();
     if(top=='/' && x==0){
     lcd.setCursor(0,0);
     lcd.print("can't divide by");
     Serial.print("can't divide by");
       return 0;
     }
      else{
     numbers.push(calculate(y,top,x));
     }
    }
    operators.push(operator_name);
    current=next_space+3;
    next_space=get_next_space(next_space+2,spaced);
    
  }
    numbers.push(spaced.substring(current).toFloat());
    while(!operators.isEmpty()){
     char top=operators.pop(); 
     
     float x=numbers.pop();
     float y=numbers.pop();
      if(top=='/' && x==0){
         lcd.setCursor(0,0);
         lcd.print("can't divide by");
        Serial.print("can't divide by");
        return 0;
      }
      else{
     numbers.push(calculate(y,top,x));
     }
    }
    return numbers.pop();
} 
String buffer="";
long last_time_operator_pressed=0;
void key_pressed(char c){
        if(c=='*'){
     if(millis()-last_time_operator_pressed<1500){
        int n=buffer.length();
        if(buffer.charAt(n-1)=='+'){
          buffer.remove(n-1);
          buffer+='-';
        }
        else if(buffer.charAt(n-1)=='-'){
          buffer.remove(n-1);
          buffer+='*';
        }
        else if(buffer.charAt(n-1)=='*'){
          buffer.remove(n-1);
          buffer+='/';
        }
        else if(buffer.charAt(n-1)=='/'){
          buffer.remove(n-1);
          buffer+='+';
        }
        else{
          buffer+='+';
        }
    } 
    else{  
      
      buffer+='+';
    }
    last_time_operator_pressed=millis(); 
  }
  else if(c=='#'&&buffer.length()>0){
    if(check_Format(buffer)){
      lcd.clear();
      lcd.setCursor(0,0);
      float ans=Evaluate(buffer);
      lcd.print(ans);
      Serial.println(ans);
    }
    else{
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print("wrong format");
      Serial.println("wrong format");
    }
    buffer="";
    last_time_operator_pressed=0;
  }
  else{
    buffer+=c;
  }
  if(buffer.length()==1){
  lcd.clear();
  }
  lcd.setCursor(0,0);
  if(buffer.length()<16){
  lcd.print(buffer);
  }
  else{
    lcd.print(buffer.substring(0,16));
    lcd.setCursor(0,1);
    lcd.print(buffer.substring(16));
  }
 
   Serial.println(buffer);
   delay(300);
}