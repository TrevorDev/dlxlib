/********
dlxlib.c
summary: commonly used functions for c programming
author: Trevor Baron
date: Nov 11 2013
********/
#include "dlxlib.h"

//INFO
double dlxlibVersion(){
	return DLXLIB_VERSION;
}

//CLOCK
double get_wall_time(){
    struct timeval time;
    if (gettimeofday(&time,NULL)){
        //  Handle error
        return 0;
    }
    return (double)time.tv_sec + (double)time.tv_usec * .000001;
}

timer createTimer(){
	timer t;
	t.start = get_wall_time();
	return t;
}

double getTime(timer t){
	return get_wall_time()-t.start;
}

//VECOTR
vector * createVector(){
	vector * ret = (vector *)calloc(1, sizeof(vector));
	return ret;
}

//FILE IO
char * fileToString(char * filename){
	char * ret;
	long input_file_size;
	FILE * input_file = fopen(filename,"r");
	fseek(input_file, 0, SEEK_END);
	input_file_size = ftell(input_file);
	rewind(input_file);
	ret = malloc((input_file_size+1) * (sizeof(char)));
	fread(ret, sizeof(char), input_file_size, input_file);
	ret[input_file_size] = '\0';
	fclose(input_file);
	return ret;
}

//STRINGS
char * strAdd(char * a,char * b){
	char * ret=(char *)calloc(strlen(a)+strlen(b)+1,sizeof(char));
	ret[0]='\0';
	strcat(ret,a);
	strcat(ret,b);
	return ret;
}

char * dupStr(char * str){
	char * ret = (char *)calloc(strlen(str)+1, sizeof(char));
	strcpy(ret, str);
	return ret;
}

vector * split(char * str, char * delim){
	vector * v = createVector();
	char *token;
	int count = 0;
	token = strtok(str, delim);
	while( token != NULL ) 
	{    
		token = strtok(NULL, delim);
		count++;
	}

	v->size=count;
	v->ar = calloc(sizeof(char*),count);
	token = str;
    for (int i = 0; i < count;i++) {
    	((char **)v->ar)[i] = dupStr(token);
        token += strlen(token) + 1;  // get the next token by skipping past the '\0'
        token += strspn(token, delim); //   then skipping any starting delimiters
    }

   return v;
}

int * strToInt(char * str){
	int * ret = calloc(1,sizeof(int));
	errno = 0;
	int num = (int)strtol(str, NULL, 0);
	if(errno!=0){
		ret = NULL;
	}else{ 
		*ret = num;
	}
	
	return ret;
}

//PRINTING
int print(const char * format, ...) {
	va_list arg;
	int done;
	va_start (arg, format);
	done = vfprintf(stderr, format, arg);
	va_end (arg);
	printf("\n");
	return done;
}