/*
 * 这是一个读取键盘的程序
 * 将键盘上按下的建打印到串口
 */

const int numRows = 4;         //键盘行数
const int numCols = 3;         //键盘列数
const int debounceTime = 20;   //开关稳定需要的毫秒数

const char keymap[numRows][numCols] = {  //定义相应的按键被按下时返回的字符
  { '1','2','3'}  ,
  { '4','5','6'}  ,
  { '7','8','9'}  ,
  { '*','0','#'}
};
const int rowPins[numRows] = { 7 ,2, 3, 6 };//这个数组用来确定 行 的引脚
const int colPins[numCols] = { 5, 8, 4 };   //这个数字用来确定 列 的引脚

void setup()
{
  Serial.begin(9600);
  for(int row = 0;row < numRows; row++)
  {
    pinMode(rowPins[row],INPUT);
    digitalWrite(rowPins[row],HIGH);
  }
  for( int column = 0; column < numCols; column++)
  {
    pinMode(colPins[column],OUTPUT);
    digitalWrite(colPins[column],HIGH);
  }
}

void loop()
{
  char key = getKey();
  if(key != 0)               //如果字符不为0
  {                           //则这个是一个有效的按键
    Serial.print("Got key");
    Serial.println(key);
  }
}

char getKey()               //返回按下的建，没有就返回0
{
  char key = 0;             //0表示没有按键被按下         
  for(int column = 0; column < numCols; column++)
  {
    digitalWrite(colPins[column ],LOW);  //激活当前列，扫描所有行，查找被按下的建
    for(int row = 0;row <numRows; row++)
    {
      if(digitalRead(rowPins[row]) == LOW)  //是被按下了吗？
      {
      delay(debounceTime);                  //去抖
      while(digitalRead(rowPins[row]) == LOW);//等待按键被释放
      key = keymap[row][column];              //记录哪个按键被按下
      }
    }
     digitalWrite(colPins[column],HIGH);      //激活当前列
  }
  return key;                              //返回按下的建，如果没有返回0
} 


 
