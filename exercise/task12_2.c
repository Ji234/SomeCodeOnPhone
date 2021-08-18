//解析XML字符串的函数族,支持int,char和double
//返回值:0->成功;-1->失败
int GetXMLBuffer_Int(const char *in_XMLBuffer,const char*in_FieldName,int *out_Value);
int GetXMLBuffer_Str(const char *in_XMLBuffer,const char*in_FieldName,int *out_Value);
int GetXMLBuffer_Double(const char *in_XMLBuffer,const char*in_FieldName,int *out_Value);
struct st_girl
{
  char name[51];//姓名
  int age;      //年龄
  int height;   //身高,单位cm
  double weight;//体重kg
  char sc[31];  //身材,火辣,普通,飞机场
  char yz[31];  //颜值,漂亮,一般,外瓜裂枣
};
char *toxml(const char * str, struct st_girl girl){
   sprintf(str,"<age>%d</age><height>%d</height><weight>%f</weigth><name>%s</name></sc>%s<sc><yz>%s</yz>",girl.age,girl.height,girl.weight,girl.name,girl.sc,girl.yz);
}
int main(){
  struct st_girl someone;
  char sxml[200];
  strcpy(someone.name,"aaa");
  someone.age=20;
  someone.height=170;
  someone.weight=60;
  strcpy(someone.yz,"漂亮");
  strcpy(someone.sc,"火辣");
  toxml(sxml,someone);
  printf("%s\n",sxml);
}

