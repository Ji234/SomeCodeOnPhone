//解析XML字符串的函数族,支持int,char和double
//返回值:0->成功;-1->失败
int GetXMLBuffer_Int(const char *in_XMLBuffer,const char*in_FieldName,int *out_Value);
int GetXMLBuffer_Str(const char *in_XMLBuffer,const char*in_FieldName,int *out_Value);
int GetXMLBuffer_Double(const char *in_XMLBuffer,const char*in_FieldName,int *out_Value);
