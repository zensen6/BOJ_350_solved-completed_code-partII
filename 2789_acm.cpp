#include<stdio.h>
#include<string.h>

int main(){
	
	char text[101];
	char str[101];
	int cnt=0;
	fgets(text,101,stdin);
	int len = strlen(text);
	for(int i=0;i<len;i++){
		
		if(text[i]=='C' ||text[i]=='A'||text[i]=='M'||text[i]=='B'||text[i]=='R'||text[i]=='I'||text[i]=='D'||text[i]=='G'||text[i]=='E')
			continue;
		else{
			
			str[cnt++] = text[i];			
		}
		
	}
	printf("%s\n",str);
	
	return 0;
	
}

