//增加函数freecplus框架中的函数

//删除字符串左边指定的的字符
void DelectLChar(char *str,const char in_char);
//删除字符串右边的指定字符
void DelectRChar(char *str,const char in_char);
//删除字符串两边的指定字符
void DelectLRChar(char *str,const char in_char);
//删除字符串中间的字符串
void DelectMstr(char *str,const char in_char);
//在字符串的右边补字符到指定长度
void LPad(char *str,const char in_char,unsigned int in_len);
//在字符串的左边补字符到指定长度
void RPad(char *str,const char in_char,unsigned int int_len);
//把小写换成大写,忽略不是字母的字符
void ToUpper(char *str);
//把大写换成小写,忽略不是字母的字符
void ToLower(char *str);
//判断内容是不是全部是数字
int IsDigit(const char *str);
//判断内容是不是全部是大写字母
int IsUpper(const char *str);
//判断内容是不是全部是小写字母
int IsLower(const char *str);
//判断内容是不是全部是ASCII字符
int IsASCII(const char *str);

