//book210.cpp
//to shw soem feature for class
//this application's function like cat
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

class CFile{
private:
	FILE *m_fp;//file point 
	bool m_bEnBuffer;//use or not use buffer area
public:
	CFile();//construction function
	CFile(bool bEuffer);//construction function
	~CFile();//destructor function
	void EnBffer(bool bEuffer=true);
	bool Open(const char *filename,const char *openmode);//open file parameter is some with fopen success return ture,false return false;
	void Fprintf(const char *fmt,...);
	bool Fgets(char *strBuffer,const int Readsize);
	void Close();
};

int main(int argc,char *argv[]){
	if(argc!=2){printf("input filename");return -1;}
	CFile File;
	if(File.Open(argv[1],"r")==false){printf("open false");return -1;}
	char strLine[300];
	while(true){
		//read a line from file
		if(File.Fgets(strLine,300)==false) break;
		printf("%s",strLine);//print the text where from file
	}
}

CFile::CFile(){
	m_fp=0;
	m_bEnBuffer=true;
}

CFile::CFile(bool bEuffer){
	m_fp=0;
	m_bEnBuffer=bEuffer;
}

void CFile::Close(){
	if(m_fp!=0) fclose(m_fp);
	m_fp=0;
}
CFile::~CFile(){
	Close();
}

void CFile::EnBffer(bool bEuffer){
	m_bEnBuffer=bEuffer;
}
bool CFile::Open(const char *filename,const char *openmode ){
	Close();
	if((m_fp=fopen(filename,openmode))==0) return false;
	return true;
}
void CFile::Fprintf(const char *fmt,...){
	if(m_fp==0) return;
	va_list arg;
	va_start(arg,fmt);
	vfprintf(m_fp,fmt,arg);
	va_end(arg);
	if(m_bEnBuffer==false) fflush(m_fp);
}
bool CFile::Fgets(char *strBuffer,const int Readsize){
	if(m_fp==0) return false;
	memset(strBuffer,0,Readsize);
	if(fgets(strBuffer,Readsize,m_fp)==0) return false;
	return true;
}
