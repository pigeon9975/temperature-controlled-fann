#define IN1 3
#define IN2 4
#define ENA 9
#define LM A0
int  val=0;          //用于存储读取出的LM35的模拟信号值
float temp=0;        //用于存储 计算出的温度值
float speed=0;
//初始化部分
void setup()
{
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT); 
  pinMode(ENA,OUTPUT);        
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);             //为控制马达的两个引脚分别写上电平值
  Serial.begin(115200);
}
//主函数部分
void loop()
{
  val=analogRead(LM);             //读取A0引脚的模拟值
  temp= val * 0.48876;               //将读取的模拟值val换算成温度值
  Serial.println(temp);
  if(temp<25)                  
  {
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);     //当温度值小于25度时，给IN1和IN2低电平，马达不转动
  }
  else if(temp>=25)
  {
    val=map(temp,26,31,30,200);            //利用map()函数对LM35读取信号值进行映射
    analogWrite(ENA,val);          //当温度值大于25度，马达的转速开始随着温度的升高而加快
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
  }                                         
}
